#pragma once
#include <string>
#include <vector>
#include <cstdint>
#include <cstring>
#include <arpa/inet.h>
#include <ctime>

enum class MessageType : uint8_t {
    TEXT = 1,
    AUTH_REQUEST,
    AUTH_SUCCESS,
    AUTH_FAILED,
    USER_LIST,
    DISCONNECT
};

struct Message {
    MessageType type;
    std::string sender;
    std::string content;
    int64_t timestamp;

    Message() = default;
    Message(MessageType t, std::string s = "", std::string c = "")
        : type(t), sender(std::move(s)), content(std::move(c)), timestamp(time(nullptr)) {}

    std::vector<char> serialize() const;
    static Message deserialize(const std::vector<char>& data);
};
