#include<stdio.h>


char* get32(unsigned char* arg0) {

	static char buffer[0x20];

	snprintf(buffer, sizeof(buffer), "%02x%02x%02x%02x", arg0[3], arg0[2],arg0[1], arg0[0]);

	return buffer;
}