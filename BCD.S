	AREA BCD,CODE
	LDR R0,=num
	MOV R1,#0		; hex/binary
	MOV R2,#0XF0
	MOV R3,#0X0F
	MOV R4,#4
	MOV R8,#10

	ADD R0,R4
	SUB R0,R0,#1
NEXT_BYTE
	LDRB R5,[R0], #-1
	AND R6,R5,R2
	LSR R6,#4
	AND R7,R5,R3
	MUL R1,R8,R1
	ADD R1,R1,R6
	MUL R1,r8,r1
	ADD R1,R1,R7
	SUBS R4,R4,#1
	BNE NEXT_BYTE
GO  BAL GO

num DCD 0x127 ;Here we store the number as hex but consider it
			  ;in decimal so deci(127)->hex(7F)
			  ;Find 7F in R1

	END
	
	