all: compile link run

compile:
	g++ -I "C:\SFML-2.6.2\include" -c game.cpp -o game.o -O2
	g++ -I "C:\SFML-2.6.2\include" -c mainMenu.cpp -o mainMenu.o -O2

link:
	g++ -I "C:\SFML-2.6.2\include" .\game.o .\mainMenu.o -o game.exe -L "C:\SFML-2.6.2\lib" -lmingw32 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-main -O2

run: 
	./game.exe