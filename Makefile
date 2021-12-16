CC=gcc
CFLGAS = -Wall -g 
SUBDIRS = src test subproc

all:$(SUBDIRS)
	@for dir in $(SUBDIRS); \
	do						\
		make -C $$dir;		\
	done;

.PHONY: clean
clean:$(SUBDIRS)
	@for dir in $(SUBDIRS); \
	do						\
		make -C $$dir clean;		\
	done;