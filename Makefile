CC=g++

ifeq ($(RELEASE), true)
	CFLAGS=-O3 -s
else
	CFLAGS=-g -Wall -Wextra
endif

ifeq ($(DEBUG), true)
	CFLAGS+=-DDEBUG
endif

bin/class-files-generator: obj/class-files-generator.o obj/filewriter.o obj/headerwriter.o obj/corewriter.o
	$(CC) $(CFLAGS) -o $@ $^

obj/class-files-generator.o: class-files-generator.cpp filewriter.h headerwriter.h corewriter.h
	$(CC) $(CFLAGS) -c -o $@ $<

obj/filewriter.o: filewriter.cpp filewriter.h
	$(CC) $(CFLAGS) -c -o $@ $<

obj/headerwriter.o: headerwriter.cpp headerwriter.h
	$(CC) $(CFLAGS) -c -o $@ $<

obj/corewriter.o: corewriter.cpp corewriter.h
	$(CC) $(CFLAGS) -c -o $@ $<
