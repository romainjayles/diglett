#ifndef _routing_h_
#define _routing_h

#include <pthread.h>

#define MAX_SIZE_INTERFACE_NAME 10

struct listener_handle_st{
	int sock_fd;
	pthread_t listener_thread;
	char interface_name[MAX_SIZE_INTERFACE_NAME];
};


/* Initialise the listener */
int init(const char *interface_name, struct listener_handle_st *handle);

/* Collect the datas */
void* collector_loop(void* arg);

int close(struct listener_handle_st *handle);



#endif
