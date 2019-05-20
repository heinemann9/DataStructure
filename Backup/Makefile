CC=gcc
CFLAGS= -w -c
LDLIBS= -lm

c_all: malloc matrix matrix_2 Point polynomial_1 polynomial_2 SimpleLinkedList stack_link stack_test1 stack_test2 stack_test3 structure text_editor LinkedRead func_pointer arraylist_ADT all
	@echo "Done"

malloc: malloc.o
	$(CC) -o $@ $<
matrix: matrix.o
	$(CC) -o $@ $<
matrix_2: matrix_2.o
	$(CC) -o $@ $<
Point: Point.o
	$(CC) -o $@ $< $(LDLIBS)
polynomial_1: polynomial_1.o
	$(CC) -o $@ $<
polynomial_2: polynomial_2.o
	$(CC) -o $@ $<
SimpleLinkedList: SimpleLinkedList.o
	$(CC) -o $@ $<
stack_link: stack_link.o
	$(CC) -o $@ $<
stack_test1: stack_test1.o
	$(CC) -o $@ $<
stack_test2: stack_test2.o
	$(CC) -o $@ $<
stack_test3: stack_test3.o
	$(CC) -o $@ $<
structure: structure.o
	$(CC) -o $@ $<
text_editor: text_editor.o
	$(CC) -o $@ $<
LinkedRead: LinkedRead.o
	$(CC) -o $@ $<
func_pointer: func_pointer.o
	$(CC) -o $@ $<
arraylist_ADT: arraylist_ADT.o
	$(CC) -o $@ $<
all: all.o
	$(CC) -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) $<

clean:
	rm -f *.o
	rm -f malloc matrix matrix_2 Point polynomial_1 polynomial_2 SimpleLinkedList stack_link stack_test1 stack_test2 stack_test3 structure text_editor LinkedRead func_pointer arraylist_ADT all
