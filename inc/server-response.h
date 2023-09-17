#pragma once
#include <iostream>
#include "message.h"

class ServerResponse : public Message{
public:
    ServerResponse();
    ServerResponse(std::string message_id, std::string server_id, std::string metadata);
private:
    std::string _server_id{};
    std::string _metadata{};
};