

static char* add_cmp(unsigned char* arg0);
static char* rol_sar(unsigned char* arg0);
static char* test_idiv(unsigned char* arg0);
static char* inc_push(unsigned char* arg0);

char* opcode(unsigned char* arg0) {

	switch (arg0[0])
	{
	case 0x00:
		return "add";
	case 0x01:
		return "add";
	case 0x02:
		return "add";
	case 0x03:
		return "add";
	case 0x04:
		return "add";
	case 0x05:
		return "add";
	case 0x06:
		return "push";
	case 0x07:
		return "pop";
	case 0x08:
		return "or";
	case 0x09:
		return "or";
	case 0x0a:
		return "or";
	case 0x0b:
		return "or";
	case 0x0c:
		return "or";
	case 0x0d:
		return "or";
	case 0x0e:
		return "push";
	case 0x10:
		return "adc";
	case 0x11:
		return "adc";
	case 0x12:
		return "adc";
	case 0x13:
		return "adc";
	case 0x14:
		return "adc";
	case 0x15:
		return "adc";
	case 0x16:
		return "push";
	case 0x17:
		return "pop";
	case 0x18:
		return "sbb";
	case 0x19:
		return "sbb";
	case 0x1a:
		return "sbb";
	case 0x1b:
		return "sbb";
	case 0x1c:
		return "sbb";
	case 0x1d:
		return "sbb";
	case 0x1e:
		return "push";
	case 0x1f:
		return "pop";
	case 0x20:
		return "and";
	case 0x21:
		return "and";
	case 0x22:
		return "and";
	case 0x23:
		return "and";
	case 0x24:
		return "and";
	case 0x25:
		return "and";
	case 0x27:
		return "daa";
	case 0x28:
		return "sub";
	case 0x29:
		return "sub";
	case 0x2a:
		return "sub";
	case 0x2b:
		return "sub";
	case 0x2c:
		return "sub";
	case 0x2d:
		return "sub";
	case 0x2f:
		return "das";
	case 0x30:
		return "xor";
	case 0x31:
		return "xor";
	case 0x32:
		return "xor";
	case 0x33:
		return "xor";
	case 0x34:
		return "xor";
	case 0x35:
		return "xor";
	case 0x37:
		return "aaa";
	case 0x38:
		return "cmp";
	case 0x39:
		return "cmp";
	case 0x3a:
		return "cmp";
	case 0x3b:
		return "cmp";
	case 0x3c:
		return "cmp";
	case 0x3d:
		return "cmp";
	case 0x3f:
		return "aas";
	case 0x40:
		return "inc";
	case 0x41:
		return "inc";
	case 0x42:
		return "inc";
	case 0x43:
		return "inc";
	case 0x44:
		return "inc";
	case 0x45:
		return "inc";
	case 0x46:
		return "inc";
	case 0x47:
		return "inc";
	case 0x48:
		return "dec";
	case 0x49:
		return "dec";
	case 0x4a:
		return "dec";
	case 0x4b:
		return "dec";
	case 0x4c:
		return "dec";
	case 0x4d:
		return "dec";
	case 0x4e:
		return "dec";
	case 0x4f:
		return "dec";
	case 0x50:
		return "push";
	case 0x51:
		return "push";
	case 0x52:
		return "push";
	case 0x53:
		return "push";
	case 0x54:
		return "push";
	case 0x55:
		return "push";
	case 0x56:
		return "push";
	case 0x57:
		return "push";
	case 0x58:
		return "pop";
	case 0x59:
		return "pop";
	case 0x5a:
		return "pop";
	case 0x5b:
		return "pop";
	case 0x5c:
		return "pop";
	case 0x5d:
		return "pop";
	case 0x5e:
		return "pop";
	case 0x5f:
		return "pop";
	case 0x60:
		return "pusha";
	case 0x61:
		return "popa";
	case 0x62:
		return "bound";
	case 0x63:
		return "arpl";
	case 0x68:
		return "push";
	case 0x69:
		return "imul";
	case 0x6a:
		return "push";
	case 0x6b:
		return "imul";
	case 0x6c:
		return "ins insb";
	case 0x6d:
		return "ins insw insd";
	case 0x6e:
		return "outs outsb";
	case 0x6f:
		return "outs outsw outsd";
	case 0x70:
		return "jo";
	case 0x71:
		return "jno";
	case 0x72:
		return "jb jnae jc";
	case 0x73:
		return "jnb jae jnc";
	case 0x74:
		return "jz je";
	case 0x75:
		return "jnz jne";
	case 0x76:
		return "jbe jna";
	case 0x77:
		return "jnbe ja";
	case 0x78:
		return "js";
	case 0x79:
		return "jns";
	case 0x7a:
		return "jp jpe";
	case 0x7b:
		return "jnp jpo";
	case 0x7c:
		return "jl jnge";
	case 0x7d:
		return "jnl jge";
	case 0x7e:
		return "jle jng";
	case 0x7f:
		return "jnle jg";
	case 0x80:
	case 0x81:
	case 0x82:
	case 0x83:
		return add_cmp(&arg0[1]);
	case 0x84:
		return "test";
	case 0x85:
		return "test";
	case 0x86:
		return "xchg";
	case 0x87:
		return "xchg";
	case 0x88:
	case 0x89:
	case 0x8a:
	case 0x8b:
	case 0x8c:
		return "mov";
	case 0x8d:
		return "lea";
	case 0x8e:
		return "mov";
	case 0x8f:
		return "pop";
	case 0x90:
		return "nop";
	case 0x91:
	case 0x92:
	case 0x93:
	case 0x94:
	case 0x95:
	case 0x96:
	case 0x97:
		return "xchg";
	case 0x98:
		return "cbw cwde";
	case 0x99:
		return "cwd cdq";
	case 0x9a:
		return "callf";
	case 0x9b:
		return "fwait wait";
	case 0x9c:
		return "pushf pushfd";
	case 0x9d:
		return "popf popfd";
	case 0x9e:
		return "sahf";
	case 0x9f:
		return "lahf";
	case 0xa0:
	case 0xa1:
	case 0xa2:
	case 0xa3:
		return "mov";
	case 0xa4:
		return "movs movsb";
	case 0xa5:
		return "movs movsw movsd";
	case 0xa6:
		return "cmps cmpsb";
	case 0xa7:
		return "cmps cmpsw cmpsd";
	case 0xa8:
		return "test";
	case 0xa9:
		return "test";
	case 0xaa:
		return "stos stosb";
	case 0xab:
		return "stos stosw stosd";
	case 0xac:
		return "lods lodsb";
	case 0xad:
		return "lods lodsw lodsd";
	case 0xae:
		return "scas scasb";
	case 0xaf:
		return "scas scasw scasd";
	case 0xb0:
	case 0xb1:
	case 0xb2:
	case 0xb3:
	case 0xb4:
	case 0xb5:
	case 0xb6:
	case 0xb7:
	case 0xb8:
	case 0xb9:
	case 0xba:
	case 0xbb:
	case 0xbc:
	case 0xbd:
	case 0xbe:
	case 0xbf:
		return "mov";
	case 0xc0:
	case 0xc1:
		return rol_sar(&arg0[1]);
	case 0xc2:
		return "retn";
	case 0xc3:
		return "retn";
	case 0xc4:
		return "les";
	case 0xc5:
		return "lds";
	case 0xc6:
		return "mov";
	case 0xc7:
		return "mov";
	case 0xc8:
		return "enter";
	case 0xc9:
		return "leave";
	case 0xca:
		return "retf";
	case 0xcb:
		return "retf";
	case 0xcc:
		return "int";
	case 0xcd:
		return "int";
	case 0xce:
		return "into";
	case 0xcf:
		return "iret iretd";
	case 0xd0:
	case 0xd1:
	case 0xd2:
	case 0xd3:
		return rol_sar(&arg0[1]);
	case 0xe0:
		return "loopnz loopne";
	case 0xe1:
		return "loopz loope";
	case 0xe2:
		return "loop";
	case 0xe3:
		return "jcxz jecxz";
	case 0xe4:
		return "in";
	case 0xe5:
		return "in";
	case 0xe6:
		return "out";
	case 0xe7:
		return "out";
	case 0xe8:
		return "call";
	case 0xe9:
		return "jmp";
	case 0xea:
		return "jmpf";
	case 0xeb:
		return "jmp";
	case 0xec:
		return "in";
	case 0xed:
		return "int";
	case 0xee:
		return "out";
	case 0xef:
		return "out";
	case 0xf1:
		return "int1 icebp";
	case 0xf4:
		return "hlt";
	case 0xf5:
		return "cmc";
	case 0xf6:
	case 0xf7:
		return test_idiv(&arg0[1]);
	case 0xf8:
		return "clc";
	case 0xf9:
		return "stc";
	case 0xfa:
		return "cli";
	case 0xfb:
		return "sti";
	case 0xfc:
		return "cld";
	case 0xfd:
		return "std";
	case 0xfe:
	case 0xff:
		return inc_push(&arg0[1]);
	default:
		return "unknown";
	}

}


static char* add_cmp(unsigned char* arg0) {

	switch (arg0[0] & 0x38)
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
		return "unkown";
	}

}

static char* rol_sar(unsigned char* arg0) {

	switch (arg0[0] & 0x38)
	{
	case 0x00:
		return "rol";
	case 0x08:
		return "ror";
	case 0x10:
		return "rcl";
	case 0x18:
		return "rcr";
	case 0x20:
		return "shl sal";
	case 0x28:
		return "shr";
	case 0x30:
		return "sal shl";
	case 0x38:
		return "sar";
	default:
		return "unkown";
	}

}

static char* test_idiv(unsigned char* arg0) {

	switch (arg0[0] & 0x38)
	{
	case 0x00:
		return "test";
	case 0x08:
		return "test";
	case 0x10:
		return "not";
	case 0x18:
		return "neg";
	case 0x20:
		return "mul";
	case 0x28:
		return "imul";
	case 0x30:
		return "div";
	case 0x38:
		return "idiv";
	default:
		return "unknown";
	}

}

static char* inc_push(unsigned char* arg0) {

	switch (arg0[0] & 0x38)
	{
	case 0x00:
		return "inc";
	case 0x08:
		return "dec";
	case 0x10:
		return "call";
	case 0x18:
		return "callf";
	case 0x20:
		return "jmp";
	case 0x28:
		return "jmpf";
	case 0x30:
		return "push";
	default:
		return "unknown";
	}

}






