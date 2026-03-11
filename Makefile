CC = clang
CFLAGS = -I./raylib/src -L./raylib/src -lraylib
FRAMEWORKS = -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL

game: src/main.c
	$(CC) src/main.c -o game $(CFLAGS) $(FRAMEWORKS)

clean:
	rm -f game