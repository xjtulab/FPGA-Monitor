CC=gcc
CFLGAS = -Wall -g 
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))
TARGET= ../monitor

$(TARGET):$(OBJ)
	$(CC) $(LDFLGAS) $^ -o $@

%.o:%.c
	$(CC) $(CFLGAS) -c  $< -o $@

.PHONY: clean
clean:
	@echo "clean all!"
	rm -rf $(OBJ) 
	rm -rf $(TARGET)