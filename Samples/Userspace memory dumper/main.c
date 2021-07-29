#include "sparta_sdk.h"

void _start()
{
	SceUID out = sceIoOpen("ms0:/umem.bin", PSP_O_WRONLY | PSP_O_CREAT | PSP_O_TRUNC, 0777);
	sceIoWrite(out, (void *)0x08800000, 0x1800000);
	sceIoClose(out);
	sceKernelDelayThread(3000000);
	sceKernelExitGame();
	return;
}
