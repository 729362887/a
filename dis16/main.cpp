#include<stdio.h>

extern char* dis16(unsigned char* arg0, int* arg1);

unsigned char bufffer[] = {0xe8,0x05,0xf2,0x04,0x00,0x00};

int main() {

	int i;
	char* str;

	str = dis16(bufffer, &i);
	printf("%s\n",str);

	getchar();

	return 0;
}



