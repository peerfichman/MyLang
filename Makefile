
all: lang

word.o: word.cpp word.h
	g++ -g -c word.cpp -o word.o

sentence.o: sentence.cpp sentence.h
	g++ -g -c sentence.cpp -o sentence.o


literal.o: literal.cpp literal.h
	g++ -c literal.cpp -o literal.o

clean:
	rm *.tab.hpp *.tab.cpp  lex.yy.c *.o lang

lex.yy.c: mylang2cpp.lex
	flex  mylang2cpp.lex

mylang2cpp.tab.cpp: mylang2cpp.ypp
	bison -d  mylang2cpp.ypp

lang: lex.yy.c mylang2cpp.tab.cpp word.o sentence.o literal.o
	g++ -g literal.o lex.yy.c mylang2cpp.tab.cpp word.o sentence.o  -o lang

mylang : word.o sentence.o	mylang.cpp
	g++ -g mylang.cpp word.o sentence.o -o mylang.exe