#include<stdio.h>
#include<string.h>

int REX_W = 0;
int REX_R = 0;
int REX_X = 0;
int REX_B = 0;


char* prefix(unsigned char* arg0, int* arg1) {

	static char buffer[0x30];
	memset(buffer, 0, sizeof(buffer));

	int index = 0;
	int i = 0;

	for (i = 0; i < 5; i++) {
		switch (arg0[i])
		{
		case 0x40:
			REX_W = 0;
			REX_R = 0;
			REX_X = 0;
			REX_B = 0;
			index++;
			snprintf(buffer, sizeof(buffer), "%s 40 REX", buffer);
			break;
		case 0x41:
			REX_W = 0;
			REX_R = 0;
			REX_X = 0;
			REX_B = 1;
			index++;
			snprintf(buffer, sizeof(buffer), "%s 41 REX.B", buffer);
			break;
		case 0x42:
			REX_W = 0;
			REX_R = 0;
			REX_X = 1;
			REX_B = 0;
			index++;
			snprintf(buffer, sizeof(buffer), "%s 42 REX.X", buffer);
			break;
		case 0x43:
			REX_W = 0;
			REX_R = 0;
			REX_X = 1;
			REX_B = 1;
			index++;
			snprintf(buffer, sizeof(buffer), "%s 43 REX.XB", buffer);
			break;
		case 0x44:
			REX_W = 0;
			REX_R = 1;
			REX_X = 0;
			REX_B = 0;
			index++;
			snprintf(buffer, sizeof(buffer), "%s 44 REX.R", buffer);
			break;
		case 0x45:
			REX_W = 0;
			REX_R = 1;
			REX_X = 0;
			REX_B = 1;
			index++;
			snprintf(buffer, sizeof(buffer), "%s 45 REX.RB", buffer);
			break;
		case 0x46:
			REX_W = 0;
			REX_R = 1;
			REX_X = 1;
			REX_B = 0;
			index++;
			snprintf(buffer, sizeof(buffer), "%s 46 REX.RX", buffer);
			break;
		case 0x47:
			REX_W = 0;
			REX_R = 1;
			REX_X = 1;
			REX_B = 1;
			index++;
			snprintf(buffer, sizeof(buffer), "%s 47 REX.RXB", buffer);
			break;
		case 0x48:
			REX_W = 1;
			REX_R = 0;
			REX_X = 0;
			REX_B = 0;
			index++;
			snprintf(buffer, sizeof(buffer), "%s 48 REX.W", buffer);
			break;
		case 0x49:
			REX_W = 1;
			REX_R = 0;
			REX_X = 0;
			REX_B = 1;
			index++;
			snprintf(buffer, sizeof(buffer), "%s 49 REX.WB", buffer);
			break;
		case 0x4a:
			REX_W = 1;
			REX_R = 0;
			REX_X = 1;
			REX_B = 0;
			index++;
			snprintf(buffer, sizeof(buffer), "%s 4a REX.WX", buffer);
			break;
		case 0x4b:
			REX_W = 1;
			REX_R = 0;
			REX_X = 1;
			REX_B = 1;
			index++;
			snprintf(buffer, sizeof(buffer), "%s 4b REX.WXB", buffer);
			break;
		case 0x4c:
			REX_W = 1;
			REX_R = 1;
			REX_X = 0;
			REX_B = 0;
			index++;
			snprintf(buffer, sizeof(buffer), "%s 4c REX.WR", buffer);
			break;
		case 0x4d:
			REX_W = 1;
			REX_R = 1;
			REX_X = 0;
			REX_B = 1;
			index++;
			snprintf(buffer, sizeof(buffer), "%s 4d REX.WRB", buffer);
			break;
		case 0x4e:
			REX_W = 1;
			REX_R = 1;
			REX_X = 1;
			REX_B = 0;
			index++;
			snprintf(buffer, sizeof(buffer), "%s 4e REX.WRX", buffer);
			break;
		case 0x4f:
			REX_W = 1;
			REX_R = 1;
			REX_X = 1;
			REX_B = 1;
			index++;
			snprintf(buffer, sizeof(buffer), "%s 4f REX.WRXB", buffer);
			break;
		case 0x64:
			index++;
			snprintf(buffer, sizeof(buffer), "%s 64 FS", buffer);
			break;
		case 0x65:
			index++;
			snprintf(buffer, sizeof(buffer), "%s 65 GS", buffer);
			break;
		default:
			goto r;
		}
	}

r:
	*arg1 = index;
	return buffer;
}











