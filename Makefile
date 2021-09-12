build: src/encrpytion.o src/usefull.o
	gcc src/encrpytion.o src/usefull.o -o output

$(src)/encrpytion.o: encrpytion.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(src)/usefull.o: usefull.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	rm src/*.o output