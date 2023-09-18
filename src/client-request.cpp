#include "client-request.h"
#include <iostream>


ClientRequest::ClientRequest()
    :   Message(std::string{}),
        _client_id(std::string{}), 
        _request_time(int{}) {
}

ClientRequest::ClientRequest(std::string message_id, std::string client_id, int request_time) {
    if(message_id.length() < MIN_STR_SIZE or client_id.length() > MAX_STR_SIZE) {
        throw std::invalid_argument("Invalid message_id size\n");
    }
    if(client_id.length() < MIN_STR_SIZE or client_id.length() >  MAX_STR_SIZE) {
        throw std::invalid_argument("Invalid client_id size\n");
    }
    if(request_time < MIN_INT_VAL or request_time >  MAX_INT_VAL) {
        throw std::invalid_argument("request_time value out of range\n");
    }
    this->_message_id = message_id;
    this->_client_id = client_id;
    this->_request_time = request_time;
}

ClientRequest::~ClientRequest() {
}

std::string ClientRequest::getClientId() {
    return _client_id;
}

int ClientRequest::getRequestTime() {
    return _request_time;
}