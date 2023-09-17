#include "client-request.h"
#include <iostream>


ClientRequest::ClientRequest()
    :   Message(std::string{}),
        _client_id(std::string{}), 
        _request_time(int{}) {
}

ClientRequest::ClientRequest(std::string message_id, std::string client_id, int request_time) 
    :   Message(message_id),
        _client_id(client_id), 
        _request_time(request_time) {
}

ClientRequest::~ClientRequest() {
}

