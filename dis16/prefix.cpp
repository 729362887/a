#include<stdio.h>
#include<string.h>

char* prefix(unsigned char* arg0, int* arg1) {

	static char buffer[0x40];
	memset(buffer,0,sizeof(buffer));

	int i=0;
	int index = 0;

	for (i = 0; i < 5;i++) {
	
		switch (arg0[i])
		{
		default:
			goto r;
		}

	}

r:
	*arg1 = index;
	return buffer;

}


