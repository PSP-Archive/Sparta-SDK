Spartaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa!!! SDK v1

Just '#include "sparta_sdk.h"' and you'll be able to use any of
the functions in the SDK (starting on line 382) - though the modules might
need to be loaded first from the disc.

Notes:

Instead of a 'main' function, the code goes in the '_start' function. ALWAYS include these lines:


	void _start(unsigned long, unsigned long *) __attribute__ ((section (".text.start")));
	void _start(unsigned long arglen, unsigned long *argp)
	{
		sceKernelDcacheWritebackAll();

This goes a long way to ensuring that all the functions will work properly.
Also, remember to put "sceKernelExitGame();" at the end of _start; otherwise
the exploit will (currently) just loop through _start forever.

The included makefile should be good enough for anything that only needs one .c file...

*******************************************************
*** We're currently having trouble with sceIoLseek. ***
*******************************************************
sceIoLseek appears to be returning invalid values. This
may cause you problems when you want to seek through a
file. If you just want to find a file's size, use this:

	SceIoStat *stat = (SceIoStat *)0x08820000; // arbitrary location in user memory
	memset(stat,0,sizeof(SceIoStat));
	sceIoGetstat("path:/to/file", stat);
	SceOff filesize = stat->st_size;



Happy coding!
