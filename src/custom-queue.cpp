#include "custom-queue.h"
#include <cstdio>
#include <string>

CustomQueue::CustomQueue() {}
CustomQueue::~CustomQueue() {}

void CustomQueue::enqueue(ClientRequest& client_request) {
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
        _top = new_node;
    }
    ++_servers_count;
    ++_queue_size;
}

void CustomQueue::deque() {
    if(_queue_size == size_t{}) {
        printf("[Error] Empty queue, nothing to dequeue\n");
        return;
    }
    else {
        Node* tmp = _front;
        _front = _front->_next;
        if(tmp->_node_type == SERVER) --_servers_count;
        else if(tmp->_node_type == CLIENT) --_clients_count;
        delete tmp;
    }
    --_queue_size;
}

std::string CustomQueue::getFront()  {
    std::string ans{};
    if(_queue_size == size_t{}) {
        printf("[Error] Empty queue, nothing to dequeue\n");
        return {};
    }
    if(_front->_node_type == SERVER) {
        ServerResponse* server_response = dynamic_cast<ServerResponse*>(_front->_data);
        ans += server_response->_message_id + " " 
             + server_response->_server_id + " "  
             + server_response->_metadata;
    }
    else {
        ClientRequest* client_request = dynamic_cast<ClientRequest*>(_front->_data);
        ans += client_request->_message_id + " " 
             + client_request->_client_id+ " "  
             + std::to_string(client_request->_request_time);
    }
    return ans;
}

unsigned int CustomQueue::getCountClients() {return _clients_count;}
unsigned int CustomQueue::getCountServers() {return _servers_count;}