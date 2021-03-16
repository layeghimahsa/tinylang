CC=gcc


parser.tab.c: parser.y
	bison -d parser.y

lex.yy.c: scanner.l
	flex scanner.l

main: parser.tab.c lex.yy.c 
	$(CC) -o main parser.tab.c lex.yy.c  



#TARGET TO GENERATE ALL THE EXECUTABLES (MAIN PROGRAM + TESTS TOGETHER)
all: main

#CLEAN COMMANDS
clean: 
	rm main parser.tab.c lex.yy.c parser.tab.h
	
	
