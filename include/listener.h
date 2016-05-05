#ifndef _routing_h_
#define _routing_h

#include <stdint.h>
#include <pthread.h>

#define MAX_SIZE_INTERFACE_NAME 10


struct listener_handle_st{
    int sock_fd;
    pthread_t listener_thread;
    char interface_name[MAX_SIZE_INTERFACE_NAME];

};

//TODO : should be in a different file ?
struct packet_st{
	uint8_t* complete_buffer;
	struct ether_header *ethernet_header;
	struct iphdr *ip;
	struct udphdr *udp;
};


/* Initialise the listener */
int init(const char *interface_name, struct listener_handle_st *handle);

/* Collect the datas */
void* collector_loop(void* arg);

/* Treat raw packet */
int _treat_raw_packet(struct packet_st packet);

/* Terminate the listener */
int close(struct listener_handle_st *handle);



#endif
