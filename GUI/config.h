// config.h
#ifndef CONFIG_H
#define CONFIG_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <QDebug>
#include <pthread.h>
#include <unistd.h>

#define BUFF_SIZE 8192


class MySingleton {
public:
    static MySingleton& instance();

    // Các phương thức để truy cập và cập nhật biến
    int getValue() const;
    void setValue(int server_sock);

private:
    MySingleton();   // Constructor private
    ~MySingleton();  // Destructor private

    // Không cho phép sao chép
    MySingleton(const MySingleton&) = delete;
    MySingleton& operator=(const MySingleton&) = delete;

    // Biến để lưu giữ trạng thái
    int server_sock;
    static MySingleton* instancePtr;
};

#endif // CONFIG_H
