SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))

all:fpga1 fpga2 fpga3 fpga4

fpga1: fpga1.o
	$(CC) $^ -o $@
fpga2: fpga2.o
	$(CC) $^ -o $@
fpga3: fpga3.o
	$(CC) $^ -o $@
fpga4: fpga4.o
	$(CC) $^ -o $@

%.o:%.c
	$(CC) $(CFLGAS) -c  $< -o $@

.PHONY: clean
clean:
	rm -rf $(OBJ) 
	rm -rf fpga1 fpga2 fpga3 fpga4