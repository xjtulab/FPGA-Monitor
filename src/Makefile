
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))
CFLGAS = -Wall -g -pthread
TARGET= ../fpga_monitor
LDFLGAS = -pthread

$(TARGET):$(OBJ)
	$(CC) $(LDFLGAS) $^ -o $@

%.o:%.c
	$(CC) $(CFLGAS) -c  $< -o $@

.PHONY: clean
clean:
	@echo "clean all!"
	rm -rf $(OBJ) 
	rm -rf $(TARGET)