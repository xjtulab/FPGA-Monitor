SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))

all:fpga1 read_cpu read_proc sysinfo priority

fpga1: fpga1.o
	$(CC) $^ -o $@

read_cpu: read_cpu.o
	$(CC) $^ -o $@

read_proc: read_proc.o
	$(CC) $^ -o $@

sysinfo: sysinfo.o
	$(CC) $^ -o $@

priority: priority.o
	$(CC) $^ -o $@

%.o:%.c
	$(CC) $(CFLGAS) -c  $< -o $@

.PHONY: clean
clean:
	@echo "clean all!"
	rm -rf $(OBJ) 
	rm -rf fpga1 read_cpu read_proc sysinfo