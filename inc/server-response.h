#pragma once
#include <iostream>
#include "message.h"

class ServerResponse : public Message{
public:
    std::string serverId{};
    std::string metadata{};
    ServerResponse(std::string messageId, std::string serverId, std::string metadata);
};