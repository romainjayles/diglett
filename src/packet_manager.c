#include "../include/packet_manager.h"
#include "../include/common.h"

int init_packet_manager(struct packet_manager_st *pm_handle){
	return ERROR_OK;
}

int close_packet_manager(struct packet_manager_st *pm_handle){
	pthread_join(pm_handle->pm_thread ,NULL);
	return ERROR_OK;
}
