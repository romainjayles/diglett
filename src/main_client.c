#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#include "../include/listener.h"
#include "../include/packet_manager.h"
#include "../include/fifo.h"
#include "../include/common.h"

void print_help();

//TODO : move test to test folder
void test_fifo();


//TODO : add macro for error checking ?
int main(int argc, char **argv) {
    int error_code;
    struct listener_handle_st listener_handle;
    struct packet_manager_st pm_handle;
    set_log_level(debug);
    /*test_fifo();
    return 0;*/

    /* Initialisation of the listener thread */
    error_code = init_listener("wlan0", &listener_handle);
    if(error_code != ERROR_OK) {
        print_log_error(error, "Init of listener returned", error_code);
        return -1;
    }

    /* Initialisation of the listener thread */
    error_code = init_packet_manager(&pm_handle);
    if(error_code != ERROR_OK) {
        print_log_error(error, "Init of packet_manager returned", error_code);
        return -1;
    }

    close_listener(&listener_handle);
    close_packet_manager(&pm_handle);
    return 0;
}


void print_help() {
    printf("Help");
}

//TODO : move to test/
void test_fifo() {
    struct fifo_st fifo;
    struct fifo_element container;
    memset(&fifo, 0, sizeof(fifo));
    print_fifo(&fifo);
    add_last("hey", &fifo);
    print_fifo(&fifo);
    add_last("ho", &fifo);
    print_fifo(&fifo);
    add_last("la gauche", &fifo);
    print_fifo(&fifo);
    printf("Returned : %i\n", get_first(&container, &fifo));
    printf("Got : %s\n", container.string);
    print_fifo(&fifo);
    printf("Returned : %i\n", get_first(&container, &fifo));
    printf("Got : %s\n", container.string);
    print_fifo(&fifo);
    printf("Returned : %i\n", get_first(&container, &fifo));
    printf("Got : %s\n", container.string);
    print_fifo(&fifo);
    printf("Returned : %i\n", get_first(&container, &fifo));
    printf("Got : %s\n", container.string);
    print_fifo(&fifo);
    printf("Returned : %i\n", get_first(&container, &fifo));
    printf("Got : %s\n", container.string);
    print_fifo(&fifo);
    print_fifo(&fifo);
    add_last("a", &fifo);
    print_fifo(&fifo);
    add_last("b", &fifo);
    print_fifo(&fifo);
    add_last("c", &fifo);
    print_fifo(&fifo);
    add_last("d", &fifo);
    print_fifo(&fifo);
    printf("Returned : %i\n", get_first(&container, &fifo));
    printf("Got : %s\n", container.string);
    print_fifo(&fifo);
    printf("Returned : %i\n", get_first(&container, &fifo));
    printf("Got : %s\n", container.string);
    print_fifo(&fifo);
    add_last("e", &fifo);
    print_fifo(&fifo);
    add_last("f", &fifo);
    print_fifo(&fifo);
    printf("Returned : %i\n", get_first(&container, &fifo));
    printf("Got : %s\n", container.string);
    print_fifo(&fifo);
    free_fifo(&fifo);
}
