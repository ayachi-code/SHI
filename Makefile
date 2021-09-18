build: src/encrpytion.o src/usefull.o src/bn.o
	gcc src/encrpytion.o src/usefull.o src/bn.o -o output

$(src)/encrpytion.o: encrpytion.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(src)/usefull.o: usefull.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(src)/bn.o: bn.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	rm src/*.o output