all: 
	g++ -I dependencies/include -L dependencies/lib -o Block_Game src/main.cpp -lmingw32 -lSDL2main -lSDL2