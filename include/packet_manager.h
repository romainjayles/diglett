#ifndef _packet_manager_h
#define _packet_manager_h

//#include <stdint.h>
#include <pthread.h>

struct packet_manager_st {
    pthread_t pm_thread;
};

int init_packet_manager(struct packet_manager_st *pm_handler);

int close_packet_manager(struct packet_manager_st *pm_handler);

#endif
