all: 
	g++ -I dependencies/include -L dependencies/lib -o a src/main.cpp -lmingw32 -lSDL2main -lSDL2