CC=g++

ifeq ($(RELEASE), true)
	CFLAGS=-O3 -s -std=c++2a
else
	CFLAGS=-g -Wall -Wextra -std=c++2a
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

clean_obj :
	rm -f -v obj/*.o

clean_bin :
	rm -f -v bin/class-files-generator

clean :
	make clean_obj
	make clean_bin

release :
	make clean
	make RELEASE=true
	make clean_obj
