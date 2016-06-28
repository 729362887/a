#include<stdio.h>


extern char* disassemble16(char* arg0, int* arg1);
extern char* disassemble32(char* arg0, int* arg1);


void choice16(char* arg0) {

	int pos = 0;
	int r;
	char* str;

begin:
	printf("%04x    ", pos);
	if (arg0[pos]==0x66) {
		printf("%02x    66\n", (unsigned char)arg0[pos]);
		pos++;
		printf("%04x    ", pos);
		str = disassemble32(&arg0[pos], &r);
		if (r) {
			printf("%s\n", str);
			pos += r;
			goto begin;
		}
		goto end;
	}

	str = disassemble16(&arg0[pos], &r);
	if (r) {
		printf("%s\n", str);
		pos += r;
		goto begin;
	}

end:
	printf("it over: %02x%02x\n", (unsigned char)arg0[pos], (unsigned char)arg0[pos + 1]);
	return;

}








