//
// Created by michael on 10/3/16.
//

#ifndef MESSAGE_GENERATOR_MESSAGEEVENT_H
#define MESSAGE_GENERATOR_MESSAGEEVENT_H

#include <iostream>

class MessageEvent {
private:
    int m_origin;
public:
    int getOrigin() const;

    void setOrigin(int m_origin);

    int getDestiny() const;

    void setDestiny(int m_destiny);

    int getSize() const;

    void setSize(int m_size);

    int getTime() const;

    void setTime(int m_time);

private:
    int m_destiny;
    int m_size;
    int m_time;
};

std::ostream &operator<<(std::ostream &out, const MessageEvent &msge);


#endif //MESSAGE_GENERATOR_MESSAGEEVENT_H
