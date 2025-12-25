
CC=gcc -ansi -Wall -Wextra -Wpedantic -O2
C=$(shell find . -name "*.c")
OUT=adoc2html
LNK=
TESTING=ex/basic.adoc

build:
	@$(CC) -o $(OUT) $(C) $(LNK)

dbuild:
	@$(CC) -o $(OUT) $(C) $(LNK) -g

clean:
	@if [ -f $(OUT) ]; then rm $(OUT); fi

exec:
	@./$(OUT) $(TESTING)

