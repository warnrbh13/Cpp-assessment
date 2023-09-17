#pragma once
#include <iostream>
#include "message.h"

class ClientRequest : public Message {
public:
    ClientRequest();
    ClientRequest(std::string message_id, std::string client_id, int request_time);
    ~ClientRequest();

    std::string _client_id;
    int _request_time;
};
