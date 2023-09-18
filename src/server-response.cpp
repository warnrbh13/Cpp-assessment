#include "server-response.h"
#include <iostream>

ServerResponse::ServerResponse()
    : Message(std::string{}),
      _server_id(std::string{}),
      _metadata(std::string{}) {}

ServerResponse::ServerResponse(std::string message_id, std::string server_id, std::string metadata) {
    if(message_id.length() < MIN_STR_SIZE or message_id.length() > MAX_STR_SIZE) {
        throw std::invalid_argument("Invalid message_id size");
    }
    if(server_id.length() < MIN_STR_SIZE or server_id.length() > MAX_STR_SIZE) {
        throw std::invalid_argument("Invalid server_id size");
    }
    if(metadata.length() < MIN_STR_SIZE or metadata.length() > MAX_STR_SIZE) {
        throw std::invalid_argument("Invalid metadata size");
    }

    this->_message_id = message_id;
    this->_server_id = server_id;
    this->_metadata = metadata;
}

ServerResponse::~ServerResponse() {}

std::string ServerResponse::getServerId() {
    return _server_id;
}

std::string ServerResponse::getMetadata() {
    return _server_id;
}