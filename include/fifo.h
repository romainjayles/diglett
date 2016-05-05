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
void add_last(char *buffer, struct fifo_element *first);

/*
 * Get first : Allow to retrieve the first element in the fifo and suppress it from the fifo
 * @buffer[out] : the datas to store in the fifo
 * @size[out] : the size of the datas
 * @fifo[inout] : the pointer on the first element(pointer). Will be modified
 * @return ERROR_EMPTY if empty
 */
int get_first(char *buffer, struct fifo_element **fifo);

#endif
