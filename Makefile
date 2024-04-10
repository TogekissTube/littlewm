all: build

build:
	gcc src/main.c -o main -Wall -Wextra -std=c17 -lX11
