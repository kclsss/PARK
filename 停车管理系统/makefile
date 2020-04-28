main:main.o project.o
	gcc -g main.o project.o -o main
main.o:main.c project.h
	gcc -g -c main.c -o main.o
seqList.o:project.c project.h
	gcc -g -c project.c -o project.o
clean:
	rm -fr *.o
	rm -fr main
