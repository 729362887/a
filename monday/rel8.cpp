#include<stdio.h>

char* getrel8(unsigned char* arg0) {

	static char buffer[0x20];

	snprintf(buffer, sizeof(buffer), "0x%02x", arg0[0]);

	return buffer;
}




