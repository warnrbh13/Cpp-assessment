#pragma once
#include <iostream>

class Message {
public:
    std::string _message_id{};
    Message();
    Message(std::string message_id);
    virtual ~Message();
};