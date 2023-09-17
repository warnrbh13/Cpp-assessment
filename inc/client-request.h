#pragma once
#include <iostream>
#include "message.h"

class ClientRequest : public Message {
public:
    std::string clientId;
    int requestTime;
    ClientRequest(std::string messageId, std::string clientId, int requestTime);
};