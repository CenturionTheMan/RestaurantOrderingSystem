all: run

run: main.exe
	./main.exe

main.exe: clear
	g++ ./Code/main.cpp -o main.exe -g ./Code/Implementations/*.cpp -lncurses

clear:
	rm -f main.exe