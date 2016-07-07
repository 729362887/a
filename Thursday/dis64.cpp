#include<stdio.h>

extern char* opcode(unsigned char* arg0);
extern char* prefix(unsigned char* arg0, int* arg1);
extern void r_rm(unsigned char* arg0, int* arg1, char** r, char** rm);
extern char* hex(unsigned char* arg0, int arg1);

char* dis64(unsigned char* arg0, int* arg1) {

	static char buffer[0x100];

	int index;
	int count;
	char* p;
	char* o;
	char* r;
	char* rm;
	char* h;

	p = prefix(arg0, &index);
	o = opcode(&arg0[index]);
	r_rm(&arg0[index + 1], &count, &r, &rm);
	h = hex(arg0, index + 1 + count);

	switch (arg0[index])
	{
	case 0x33:
		snprintf(buffer, sizeof(buffer), "%s    %s %s %s,%s", h, p, o, r,rm );
		return buffer;
	case 0x83:
		snprintf(buffer, sizeof(buffer), "%s    %s %s %s,0x%02x", hex(arg0, index + 1 + count + 1), p, o, rm, arg0[index + 1 + count]);
		return buffer;
	case 0x85:
		snprintf(buffer, sizeof(buffer), "%s    %s %s %s,%s", h, p, o, rm, r);
		return buffer;
	case 0x89:
		snprintf(buffer, sizeof(buffer), "%s    %s %s %s,%s", h, p, o, rm, r);
		return buffer;
	case 0x8b:
		snprintf(buffer, sizeof(buffer), "%s    %s %s %s,%s", h, p, o, r, rm);
		return buffer;
	default:
		return "unknown";
	}



}


