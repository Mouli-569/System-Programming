#compiler
GPP = g++
#compiler flags
CFLAG = -g -Wall
#output flag
OFLAG = -o
#binary file directory
BIN = ../bin
#source file directory
SRC = ../src
#object file directory
OBJ = ../obj
#header file directory
INC = ../inc
IFLAG = -I $(INC)

all: build-client build-server

build-client: build-client-obj 
	$(GPP) $(IFLAG) $(CFLAG) $(OFLAG) $(BIN)/client $(SRC)/clientMain.cpp $(OBJ)/client.o

build-server: build-server-obj
	$(GPP) $(IFLAG) $(CFLAG) $(OFLAG) $(BIN)/server $(SRC)/serverMain.cpp $(OBJ)/server.o

build-server-obj: $(SRC)/server.cpp
	$(GPP) $(IFLAG) -c $(SRC)/server.cpp $(OFLAG) $(OBJ)/server.o

build-client-obj: $(SRC)/client.cpp
	$(GPP) $(IFLAG) -c $(SRC)/client.cpp $(OFLAG) $(OBJ)/client.o

server: 
	$(BIN)/server

client:
	$(BIN)/client

clean:
	rm $(OBJ)/server.o $(OBJ)/client.o $(BIN)/server $(BIN)/client
