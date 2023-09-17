#pragma once
#include <iostream>
#include "client-request.h"
#include "server-response.h"

union QueueElement {
public:
    ClientRequest _client_value;
    ServerResponse _server_value;
    QueueElement* next;
    QueueElement(ClientRequest& client_request) {
        _client_value = client_request;
        _server_value = {};
        next = nullptr;
    }
    QueueElement(ServerResponse& server_value) {
        _client_value = {};
        _server_value = server_value;
        next = nullptr;
    }
};

class CustomQueue {
public:
    CustomQueue();
    ~CustomQueue();

    void enqueue(ClientRequest& client_request);
    void enqueue(ServerResponse& server_response);

    void deque();
    std::string getFront();
    unsigned int getCountClients();
    unsigned int getCountServers();

private:
    static const int MAX_SIZE{1000};

    QueueElement* _front{};
    QueueElement* _top{};
    size_t _queue_size{};

    unsigned int _clients_count{};
    unsigned int _servers_count{};
};