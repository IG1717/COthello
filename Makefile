CC = clang
CFLAGS = -I./raylib/src -L./raylib/src -lraylib
FRAMEWORKS = -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL

SRCS = src/main.c src/board.c

game: $(SRCS)
	$(CC) $(SRCS) -o game $(CFLAGS) $(FRAMEWORKS)

clean:
	rm -f game