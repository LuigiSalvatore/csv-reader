APPLICATIVO = Manip_CSV
CMD_RM = del #rf -f
CFLAGS = -c -std=c++11 -DMESSAGE
#NAME = "main copy"
DASHOES = main.o ListaDeDatas.o ListaRua.o Funcs.o ListaPlaca.o

all:			${APPLICATIVO}

${APPLICATIVO}:	${DASHOES}
	g++ -o ${APPLICATIVO} ${DASHOES}

main.o:			main.cpp ListaDeDatas.cpp ListaDeDatas.hpp ListaRua.cpp ListaRua.hpp Funcs.cpp Funcs.hpp ListaPlaca.cpp ListaPlaca.hpp
	g++ ${CFLAGS} main.cpp

ListaRua.o:		ListaRua.cpp ListaRua.hpp ListaPlaca.cpp ListaPlaca.hpp ListaDeDatas.cpp ListaDeDatas.hpp 
	g++ ${CFLAGS} ListaRua.cpp
	
ListaPlaca.o:	ListaPlaca.cpp ListaPlaca.hpp
	g++ ${CFLAGS} ListaPlaca.cpp

Funcs.o:		Funcs.cpp Funcs.hpp 
	g++ ${CFLAGS} Funcs.cpp
	
ListaDeDatas.o:	ListaDeDatas.cpp ListaDeDatas.hpp 
	g++ ${CFLAGS} ListaDeDatas.cpp

run:			${APPLICATIVO} 
	./${APPLICATIVO}

clean: 			
	${CMD_RM} *.o ${APPLICATIVO}
	
