
OEIHOME = ../oei
OEIARCH = armv7Linux4gcc7.5.0.cortex-a9
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))
CFLGAS = -Wall -g -pthread
TARGET= ../fpga_monitor
LDPREFIX = -static-libgcc
LDFLGAS = -L$(OEIHOME)/lib/${OEIARCH} -pthread -ldl -lnsl -lm -lrt \
	-loei_rhsmz -loei_whsmz -loei_discdpdez -loeiz

DEFINES = -DOEI_UNIX -DOEI_LINUX -DOEI_POSIX_THREADS
INCLUDES =  -I. -I$(OEIHOME)/include

$(TARGET):$(OBJ)
	$(CC) $(LDPREFIX) -o $@  $^ $(LDFLGAS)

%.o:%.c
	$(CC) $(CFLGAS) $(INCLUDES) $(DEFINES) -c  $< -o $@

.PHONY: clean
clean:
	@echo "clean all!"
	rm -rf $(OBJ) 
	rm -rf $(TARGET)