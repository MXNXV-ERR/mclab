	AREA AVG16BIT,CODE
	LDR R0,=NOS
	MOV R1,#4 ;Put #9 if 10 numbers are asked
	LDRH R2,[R0],#2
NEXT
	LDRH R3,[R0],#2
	ADD R2,R2,R3
	SUBS R1,R1,#1
	BNE NEXT
	MOV R1,#10
	MOV R4,#0	;avg
DIVIDE
	SUBS R2,R2,R1
	ADDPL R4,R4,#1
	BPL DIVIDE
	ldr r0, =AVG
	STRH R4,[R0]
NOS dcw 0x500, 0x400, 0x300, 0x200, 0x100 ;Enter ten numbers here
GO	B GO
	AREA NUMBER,DATA
;NOS space 20
AVG dcw 0
	END
