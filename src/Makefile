CPP_SHARED := -std=c++11 -O3 -shared -fPIC -I ../inc -I /usr/include -I /usr/local/include -I /usr/include/postgresql \
Base.cpp Bars.cpp File.cpp Json.cpp Title.cpp FuList.cpp ErrLog.cpp Daemon.cpp HubApi.cpp HubCtp.cpp HubSim.cpp HubBck.cpp MdCtp.cpp MdSpi.cpp MkSim.cpp Global.cpp TdFuBo.cpp \
ApiClient.cpp BitMap.cpp

LDFLAGS += -L/usr/local/lib `pkg-config --libs protobuf grpc++ grpc`\
           -Wl,--no-as-needed -lgrpc++_reflection -Wl,--as-needed\
           -ldl

default: exes

lib:
	make `(uname -s)`
Linux:
	$(CXX) $(CPP_SHARED) -s -o ../../u/lib/libuBEE.so

CC = g++
CPPFLAGS =  -std=c++11 -O3
CFLAGS =  -std=c++11 -O3 -fPIC  -luWS -lssl -lz -lpthread -lcjson -Wunused-result
LIBPATH = -L/home/riddle/uws -L ./ -L ../../u/lib
LINK =  $(CC)

ALLLIBS = -luBEE -luWS -lssl -lz -lpthread -lcjson  -lApiClient -luuid 

CTPLIBS:= ../ctp/thostmduserapi.so \
        ../ctp/thosttraderapi.so

EXE = ../../u/exe/

SRC = ../src/
INC = ../inc/
OBJ = ../../u/obj/

INCS = -I ../inc \
       -I /usr/include \
       -I /usr/local/include
#	   -I /usr/include/postgresql


exes: $(EXE)dserver.x \
	$(EXE)tqdata.x \
	$(EXE)fugen.x \
	$(EXE)wserver.x

DATASERVER:= \
	$(OBJ)Dataserver.o 

TQDATA:= \
	$(OBJ)Tqdata.o 

FUGEN:= \
    $(OBJ)FuGen.o

WEBSERVER:= \
	$(OBJ)Webserver.o 

$(EXE)dserver.x: $(DATASERVER)
	$(CC) $(CPPFLAGS) -o $(EXE)dserver.x $(DATASERVER) $(LIBPATH) $(ALLLIBS) $(CTPLIBS) $(LDFLAGS)

$(EXE)tqdata.x: $(TQDATA)
	$(CC) $(CPPFLAGS) -o $(EXE)tqdata.x $(TQDATA) $(LIBPATH) $(ALLLIBS) $(CTPLIBS) $(LDFLAGS)

$(EXE)fugen.x: $(FUGEN)
	$(CC) $(CPPFLAGS) -o $(EXE)fugen.x $(FUGEN) $(LIBPATH) $(ALLLIBS) $(CTPLIBS) $(LDFLAGS)

$(EXE)wserver.x: $(WEBSERVER)
	$(CC) $(CPPFLAGS) -o $(EXE)wserver.x $(WEBSERVER) $(LIBPATH) $(ALLLIBS) $(CTPLIBS) $(LDFLAGS)

$(OBJ)FuGen.o: $(SRC)FuGen.cpp
	$(CC) -c $(CPPFLAGS) $(INCS) -o $(OBJ)FuGen.o  $(SRC)FuGen.cpp

$(OBJ)Dataserver.o: $(SRC)Dataserver.cpp
	$(CC) -c $(CPPFLAGS) $(INCS) -o $(OBJ)Dataserver.o  $(SRC)Dataserver.cpp

$(OBJ)Tqdata.o: $(SRC)Tqdata.cpp
	$(CC) -c $(CPPFLAGS) $(INCS) -o $(OBJ)Tqdata.o  $(SRC)Tqdata.cpp

$(OBJ)Webserver.o: $(SRC)Webserver.cpp
	$(CC) -c $(CPPFLAGS) $(INCS) -o $(OBJ)Webserver.o  $(SRC)Webserver.cpp

