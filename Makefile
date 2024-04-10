all: build

build:
	gcc src/main.c -o littlewm -Wall -Wextra -std=c17 -lX11
