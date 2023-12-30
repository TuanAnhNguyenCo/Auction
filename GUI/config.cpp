// config.cpp
#include "config.h"
#include "account.h"

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

Account MySingleton::getAccount() const {
    return account;
}

void MySingleton::setAccount(Account account1) {
    account = account1;
}

void MySingleton::getRooms(){
    send(MySingleton::instance().getValue(), "14", BUFF_SIZE - 1, 0);
}
void MySingleton::getItems(){
    send(MySingleton::instance().getValue(), "18", BUFF_SIZE - 1, 0);
}
