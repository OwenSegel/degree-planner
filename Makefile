CC = gcc
CFLAGS = -Wall -Werror -std=c17 -g
TARGET = planner

SRCS = src/main.c src/course.c src/check.c src/parse.c
HDRS = src/course.h src/check.h src/parse.h

$(TARGET): $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) -o $@ $(SRCS)

clean:
	rm -f $(TARGET)

.PHONY: clean
