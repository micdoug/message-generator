//
// Created by michael on 10/3/16.
//

#include "MessageEvent.h"

int MessageEvent::getOrigin() const {
    return m_origin;
}

void MessageEvent::setOrigin(int m_origin) {
    MessageEvent::m_origin = m_origin;
}

int MessageEvent::getDestiny() const {
    return m_destiny;
}

void MessageEvent::setDestiny(int m_destiny) {
    MessageEvent::m_destiny = m_destiny;
}

int MessageEvent::getSize() const {
    return m_size;
}

void MessageEvent::setSize(int m_size) {
    MessageEvent::m_size = m_size;
}

int MessageEvent::getTime() const {
    return m_time;
}

void MessageEvent::setTime(int m_time) {
    MessageEvent::m_time = m_time;
}

std::ostream &operator<<(std::ostream &out, const MessageEvent &msge) {
    out << msge.getTime() << " C "
        << msge.getOrigin() << " "
        << msge.getDestiny() << " "
        << msge.getSize() << std::endl;
    return out;
}
