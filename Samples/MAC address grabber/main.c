#include "sparta_sdk.h"

void _start()
{
	u8 mac[6];
	SceUID out = sceIoOpen("ms0:/mac.txt", PSP_O_WRONLY | PSP_O_CREAT | PSP_O_TRUNC, 0777);
	SceUID res = sceWlanGetEtherAddr(&mac);
	sceIoWrite(out, "GripShift Exploit Demo by FreePlay\nYour MAC address:\n", 53);
	if (! (res && 0x80020000) )
	{
		int x;
		for(x=0;x<6;x++)
		{
			u8 hi, lo;
			hi = mac[x]/16;
			lo = mac[x]-16*hi;
			sceIoWrite(out, "0123456789ABCDEF"+hi, 1);
			sceIoWrite(out, "0123456789ABCDEF"+lo, 1);
		}
	}
	else
	{
		sceIoWrite(out, "failed to get MAC address!", 6);
	}
	sceIoClose(out);
	sceKernelDelayThread(3000000);
	sceKernelExitGame();
	return;
}
