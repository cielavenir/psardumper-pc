#define argc(a) (sizeof(a)/sizeof(a[0])/2)
int Expand(char *pbp, int argc, char **argv, int isPBP);
void ExtractReboot(char *loadexec, char *reboot, char *rebootname);

int endswith(const char *s, const char *needle){
	if(strlen(s)<strlen(needle))return 0;
	return !strcasecmp(s+strlen(s)-strlen(needle),needle);
}

int main(int _, char **argv){
#if defined(POPSDECO)
	{	char *p401[]={
			"ms0:/F0/kd/impose.prx","ms0:/seplugins/popsloader/modules/impose.prx",
			"ms0:/F0/kd/resource/impose.rsc","ms0:/seplugins/popsloader/modules/impose.rsc",
			"ms0:/F0/kd/popsman.prx","ms0:/seplugins/popsloader/modules/401/popsman.prx",
			"ms0:/F0/kd/pops.prx","ms0:/seplugins/popsloader/modules/401/pops.prx",
			"ms0:/F0/vsh/module/common_util.prx","ms0:/seplugins/popsloader/modules/401/common_util.prx",
			"ms0:/F0/vsh/module/pafmini.prx","ms0:/seplugins/popsloader/modules/401/pafmini.prx",
			"ms0:/F0/vsh/module/libpspvmc.prx","ms0:/seplugins/popsloader/modules/401/libpspvmc.prx",
		}; Expand("401.PBP",argc(p401),p401,1);}
	{	char *p302[]={
			"ms0:/F0/kd/popsman.prx","ms0:/seplugins/popsloader/modules/302/popsman.prx",
			"ms0:/F0/kd/pops.prx","ms0:/seplugins/popsloader/modules/302/pops.prx",
			"ms0:/F0/kd/meaudio.prx","ms0:/seplugins/popsloader/modules/302/meaudio.prx",
			"ms0:/F0/vsh/module/common_util.prx","ms0:/seplugins/popsloader/modules/302/common_util.prx",
			"ms0:/F0/vsh/module/pafmini.prx","ms0:/seplugins/popsloader/modules/302/pafmini.prx",
		}; Expand("302.PBP",argc(p302),p302,1);}
	{	char *p303[]={
			"ms0:/F0/kd/popsman.prx","ms0:/seplugins/popsloader/modules/303/popsman.prx",
			"ms0:/F0/kd/pops.prx","ms0:/seplugins/popsloader/modules/303/pops.prx",
			"ms0:/F0/kd/meaudio.prx","ms0:/seplugins/popsloader/modules/303/meaudio.prx",
			"ms0:/F0/vsh/module/common_util.prx","ms0:/seplugins/popsloader/modules/303/common_util.prx",
			"ms0:/F0/vsh/module/pafmini.prx","ms0:/seplugins/popsloader/modules/303/pafmini.prx",
		}; Expand("303.PBP",argc(p303),p303,1);}
	{	char *p310[]={
			"ms0:/F0/kd/popsman.prx","ms0:/seplugins/popsloader/modules/310/popsman.prx",
			"ms0:/F0/kd/pops.prx","ms0:/seplugins/popsloader/modules/310/pops.prx",
			"ms0:/F0/vsh/module/common_util.prx","ms0:/seplugins/popsloader/modules/310/common_util.prx",
			"ms0:/F0/vsh/module/pafmini.prx","ms0:/seplugins/popsloader/modules/310/pafmini.prx",
		}; Expand("310.PBP",argc(p310),p310,1);}
	{	char *p311[]={
			"ms0:/F0/kd/popsman.prx","ms0:/seplugins/popsloader/modules/311/popsman.prx",
			"ms0:/F0/kd/pops.prx","ms0:/seplugins/popsloader/modules/311/pops.prx",
			"ms0:/F0/vsh/module/common_util.prx","ms0:/seplugins/popsloader/modules/311/common_util.prx",
			"ms0:/F0/vsh/module/pafmini.prx","ms0:/seplugins/popsloader/modules/311/pafmini.prx",
		}; Expand("311.PBP",argc(p311),p311,1);}
	{	char *p330[]={
			"ms0:/F0/kd/popsman.prx","ms0:/seplugins/popsloader/modules/330/popsman.prx",
			"ms0:/F0/kd/pops.prx","ms0:/seplugins/popsloader/modules/330/pops.prx",
			"ms0:/F0/vsh/module/common_util.prx","ms0:/seplugins/popsloader/modules/330/common_util.prx",
			"ms0:/F0/vsh/module/pafmini.prx","ms0:/seplugins/popsloader/modules/330/pafmini.prx",
		}; Expand("330.PBP",argc(p330),p330,1);}
	{	char *p340[]={
			"ms0:/F0/kd/popsman.prx","ms0:/seplugins/popsloader/modules/340/popsman.prx",
			"ms0:/F0/kd/pops.prx","ms0:/seplugins/popsloader/modules/340/pops.prx",
			"ms0:/F0/vsh/module/common_util.prx","ms0:/seplugins/popsloader/modules/340/common_util.prx",
			"ms0:/F0/vsh/module/pafmini.prx","ms0:/seplugins/popsloader/modules/340/pafmini.prx",
			"ms0:/F0/vsh/module/libpspvmc.prx","ms0:/seplugins/popsloader/modules/340/libpspvmc.prx",
		}; Expand("340.PBP",argc(p340),p340,1);}
	{	char *p350[]={
			"ms0:/F0/kd/popsman.prx","ms0:/seplugins/popsloader/modules/350/popsman.prx",
			"ms0:/F0/kd/pops.prx","ms0:/seplugins/popsloader/modules/350/pops.prx",
			"ms0:/F0/vsh/module/common_util.prx","ms0:/seplugins/popsloader/modules/350/common_util.prx",
			"ms0:/F0/vsh/module/pafmini.prx","ms0:/seplugins/popsloader/modules/350/pafmini.prx",
			"ms0:/F0/vsh/module/libpspvmc.prx","ms0:/seplugins/popsloader/modules/350/libpspvmc.prx",
		}; Expand("350.PBP",argc(p350),p350,1);}
	{	char *p351[]={
			"ms0:/F0/kd/popsman.prx","ms0:/seplugins/popsloader/modules/351/popsman.prx",
			"ms0:/F0/kd/pops.prx","ms0:/seplugins/popsloader/modules/351/pops.prx",
			"ms0:/F0/vsh/module/common_util.prx","ms0:/seplugins/popsloader/modules/351/common_util.prx",
			"ms0:/F0/vsh/module/pafmini.prx","ms0:/seplugins/popsloader/modules/351/pafmini.prx",
			"ms0:/F0/vsh/module/libpspvmc.prx","ms0:/seplugins/popsloader/modules/351/libpspvmc.prx",
		}; Expand("351.PBP",argc(p351),p351,1);}
	{	char *p352[]={
			"ms0:/F0/kd/popsman.prx","ms0:/seplugins/popsloader/modules/352/popsman.prx",
			"ms0:/F0/kd/pops.prx","ms0:/seplugins/popsloader/modules/352/pops.prx",
			"ms0:/F0/vsh/module/common_util.prx","ms0:/seplugins/popsloader/modules/352/common_util.prx",
			"ms0:/F0/vsh/module/pafmini.prx","ms0:/seplugins/popsloader/modules/352/pafmini.prx",
			"ms0:/F0/vsh/module/libpspvmc.prx","ms0:/seplugins/popsloader/modules/352/libpspvmc.prx",
		}; Expand("352.PBP",argc(p352),p352,1);}
	{	char *p371[]={
			"ms0:/F0/kd/popsman.prx","ms0:/seplugins/popsloader/modules/371/popsman.prx",
			"ms0:/F0/kd/pops.prx","ms0:/seplugins/popsloader/modules/371/pops.prx",
			"ms0:/F0/vsh/module/common_util.prx","ms0:/seplugins/popsloader/modules/371/common_util.prx",
			"ms0:/F0/vsh/module/pafmini.prx","ms0:/seplugins/popsloader/modules/371/pafmini.prx",
			"ms0:/F0/vsh/module/libpspvmc.prx","ms0:/seplugins/popsloader/modules/371/libpspvmc.prx",
		}; Expand("371.PBP",argc(p371),p371,1);}
	{	char *p372[]={
			"ms0:/F0/kd/popsman.prx","ms0:/seplugins/popsloader/modules/372/popsman.prx",
			"ms0:/F0/kd/pops.prx","ms0:/seplugins/popsloader/modules/372/pops.prx",
			"ms0:/F0/vsh/module/common_util.prx","ms0:/seplugins/popsloader/modules/372/common_util.prx",
			"ms0:/F0/vsh/module/pafmini.prx","ms0:/seplugins/popsloader/modules/372/pafmini.prx",
			"ms0:/F0/vsh/module/libpspvmc.prx","ms0:/seplugins/popsloader/modules/372/libpspvmc.prx",
		}; Expand("372.PBP",argc(p372),p372,1);}
	{	char *p380[]={
			"ms0:/F0/kd/popsman.prx","ms0:/seplugins/popsloader/modules/380/popsman.prx",
			"ms0:/F0/kd/pops.prx","ms0:/seplugins/popsloader/modules/380/pops.prx",
			"ms0:/F0/vsh/module/common_util.prx","ms0:/seplugins/popsloader/modules/380/common_util.prx",
			"ms0:/F0/vsh/module/pafmini.prx","ms0:/seplugins/popsloader/modules/380/pafmini.prx",
			"ms0:/F0/vsh/module/libpspvmc.prx","ms0:/seplugins/popsloader/modules/380/libpspvmc.prx",
		}; Expand("380.PBP",argc(p380),p380,1);}
	{	char *p390[]={
			"ms0:/F0/kd/popsman.prx","ms0:/seplugins/popsloader/modules/390/popsman.prx",
			"ms0:/F0/kd/pops.prx","ms0:/seplugins/popsloader/modules/390/pops.prx",
			"ms0:/F0/vsh/module/common_util.prx","ms0:/seplugins/popsloader/modules/390/common_util.prx",
			"ms0:/F0/vsh/module/pafmini.prx","ms0:/seplugins/popsloader/modules/390/pafmini.prx",
			"ms0:/F0/vsh/module/libpspvmc.prx","ms0:/seplugins/popsloader/modules/390/libpspvmc.prx",
		}; Expand("390.PBP",argc(p390),p390,1);}
	{	char *p393[]={
			"ms0:/F0/kd/popsman.prx","ms0:/seplugins/popsloader/modules/393/popsman.prx",
			"ms0:/F0/kd/pops.prx","ms0:/seplugins/popsloader/modules/393/pops.prx",
			"ms0:/F0/vsh/module/common_util.prx","ms0:/seplugins/popsloader/modules/393/common_util.prx",
			"ms0:/F0/vsh/module/pafmini.prx","ms0:/seplugins/popsloader/modules/393/pafmini.prx",
			"ms0:/F0/vsh/module/libpspvmc.prx","ms0:/seplugins/popsloader/modules/393/libpspvmc.prx",
		}; Expand("393.PBP",argc(p393),p393,1);}
	{	char *p396[]={
			"ms0:/F0/kd/popsman.prx","ms0:/seplugins/popsloader/modules/396/popsman.prx",
			"ms0:/F0/kd/pops.prx","ms0:/seplugins/popsloader/modules/396/pops.prx",
			"ms0:/F0/vsh/module/common_util.prx","ms0:/seplugins/popsloader/modules/396/common_util.prx",
			"ms0:/F0/vsh/module/pafmini.prx","ms0:/seplugins/popsloader/modules/396/pafmini.prx",
			"ms0:/F0/vsh/module/libpspvmc.prx","ms0:/seplugins/popsloader/modules/396/libpspvmc.prx",
		}; Expand("396.PBP",argc(p396),p396,1);}
	{	char *p500[]={
			"ms0:/F0/kd/popsman.prx","ms0:/seplugins/popsloader/modules/500/popsman.prx",
			"ms0:/F0/kd/pops.prx","ms0:/seplugins/popsloader/modules/500/pops.prx",
			"ms0:/F0/vsh/module/common_util.prx","ms0:/seplugins/popsloader/modules/500/common_util.prx",
			"ms0:/F0/vsh/module/pafmini.prx","ms0:/seplugins/popsloader/modules/500/pafmini.prx",
			"ms0:/F0/vsh/module/libpspvmc.prx","ms0:/seplugins/popsloader/modules/500/libpspvmc.prx",
		}; Expand("500.PBP",argc(p500),p500,1);}
	{	char *p501[]={
			"ms0:/F0/kd/popsman.prx","ms0:/seplugins/popsloader/modules/501/popsman.prx",
			"ms0:/F0/kd/pops.prx","ms0:/seplugins/popsloader/modules/501/pops.prx",
			"ms0:/F0/vsh/module/common_util.prx","ms0:/seplugins/popsloader/modules/501/common_util.prx",
			"ms0:/F0/vsh/module/pafmini.prx","ms0:/seplugins/popsloader/modules/501/pafmini.prx",
			"ms0:/F0/vsh/module/libpspvmc.prx","ms0:/seplugins/popsloader/modules/501/libpspvmc.prx",
		}; Expand("501.PBP",argc(p501),p501,1);}
	{	char *p503[]={
			"ms0:/F0/kd/popsman.prx","ms0:/seplugins/popsloader/modules/503/popsman.prx",
			"ms0:/F0/kd/pops.prx","ms0:/seplugins/popsloader/modules/503/pops.prx",
			"ms0:/F0/vsh/module/common_util.prx","ms0:/seplugins/popsloader/modules/503/common_util.prx",
			"ms0:/F0/vsh/module/pafmini.prx","ms0:/seplugins/popsloader/modules/503/pafmini.prx",
			"ms0:/F0/vsh/module/libpspvmc.prx","ms0:/seplugins/popsloader/modules/503/libpspvmc.prx",
		}; Expand("503.PBP",argc(p503),p503,1);}
	{	char *p550[]={
			"ms0:/F0/kd/popsman.prx","ms0:/seplugins/popsloader/modules/550/popsman.prx",
			"ms0:/F0/kd/pops.prx","ms0:/seplugins/popsloader/modules/550/pops.prx",
			"ms0:/F0/vsh/module/common_util.prx","ms0:/seplugins/popsloader/modules/550/common_util.prx",
			"ms0:/F0/vsh/module/pafmini.prx","ms0:/seplugins/popsloader/modules/550/pafmini.prx",
			"ms0:/F0/vsh/module/libpspvmc.prx","ms0:/seplugins/popsloader/modules/550/libpspvmc.prx",
		}; Expand("550.PBP",argc(p550),p550,1);}
	{	char *p551[]={
			"ms0:/F0/kd/popsman.prx","ms0:/seplugins/popsloader/modules/551/popsman.prx",
			"ms0:/F0/kd/pops.prx","ms0:/seplugins/popsloader/modules/551/pops.prx",
			"ms0:/F0/vsh/module/common_util.prx","ms0:/seplugins/popsloader/modules/551/common_util.prx",
			"ms0:/F0/vsh/module/pafmini.prx","ms0:/seplugins/popsloader/modules/551/pafmini.prx",
			"ms0:/F0/vsh/module/libpspvmc.prx","ms0:/seplugins/popsloader/modules/551/libpspvmc.prx",
		}; Expand("551.PBP",argc(p551),p551,1);}
	{	char *p600[]={
			"ms0:/F0/kd/popsman.prx","ms0:/seplugins/popsloader/modules/600/popsman.prx",
			"ms0:/F0/kd/pops.prx","ms0:/seplugins/popsloader/modules/600/pops.prx",
			"ms0:/F0/kd/pops_01g.prx","ms0:/seplugins/popsloader/modules/600/pops_01g.prx",
			"ms0:/F0/kd/pops_02g.prx","ms0:/seplugins/popsloader/modules/600/pops_02g.prx",
			"ms0:/F0/kd/pops_03g.prx","ms0:/seplugins/popsloader/modules/600/pops_03g.prx",
			"ms0:/F0/kd/pops_04g.prx","ms0:/seplugins/popsloader/modules/600/pops_04g.prx",
			"ms0:/F0/kd/pops_05g.prx","ms0:/seplugins/popsloader/modules/600/pops_05g.prx",
			"ms0:/F0/kd/pops_06g.prx","ms0:/seplugins/popsloader/modules/600/pops_06g.prx",
			"ms0:/F0/kd/pops_07g.prx","ms0:/seplugins/popsloader/modules/600/pops_07g.prx",
			"ms0:/F0/kd/pops_08g.prx","ms0:/seplugins/popsloader/modules/600/pops_08g.prx",
			"ms0:/F0/kd/pops_09g.prx","ms0:/seplugins/popsloader/modules/600/pops_09g.prx",
			"ms0:/F0/vsh/module/common_util.prx","ms0:/seplugins/popsloader/modules/600/common_util.prx",
			"ms0:/F0/vsh/module/pafmini.prx","ms0:/seplugins/popsloader/modules/600/pafmini.prx",
			"ms0:/F0/vsh/module/libpspvmc.prx","ms0:/seplugins/popsloader/modules/600/libpspvmc.prx",
		}; Expand("600.PBP",argc(p600),p600,1);}
	{	char *p610[]={
			"ms0:/F0/kd/popsman.prx","ms0:/seplugins/popsloader/modules/610/popsman.prx",
			"ms0:/F0/kd/pops.prx","ms0:/seplugins/popsloader/modules/610/pops.prx",
			"ms0:/F0/kd/pops_01g.prx","ms0:/seplugins/popsloader/modules/610/pops_01g.prx",
			"ms0:/F0/kd/pops_02g.prx","ms0:/seplugins/popsloader/modules/610/pops_02g.prx",
			"ms0:/F0/kd/pops_03g.prx","ms0:/seplugins/popsloader/modules/610/pops_03g.prx",
			"ms0:/F0/kd/pops_04g.prx","ms0:/seplugins/popsloader/modules/610/pops_04g.prx",
			"ms0:/F0/kd/pops_05g.prx","ms0:/seplugins/popsloader/modules/610/pops_05g.prx",
			"ms0:/F0/kd/pops_06g.prx","ms0:/seplugins/popsloader/modules/610/pops_06g.prx",
			"ms0:/F0/kd/pops_07g.prx","ms0:/seplugins/popsloader/modules/610/pops_07g.prx",
			"ms0:/F0/kd/pops_08g.prx","ms0:/seplugins/popsloader/modules/610/pops_08g.prx",
			"ms0:/F0/kd/pops_09g.prx","ms0:/seplugins/popsloader/modules/610/pops_09g.prx",
			"ms0:/F0/vsh/module/common_util.prx","ms0:/seplugins/popsloader/modules/610/common_util.prx",
			"ms0:/F0/vsh/module/pafmini.prx","ms0:/seplugins/popsloader/modules/610/pafmini.prx",
			"ms0:/F0/vsh/module/libpspvmc.prx","ms0:/seplugins/popsloader/modules/610/libpspvmc.prx",
		}; Expand("610.PBP",argc(p610),p610,1);}
	{	char *p610go[]={
			"ms0:/F0/kd/popsman.prx","ms0:/seplugins/popsloader/modules/610/popsman.prx",
			"ms0:/F0/kd/pops.prx","ms0:/seplugins/popsloader/modules/610/pops.prx",
			"ms0:/F0/kd/pops_01g.prx","ms0:/seplugins/popsloader/modules/610/pops_01g.prx",
			"ms0:/F0/kd/pops_02g.prx","ms0:/seplugins/popsloader/modules/610/pops_02g.prx",
			"ms0:/F0/kd/pops_03g.prx","ms0:/seplugins/popsloader/modules/610/pops_03g.prx",
			"ms0:/F0/kd/pops_04g.prx","ms0:/seplugins/popsloader/modules/610/pops_04g.prx",
			"ms0:/F0/kd/pops_05g.prx","ms0:/seplugins/popsloader/modules/610/pops_05g.prx",
			"ms0:/F0/kd/pops_06g.prx","ms0:/seplugins/popsloader/modules/610/pops_06g.prx",
			"ms0:/F0/kd/pops_07g.prx","ms0:/seplugins/popsloader/modules/610/pops_07g.prx",
			"ms0:/F0/kd/pops_08g.prx","ms0:/seplugins/popsloader/modules/610/pops_08g.prx",
			"ms0:/F0/kd/pops_09g.prx","ms0:/seplugins/popsloader/modules/610/pops_09g.prx",
			"ms0:/F0/vsh/module/common_util.prx","ms0:/seplugins/popsloader/modules/610/common_util.prx",
			"ms0:/F0/vsh/module/pafmini.prx","ms0:/seplugins/popsloader/modules/610/pafmini.prx",
			"ms0:/F0/vsh/module/libpspvmc.prx","ms0:/seplugins/popsloader/modules/610/libpspvmc.prx",
		}; Expand("610-GO.PBP",argc(p610go),p610go,1);}
	{	char *p620[]={
			"ms0:/F0/kd/popsman.prx","ms0:/seplugins/popsloader/modules/620/popsman.prx",
			"ms0:/F0/kd/pops.prx","ms0:/seplugins/popsloader/modules/620/pops.prx",
			"ms0:/F0/kd/pops_01g.prx","ms0:/seplugins/popsloader/modules/620/pops_01g.prx",
			"ms0:/F0/kd/pops_02g.prx","ms0:/seplugins/popsloader/modules/620/pops_02g.prx",
			"ms0:/F0/kd/pops_03g.prx","ms0:/seplugins/popsloader/modules/620/pops_03g.prx",
			"ms0:/F0/kd/pops_04g.prx","ms0:/seplugins/popsloader/modules/620/pops_04g.prx",
			"ms0:/F0/kd/pops_05g.prx","ms0:/seplugins/popsloader/modules/620/pops_05g.prx",
			"ms0:/F0/kd/pops_06g.prx","ms0:/seplugins/popsloader/modules/620/pops_06g.prx",
			"ms0:/F0/kd/pops_07g.prx","ms0:/seplugins/popsloader/modules/620/pops_07g.prx",
			"ms0:/F0/kd/pops_08g.prx","ms0:/seplugins/popsloader/modules/620/pops_08g.prx",
			"ms0:/F0/kd/pops_09g.prx","ms0:/seplugins/popsloader/modules/620/pops_09g.prx",
			"ms0:/F0/vsh/module/common_util.prx","ms0:/seplugins/popsloader/modules/620/common_util.prx",
			"ms0:/F0/vsh/module/pafmini.prx","ms0:/seplugins/popsloader/modules/620/pafmini.prx",
			"ms0:/F0/vsh/module/libpspvmc.prx","ms0:/seplugins/popsloader/modules/620/libpspvmc.prx",
		}; Expand("620.PBP",argc(p620),p620,1);}
	{	char *p620go[]={
			"ms0:/F0/kd/popsman.prx","ms0:/seplugins/popsloader/modules/620/popsman.prx",
			"ms0:/F0/kd/pops.prx","ms0:/seplugins/popsloader/modules/620/pops.prx",
			"ms0:/F0/kd/pops_01g.prx","ms0:/seplugins/popsloader/modules/620/pops_01g.prx",
			"ms0:/F0/kd/pops_02g.prx","ms0:/seplugins/popsloader/modules/620/pops_02g.prx",
			"ms0:/F0/kd/pops_03g.prx","ms0:/seplugins/popsloader/modules/620/pops_03g.prx",
			"ms0:/F0/kd/pops_04g.prx","ms0:/seplugins/popsloader/modules/620/pops_04g.prx",
			"ms0:/F0/kd/pops_05g.prx","ms0:/seplugins/popsloader/modules/620/pops_05g.prx",
			"ms0:/F0/kd/pops_06g.prx","ms0:/seplugins/popsloader/modules/620/pops_06g.prx",
			"ms0:/F0/kd/pops_07g.prx","ms0:/seplugins/popsloader/modules/620/pops_07g.prx",
			"ms0:/F0/kd/pops_08g.prx","ms0:/seplugins/popsloader/modules/620/pops_08g.prx",
			"ms0:/F0/kd/pops_09g.prx","ms0:/seplugins/popsloader/modules/620/pops_09g.prx",
			"ms0:/F0/vsh/module/common_util.prx","ms0:/seplugins/popsloader/modules/620/common_util.prx",
			"ms0:/F0/vsh/module/pafmini.prx","ms0:/seplugins/popsloader/modules/620/pafmini.prx",
			"ms0:/F0/vsh/module/libpspvmc.prx","ms0:/seplugins/popsloader/modules/620/libpspvmc.prx",
		}; Expand("620-GO.PBP",argc(p620go),p620go,1);}
	{	char *p635[]={
			"ms0:/F0/kd/popsman.prx","ms0:/seplugins/popsloader/modules/635/popsman.prx",
			"ms0:/F0/kd/pops.prx","ms0:/seplugins/popsloader/modules/635/pops.prx",
			"ms0:/F0/kd/pops_01g.prx","ms0:/seplugins/popsloader/modules/635/pops_01g.prx",
			"ms0:/F0/kd/pops_02g.prx","ms0:/seplugins/popsloader/modules/635/pops_02g.prx",
			"ms0:/F0/kd/pops_03g.prx","ms0:/seplugins/popsloader/modules/635/pops_03g.prx",
			"ms0:/F0/kd/pops_04g.prx","ms0:/seplugins/popsloader/modules/635/pops_04g.prx",
			"ms0:/F0/kd/pops_05g.prx","ms0:/seplugins/popsloader/modules/635/pops_05g.prx",
			"ms0:/F0/kd/pops_06g.prx","ms0:/seplugins/popsloader/modules/635/pops_06g.prx",
			"ms0:/F0/kd/pops_07g.prx","ms0:/seplugins/popsloader/modules/635/pops_07g.prx",
			"ms0:/F0/kd/pops_08g.prx","ms0:/seplugins/popsloader/modules/635/pops_08g.prx",
			"ms0:/F0/kd/pops_09g.prx","ms0:/seplugins/popsloader/modules/635/pops_09g.prx",
			"ms0:/F0/vsh/module/common_util.prx","ms0:/seplugins/popsloader/modules/635/common_util.prx",
			"ms0:/F0/vsh/module/pafmini.prx","ms0:/seplugins/popsloader/modules/635/pafmini.prx",
			"ms0:/F0/vsh/module/libpspvmc.prx","ms0:/seplugins/popsloader/modules/635/libpspvmc.prx",
		}; Expand("635.PBP",argc(p635),p635,1);}
	{	char *p635go[]={
			"ms0:/F0/kd/popsman.prx","ms0:/seplugins/popsloader/modules/635/popsman.prx",
			"ms0:/F0/kd/pops.prx","ms0:/seplugins/popsloader/modules/635/pops.prx",
			"ms0:/F0/kd/pops_01g.prx","ms0:/seplugins/popsloader/modules/635/pops_01g.prx",
			"ms0:/F0/kd/pops_02g.prx","ms0:/seplugins/popsloader/modules/635/pops_02g.prx",
			"ms0:/F0/kd/pops_03g.prx","ms0:/seplugins/popsloader/modules/635/pops_03g.prx",
			"ms0:/F0/kd/pops_04g.prx","ms0:/seplugins/popsloader/modules/635/pops_04g.prx",
			"ms0:/F0/kd/pops_05g.prx","ms0:/seplugins/popsloader/modules/635/pops_05g.prx",
			"ms0:/F0/kd/pops_06g.prx","ms0:/seplugins/popsloader/modules/635/pops_06g.prx",
			"ms0:/F0/kd/pops_07g.prx","ms0:/seplugins/popsloader/modules/635/pops_07g.prx",
			"ms0:/F0/kd/pops_08g.prx","ms0:/seplugins/popsloader/modules/635/pops_08g.prx",
			"ms0:/F0/kd/pops_09g.prx","ms0:/seplugins/popsloader/modules/635/pops_09g.prx",
			"ms0:/F0/vsh/module/common_util.prx","ms0:/seplugins/popsloader/modules/635/common_util.prx",
			"ms0:/F0/vsh/module/pafmini.prx","ms0:/seplugins/popsloader/modules/635/pafmini.prx",
			"ms0:/F0/vsh/module/libpspvmc.prx","ms0:/seplugins/popsloader/modules/635/libpspvmc.prx",
		}; Expand("635-GO.PBP",argc(p635go),p635go,1);}
	{	char *p639[]={
			"ms0:/F0/kd/popsman.prx","ms0:/seplugins/popsloader/modules/639/popsman.prx",
			"ms0:/F0/kd/pops.prx","ms0:/seplugins/popsloader/modules/639/pops.prx",
			"ms0:/F0/kd/pops_01g.prx","ms0:/seplugins/popsloader/modules/639/pops_01g.prx",
			"ms0:/F0/kd/pops_02g.prx","ms0:/seplugins/popsloader/modules/639/pops_02g.prx",
			"ms0:/F0/kd/pops_03g.prx","ms0:/seplugins/popsloader/modules/639/pops_03g.prx",
			"ms0:/F0/kd/pops_04g.prx","ms0:/seplugins/popsloader/modules/639/pops_04g.prx",
			"ms0:/F0/kd/pops_05g.prx","ms0:/seplugins/popsloader/modules/639/pops_05g.prx",
			"ms0:/F0/kd/pops_06g.prx","ms0:/seplugins/popsloader/modules/639/pops_06g.prx",
			"ms0:/F0/kd/pops_07g.prx","ms0:/seplugins/popsloader/modules/639/pops_07g.prx",
			"ms0:/F0/kd/pops_08g.prx","ms0:/seplugins/popsloader/modules/639/pops_08g.prx",
			"ms0:/F0/kd/pops_09g.prx","ms0:/seplugins/popsloader/modules/639/pops_09g.prx",
			"ms0:/F0/vsh/module/common_util.prx","ms0:/seplugins/popsloader/modules/639/common_util.prx",
			"ms0:/F0/vsh/module/pafmini.prx","ms0:/seplugins/popsloader/modules/639/pafmini.prx",
			"ms0:/F0/vsh/module/libpspvmc.prx","ms0:/seplugins/popsloader/modules/639/libpspvmc.prx",
		}; Expand("639.PBP",argc(p639),p639,1);}
	{	char *p639go[]={
			"ms0:/F0/kd/popsman.prx","ms0:/seplugins/popsloader/modules/639/popsman.prx",
			"ms0:/F0/kd/pops.prx","ms0:/seplugins/popsloader/modules/639/pops.prx",
			"ms0:/F0/kd/pops_01g.prx","ms0:/seplugins/popsloader/modules/639/pops_01g.prx",
			"ms0:/F0/kd/pops_02g.prx","ms0:/seplugins/popsloader/modules/639/pops_02g.prx",
			"ms0:/F0/kd/pops_03g.prx","ms0:/seplugins/popsloader/modules/639/pops_03g.prx",
			"ms0:/F0/kd/pops_04g.prx","ms0:/seplugins/popsloader/modules/639/pops_04g.prx",
			"ms0:/F0/kd/pops_05g.prx","ms0:/seplugins/popsloader/modules/639/pops_05g.prx",
			"ms0:/F0/kd/pops_06g.prx","ms0:/seplugins/popsloader/modules/639/pops_06g.prx",
			"ms0:/F0/kd/pops_07g.prx","ms0:/seplugins/popsloader/modules/639/pops_07g.prx",
			"ms0:/F0/kd/pops_08g.prx","ms0:/seplugins/popsloader/modules/639/pops_08g.prx",
			"ms0:/F0/kd/pops_09g.prx","ms0:/seplugins/popsloader/modules/639/pops_09g.prx",
			"ms0:/F0/vsh/module/common_util.prx","ms0:/seplugins/popsloader/modules/639/common_util.prx",
			"ms0:/F0/vsh/module/pafmini.prx","ms0:/seplugins/popsloader/modules/639/pafmini.prx",
			"ms0:/F0/vsh/module/libpspvmc.prx","ms0:/seplugins/popsloader/modules/639/libpspvmc.prx",
		}; Expand("639-GO.PBP",argc(p639go),p639go,1);}
	{	char *p660[]={
			"ms0:/F0/kd/popsman.prx","ms0:/seplugins/popsloader/modules/660/popsman.prx",
			"ms0:/F0/kd/pops.prx","ms0:/seplugins/popsloader/modules/660/pops.prx",
			"ms0:/F0/kd/pops_01g.prx","ms0:/seplugins/popsloader/modules/660/pops_01g.prx",
			"ms0:/F0/kd/pops_02g.prx","ms0:/seplugins/popsloader/modules/660/pops_02g.prx",
			"ms0:/F0/kd/pops_03g.prx","ms0:/seplugins/popsloader/modules/660/pops_03g.prx",
			"ms0:/F0/kd/pops_04g.prx","ms0:/seplugins/popsloader/modules/660/pops_04g.prx",
			"ms0:/F0/kd/pops_05g.prx","ms0:/seplugins/popsloader/modules/660/pops_05g.prx",
			"ms0:/F0/kd/pops_06g.prx","ms0:/seplugins/popsloader/modules/660/pops_06g.prx",
			"ms0:/F0/kd/pops_07g.prx","ms0:/seplugins/popsloader/modules/660/pops_07g.prx",
			"ms0:/F0/kd/pops_08g.prx","ms0:/seplugins/popsloader/modules/660/pops_08g.prx",
			"ms0:/F0/kd/pops_09g.prx","ms0:/seplugins/popsloader/modules/660/pops_09g.prx",
			"ms0:/F0/kd/pops_10g.prx","ms0:/seplugins/popsloader/modules/660/pops_10g.prx",
			"ms0:/F0/kd/pops_11g.prx","ms0:/seplugins/popsloader/modules/660/pops_11g.prx",
			"ms0:/F0/kd/pops_12g.prx","ms0:/seplugins/popsloader/modules/660/pops_12g.prx",
			"ms0:/F0/vsh/module/common_util.prx","ms0:/seplugins/popsloader/modules/660/common_util.prx",
			"ms0:/F0/vsh/module/pafmini.prx","ms0:/seplugins/popsloader/modules/660/pafmini.prx",
			"ms0:/F0/vsh/module/libpspvmc.prx","ms0:/seplugins/popsloader/modules/660/libpspvmc.prx",
		}; Expand("660.PBP",argc(p660),p660,1);}
	{	char *p660go[]={
			"ms0:/F0/kd/popsman.prx","ms0:/seplugins/popsloader/modules/660/popsman.prx",
			"ms0:/F0/kd/pops.prx","ms0:/seplugins/popsloader/modules/660/pops.prx",
			"ms0:/F0/kd/pops_01g.prx","ms0:/seplugins/popsloader/modules/660/pops_01g.prx",
			"ms0:/F0/kd/pops_02g.prx","ms0:/seplugins/popsloader/modules/660/pops_02g.prx",
			"ms0:/F0/kd/pops_03g.prx","ms0:/seplugins/popsloader/modules/660/pops_03g.prx",
			"ms0:/F0/kd/pops_04g.prx","ms0:/seplugins/popsloader/modules/660/pops_04g.prx",
			"ms0:/F0/kd/pops_05g.prx","ms0:/seplugins/popsloader/modules/660/pops_05g.prx",
			"ms0:/F0/kd/pops_06g.prx","ms0:/seplugins/popsloader/modules/660/pops_06g.prx",
			"ms0:/F0/kd/pops_07g.prx","ms0:/seplugins/popsloader/modules/660/pops_07g.prx",
			"ms0:/F0/kd/pops_08g.prx","ms0:/seplugins/popsloader/modules/660/pops_08g.prx",
			"ms0:/F0/kd/pops_09g.prx","ms0:/seplugins/popsloader/modules/660/pops_09g.prx",
			"ms0:/F0/kd/pops_10g.prx","ms0:/seplugins/popsloader/modules/660/pops_10g.prx",
			"ms0:/F0/kd/pops_11g.prx","ms0:/seplugins/popsloader/modules/660/pops_11g.prx",
			"ms0:/F0/kd/pops_12g.prx","ms0:/seplugins/popsloader/modules/660/pops_12g.prx",
			"ms0:/F0/vsh/module/common_util.prx","ms0:/seplugins/popsloader/modules/660/common_util.prx",
			"ms0:/F0/vsh/module/pafmini.prx","ms0:/seplugins/popsloader/modules/660/pafmini.prx",
			"ms0:/F0/vsh/module/libpspvmc.prx","ms0:/seplugins/popsloader/modules/660/libpspvmc.prx",
		}; Expand("660-GO.PBP",argc(p660go),p660go,1);}
#elif defined(DC8EX)
		//const char *music_pbpname="550.PBP";
		const char *music_pbpname="551.PBP";
		{	char *pMUSIC[]={
				"ms0:/F0/vsh/module/content_browser.prx","ms0:/TM/DC8/vsh/module/content_browser.prx",
				"ms0:/F0/vsh/module/mp4msv.prx","ms0:/TM/DC8/vsh/module/mp4msv.prx",
				"ms0:/F0/vsh/module/msvideo_main_plugin.prx","ms0:/TM/DC8/vsh/module/msvideo_main_plugin.prx",
				"ms0:/F0/vsh/module/msvideo_plugin.prx","ms0:/TM/DC8/vsh/module/msvideo_plugin.prx",
				"ms0:/F0/vsh/module/music_browser.prx","ms0:/TM/DC8/vsh/module/music_browser.prx",
				"ms0:/F0/vsh/module/music_main_plugin.prx","ms0:/TM/DC8/vsh/module/music_main_plugin.prx",
				"ms0:/F0/vsh/module/music_parser.prx","ms0:/TM/DC8/vsh/module/music_parser.prx",
				"ms0:/F0/vsh/module/music_player.prx","ms0:/TM/DC8/vsh/module/music_player.prx",
				"ms0:/F0/vsh/module/photo_browser.prx","ms0:/TM/DC8/vsh/module/photo_browser.prx",
				"ms0:/F0/vsh/module/photo_main_plugin.prx","ms0:/TM/DC8/vsh/module/photo_main_plugin.prx",
				"ms0:/F0/vsh/module/photo_player.prx","ms0:/TM/DC8/vsh/module/photo_player.prx",
				"ms0:/F0/vsh/module/video_main_plugin.prx","ms0:/TM/DC8/vsh/module/video_main_plugin.prx",
				"ms0:/F0/vsh/module/video_plugin.prx","ms0:/TM/DC8/vsh/module/video_plugin.prx",
				"ms0:/F0/vsh/module/visualizer_plugin.prx","ms0:/TM/DC8/vsh/module/visualizer_plugin.prx",
				"ms0:/F0/vsh/resource/content_browser_plugin.rco","ms0:/TM/DC8/vsh/resource/content_browser_plugin.rco",
				"ms0:/F0/vsh/resource/msvideo_main_plugin.rco","ms0:/TM/DC8/vsh/resource/msvideo_main_plugin.rco",
				"ms0:/F0/vsh/resource/music_browser_plugin.rco","ms0:/TM/DC8/vsh/resource/music_browser_plugin.rco",
				"ms0:/F0/vsh/resource/music_player_plugin.rco","ms0:/TM/DC8/vsh/resource/music_player_plugin.rco",
				"ms0:/F0/vsh/resource/photo_browser_plugin.rco","ms0:/TM/DC8/vsh/resource/photo_browser_plugin.rco",
				"ms0:/F0/vsh/resource/photo_player_plugin.rco","ms0:/TM/DC8/vsh/resource/photo_player_plugin.rco",
				"ms0:/F0/vsh/resource/video_main_plugin.rco","ms0:/TM/DC8/vsh/resource/video_main_plugin.rco",
				"ms0:/F0/vsh/resource/video_plugin_videotoolbar.rco","ms0:/TM/DC8/vsh/resource/video_plugin_videotoolbar.rco",
				"ms0:/F0/vsh/resource/visualizer_plugin.rco","ms0:/TM/DC8/vsh/resource/visualizer_plugin.rco",
			}; Expand(music_pbpname,argc(pMUSIC),pMUSIC,1);}
		//const char *prome_pbpname="631.PBP";
		const char *prome_pbpname="635.PBP";
		{	char *pPROME[]={
				"ms0:/F0/kd/audiocodec_260.prx","ms0:/TM/DC8/6xxModules/audiocodec_260.prx",
				"ms0:/F0/kd/avcodec.prx","ms0:/TM/DC8/6xxModules/avcodec.prx",
				"ms0:/F0/kd/g729.prx","ms0:/TM/DC8/6xxModules/g729.prx",
				"ms0:/F0/kd/libaac.prx","ms0:/TM/DC8/6xxModules/libaac.prx",
				"ms0:/F0/kd/libatrac3plus.prx","ms0:/TM/DC8/6xxModules/libatrac3plus.prx",
				"ms0:/F0/kd/libmp3.prx","ms0:/TM/DC8/6xxModules/libmp3.prx",
				"ms0:/F0/kd/libmp4.prx","ms0:/TM/DC8/6xxModules/libmp4.prx",
				"ms0:/F0/kd/me_wrapper.prx","ms0:/TM/DC8/6xxModules/me_wrapper.prx",
				"ms0:/F0/kd/mp4msv.prx","ms0:/TM/DC8/6xxModules/mp4msv.prx",
				"ms0:/F0/kd/mpeg.prx","ms0:/TM/DC8/6xxModules/mpeg.prx",
				"ms0:/F0/kd/mpegbase_260.prx","ms0:/TM/DC8/6xxModules/mpegbase_260.prx",
				"ms0:/F0/kd/sc_sascore.prx","ms0:/TM/DC8/6xxModules/sc_sascore.prx",
				"ms0:/F0/kd/vaudio.prx","ms0:/TM/DC8/6xxModules/vaudio.prx",
				"ms0:/F0/kd/videocodec_260.prx","ms0:/TM/DC8/6xxModules/videocodec_260.prx",
				"ms0:/F0/kd/resource/me_t2img.img","ms0:/TM/DC8/6xxModules/me_t2img.img",
				"ms0:/F0/kd/resource/meimg.img","ms0:/TM/DC8/6xxModules/meimg.img",
			}; Expand(prome_pbpname,argc(pPROME),pPROME,1);}
#else
	if(endswith(argv[1],".PBP") || endswith(argv[1],".PSP") || endswith(argv[1],".PRX")){
		decPSP(argv[1],endswith(argv[1],".PBP"));
	}
	if(endswith(argv[1],".PBP")){
		Expand(argv[1],0,(void*)0,1);
		ExtractReboot("F0/kd/loadexec.prx", "ms0:/F0/reboot.bin", "ms0:/F0/reboot.bin");
		ExtractReboot("F0/kd/loadexec_01g.prx", "ms0:/F0/reboot.bin", "ms0:/F0/reboot.bin");
		ExtractReboot("F0/kd/loadexec_02g.prx", "ms0:/F0/reboot_02g.bin", "ms0:/F0/reboot_02g.bin");
		ExtractReboot("F0/kd/loadexec_03g.prx", "ms0:/F0/reboot_03g.bin", "ms0:/F0/reboot_03g.bin");
		ExtractReboot("F0/kd/loadexec_04g.prx", "ms0:/F0/reboot_04g.bin", "ms0:/F0/reboot_04g.bin");
		ExtractReboot("F0/kd/loadexec_05g.prx", "ms0:/F0/reboot_05g.bin", "ms0:/F0/reboot_05g.bin");
		ExtractReboot("F0/kd/loadexec_06g.prx", "ms0:/F0/reboot_06g.bin", "ms0:/F0/reboot_06g.bin");
		ExtractReboot("F0/kd/loadexec_07g.prx", "ms0:/F0/reboot_07g.bin", "ms0:/F0/reboot_07g.bin");
		ExtractReboot("F0/kd/loadexec_08g.prx", "ms0:/F0/reboot_08g.bin", "ms0:/F0/reboot_08g.bin");
		ExtractReboot("F0/kd/loadexec_09g.prx", "ms0:/F0/reboot_09g.bin", "ms0:/F0/reboot_09g.bin");
		ExtractReboot("F0/kd/loadexec_10g.prx", "ms0:/F0/reboot_10g.bin", "ms0:/F0/reboot_10g.bin");
		ExtractReboot("F0/kd/loadexec_11g.prx", "ms0:/F0/reboot_11g.bin", "ms0:/F0/reboot_11g.bin");
		ExtractReboot("F0/kd/loadexec_12g.prx", "ms0:/F0/reboot_12g.bin", "ms0:/F0/reboot_12g.bin");
	}
	if(endswith(argv[1],".PSAR")){
		Expand(argv[1],0,(void*)0,0);
	}
#endif
    return 0;
}
