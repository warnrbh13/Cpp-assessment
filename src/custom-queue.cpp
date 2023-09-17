#include "custom-queue.h"
#include <cstdio>

CustomQueue::CustomQueue() {}

void CustomQueue::enqueue(ClientRequest& client_request) {
    if(_clients_count + _servers_count > MAX_SIZE) {printf("[Error] Max size reached\n");}
    QueueElement* new_element = new QueueElement(client_request);
    if(_queue_size == size_t{}) {
        _front = new_element;
        _top = new_element;
    }
    else {
        _top->next = new_element;
        _top = new_element;
    }
    ++_clients_count;
    ++_queue_size;
}

void CustomQueue::enqueue(ServerResponse& server_response) {
    if(_clients_count + _servers_count > MAX_SIZE) {
        printf("[Error] Max size reached\n");
        return;
    }

    QueueElement* new_element = new QueueElement(server_response);
    if(_queue_size == size_t{}) {
        _front = new_element;
        _top = new_element;
    }
    else {
        _top->next = new_element;
        _top = new_element;
    }
    ++_servers_count;
    ++_queue_size;
}

void CustomQueue::deque() {
}