CPP = g++ # c++ compiler
OUTPUT = Block-Game.exe # output file
LIBS = -lSDL2main -lSDL2 # libraries
SRC = src/main.cpp src/block.cpp src/Renderer.cpp # source files

all:
	$(CPP) $(CPPFLAGS) -o $(OUTPUT) $(SRC) $(LIBS)

clean:
	rm $(OUTPUT)
