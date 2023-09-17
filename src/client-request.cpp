#include "client-request.h"
#include <iostream>

ClientRequest::ClientRequest(std::string messageId, std::string clientId, int requestTime) {
    this->messageId = messageId;
    this->clientId = clientId;
    this->requestTime = requestTime;
}