DATA SEGMENT
str1 db 'HI!$'
LENGTH EQU $-str1-1
DATA ENDS

ASSUME CS:CODE, DS:DATA

CODE SEGMENT
START:
MOV AX,SEG str1
MOV DS,AX
MOV SI, OFFSET 	str1
MOV CX, LENGTH
ADD SI, CX
DEC SI
AA:
MOV DL,[SI]
MOV AH, 02H
INT 21H
DEC SI
LOOP AA
MOV AX,4C00h
INT 21H
CODE ENDS
END START