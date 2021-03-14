## PSARDumper on PC / PopsDeco on PC

- found sceMesgd\_driver\_102DC8AF implementation in https://github.com/jpcsp/jpcsp/commit/578600cfb9755179d9a3e40feab9f6e2dba92df0
- found kl4e implementation in https://github.com/jpcsp/jpcsp/blob/master/src/jpcsp/format/KL4E.java
- found https://github.com/John-K/pspdecrypt

This repo is degraded copy of pspdecrypt. I recommended to use pspdecypt.

This repo does not support PRX5/PRX6/IPLstage3.

## Specific usage:

### PopsDeco on PC

- Run `PopsDeco` (after preparing PBPs)

### 500DC8ex

```
mkdir TM
./psardumper 500.PBP
rm -rf F0/PSARDUMPER/
rm F0/reboot*.bin
mv F0 TM/DC8
./DC8EX
mv TM/DC8/vsh/resource/01-12_03g.bmp TM/DC8/vsh/resource/bg.bmp
```

Then put libpuer\_dist/PSP/GAME/500DC8ex/res to this dir.

```
cp res/ipl.bin res/ipl_01g.bin res/ipl_02g.bin res/tmctrl500.prx res/prometheus_key.txt TM/DC8/
cp res/intraFont.prx res/recovery.prx res/satelite.prx res/vlf.prx TM/DC8/vsh/module/
cp res/version.txt TM/DC8/vsh/etc/

cp res/stargate.prx res/prometheus_lite.prx res/march33.prx res/resurrection.prx res/systemctrl.prx res/systemctrl_02g.prx res/leda.prx TM/DC8/kd/
cp res/dcman.prx res/emc_sm_updater.prx res/galaxy.prx res/idcanager.prx res/idsregeneration.prx res/iop.prx res/ipl_update.prx res/lfatfs_updater.prx res/lflash_fatfmt_updater.prx res/lflash_fdisk.prx TM/DC8/kd/
cp res/libpsardumper.prx res/popcorn.prx res/pspdecrypt.prx res/usbdevice.prx res/vshctrl.prx TM/DC8/kd/
cp res/pspbtdnf.bin res/pspbtdnf_02g.bin res/pspbtjnf.bin res/pspbtjnf_02g.bin res/pspbtknf.bin res/pspbtknf_02g.bin res/pspbtlnf.bin res/pspbtlnf_02g.bin TM/DC8/kd/
```

