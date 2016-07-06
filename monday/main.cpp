#include<stdio.h>

extern char* dis32(unsigned char* arg0, int* arg1);

static unsigned char buffer[] = { 0x66,0x56,0xc4,0x04,0x27,0x5e,0x73,0x33,0x00,0x00,0x00,0x00,0x00,0x66 };

int main() {

	int count;
	char* str;

	str = dis32(buffer, &count);
	printf("%s\n", str);

	getchar();

	return 0;
}
