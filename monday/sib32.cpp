


char* getsib32(unsigned char* arg0) {
	
	switch (arg0[0] & 0xf8)
	{
	case 0x00:
		return "eax";
	case 0x08:
		return "ecx";
	case 0x10:
		return "edx";
	case 0x18:
		return "ebx";
	case 0x20:
		return "none";
	case 0x28:
		return "ebp";
	case 0x30:
		return "esi";
	case 0x38:
		return "edi";
	
	case 0x40:
		return "eax*2";
	case 0x48:
		return "ecx*2";
	case 0x50:
		return "edx*2";
	case 0x58:
		return "ebx*2";
	case 0x60:
		return "none";
	case 0x68:
		return "ebp*2";
	case 0x70:
		return "esi*2";
	case 0x78:
		return "edi*2";

	case 0x80:
		return "eax*4";
	case 0x88:
		return "ecx*4";
	case 0x90:
		return "edx*4";
	case 0x98:
		return "ebx*4";
	case 0xa0:
		return "none";
	case 0xa8:
		return "ebp*4";
	case 0xb0:
		return "esi*4";
	case 0xb8:
		return "edi*4";

	case 0xc0:
		return "eax*8";
	case 0xc8:
		return "ecx*8";
	case 0xd0:
		return "edx*8";
	case 0xd8:
		return "ebx*8";
	case 0xe0:
		return "none";
	case 0xe8:
		return "ebp*8";
	case 0xf0:
		return "esi*8";
	case 0xf8:
		return "edi*8";

	default:
		return "unknown";
	}

}

