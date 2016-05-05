#ifndef _fifo_h_
#define _fifo_h_

#include <stdint.h>

/*
 * The Fifo structure
 */
struct fifo_element {
	struct fifo_element *next; /* A pointer to the next structure or null if the end */
    char *string; /* The value as retrieved by the listener */
    //int size; /* The size of the value array */
};

/* 
 * The fifo structure.
 * Pointer on last is here to keep track of the last element and fasten the insertion in last position
 */
struct fifo_st{
	struct fifo_element *first;
	struct fifo_element *last;
};

void print_fifo(struct fifo_st *fifo);


/*
 * Allow to init the fifo
 * @return : a pointer on the first element
 */
struct fifo_element init_fifo();

/*
 * Allow to add an element in the last position of the fifo
 * @buffer[in] : A buffer containing the datas
 * @size[in] : the total size of datas contained in the buffer
 * @first[in] : the first element of the fifo
 */
void add_last(char *buffer, struct fifo_st *fifo);

/*
 * Get first : Allow to retrieve the first element in the fifo and suppress it from the fifo
 * @buffer[out] : the datas to store in the fifo
 * @size[out] : the size of the datas
 * @fifo[inout] : the pointer on the first element(pointer). Will be modified
 * @return ERROR_EMPTY if empty
 */
int get_first(struct fifo_element *dest, struct fifo_st *fifo);

void free_fifo(struct fifo_st *fifo);

#endif
