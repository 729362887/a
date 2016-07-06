#include<stdio.h>

extern char* getsib32(unsigned char* arg0);

char* getmodrm32(unsigned char* arg0, int* arg1) {

	static char buffer[0x30];

	switch (arg0[0] & 0xc7)
	{
	case 0x00:
		*arg1 = 1;
		return "dword ptr [eax]";
	case 0x01:
		*arg1 = 1;
		return "dword ptr [ecx]";
	case 0x02:
		*arg1 = 1;
		return "dword ptr [edx]";
	case 0x03:
		*arg1 = 1;
		return "dword ptr [ebx]";
	case 0x04:
		*arg1 = 2;
		return "dword ptr [sib]";
	case 0x05:
		*arg1 = 5;
		snprintf(buffer,sizeof(buffer),"dword ptr [0x%02x%02x%02x%02x]",arg0[4],arg0[3], arg0[2], arg0[1]);
		return buffer;
	case 0x06:
		*arg1 = 1;
		return "dword ptr [esi]";
	case 0x07:
		*arg1 = 1;
		return "dword ptr [edi]";
	case 0x40:
		*arg1 = 2;
		snprintf(buffer,sizeof(buffer),"dword ptr [eax+0x%02x]",arg0[1]);
		return buffer;
	case 0x41:
		*arg1 = 2;
		snprintf(buffer, sizeof(buffer), "dword ptr [ecx+0x%02x]", arg0[1]);
		return buffer;
	case 0x42:
		*arg1 = 2;
		snprintf(buffer, sizeof(buffer), "dword ptr [edx+0x%02x]", arg0[1]);
		return buffer;
	case 0x43:
		*arg1 = 2;
		snprintf(buffer, sizeof(buffer), "dword ptr [ebx+0x%02x]", arg0[1]);
		return buffer;
	case 0x44:
		*arg1 = 3;
		snprintf(buffer, sizeof(buffer), "dword ptr [%s+0x%02x]",getsib32(&arg0[1]), arg0[2]);
		return buffer;
	case 0x45:
		*arg1 = 2;
		snprintf(buffer, sizeof(buffer), "dword ptr [ebp+0x%02x]", arg0[1]);
		return buffer;
	case 0x46:
		*arg1 = 2;
		snprintf(buffer, sizeof(buffer), "dword ptr [esi+0x%02x]", arg0[1]);
		return buffer;
	case 0x47:
		*arg1 = 2;
		snprintf(buffer, sizeof(buffer), "dword ptr [edi+0x%02x]", arg0[1]);
		return buffer;
	case 0x80:
		*arg1 = 5;
		snprintf(buffer, sizeof(buffer), "dword ptr [eax+0x%02x%02x%02x%02x]", arg0[4], arg0[3], arg0[2], arg0[1]);
		return buffer;
	case 0x81:
		*arg1 = 5;
		snprintf(buffer, sizeof(buffer), "dword ptr [ecx+0x%02x%02x%02x%02x]", arg0[1], arg0[3], arg0[2], arg0[1]);
		return buffer;
	case 0x82:
		*arg1 = 5;
		snprintf(buffer, sizeof(buffer), "dword ptr [edx+0x%02x%02x%02x%02x]", arg0[1], arg0[3], arg0[2], arg0[1]);
		return buffer;
	case 0x83:
		*arg1 = 5;
		snprintf(buffer, sizeof(buffer), "dword ptr [ebx+0x%02x%02x%02x%02x]", arg0[1], arg0[3], arg0[2], arg0[1]);
		return buffer;
	case 0x84:
		*arg1 = 5;
		snprintf(buffer, sizeof(buffer), "dword ptr [sib+0x%02x%02x%02x%02x]", arg0[1], arg0[3], arg0[2], arg0[1]);
		return buffer;
	case 0x85:
		*arg1 = 5;
		snprintf(buffer, sizeof(buffer), "dword ptr [ebp+0x%02x%02x%02x%02x]", arg0[1], arg0[3], arg0[2], arg0[1]);
		return buffer;
	case 0x86:
		*arg1 = 5;
		snprintf(buffer, sizeof(buffer), "dword ptr [esi+0x%02x%02x%02x%02x]", arg0[1], arg0[3], arg0[2], arg0[1]);
		return buffer;
	case 0x87:
		*arg1 = 5;
		snprintf(buffer, sizeof(buffer), "dword ptr [edi+0x%02x%02x%02x%02x]", arg0[1], arg0[3], arg0[2], arg0[1]);
		return buffer;
	case 0xc0:
		*arg1 = 1;
		return "eax";
	case 0xc1:
		*arg1 = 1;
		return "ecx";
	case 0xc2:
		*arg1 = 1;
		return "edx";
	case 0xc3:
		*arg1 = 1;
		return "ebx";
	case 0xc4:
		*arg1 = 1;
		return "esp";
	case 0xc5:
		*arg1 = 1;
		return "ebp";
	case 0xc6:
		*arg1 = 1;
		return "esi";
	case 0xc7:
		*arg1 = 1;
		return "edi";

	default:
		return "unknown";
	}

}

