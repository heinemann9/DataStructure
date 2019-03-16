CFLAGS= -Wall -c

all: malloc matrix matrix_2 Point polynomial_1 polynomial_2 SimpleLinkedList stack_link stack_test1 stack_test2 stack_test3 structure text_editor LinkedRead func_pointer arraylist_ADT all_c
	@echo "Done"

malloc: malloc.o
	gcc -o $@ $<
matrix: matrix.o
	gcc -o $@ $<
matrix_2: matrix_2.o
	gcc -o $@ $<
Point: Point.o
	gcc -o $@ $< -lm
polynomial_1: polynomial_1.o
	gcc -o $@ $<
polynomial_2: polynomial_2.o
	gcc -o $@ $<
SimpleLinkedList: SimpleLinkedList.o
	gcc -o $@ $<
stack_link: stack_link.o
	gcc -o $@ $<
stack_test1: stack_test1.o
	gcc -o $@ $<
stack_test2: stack_test2.o
	gcc -o $@ $<
stack_test3: stack_test3.o
	gcc -o $@ $<
structure: structure.o
	gcc -o $@ $<
text_editor: text_editor.o
	gcc -o $@ $<
LinkedRead: LinkedRead.o
	gcc -o $@ $<
func_pointer: func_pointer.o
	gcc -o $@ $<
arraylist_ADT: arraylist_ADT.o
	gcc -o $@ $<
all_c: all.o
	gcc -o $@ $<

%.o: %.c
	gcc $(CFLAGS) $<
