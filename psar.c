#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <zlib.h>

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

#define PSAR_BUFFER_SIZE	9400000*4
u8 buf[PSAR_BUFFER_SIZE],g_dataOut[PSAR_BUFFER_SIZE],g_dataOut2[PSAR_BUFFER_SIZE];

int iBase, cbChunk, psarVersion;
int psarPosition;
int decrypted;

static char com_table[0x4000];
static int comtable_size;

static char _1g_table[0x4000];
static int _1gtable_size;

static char _2g_table[0x4000];
static int _2gtable_size;

static char _3g_table[0x4000];
static int _3gtable_size;

static char _4g_table[0x4000];
static int _4gtable_size;

static char _5g_table[0x4000];
static int _5gtable_size;

static char _6g_table[0x4000];
static int _6gtable_size;

static char _7g_table[0x4000];
static int _7gtable_size;

static char _8g_table[0x4000];
static int _8gtable_size;

static char _9g_table[0x4000];
static int _9gtable_size;

static char _10g_table[0x4000];
static int _10gtable_size;

static char _11g_table[0x4000];
static int _11gtable_size;

static char _12g_table[0x4000];
static int _12gtable_size;

int sceUtilsBufferCopyWithRange(u8* outbuff, int outsize, u8* inbuff, int insize, int cmd);
int pspDecryptTable(u8 *buf1, u8 *buf2, int size, int mode);
int pspDecryptPRX(u8 *inbuf, u8 *outbuf, u32 size);
int pspDecryptIPL1(const u8* pbIn, u8* pbOut, int cbIn);
int pspLinearizeIPL2(const u8* pbIn, u8* pbOut, int cbIn, u32 *startAddr);
int pspDecryptIPL3(const u8* pbIn, u8* pbOut, int cbIn);

static int OVERHEAD;
#define SIZE_A      0x110 /* size of uncompressed file entry = 272 bytes */

// for 1.50 and later, they mangled the plaintext parts of the header
static void Demangle(const u8* pIn, u8* pOut)
{
    u8 buffer[20+0x130];
	u8 K1[0x10] = { 0xD8, 0x69, 0xB8, 0x95, 0x33, 0x6B, 0x63, 0x34, 0x98, 0xB9, 0xFC, 0x3C, 0xB7, 0x26, 0x2B, 0xD7 };
	u8 K2[0x10] = { 0x0D, 0xA0, 0x90, 0x84, 0xAF, 0x9E, 0xB6, 0xE2, 0xD2, 0x94, 0xF2, 0xAA, 0xEF, 0x99, 0x68, 0x71 };
	int i;
	memcpy(buffer+20, pIn, 0x130);
	if (psarVersion == 5) for ( i = 0; i < 0x130; ++i ) { buffer[20+i] ^= K1[i & 0xF]; }
    u32* pl = (u32*)buffer; // first 20 bytes
    pl[0] = 5;
    pl[1] = pl[2] = 0;
    pl[3] = 0x55;
    pl[4] = 0x130;
    sceUtilsBufferCopyWithRange(buffer, 20+0x130, buffer, 20+0x130, 0x7);
	if (psarVersion == 5) for ( i = 0; i < 0x130; ++i ) { buffer[i] ^= K2[i & 0xF]; }
    memcpy(pOut, buffer, 0x130);
}

static int DecodeBlock(const u8* pIn, int cbIn, u8* pOut)
{
    // pOut also used as temporary buffer for mangled input
    // assert((((u32)pOut) & 0x3F) == 0); // must be aligned

	if (decrypted)
	{
		if (pIn != pOut)
		{
			memcpy(pOut, pIn, cbIn);
		}

		return cbIn;
	}

    memcpy(pOut, pIn, cbIn + 0x10); // copy a little more for $10 page alignment

    int ret;
    int cbOut;
    
    if (psarVersion != 1)
	{
		Demangle(pIn+0x20, pOut+0x20); // demangle the inside $130 bytes
	}
/*
    if (*(u32 *)&pOut[0xD0] == 0x0E000000)
    {
		ret = 1;//sceMesgd_driver_102DC8AF(pOut, cbIn, &cbOut);
	}
	else if (*(u32 *)&pOut[0xD0] == 0x06000000)
	{
		ret = 1;//sceNwman_driver_9555D68D(pOut, cbIn, &cbOut);
	}
	else
*/
	{
		cbOut = pspDecryptPRX(pOut, pOut, cbIn);
		if (cbOut < 0)
		{
			printf("Unknown psar tag.\n");
			return 0xFFFFFFFC;
		}
		else
			return cbOut;
	}
    if (ret != 0)
        return ret; // error

	return cbOut;
}

int pspPSARInit(u8 *dataPSAR, u8 *dataOut, u8 *dataOut2)
{

//initialize global vars
//iBase=cbChunk=psarPosition=decrypted=0;

	if (memcmp(dataPSAR, "PSAR", 4) != 0)
    {
        //pspSdkSetK1(k1);
		return -1;
    }

	decrypted = (*(u32 *)&dataPSAR[0x20] == 0x2C333333); // 3.5X M33, and 3.60 unofficial psar's

	if (decrypted)
	{
		OVERHEAD = 0;
	}
	else
	{
		OVERHEAD = 0x150;
	}

	//oldschool = (dataPSAR[4] == 1); /* bogus update */
	psarVersion = dataPSAR[4];

    int cbOut;
	
    // at the start of the PSAR file,
    //   there are one or two special version data chunks
    // printf("Special PSAR records:\n");
    cbOut = DecodeBlock(&dataPSAR[0x10], OVERHEAD+SIZE_A, dataOut);
    if (cbOut <= 0)
    {
        //pspSdkSetK1(k1);
        return cbOut;
    }

    if (cbOut != SIZE_A)
    {
        //pspSdkSetK1(k1);
        return -2;
    }

    iBase = 0x10+OVERHEAD+SIZE_A; // after first entry
            // iBase points to the next block to decode (0x10 aligned)

	if (decrypted)
	{
		cbOut = DecodeBlock(&dataPSAR[0x10+OVERHEAD+SIZE_A], *(u32 *)&dataOut[0x90], dataOut2);
		if (cbOut <= 0)
		{
			//pspSdkSetK1(k1);
			return -3;
		}
		   
		iBase += OVERHEAD+cbOut;
		//pspSdkSetK1(k1);
		return 0;
	}
	
	if (psarVersion != 1)
	{
		// second block
		cbOut = DecodeBlock(&dataPSAR[0x10+OVERHEAD+SIZE_A], OVERHEAD+100, dataOut2);
		if (cbOut <= 0)
		{
			//printf("Performing V2.70 test\n"); // version 2.7 is bigger
			cbOut = DecodeBlock(&dataPSAR[0x10+OVERHEAD+SIZE_A], OVERHEAD+144, dataOut2);
			if (cbOut <= 0)
			{
				cbOut = DecodeBlock(&dataPSAR[0x10+OVERHEAD+SIZE_A], OVERHEAD+*(u16 *)&dataOut[0x90], dataOut2);
				if (cbOut <= 0)
				{
					//pspSdkSetK1(k1);
					return -4;
				}
			}
		}
	}
       
	cbChunk = (cbOut + 15) & 0xFFFFFFF0;
	iBase += OVERHEAD+cbChunk;
	psarPosition = 0;

	//pspSdkSetK1(k1);
	return 0;
}

int sceKernelDeflateDecompress(u8 *dest, u32 destSize, u8 *src, u32 unknown)
{
	z_stream z;
	z.zalloc = Z_NULL;
	z.zfree = Z_NULL;
	z.opaque = Z_NULL;
    int ret = inflateInit2(&z, 47);
    z.avail_in = PSAR_BUFFER_SIZE;
    z.next_out = dest;
    z.avail_out = destSize;
    z.next_in = src;
    ret = inflate(&z, Z_FULL_FLUSH);
    inflateEnd(&z);

    if (ret != Z_STREAM_END) {
        return -1;
    } else {
        return destSize;
    }
}

int pspPSARGetNextFile(u8 *dataPSAR, int cbFile, u8 *dataOut, u8 *dataOut2, char *name, int *retSize, int *retPos, int *signcheck)
{
	//int k1 = pspSdkSetK1(0);
	int cbOut;

	if (iBase >= (cbFile-OVERHEAD))
	{
		//pspSdkSetK1(k1);
		return 0; // no more files
	}

	cbOut = DecodeBlock(&dataPSAR[iBase-psarPosition], OVERHEAD+SIZE_A, dataOut);
	if (cbOut <= 0)
	{
		//pspSdkSetK1(k1);
		return -1;
	}
	if (cbOut != SIZE_A)
	{
		//pspSdkSetK1(k1);
		return -1;
	}

	strcpy(name, (const char*)&dataOut[4]);
	u32* pl = (u32*)&dataOut[0x100];
	*signcheck = (dataOut[0x10F] == 2);
        
	// pl[0] is 0
	// pl[1] is the PSAR chunk size (including OVERHEAD)
	// pl[2] is true file size (TypeA=272=SIZE_A, TypeB=size when expanded)
	// pl[3] is flags or version?
	if (pl[0] != 0)
	{
		//pspSdkSetK1(k1);
		return -1;
	}

	iBase += OVERHEAD + SIZE_A;
	u32 cbDataChunk = pl[1]; // size of next data chunk (including OVERHEAD)
	u32 cbExpanded = pl[2]; // size of file when expanded

	if (cbExpanded > 0)
	{
		cbOut = DecodeBlock(&dataPSAR[iBase-psarPosition], cbDataChunk, dataOut);
		if (cbOut > 10 && dataOut[0] == 0x78 && dataOut[1] == 0x9C)
		{
			// standard Deflate header
			const u8* pbIn = &dataOut[0]; // after header
			u32 pbEnd;
			
			//insize=cbOut
			int ret = sceKernelDeflateDecompress(dataOut2, cbExpanded, pbIn, &pbEnd);
			
			if (ret == cbExpanded)
			{
                *retSize = ret;
			}
                    
			else
			{
				//pspSdkSetK1(k1);
				return -1;
			}
		}

		else
		{
			iBase -= (OVERHEAD + SIZE_A);
			//pspSdkSetK1(k1);
			return -1;
		}
	}

	else if (cbExpanded == 0)
	{
        *retSize = 0;
		// Directory
	}
	
	else
	{
		//pspSdkSetK1(k1);
		return -1;
	}
        
	iBase += cbDataChunk;
	*retPos = iBase;
	
	//pspSdkSetK1(k1);
	return 1; // morefiles
}

static int is5Dnum(char *str)
{
	int len = strlen(str);

	if (len != 5)
		return 0;

	int i;

	for (i = 0; i < len; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return 0;
	}

	return 1;
}

static char *GetVersion(char *buf)
{
	char *p = strrchr(buf, ',');

	if (!p)
		return NULL;

	return p+1;
}

int makedir(const char *_dir){
	if(!_dir||!*_dir)return -1;
	char *dir=(char*)_dir; //unsafe, but OK
	int l=strlen(dir),i=0,ret=0;
	for(;i<l;i++){
		int c=dir[i];
		if(c=='\\'||c=='/'){
			dir[i]=0;
#if defined(_WIN32) || (!defined(__GNUC__) && !defined(__clang__))
			ret=mkdir(dir);
#else
			ret=mkdir(dir,0755);
#endif
			dir[i]=c;
		}
	}
	return ret;
}

static int WriteFile(const char *szDataPath, u8 *pbToSave, int cbToSave)
{
	if(!strncmp(szDataPath,"ms0:/",5)){
		const char *szRelDataPath = szDataPath+5;
		makedir(szRelDataPath);
		FILE *f = fopen(szRelDataPath, "wb");
		int r = fwrite(pbToSave, 1, cbToSave, f);
		fclose(f);
		return r;
	}
	return -1;
}

void ErrorExit(int milisecs, char *fmt, ...)
{
	va_list list;
	char msg[256];

	va_start(list, fmt);
	vsprintf(msg, fmt, list);
	va_end(list);

	puts(msg);
	
	//sceKernelDelayThread(milisecs*1000);
	
	abort();
}

static int FindTablePath(char *table, int table_size, char *number, char *szOut)
{
	int i, j, k;

	for (i = 0; i < table_size-5; i++)
	{
		if (strncmp(number, table+i, 5) == 0)
		{
			for (j = 0, k = 0; ; j++, k++)
			{
				if (table[i+j+6] < 0x20)
				{
					szOut[k] = 0;
					break;
				}

				if (table[i+5] == '|' && !strncmp(table+i+6, "flash", 5) &&
					j == 6)
				{
					szOut[6] = ':';
					szOut[7] = '/';
					k++;
				}
				else if (table[i+5] == '|' && !strncmp(table+i+6, "ipl", 3) &&
					j == 3)
				{
					szOut[3] = ':';
					szOut[4] = '/';
					k++;
				}
				else
				{
					szOut[k] = table[i+j+6];
				}
			}

			return 1;
		}
	}

	return 0;
}

int main(){
    kirk_init();
    FILE *f=fopen("661.PBP","rb");
    fread(buf,1,0x28,f);
    int psar_offs = *(u32*)(buf+0x24);
	fseek(f, 0, SEEK_END);
	int cbFile = ftell(f) - psar_offs;
    fseek(f,psar_offs,SEEK_SET);
    fread(buf,1,cbFile,f);
    if(memcmp(buf,"PSAR",4)){
        printf("not psar");
    }
	int table_mode;
pspPSARInit(buf, g_dataOut, g_dataOut2);

	
	char *version = GetVersion((char *)g_dataOut+0x10);
	printf("Version %s.\n", version);

	if (memcmp(version, "3.8", 3) == 0 || memcmp(version, "3.9", 3) == 0)
	{
		table_mode = 1;
	}
	else if (memcmp(version, "4.", 2) == 0)
	{
		table_mode = 2;
	}
	else if (memcmp(version, "5.", 2) == 0)
	{
		table_mode = 3;
	}
    else if ((memcmp(version, "6.3", 3) == 0) && (psarVersion == 5))
	{
		table_mode = 4;
	}
    else if ((memcmp(version, "6.6", 3) == 0) && (psarVersion == 5))
	{
		table_mode = 4;
	}
    else if ((memcmp(version, "6.", 2) == 0) && (psarVersion == 5)) // 6.10/6.20 PSPgo
	{
		table_mode = 5;
	}
    else if (memcmp(version, "6.", 2) == 0)
	{
		table_mode = 4;
	}
	else
	{
		table_mode = 0;
	}
	int s=0;
	char name[128];
			int cbExpanded;
			int pos;
			int signcheck;
	for(;;){
		int res = pspPSARGetNextFile(buf, cbFile, g_dataOut, g_dataOut2, name, &cbExpanded, &pos, &signcheck);
		if(res<=0)break;
		s+=cbExpanded;
		//printf("%d %d %s\n",s,cbExpanded,name);
		
		if (is5Dnum(name))
		{
			if (   strcmp(name, "00001") != 0 && strcmp(name, "00002") != 0 && strcmp(name, "00003") != 0 && strcmp(name, "00004") != 0 && strcmp(name, "00005") != 0
                && strcmp(name, "00006") != 0 && strcmp(name, "00007") != 0 && strcmp(name, "00008") != 0 && strcmp(name, "00009") != 0 && strcmp(name, "00010") != 0 && strcmp(name, "00011") != 0 && strcmp(name, "00012") != 0)
			{
				int found = 0;
				
				if (_1gtable_size > 0)
				{
					found = FindTablePath(_1g_table, _1gtable_size, name, name);
				}

				if (!found && _2gtable_size > 0)
				{
					found = FindTablePath(_2g_table, _2gtable_size, name, name);
				}

				if (!found && _3gtable_size > 0)
				{
					found = FindTablePath(_3g_table, _3gtable_size, name, name);
				}
				
				if (!found && _4gtable_size > 0)
				{
					found = FindTablePath(_4g_table, _4gtable_size, name, name);
				}
				
				if (!found && _5gtable_size > 0)
				{
					found = FindTablePath(_5g_table, _5gtable_size, name, name);
				}

				if (!found && _6gtable_size > 0)
				{
					found = FindTablePath(_6g_table, _6gtable_size, name, name);
				}

				if (!found && _7gtable_size > 0)
				{
					found = FindTablePath(_7g_table, _7gtable_size, name, name);
				}

				if (!found && _8gtable_size > 0)
				{
					found = FindTablePath(_8g_table, _8gtable_size, name, name);
				}

				if (!found && _9gtable_size > 0)
				{
					found = FindTablePath(_9g_table, _9gtable_size, name, name);
				}
				
				if (!found && _10gtable_size > 0)
				{
					found = FindTablePath(_10g_table, _10gtable_size, name, name);
				}
				
				if (!found && _11gtable_size > 0)
				{
					found = FindTablePath(_11g_table, _11gtable_size, name, name);
				}
				if (!found && _12gtable_size > 0)
				{
					found = FindTablePath(_12g_table, _12gtable_size, name, name);
				}

				if (!found)
				{
					ErrorExit(5000, "Part 1 Error: cannot find path of %s.\n", name);
					//printf("Warning: first cannot find path of %s\n", name);
					//sceKernelDelayThread(2*1000*1000);
					//error = 0;
					continue;
				}
			}
		}
		else if (!strncmp(name, "com:", 4) && comtable_size > 0)
		{
			if (!FindTablePath(com_table, comtable_size, name+4, name))
			{
				ErrorExit(5000, "Part 2 Error: cannot find path of %s.\n", name);
				//printf("Warning: second cannot find path of %s\n", name);
				//sceKernelDelayThread(2*1000*1000);
				//error = 0;
				continue;
				//ErrorExit(5000, "Error: cannot find path of %s.\n", name);
			}
		}
		else if (!strncmp(name, "01g:", 4) && _1gtable_size > 0)
		{
			if (!FindTablePath(_1g_table, _1gtable_size, name+4, name))
			{
				ErrorExit(5000, "Error: 01g cannot find path of %s.\n", name);
			}
		}
		else if (!strncmp(name, "02g:", 4) && _2gtable_size > 0)
		{
			if (!FindTablePath(_2g_table, _2gtable_size, name+4, name))
			{
				ErrorExit(5000, "Error: 01g cannot find path of %s.\n", name);
			}
		}

        printf("'%s' ", name);

		char* szFileBase = strrchr(name, '/');
		
		if (szFileBase != NULL)
			szFileBase++;  // after slash
		else
			szFileBase = "err.err";

		
		if (cbExpanded > 0)
		{
			char szDataPath[128];
			
			if (!strncmp(name, "flash0:/", 8))
			{
				sprintf(szDataPath, "ms0:/F0/%s", name+8);
			}

			else if (!strncmp(name, "flash1:/", 8))
			{
				sprintf(szDataPath, "ms0:/F1/%s", name+8);
			}

			else if (!strcmp(name, "com:00000"))
			{
				comtable_size = pspDecryptTable(g_dataOut2, g_dataOut, cbExpanded, table_mode);
							
				if (comtable_size <= 0)
				{
					ErrorExit(5000, "Cannot decrypt common table.\n");
				}

				if (comtable_size > sizeof(com_table))
				{
					ErrorExit(5000, "Com table buffer too small. Recompile with bigger buffer.\n");
				}

				memcpy(com_table, g_dataOut2, comtable_size);
				strcpy(szDataPath, "ms0:/F0/PSARDUMPER/common_files_table.bin");
			}

			else if (!strcmp(name, "01g:00000") || !strcmp(name, "00001"))
			{
				_1gtable_size = pspDecryptTable(g_dataOut2, g_dataOut, cbExpanded, table_mode);
					
				if (_1gtable_size <= 0)
				{
					
					ErrorExit(5000, "Cannot decrypt 1g table.\n");
					
				}

				if (_1gtable_size > sizeof(_1g_table))
				{
					ErrorExit(5000, "1g table buffer too small. Recompile with bigger buffer.\n");
				}

				memcpy(_1g_table, g_dataOut2, _1gtable_size);
				strcpy(szDataPath, "ms0:/F0/PSARDUMPER/1000_files_table.bin");
			}
					
			else if (!strcmp(name, "02g:00000") || !strcmp(name, "00002"))
			{
				_2gtable_size = pspDecryptTable(g_dataOut2, g_dataOut, cbExpanded, table_mode);
							
				if (_2gtable_size <= 0)
				{
					ErrorExit(5000, "Cannot decrypt 2g table %08X.\n", _2gtable_size);
				}

				if (_2gtable_size > sizeof(_2g_table))
				{
					ErrorExit(5000, "2g table buffer too small. Recompile with bigger buffer.\n");
				}

				memcpy(_2g_table, g_dataOut2, _2gtable_size);
				strcpy(szDataPath, "ms0:/F0/PSARDUMPER/2000_files_table.bin");
			}

			else if (!strcmp(name, "00003"))
			{
				_3gtable_size = pspDecryptTable(g_dataOut2, g_dataOut, cbExpanded, table_mode);
							
				if (_3gtable_size <= 0)
				{
					// We don't have yet the keys for table of 3000, they are only in mesg_led03g.prx
					printf("Cannot decrypt 3g table %08X.\n", _3gtable_size);
					//error = 0;
					continue;
				}

				if (_3gtable_size > sizeof(_3g_table))
				{
					ErrorExit(5000, "3g table buffer too small. Recompile with bigger buffer.\n");
				}

				memcpy(_3g_table, g_dataOut2, _3gtable_size);
				strcpy(szDataPath, "ms0:/F0/PSARDUMPER/3000_files_table.bin");
			}
			else if (!strcmp(name, "00004"))
			{
				_4gtable_size = pspDecryptTable(g_dataOut2, g_dataOut, cbExpanded, table_mode);
							
				if (_4gtable_size <= 0)
				{
					printf("Cannot decrypt 4g table %08X.\n", _4gtable_size);
					//error = 0;
					continue;
				}

				if (_4gtable_size > sizeof(_4g_table))
				{
					ErrorExit(5000, "4g table buffer too small. Recompile with bigger buffer.\n");
				}

				memcpy(_4g_table, g_dataOut2, _4gtable_size);
				strcpy(szDataPath, "ms0:/F0/PSARDUMPER/4000_files_table.bin");
			}
			else if (!strcmp(name, "00005"))
			{
				_5gtable_size = pspDecryptTable(g_dataOut2, g_dataOut, cbExpanded, table_mode);
							
				if (_5gtable_size <= 0)
				{
					printf("Cannot decrypt 5g table %08X.\n", _5gtable_size);
					//error = 0;
					continue;
				}

				if (_5gtable_size > sizeof(_5g_table))
				{
					ErrorExit(5000, "5g table buffer too small. Recompile with bigger buffer.\n");
				}

				memcpy(_5g_table, g_dataOut2, _5gtable_size);
				strcpy(szDataPath, "ms0:/F0/PSARDUMPER/5000_files_table.bin");
			}
			else if (!strcmp(name, "00006"))
			{
				_6gtable_size = pspDecryptTable(g_dataOut2, g_dataOut, cbExpanded, table_mode);
							
				if (_6gtable_size <= 0)
				{
					printf("Cannot decrypt 6g table %08X.\n", _6gtable_size);
					//error = 0;
					continue;
				}

				if (_6gtable_size > sizeof(_6g_table))
				{
					ErrorExit(5000, "6g table buffer too small. Recompile with bigger buffer.\n");
				}

				memcpy(_6g_table, g_dataOut2, _6gtable_size);
				strcpy(szDataPath, "ms0:/F0/PSARDUMPER/6000_files_table.bin");
			}
			else if (!strcmp(name, "00007"))
			{
				_7gtable_size = pspDecryptTable(g_dataOut2, g_dataOut, cbExpanded, table_mode);
							
				if (_7gtable_size <= 0)
				{
					printf("Cannot decrypt 7g table %08X.\n", _7gtable_size);
					//error = 0;
					continue;
				}

				if (_7gtable_size > sizeof(_7g_table))
				{
					ErrorExit(5000, "7g table buffer too small. Recompile with bigger buffer.\n");
				}

				memcpy(_7g_table, g_dataOut2, _7gtable_size);
				strcpy(szDataPath, "ms0:/F0/PSARDUMPER/7000_files_table.bin");
			}
			else if (!strcmp(name, "00008"))
			{
				_8gtable_size = pspDecryptTable(g_dataOut2, g_dataOut, cbExpanded, table_mode);
							
				if (_8gtable_size <= 0)
				{
					printf("Cannot decrypt 8g table %08X.\n", _8gtable_size);
					//error = 0;
					continue;
				}

				if (_8gtable_size > sizeof(_8g_table))
				{
					ErrorExit(5000, "8g table buffer too small. Recompile with bigger buffer.\n");
				}

				memcpy(_8g_table, g_dataOut2, _8gtable_size);
				strcpy(szDataPath, "ms0:/F0/PSARDUMPER/8000_files_table.bin");
			}
			else if (!strcmp(name, "00009"))
			{
				_9gtable_size = pspDecryptTable(g_dataOut2, g_dataOut, cbExpanded, table_mode);
							
				if (_9gtable_size <= 0)
				{
					printf("Cannot decrypt 9g table %08X.\n", _9gtable_size);
					//error = 0;
					continue;
				}

				if (_9gtable_size > sizeof(_9g_table))
				{
					ErrorExit(5000, "9g table buffer too small. Recompile with bigger buffer.\n");
				}

				memcpy(_9g_table, g_dataOut2, _9gtable_size);
				strcpy(szDataPath, "ms0:/F0/PSARDUMPER/9000_files_table.bin");
			}
			else if (!strcmp(name, "00010"))
			{
				_10gtable_size = pspDecryptTable(g_dataOut2, g_dataOut, cbExpanded, table_mode);
							
				if (_10gtable_size <= 0)
				{
					printf("Cannot decrypt 10g table %08X.\n", _10gtable_size);
					//error = 0;
					continue;
				}

				if (_10gtable_size > sizeof(_10g_table))
				{
					ErrorExit(5000, "10g table buffer too small. Recompile with bigger buffer.\n");
				}

				memcpy(_10g_table, g_dataOut2, _10gtable_size);
				strcpy(szDataPath, "ms0:/F0/PSARDUMPER/10000_files_table.bin");
			}
			else if (!strcmp(name, "00011"))
			{
				_11gtable_size = pspDecryptTable(g_dataOut2, g_dataOut, cbExpanded, table_mode);
							
				if (_11gtable_size <= 0)
				{
					printf("Cannot decrypt 11g table %08X.\n", _11gtable_size);
					//error = 0;
					continue;
				}

				if (_11gtable_size > sizeof(_11g_table))
				{
					ErrorExit(5000, "11g table buffer too small. Recompile with bigger buffer.\n");
				}

				memcpy(_11g_table, g_dataOut2, _11gtable_size);
				strcpy(szDataPath, "ms0:/F0/PSARDUMPER/11000_files_table.bin");
			}
			else if (!strcmp(name, "00012"))
			{
				_12gtable_size = pspDecryptTable(g_dataOut2, g_dataOut, cbExpanded, table_mode);
							
				if (_12gtable_size <= 0)
				{
					printf("Cannot decrypt 12g table %08X.\n", _12gtable_size);
					//error = 0;
					continue;
				}

				if (_12gtable_size > sizeof(_12g_table))
				{
					ErrorExit(5000, "12g table buffer too small. Recompile with bigger buffer.\n");
				}

				memcpy(_12g_table, g_dataOut2, _12gtable_size);
				strcpy(szDataPath, "ms0:/F0/PSARDUMPER/12000_files_table.bin");
			}

			else
			{
				sprintf(szDataPath, "ms0:/F0/PSARDUMPER/%s", strrchr(name, '/') + 1);
			}

#if 0
			//select file
			int i=0;
			for(;i<argc;i++)
				if(!strcmp(szDataPath,argv[2*i])){strcpy(szDataPath,argv[2*i+1]);break;}
			if(i==argc){error=0;continue;}
#endif
			
			printf("%s,",szDataPath);

			printf("expanded");

			if (/*(mode != MODE_DECRYPT) ||*/ (memcmp(g_dataOut2, "~PSP", 4) != 0))
			{
				if (strncmp(name, "ipl:", 4) == 0 && *(u32*)(g_dataOut2 + 0x60) != 1 && *(u32*)(g_dataOut2 + 0x60) != 0x10001)
				{
					// IPL Pre-decryption
					cbExpanded = pspDecryptPRX(g_dataOut2, g_dataOut, cbExpanded);

					if (cbExpanded <= 0)
					{
						printf("Warning: cannot pre-decrypt 2000 IPL.\n");
					}
					else
					{
						memcpy(g_dataOut2, g_dataOut, cbExpanded);
					}
				}

				if (WriteFile(szDataPath, g_dataOut2, cbExpanded) != cbExpanded)
	            {
					ErrorExit(5000, "Cannot write %s.\n", szDataPath);
					break;
				}
	                    
				printf(",saved");
			}


			if (memcmp(g_dataOut2, "~PSP", 4) == 0)
			{
				memset(g_dataOut2+0x104,0,0x28);
				int cbDecrypted = pspDecryptPRX(g_dataOut2, g_dataOut, cbExpanded);

				// output goes back to main buffer
				// trashed 'g_dataOut2'
				if (cbDecrypted > 0)
				{
					u8* pbToSave = g_dataOut;
					int cbToSave = cbDecrypted;

					printf(",decrypted");
                            
					if ((g_dataOut[0] == 0x1F && g_dataOut[1] == 0x8B) ||
						memcmp(g_dataOut, "2RLZ", 4) == 0 || memcmp(g_dataOut, "KL4E", 4) == 0 || memcmp(g_dataOut, "KL3E", 4) == 0)
					{
						int cbExp = pspDecompress(g_dataOut, g_dataOut2, sizeof(g_dataOut));
						
						if (cbExp > 0)
						{
							printf(",decompressed",cbExp);
							pbToSave = g_dataOut2;
							cbToSave = cbExp;
						}
						else
						{
							printf("Decompress error 0x%08X\n"
								   "File will be written compressed.\n", cbExp);
						}
					}
        			
					if (WriteFile(szDataPath, pbToSave, cbToSave) != cbToSave)
					{
						ErrorExit(5000, "Error writing %s.\n", szDataPath);
					}
                    
					printf(",saved!");
				}
				else
				{
					printf(",not decrypted.");
					
				}
			}

			//else if (strncmp(name, "ipl:", 4) == 0)
			else if (strncmp(name, "ipl:/nandipl_01g", 16) == 0 || strncmp(name, "ipl:/nandipl_02g", 16) == 0)
			{
				sprintf(szDataPath, "ms0:/F0/PSARDUMPER/part1_%s", szFileBase);

				int cb1 = pspDecryptIPL1(g_dataOut2, g_dataOut, cbExpanded);

				if (cb1 > 0 && (WriteFile(szDataPath, g_dataOut, cb1) == cb1))
				{
					u32 startAddr = 0;
					int cb2 = pspLinearizeIPL2(g_dataOut, g_dataOut2, cb1, &startAddr);
					u32 offs = 0x04100000 - startAddr;
					printf("%x\n",offs);
					sprintf(szDataPath, "ms0:/F0/PSARDUMPER/part2_%s", szFileBase);
					
					WriteFile(szDataPath, g_dataOut2, cb2);
#if 0
					int cb3 = pspDecryptIPL3(g_dataOut2+offs, g_dataOut, cb2-offs);
					sprintf(szDataPath, "ms0:/F0/PSARDUMPER/part3_%s", szFileBase);
					WriteFile(szDataPath, g_dataOut, cb3);
#endif
				}
			}
		}
		else if (cbExpanded == 0)
		{
			printf("empty");
		}
		printf("\n");
	}
}
