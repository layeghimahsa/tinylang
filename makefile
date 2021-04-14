
parser.tab.c parser.tab.h: parser.y
	bison -d parser.y

lex.yy.c: scanner.l parser.tab.h
	flex scanner.l

main: main.c parser.tab.c lex.yy.c interpreter.c
	gcc main.c lex.yy.c parser.tab.c interpreter.c -o a.exe



#TARGET TO GENERATE ALL THE EXECUTABLES (MAIN PROGRAM + TESTS TOGETHER)
all: main

#CLEAN COMMANDS
clean: 
	rm main parser.tab.c lex.yy.c parser.tab.h
	
	
