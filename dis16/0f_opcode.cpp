

char* _0f_opcode(unsigned char* arg0) {

	switch (arg0[0])
	{
	case 0x80:
		return "jo";
	case 0x81:
		return "jno";
	case 0x82:
		return "jb jnae jc";
	case 0x83:
		return "jnb jae jnc";
	case 0x84:
		return "jz je";
	case 0x85:
		return "jnz jne";
	case 0x86:
		return "jbe jna";
	case 0x87:
		return "jnbe ja";
	case 0x88:
		return "js";
	case 0x89:
		return "jns";
	case 0x8a:
		return "jp jpe";
	case 0x8b:
		return "jnp jpo";
	case 0x8c:
		return "jl jnge";
	case 0x8d:
		return "jnl nge";
	case 0x8e:
		return "jle jng";
	case 0x8f:
		return "jnle jg";
	case 0x90:
		return "seto";
	case 0x91:
		return "setno";
	case 0x92:
		return "setb setnae setc";
	case 0x93:
		return "setnb setae setnc";
	case 0x94:
		return "setz sete";
	case 0x95:
		return "setnz setne";
	case 0x96:
		return "setbe setna";
	case 0x97:
		return "setnbe seta";
	case 0x98:
		return "sets";
	case 0x99:
		return "setns";
	case 0x9a:
		return "setp setpe";
	case 0x9b:
		return "setnp setpo";
	case 0x9c:
		return "setl setnge";
	case 0x9d:
		return "setnl setge";
	case 0x9e:
		return "setle setng";
	case 0x9f:
		return "setnle setg";
	default:
		return "unknown";
	}

}



