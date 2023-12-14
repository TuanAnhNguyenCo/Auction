// config.cpp
#include "config.h"

MySingleton* MySingleton::instancePtr = nullptr;

MySingleton& MySingleton::instance() {
    if (!instancePtr) {
        instancePtr = new MySingleton;
    }
    return *instancePtr;
}

MySingleton::MySingleton() : server_sock(0) {
    // Additional initialization if needed
}

MySingleton::~MySingleton() {
    // Clean up if needed
    delete instancePtr;
}

int MySingleton::getValue() const {
    return server_sock;
}

void MySingleton::setValue(int newServerSock) {
    server_sock = newServerSock;
}