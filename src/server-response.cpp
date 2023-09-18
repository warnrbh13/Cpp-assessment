#include "server-response.h"
#include <iostream>

ServerResponse::ServerResponse()
    :   Message(std::string{}),
        _server_id(std::string{}),
        _metadata(std::string{}) {

}

ServerResponse::ServerResponse(std::string message_id, std::string server_id, std::string metadata) 
    :   Message(message_id),
        _server_id(server_id),
        _metadata(metadata) {

}

ServerResponse::~ServerResponse() {
    
}