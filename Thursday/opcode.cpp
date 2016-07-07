#include<stdio.h>

static char* add_cmp(unsigned char* arg0);

char* opcode(unsigned char* arg0) {

	switch (arg0[0])
	{
	case 0x33:
		return "xor";
	case 0x83:
		return add_cmp(&arg0[1]);
	case 0x85:
		return "test";
	case 0x89:
		return "mov";
	case 0x8b:
		return "mov";
	default:
		return "unknown";
	}


}

static char* add_cmp( unsigned char* arg0 ) {

	switch ( arg0[0] & 0x38 )
	{
	case 0x00:
		return "add";
	case 0x08:
		return "or";
	case 0x10:
		return "adc";
	case 0x18:
		return "sbb";
	case 0x20:
		return "and";
	case 0x28:
		return "sub";
	case 0x30:
		return "xor";
	case 0x38:
		return "cmp";
	default:
		return "unknown";
	}

}

