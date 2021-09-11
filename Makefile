# output: encryption.o
# 	gcc src/encryption.o -o output
build: kaas/foo.o
	gcc kaas/foo.o -o output

$(kaas)/foo.o: foo.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

# $(kaas)/foo.o: foo.c
# 	gcc foo.c


# encryption.o: src/encrpytion.c
# 	gcc -c src/encrpytion.c

# usefull.o: src/usefull.c includes/usefull.h
# 	gcc -c src/usefull.c