#pragma once
#include <iostream>
#include "client-request.h"
#include "server-response.h"

enum NodeType {
    CLIENT = 0,
    SERVER
};

struct Node {
    NodeType _node_type;
    Message* _data;
    Node* _next;
    Node() : _data(nullptr), _next(nullptr) {}
    Node(NodeType type, Message* data, Node* next)
        :   _node_type(type),
            _data(data),
            _next(next) {}
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

    Node* _front{};
    Node* _top{};
    size_t _queue_size{};

    unsigned int _clients_count{};
    unsigned int _servers_count{};
};