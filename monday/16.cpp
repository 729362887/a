#include<stdio.h>


char* get16(unsigned char* arg0) {

	static char buffer[0x20];

	snprintf(buffer, sizeof(buffer), "%02x%02x", arg0[1], arg0[0]);

	return buffer;
}






