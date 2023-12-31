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
void MySingleton::getParticipents(){

    MySingleton::instance().participents.clear();
    MySingleton::instance().room_ids.clear();
    for (std::list<AuctionRoomStruct>::iterator it = MySingleton::instance().auction_rooms.begin(); it != MySingleton::instance().auction_rooms.end(); ++it) {
        GetParticipateMess mess;
        mess.room_id = it->id;
        MySingleton::instance().room_ids.push_front(it->id);
        send(MySingleton::instance().getValue(), "20", BUFF_SIZE - 1, 0);
        send(MySingleton::instance().getValue(), &mess,sizeof(GetParticipateMess), 0);
    }

}
