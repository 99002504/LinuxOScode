TARGET=all.out
$(TARGET):test.o factorial.o isPrime.o isPalindrome.o flip.o reset.o strcomp.o set.o strlen.o strcopy.o vsum.o
	gcc test.o factorial.o isPrime.o isPalindrome.o flip.o reset.o strcomp.o set.o strlen.o strcopy.o vsum.o -o alll.out
	 
test.o: test.c bitmask.h mystring.h myutils.h
	gcc test.c -c
factorial.o: factorial.c myutils.h
	gcc factorial.c -c
isPrime.o: isPrime.c myutils.h
	gcc isPrime.c -c
isPalindrome.o: isPalindrome.c myutils.h
	gcc isPalindrome.c -c
flip.o: flip.c bitmask.h
	gcc flip.c -c
reset.o: reset.c bitmask.h
	gcc reset.c -c
strcomp.o: strcomp.c mystring.h
	gcc strcomp.c -c
set.o: set.c bitmask.h
	gcc set.c -c
strlen.o: strlen.c mystring.h
	gcc strlen.c -c
strcopy.o: strcopy.c mystring.h
	gcc strcopy.c -c 
vsum.o: vsum.c myutils.h
	gcc vsum.c -c

