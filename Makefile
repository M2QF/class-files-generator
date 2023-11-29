CC=g++

ifeq ($(RELEASE), true)
	CFLAGS=-O3 -s
else
	CFLAGS=-g -Wall -Wextra
endif

ifeq ($(DEBUG), true)
	CFLAGS+=-DDEBUG
endif

bin/class-file-generator: obj/class-file-generator.o obj/filewriter.o obj/headerwriter.o obj/corewriter.o
	$(CC) $(CFLAGS) -o $@ $^

obj/class-file-generator.o: src/class-file-generator.cpp src/filewriter.h src/headerwriter.h src/corewriter.h
	$(CC) $(CFLAGS) -c -o $@ $<

obj/filewriter.o: src/filewriter.cpp src/filewriter.h
	$(CC) $(CFLAGS) -c -o $@ $<

obj/headerwriter.o: src/headerwriter.cpp src/headerwriter.h
	$(CC) $(CFLAGS) -c -o $@ $<

obj/corewriter.o: src/corewriter.cpp src/corewriter.h
	$(CC) $(CFLAGS) -c -o $@ $<