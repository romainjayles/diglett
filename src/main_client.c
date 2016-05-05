#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#include "../include/listener.h"
#include "../include/fifo.h"
#include "../include/common.h"

void print_help();

void test_fifo(){
	struct fifo_element *fifo;
	add_last("hey", &fifo);
}

int main(int argc, char **argv) {
    int error_code;
    struct listener_handle_st listener_handle;
    set_log_level(debug);
    error_code = init("wlan0", &listener_handle);
    if(error_code != ERROR_OK) {
        print_log_error(error, "Init returned", error_code);
        return -1;
    }
    test_fifo();
    pthread_join(listener_handle.listener_thread ,NULL);
    return 0;
}


void print_help() {
    printf("Help");
}
