#include<stdio.h>

extern char* dis64(unsigned char* arg0, int* arg1);

unsigned char buffer[] = { 0x48,0x85,0xdb,0x68,0x03,0x00,0x00,0x00,0x00 };

int main() {

	int i;
	char* str;

	str = dis64(buffer, &i);
	printf("%s\n", str);

	getchar();

	return 0;
}





