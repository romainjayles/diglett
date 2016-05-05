
#include "../include/listener.h"
#include "../include/common.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


#include <arpa/inet.h>
#include <net/if.h>
#include <pthread.h>
#include <sys/socket.h>
#include <net/ethernet.h>


#define MAX_RCVFROM_BUFFER 2048

//divide in init_socket and init_thread ?


int init_listener(const char *interface_name, struct listener_handle_st *handle) {

    struct ifreq ifr;
    int error_code, fd, sockopt;
    /* We set the ifreq structure */
    memset(&ifr, 0, sizeof(ifr));
    strncpy(ifr.ifr_name, interface_name, strlen(ifr.ifr_name));
    strncpy(handle->interface_name, interface_name, sizeof(handle->interface_name));


    /*
     * AF_PACKET = low level packet interface
     * SOCK_RAW = raw network protocol access
     */
    print_log(info, "Oppening the socket\n");
    fd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if(fd < 0) {
        print_log(error, "Impossible to open the socket\n");
        return ERROR_IMPOSSIBLE_TO_OPEN_SOCKET;
    }
    handle->sock_fd = fd;
    print_log(info, "Socket oppened\n");

    /* Reuse*/
    error_code = setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &sockopt, sizeof sockopt);
    if(error_code != 0) {
        //TODO
        return ERROR_UNDEFINED;
    }

    /*
     * Binding the socket to the interface
     * SOL_SOCKET = options manipulate at the socket API level
     * BINDTODEVICE =
     */
    error_code = setsockopt(fd, SOL_SOCKET, SO_BINDTODEVICE, (void *)&ifr, sizeof(ifr));
    if(error_code != 0) {
        print_log(error, "Impossible to set option on socket/n");
        return ERROR_UNDEFINED;
    }
    print_log(info, "Option set on socket\n");
    print_log(info, "Launching the collector loop\n");
    //TODO : check if pthread attribute should be null ?
    //Launching the listener loop
    error_code = pthread_create(&handle->listener_thread, NULL, collector_loop, (void*) &(handle->sock_fd));
    //collector_loop(&fd);

    //TODO : The return number should be different
    if(error_code != 0) {
        print_log(error, "Impossible to create the listener thread\n");
        return ERROR_UNDEFINED;
    }



}

int close_listener(struct listener_handle_st *handle) {
    pthread_join(handle->listener_thread ,NULL);
    if(close(handle->sock_fd) != 0) {
        return ERROR_IMPOSSIBLE_TO_CLOSE_SOCKET;
    }
}

/*
 * Allow to treat a packed as received by the socket
 */
//TODO : should be done by packet_manager ?
int _treat_raw_packet(struct packet_st packet) {
}

void* collector_loop(void* arg) {
    struct packet_st packet;
    int fd = *((int*)(arg));
    int receive_sz, i;
    uint8_t receive_buffer[MAX_RCVFROM_BUFFER];

    while(1) {
        receive_sz = recvfrom(fd, receive_buffer, MAX_RCVFROM_BUFFER, 0, NULL, NULL);
        printf("listener: got packet %i bytes\n", receive_sz);
        for(i=0; i < receive_sz; i++) {
            printf("%02x:", receive_buffer[i]);
        }
    }

}
