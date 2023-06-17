CPP = g++ # c++ compiler
CPPFLAGS = -I dependencies/include -L dependencies/lib # include paths
OUTPUT = a.exe # output file
LIBS = -lmingw32 -lSDL2main -lSDL2 # libraries
SRC = src/main.cpp src/Block.cpp src/Renderer.cpp # source files

all:
	$(CPP) $(CPPFLAGS) -o $(OUTPUT) $(SRC) $(LIBS)

clean:
	$(RM) a.exe