#include<stdio.h>

extern char* dis16(unsigned char* arg0, int* arg1);

unsigned char bufffer[] = {0x24,0xff,0x02,0x00,0x55,0xaa};

int main() {

	int i;
	char* str;

	str = dis16(bufffer, &i);
	printf("%s\n",str);

	getchar();

	return 0;
}



