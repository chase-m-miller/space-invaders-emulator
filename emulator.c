// See case 0x80 for verbose description of flag logic
// see case 0x81 for shorthand
// Note to self: study 0x86 further
// AC flag is not implemented because it is unused by Space Invaders

typedef struct ConditionCodes {
	uint8_t	z:1;
	uint8_t	s:1;
	uint8_t	p:1;
	uint8_t	cy:1;
	uint8_t	ac:1;
	uint8_t	pad:3;
} ConditionCodes;

typedef struct State8080 {
	uint8_t	 a;
	uint8_t	 b;
	uint8_t	 c;
	uint8_t	 d;
	uint8_t	 e;
	uint8_t	 h;
	uint8_t	 l;
	uint16_t sp;
	uint16_t pc;
	uint8_t	 *memory;
	struct ConditionCodes cc;
	uint8_t  int_enable;
} State8080;

void UnimplementedInstruction(State8080 *state) {
	printf("Error: Unimplemented instruction\n");
	exit(1);
}

int Emulate8080Op(State8080 *state) {
	unsigned char *opcode = &state->memory[state->pc];

	switch(*opcode) {
		case 0x00: break; // NOP
		case 0x01: state->c = opcode[1]; // LXI B,word
			   state->b = opcode[2];
			   state->pc += 2;
			   break;
		case 0x02: UnimplementedInstruction(state); break;
		case 0x03: UnimplementedInstruction(state); break;
		case 0x04: UnimplementedInstruction(state); break;
		case 0x05: UnimplementedInstruction(state); break;
		case 0x06: UnimplementedInstruction(state); break;
		case 0x07: UnimplementedInstruction(state); break;
		case 0x08: UnimplementedInstruction(state); break;
		case 0x09: UnimplementedInstruction(state); break;
		case 0x0a: UnimplementedInstruction(state); break;
		case 0x0b: UnimplementedInstruction(state); break;
		case 0x0c: UnimplementedInstruction(state); break;
		case 0x0d: UnimplementedInstruction(state); break;
		case 0x0e: UnimplementedInstruction(state); break;
		case 0x0f: UnimplementedInstruction(state); break;
		case 0x10: UnimplementedInstruction(state); break;
		case 0x11: UnimplementedInstruction(state); break;
		case 0x12: UnimplementedInstruction(state); break;
		case 0x13: UnimplementedInstruction(state); break;
		case 0x14: UnimplementedInstruction(state); break;
		case 0x15: UnimplementedInstruction(state); break;
		case 0x16: UnimplementedInstruction(state); break;
		case 0x17: UnimplementedInstruction(state); break;
		case 0x18: UnimplementedInstruction(state); break;
		case 0x19: UnimplementedInstruction(state); break;
		case 0x1a: UnimplementedInstruction(state); break;
		case 0x1b: UnimplementedInstruction(state); break;
		case 0x1c: UnimplementedInstruction(state); break;
		case 0x1d: UnimplementedInstruction(state); break;
		case 0x1e: UnimplementedInstruction(state); break;
		case 0x1f: UnimplementedInstruction(state); break;
		case 0x20: UnimplementedInstruction(state); break;
		case 0x21: UnimplementedInstruction(state); break;
		case 0x22: UnimplementedInstruction(state); break;
		case 0x23: UnimplementedInstruction(state); break;
		case 0x24: UnimplementedInstruction(state); break;
		case 0x25: UnimplementedInstruction(state); break;
		case 0x26: UnimplementedInstruction(state); break;
		case 0x27: UnimplementedInstruction(state); break;
		case 0x28: UnimplementedInstruction(state); break;
		case 0x29: UnimplementedInstruction(state); break;
		case 0x2a: UnimplementedInstruction(state); break;
		case 0x2b: UnimplementedInstruction(state); break;
		case 0x2c: UnimplementedInstruction(state); break;
		case 0x2d: UnimplementedInstruction(state); break;
		case 0x2e: UnimplementedInstruction(state); break;
		case 0x2f: UnimplementedInstruction(state); break;
		case 0x30: UnimplementedInstruction(state); break;
		case 0x31: UnimplementedInstruction(state); break;
		case 0x32: UnimplementedInstruction(state); break;
		case 0x33: UnimplementedInstruction(state); break;
		case 0x34: UnimplementedInstruction(state); break;
		case 0x35: UnimplementedInstruction(state); break;
		case 0x36: UnimplementedInstruction(state); break;
		case 0x37: UnimplementedInstruction(state); break;
		case 0x38: UnimplementedInstruction(state); break;
		case 0x39: UnimplementedInstruction(state); break;
		case 0x3a: UnimplementedInstruction(state); break;
		case 0x3b: UnimplementedInstruction(state); break;
		case 0x3c: UnimplementedInstruction(state); break;
		case 0x3d: UnimplementedInstruction(state); break;
		case 0x3e: UnimplementedInstruction(state); break;
		case 0x3f: UnimplementedInstruction(state); break;
		case 0x40: state->b = state->b; break; // MOV B,B
		case 0x41: state->b = state->c; break; // MOV B,C
		case 0x42: state->b = state->d; break; // MOV B,D
		case 0x43: state->b = state->e; break; // MOV B,E
		case 0x44: state->b = state->h; break; // MOV B,H
		case 0x45: state->b = state->l; break; // MOV B,L
		case 0x46: state->b = (state->h<<8) | (state->l); break; // MOV B,M
		case 0x47: state->b = state->a; break; // MOV B,A
		case 0x48: state->c = state->b; break; // MOV C,B
		case 0x49: state->c = state->c; break; // MOV C,C
		case 0x4a: state->c = state->d; break; // MOV C,D
		case 0x4b: state->c = state->e; break; // MOV C,E
		case 0x4c: state->c = state->h; break; // MOV C,H
		case 0x4d: state->c = state->l; break; // MOV C,L
		case 0x4e: state->c = (state->h<<8) | (state->l); break; // MOV C,M
		case 0x4f: state->c = state->a; break; // MOV C,A
		case 0x50: state->d = state->b; break; // MOV D,B
		case 0x51: state->d = state->c; break; // MOV D,C
		case 0x52: state->d = state->d; break; // MOV D,D
		case 0x53: state->d = state->e; break; // MOV D,E
		case 0x54: state->d = state->h; break; // MOV D,H
		case 0x55: state->d = state->l; break; // MOV D,L
		case 0x56: state->d = (state->h<<8) | (state->l); break; // MOV D,M
		case 0x57: state->d = state->a; break; // MOV D,A
		case 0x58: state->e = state->b; break; // MOV E,B
		case 0x59: state->e = state->c; break; // MOV E,C
		case 0x5a: state->e = state->d; break; // MOV E,D
		case 0x5b: state->e = state->e; break; // MOV E,E
		case 0x5c: state->e = state->h; break; // MOV E,H
		case 0x5d: state->e = state->l; break; // MOV E,L
		case 0x5e: state->e = (state->h<<8) | (state->l); break; // MOV E,M
		case 0x5f: state->e = state->a; break; // MOV E,A
		case 0x60: state->h = state->b; break; // MOV H,B
		case 0x61: state->h = state->c; break; // MOV H,C
		case 0x62: state->h = state->d; break; // MOV H,D
		case 0x63: state->h = state->e; break; // MOV H,E
		case 0x64: state->h = state->h; break; // MOV H,H
		case 0x65: state->h = state->l; break; // MOV H,L
		case 0x66: state->h = (state->h<<8) | (state->l); break; // MOV H,M
		case 0x67: state->h = state->a; break; // MOV H,A
		case 0x68: state->l = state->b; break; // MOV L,B
		case 0x69: state->l = state->c; break; // MOV L,C
		case 0x6a: state->l = state->d; break; // MOV L,D
		case 0x6b: state->l = state->e; break; // MOV L,E
		case 0x6c: state->l = state->h; break; // MOV L,H
		case 0x6d: state->l = state->l; break; // MOV L,L
		case 0x6e: state->l = (state->h<<8) | (state->l); break;  // MOV L,M
		case 0x6f: state->l = state->a; break; // MOV L,A
		case 0x70: UnimplementedInstruction(state); break;
		case 0x71: UnimplementedInstruction(state); break;
		case 0x72: UnimplementedInstruction(state); break;
		case 0x73: UnimplementedInstruction(state); break;
		case 0x74: UnimplementedInstruction(state); break;
		case 0x75: UnimplementedInstruction(state); break;
		case 0x76: UnimplementedInstruction(state); break;
		case 0x77: UnimplementedInstruction(state); break;
		case 0x78: state->a = state->b; break; // MOV A,B
		case 0x79: state->a = state->c; break; // MOV A,C
		case 0x7a: state->a = state->d; break; // MOV A,D
		case 0x7b: state->a = state->e; break; // MOV A,E
		case 0x7c: state->a = state->h; break; // MOV A,H
		case 0x7d: state->a = state->l; break; // MOV A,L
		case 0x7e: state->a = (state->h<<8) | (state->l); break; // MOV A,M
		case 0x7f: state->a = state->a; break; // MOV A,A
		case 0x80:	// ADD B
			{
				// does the math with higher precision
				// to capture the carry out
				uint16_t answer = (uint16_t) state->a + (uint16_t) state->b;

				// Zero flag: if result is zero,
				// set the flag to zero
				// else clear the flag
				if ((answer & 0xff) == 0)
					state->cc.z = 1;
				else
					state->cc.z = 0;

				// Sign flag: if bit 7 is set,
				// set the sign flag
				// else clear the sign flag
				if (answer & 0x80)
					state->cc.s = 1;
				else
					state->cc.s = 0;

				// Carry flag
				if (answer > 0xff)
					state->cc.cy = 1;
				else
					state->cc.cy = 0;

				// Parity is handled by a subroutine
				state->cc.p = Parity(answer & 0xff);

				state->a = answer & 0xff;
				break;
			}
		case 0x81:	// ADD C
			{
				uint16_t answer = (uint16_t) state->a + (uint16_t) state->c;
				state->cc.z = ((answer & 0xff) == 0);
				state->cc.s = ((answer & 0x80) != 0);
				state->cc.cy = (answer > 0xff);
				state->cc.p = Parity(answer & 0xff);
				state->a = answer & 0xff;
				break;
			}
		case 0x82:	// ADD D
			{
				uint16_t answer = (uint16_t) state->a + (uint16_t) state->d;
				state->cc.z = ((answer & 0xff) == 0);
				state->cc.s = ((answer & 0x80) != 0);
				state->cc.cy = (answer > 0xff);
				state->cc.p = Parity(answer & 0xff);
				state->a = answer & 0xff;
				break;
			}
		case 0x83:	// ADD E
			{
				uint16_t answer = (uint16_t) state->a + (uint16_t) state->e;
				state->cc.z = ((answer & 0xff) == 0);
				state->cc.s = ((answer & 0x80) != 0);
				state->cc.cy = (answer > 0xff);
				state->cc.p = Parity(answer & 0xff);
				state->a = answer & 0xff;
				break;
			}
		case 0x84:	// ADD H
			{
				uint16_t answer = (uint16_t) state->a + (uint16_t) state->h;
				state->cc.z = ((answer & 0xff) == 0);
				state->cc.s = ((answer & 0x80) != 0);
				state->cc.cy = (answer > 0xff);
				state->cc.p = Parity(answer & 0xff);
				state->a = answer & 0xff;
				break;
			}
		case 0x85:	// ADD L
			{
				uint16_t answer = (uint16_t) state->a + (uint16_t) state->l;
				state->cc.z = ((answer & 0xff) == 0);
				state->cc.s = ((answer & 0x80) != 0);
				state->cc.cy = (answer > 0xff);
				state->cc.p = Parity(answer & 0xff);
				state->a = answer & 0xff;
				break;
			}
		case 0x86:	// ADD M
			{
				uint16_t offset = (state->h<<8) | (state->l);
				uint16_t answer = (uint16_t) state->a + state->memory[offset];
				state->cc.z = ((answer & 0xff) == 0);
				state->cc.s = ((answer & 0x80) != 0);
				state->cc.cy = (answer > 0xff);
				state->cc.p = Parity(answer & 0xff);
				state->a = answer & 0xff;
				break;
			}
		case 0x87:	// ADD A
			{
				uint16_t answer = (uint16_t) state->a + (uint16_t) state->a;
				state->cc.z = ((answer & 0xff) == 0);
				state->cc.s = ((answer & 0x80) != 0);
				state->cc.cy = (answer > 0xff);
				state->cc.p = Parity(answer & 0xff);
				state->a = answer & 0xff;
				break;
			}
		case 0x88: UnimplementedInstruction(state); break;
		case 0x89: UnimplementedInstruction(state); break;
		case 0x8a: UnimplementedInstruction(state); break;
		case 0x8b: UnimplementedInstruction(state); break;
		case 0x8c: UnimplementedInstruction(state); break;
		case 0x8d: UnimplementedInstruction(state); break;
		case 0x8e: UnimplementedInstruction(state); break;
		case 0x8f: UnimplementedInstruction(state); break;
		case 0x90:	// SUB B
			{
				uint16_t answer = (uint16_t) state->a - (uint16_t) state->b;
				state->cc.z = ((answer & 0xff) == 0);
				state->cc.s = ((answer & 0x80) != 0);
				state->cc.cy = (answer > 0xff);
				state->cc.p = Parity(answer & 0xff);
				state->a = answer & 0xff;
				break;
			}
		case 0x91:	// SUB C
			{
				uint16_t answer = (uint16_t) state->a - (uint16_t) state->c;
				state->cc.z = ((answer & 0xff) == 0);
				state->cc.s = ((answer & 0x80) != 0);
				state->cc.cy = (answer > 0xff);
				state->cc.p = Parity(answer & 0xff);
				state->a = answer & 0xff;
				break;
			}
		case 0x92:	// SUB D
			{
				uint16_t answer = (uint16_t) state->a - (uint16_t) state->d;
				state->cc.z = ((answer & 0xff) == 0);
				state->cc.s = ((answer & 0x80) != 0);
				state->cc.cy = (answer > 0xff);
				state->cc.p = Parity(answer & 0xff);
				state->a = answer & 0xff;
				break;
			}
		case 0x93:	// SUB E
			{
				uint16_t answer = (uint16_t) state->a - (uint16_t) state->e;
				state->cc.z = ((answer & 0xff) == 0);
				state->cc.s = ((answer & 0x80) != 0);
				state->cc.cy = (answer > 0xff);
				state->cc.p = Parity(answer & 0xff);
				state->a = answer & 0xff;
				break;
			}
		case 0x94:	// SUB H
			{
				uint16_t answer = (uint16_t) state->a - (uint16_t) state->h;
				state->cc.z = ((answer & 0xff) == 0);
				state->cc.s = ((answer & 0x80) != 0);
				state->cc.cy = (answer > 0xff);
				state->cc.p = Parity(answer & 0xff);
				state->a = answer & 0xff;
				break;
			}
		case 0x95:	// SUB L
			{
				uint16_t answer = (uint16_t) state->a - (uint16_t) state->l;
				state->cc.z = ((answer & 0xff) == 0);
				state->cc.s = ((answer & 0x80) != 0);
				state->cc.cy = (answer > 0xff);
				state->cc.p = Parity(answer & 0xff);
				state->a = answer & 0xff;
				break;
			}
		case 0x96:	// SUB M
			{
				uint16_t answer = (uint16_t) state->a - ((state->h<<8) | (state->l));
				state->cc.z = ((answer & 0xff) == 0);
				state->cc.s = ((answer & 0x80) != 0);
				state->cc.cy = (answer > 0xff);
				state->cc.p = Parity(answer & 0xff);
				state->a = answer & 0xff;
				break;
			}
		case 0x97:	// SUB A
			{
				uint16_t answer = (uint16_t) state->a - (uint16_t) state->a;
				state->cc.z = ((answer & 0xff) == 0);
				state->cc.s = ((answer & 0x80) != 0);
				state->cc.cy = (answer > 0xff);
				state->cc.p = Parity(answer & 0xff);
				state->a = answer & 0xff;
				break;
			}
		case 0x98: UnimplementedInstruction(state); break;
		case 0x99: UnimplementedInstruction(state); break;
		case 0x9a: UnimplementedInstruction(state); break;
		case 0x9b: UnimplementedInstruction(state); break;
		case 0x9c: UnimplementedInstruction(state); break;
		case 0x9d: UnimplementedInstruction(state); break;
		case 0x9e: UnimplementedInstruction(state); break;
		case 0x9f: UnimplementedInstruction(state); break;
		case 0xa0: UnimplementedInstruction(state); break;
		case 0xa1: UnimplementedInstruction(state); break;
		case 0xa2: UnimplementedInstruction(state); break;
		case 0xa3: UnimplementedInstruction(state); break;
		case 0xa4: UnimplementedInstruction(state); break;
		case 0xa5: UnimplementedInstruction(state); break;
		case 0xa6: UnimplementedInstruction(state); break;
		case 0xa7: UnimplementedInstruction(state); break;
		case 0xa8: UnimplementedInstruction(state); break;
		case 0xa9: UnimplementedInstruction(state); break;
		case 0xaa: UnimplementedInstruction(state); break;
		case 0xab: UnimplementedInstruction(state); break;
		case 0xac: UnimplementedInstruction(state); break;
		case 0xad: UnimplementedInstruction(state); break;
		case 0xae: UnimplementedInstruction(state); break;
		case 0xaf: UnimplementedInstruction(state); break;
		case 0xb0: UnimplementedInstruction(state); break;
		case 0xb1: UnimplementedInstruction(state); break;
		case 0xb2: UnimplementedInstruction(state); break;
		case 0xb3: UnimplementedInstruction(state); break;
		case 0xb4: UnimplementedInstruction(state); break;
		case 0xb5: UnimplementedInstruction(state); break;
		case 0xb6: UnimplementedInstruction(state); break;
		case 0xb7: UnimplementedInstruction(state); break;
		case 0xb8: UnimplementedInstruction(state); break;
		case 0xb9: UnimplementedInstruction(state); break;
		case 0xba: UnimplementedInstruction(state); break;
		case 0xbb: UnimplementedInstruction(state); break;
		case 0xbc: UnimplementedInstruction(state); break;
		case 0xbd: UnimplementedInstruction(state); break;
		case 0xbe: UnimplementedInstruction(state); break;
		case 0xbf: UnimplementedInstruction(state); break;
		case 0xc0: UnimplementedInstruction(state); break;
		case 0xc1: UnimplementedInstruction(state); break;
		case 0xc2:	// JNZ address
			{
				if (state->cc.z == 0)
				{
					state->pc = (opcode[2] << 8) | opcode[1];
				}
				else
				{
					state->pc += 2;
				}
				break;
			}
		case 0xc3:	// JMP address
			{
				state->pc = (opcode[2] << 8) | opcode[1];
				break;
			}
		case 0xc4: UnimplementedInstruction(state); break;
		case 0xc5: UnimplementedInstruction(state); break;
		case 0xc6:	// ADI byte
			{
				uint16_t answer = (uint16_t) state->a + (uint16_t) opcode[1];
				state->cc.z = ((answer & 0xff) == 0);
				state->cc.s = ((answer & 0x80) != 0);
				state->cc.cy = (answer > 0xff);
				state->cc.p = Parity(answer & 0xff);
				state->a = answer & 0xff;
			}
		case 0xc7: UnimplementedInstruction(state); break;
		case 0xc8: UnimplementedInstruction(state); break;
		case 0xc9:	// RET
			{
				state->pc = state->memory[state->sp] | (state->memory[state->sp+1] << 8);
				state->sp += 2;
				break;
			}
		case 0xca:	// JZ address
			{
				if (state->cc.z != 0)
				{
					state->pc = (opcode[2] << 8) | opcode[1];
				}
				else
				{
					state->pc += 2;
				}
				break;
			}
		case 0xcb: UnimplementedInstruction(state); break;
		case 0xcc: UnimplementedInstruction(state); break;
		case 0xcd:	// CALL address
			{
				uint16_t ret = state->pc+2;
				state->memory[state->sp-1] = (ret >> 8) & 0xff;
				state->memory[state->sp-2] = (ret & 0xff);
				state->sp = state->sp - 2;
				state->pc = (opcode[2] << 8) | opcode[1];
				break;
			}
		case 0xce: UnimplementedInstruction(state); break;
		case 0xcf: UnimplementedInstruction(state); break;
		case 0xd0: UnimplementedInstruction(state); break;
		case 0xd1: UnimplementedInstruction(state); break;
		case 0xd2:	// JNC address
			{
				if (state->cc.cy == 0)
				{
					state->pc = (opcode[2] << 8) | opcode[1];
				}
				else
				{
					state->pc += 2;
				}
				break;
			}
		case 0xd3: UnimplementedInstruction(state); break;
		case 0xd4: UnimplementedInstruction(state); break;
		case 0xd5: UnimplementedInstruction(state); break;
		case 0xd6:	// SUI address
			{
				uint16_t answer = (uint16_t) state->a - (uint16_t) opcode[1];
				state->cc.z = ((answer & 0xff) == 0);
				state->cc.s = ((answer & 0x80) != 0);
				state->cc.cy = (answer > 0xff);
				state->cc.p = Parity(answer & 0xff);
				state->a = answer & 0xff;
				break;
			}
		case 0xd7: UnimplementedInstruction(state); break;
		case 0xd8: UnimplementedInstruction(state); break;
		case 0xd9: UnimplementedInstruction(state); break;
		case 0xda:	// JC address
			{
				if (state->cc.cy != 0)
				{
					state->pc = (opcode[2] << 8) | opcode[1];
				}
				else
				{
					state->pc += 2;
				}
				break;
			}
		case 0xdb: UnimplementedInstruction(state); break;
		case 0xdc: UnimplementedInstruction(state); break;
		case 0xdd: UnimplementedInstruction(state); break;
		case 0xde: UnimplementedInstruction(state); break;
		case 0xdf: UnimplementedInstruction(state); break;
		case 0xe0: UnimplementedInstruction(state); break;
		case 0xe1: UnimplementedInstruction(state); break;
		case 0xe2: UnimplementedInstruction(state); break;
		case 0xe3: UnimplementedInstruction(state); break;
		case 0xe4: UnimplementedInstruction(state); break;
		case 0xe5: UnimplementedInstruction(state); break;
		case 0xe6: UnimplementedInstruction(state); break;
		case 0xe7: UnimplementedInstruction(state); break;
		case 0xe8: UnimplementedInstruction(state); break;
		case 0xe9: UnimplementedInstruction(state); break;
		case 0xea: UnimplementedInstruction(state); break;
		case 0xeb: UnimplementedInstruction(state); break;
		case 0xec: UnimplementedInstruction(state); break;
		case 0xed: UnimplementedInstruction(state); break;
		case 0xee: UnimplementedInstruction(state); break;
		case 0xef: UnimplementedInstruction(state); break;
		case 0xf0: UnimplementedInstruction(state); break;
		case 0xf1: UnimplementedInstruction(state); break;
		case 0xf2:	// JP address
			{
				if (state->cc.p == 1)
				{
					state->pc = (opcode[2] << 8) | opcode[1];
				}
				else
				{
					state->pc += 2;
				}
				break;
			}
		case 0xf3: UnimplementedInstruction(state); break;
		case 0xf4: UnimplementedInstruction(state); break;
		case 0xf5: UnimplementedInstruction(state); break;
		case 0xf6: UnimplementedInstruction(state); break;
		case 0xf7: UnimplementedInstruction(state); break;
		case 0xf8: UnimplementedInstruction(state); break;
		case 0xf9: UnimplementedInstruction(state); break;
		case 0xfa: UnimplementedInstruction(state); break;
		case 0xfb: UnimplementedInstruction(state); break;
		case 0xfc: UnimplementedInstruction(state); break;
		case 0xfd: UnimplementedInstruction(state); break;
		case 0xfe: UnimplementedInstruction(state); break;
		case 0xff: UnimplementedInstruction(state); break;
	}
	state->pc += 1;
}
