#include "server-response.h"
#include <iostream>

ServerResponse::ServerResponse(std::string messageId, std::string serverId, std::string metadata) {
    this->messageId = messageId;
    this->serverId = serverId;
    this->metadata = metadata;
}