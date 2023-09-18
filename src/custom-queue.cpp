#include "custom-queue.h"
#include <cstdio>

CustomQueue::CustomQueue() {}
CustomQueue::~CustomQueue() {}

void CustomQueue::enqueue(ClientRequest& client_request) {
    printf("[%s]", __func__);
    if(_clients_count + _servers_count > MAX_SIZE) {
        printf("[Error] Max size reached\n");
        return;
    }

    Node* new_node = new Node(CLIENT, &client_request, nullptr);
    if(_queue_size == size_t{}) {
        _front  = new_node, _top = new_node;
    }
    else {
        _top->_next = new_node;
    }
    ++_clients_count;
    ++_queue_size;
}

void CustomQueue::enqueue(ServerResponse& server_response) {
    printf("[%s]", __func__);
    if(_clients_count + _servers_count > MAX_SIZE) {
        printf("[Error] Max size reached\n");
        return;
    }

    Node* new_node = new Node(SERVER, &server_response, nullptr);
    if(_queue_size == size_t{}) {
        _front  = new_node, _top = new_node;
    }
    else {
        _top->_next = new_node;
    }
    ++_servers_count;
    ++_queue_size;
}

void CustomQueue::deque() {
    printf("[%s]", __func__);
    if(_queue_size == size_t{}) {
        printf("[Error] Empty queue, nothing to dequeue\n");
        return;
    }
    else {
        Node* tmp = _front;
        _front = _front->_next;
        if(tmp->_node_type == CLIENT) --_clients_count;
        else if(tmp->_node_type == SERVER) --_servers_count;
        delete tmp;
    }
    --_queue_size;
}