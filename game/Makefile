APPNAME:=$(shell basename `pwd`)

LDFLAGS:= -L../raylib/src -lm -lraylib -pthread -lopengl32 -lgdi32 -lwinmm -mwindows

CFLAGS:= -g -Wfatal-errors -pedantic -Wall -Wextra -Werror
CFLAGS+= -std=c99 -I ./include -I ../raylib/src

SRC:=$(wildcard src/*.c)
OBJ:=$(SRC:src/%.c=obj/%.o)

CC=x86_64-w64-mingw32-gcc

$(APPNAME).exe: $(OBJ)
	$(CC) $(OBJ) -o $(APPNAME).exe $(LDFLAGS)

$(OBJ): obj/%.o : src/%.c
	$(CC) $(CFLAGS) -c $< -o $@
