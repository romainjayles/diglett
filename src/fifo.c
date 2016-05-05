#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/fifo.h"
#include "../include/common.h"

struct fifo_element init_fifo() {
}

void print_fifo(struct fifo_st *fifo) {
    struct fifo_element *current = fifo->first;
    int i = 0;
    printf("------ Printing fifo ------\n");
    while(current != NULL) {
        printf("%i - %s\n", i, current->string);
        current = current->next;
        i++;
    }
    printf("---------------------------\n\n");
}

void add_last(char *buffer, struct fifo_st *fifo) {
    // Creation of the new element
    struct fifo_element *new_element = malloc(sizeof(struct fifo_st));
    new_element->string = malloc(strlen(buffer)+1);
    new_element->next = NULL;
    strcpy(new_element->string, buffer);
    // If this is the first element
    if(fifo->first == NULL) {
        //The only element will be this new element
        fifo->first = new_element;
        fifo->last = new_element;
        // If not
    } else {
        //Adding the new to the next of the previous last
        fifo->last->next = new_element;
        //Fixing the new last to the new element
        fifo->last = new_element;
    }
}

int get_first(struct fifo_element *dest, struct fifo_st *fifo) {
	struct fifo_element *old_fist;
	//If the fifo is empty
	if(fifo->first == NULL){
		return ERROR_EMPTY;
	//If not
	}else{
		// We copy the content of the first element to the destination
		//TODO : have to be remove in further vesions.
		free(dest->string);
		memcpy(dest, fifo->first, sizeof(*dest));
		old_fist = fifo->first;
		// If this was the last element
		if(fifo->first->next == NULL){
			fifo->first = NULL;
			fifo->last = NULL;
		}else{
			fifo->first = fifo->first->next;
		}
		free(old_fist);
	}
	return ERROR_OK;
    
}


void free_fifo(struct fifo_st *fifo){
	struct fifo_element *current = fifo->first;
	struct fifo_element *old_current;
    while(current != NULL) {
        free(current->string);
        old_current = current;
        current = current->next;
        free(old_current);
        
    }
}

