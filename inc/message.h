#pragma once
#include <iostream>

class Message {
public:
    Message();
    Message(std::string message_id);
    virtual ~Message();

    std::string getMessageId(){return _message_id;}

protected:
    const size_t MAX_STR_SIZE{50};
    const size_t MIN_STR_SIZE{1};
    const size_t MAX_INT_VAL{1000};
    const size_t MIN_INT_VAL{1};

    std::string _message_id{};
};