CCC = clang
LEX = flex
CFLAGS = -Wall
LEXFLAGS = -Wno-unused

OBJS = lex.yy.o

engToLt: $(OBJS)
	$(CCC) $(CFLAGS) -ll -o run $(OBJS)

lex.yy.c: ltToEng.l
	$(LEX) ltToEng.l

lex.yy.o: lex.yy.c
	$(CCC) $(CFLAGS) $(LEXFLAGS) -c lex.yy.c
	
clean:
	rm -f run *.o lex.yy.c
