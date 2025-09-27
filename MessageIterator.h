#ifndef MESSAGEITERATOR_H
#define MESSAGEITERATOR_H

#include "Iterator.h"

class MessageIterator : public Iterator<Message*> {
private:
    std::vector<Message*>::iterator current;
    std::vector<Message*>::iterator end;
    std::vector<Message*> messages;

public:
    MessageIterator(const std::vector<Message*>& messageList);
    void first() override;
    void next() override;
    bool isDone() const override;
    Message* currentItem() const override;
};

#endif