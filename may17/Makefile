cc = g++
BIN = bin/
OBJ = obj/
INC = include/
SRC = src/
CFLAG = -c
OFLAG = -o
all:clean build-server build-client

build-server: ${OBJ}func.o
	${cc} ${OFLAG} ${BIN}server29 ${SRC}server.cpp ${OBJ}func.o
${OBJ}func.o:
	${cc} ${CFLAG} ${OFLAG} ${OBJ}func.o ${SRC}func.cpp

build-client:
	${cc} ${OFLAG} ${BIN}client29 ${SRC}client.cpp

start-server:
	./${BIN}server29
start-client:
	./${BIN}client29
clean:
	rm ${OBJ}func.o 
	rm ${BIN}client29
	rm ${BIN}server29
