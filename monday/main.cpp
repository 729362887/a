#include<stdio.h>

extern char* dis32(unsigned char* arg0, int* arg1);

static unsigned char buffer[] = {0xc7,0x45,0xfc,0x00,0x00,0x00,0x00,0x00 };

int main() {

	int count;
	char* str;

	str = dis32(buffer, &count);
	printf("%s\n", str);

	getchar();

	return 0;
}
