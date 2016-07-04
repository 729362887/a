#include<stdio.h>

char* gethex(unsigned char* arg0, int arg1) {

	static char buffer[0x30];
	int i = 0;

	snprintf(buffer,sizeof(buffer),"0x");
	for (i = 0; i < arg1;i++) {
		snprintf(buffer, sizeof(buffer), "%s%02x", buffer, arg0[i]);
	}

	return buffer;
}







