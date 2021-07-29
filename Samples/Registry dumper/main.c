#include "sparta_sdk.h"

void _start(unsigned long, unsigned long *) __attribute__ ((section (".text.start")));
void _start(unsigned long arglen, unsigned long *argp)
{
	sceKernelDcacheWritebackAll();

	SceUID in = sceIoOpen("flash1:/registry/system.dreg", PSP_O_RDONLY , 31);
	SceUID out = sceIoOpen("ms0:/system.dreg", PSP_O_WRONLY | PSP_O_CREAT | PSP_O_TRUNC, 31);

	SceIoStat *stat = (SceIoStat *)0x08820000;
	memset(stat,0,sizeof(SceIoStat));
	sceIoGetstat("flash1:/registry/system.dreg", stat);
	SceOff len = stat->st_size;

	sceIoRead(in, (void*)0x08830000, len);
	sceIoClose(in);

	sceIoWrite(out, (void*)0x08830000, len);
	sceIoClose(out);

	in = sceIoOpen("flash1:/registry/system.ireg", PSP_O_RDONLY , 31);
	out = sceIoOpen("ms0:/system.ireg", PSP_O_WRONLY | PSP_O_CREAT | PSP_O_TRUNC, 31);

	memset(stat,0,sizeof(SceIoStat));
	sceIoGetstat("flash1:/registry/system.ireg", stat);
	len = stat->st_size;

	sceIoRead(in, (void*)0x08830000, len);
	sceIoClose(in);

	sceIoWrite(out, (void*)0x08830000, len);
	sceIoClose(out);


	sceKernelDelayThread(3000000);
	sceKernelExitGame();

	return;
}
