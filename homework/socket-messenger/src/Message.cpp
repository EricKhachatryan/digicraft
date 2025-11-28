// src/Message.cpp
#include "../include/Message.hpp"
#include <stdexcept>
#include <arpa/inet.h>

// Простая и надёжная реализация ntohll/htonll (работает везде)
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
    #define htonll(x) ((uint64_t)htonl((x) >> 32) | (uint64_t)htonl(x) << 32)
    #define ntohll(x) htonll(x)
#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
    #define htonll(x) (x)
    #define ntohll(x) (x)
#else
    #error "Unknown byte order"
#endif

std::vector<char> Message::serialize() const {
    uint16_t sender_len = htons(static_cast<uint16_t>(sender.size()));
    uint16_t content_len = htons(static_cast<uint16_t>(content.size()));
    uint64_t ts_net = htonll(static_cast<uint64_t>(timestamp));

    size_t total = 1 + 2 + 2 + 8 + sender.size() + content.size();
    std::vector<char> buf(total);

    char* p = buf.data();
    *p++ = static_cast<uint8_t>(type);
    std::memcpy(p, &sender_len, 2); p += 2;
    std::memcpy(p, &content_len, 2); p += 2;
    std::memcpy(p, &ts_net, 8); p += 8;
    std::memcpy(p, sender.data(), sender.size()); p += sender.size();
    std::memcpy(p, content.data(), content.size());

    return buf;
}

Message Message::deserialize(const std::vector<char>& data) {
    if (data.size() < 13) {
        throw std::runtime_error("Too small packet");
    }

    const char* p = data.data();
    Message msg;
    msg.type = static_cast<MessageType>(*p++);
    
    uint16_t sender_len = ntohs(*reinterpret_cast<const uint16_t*>(p)); p += 2;
    uint16_t content_len = ntohs(*reinterpret_cast<const uint16_t*>(p)); p += 2;
    uint64_t ts_raw = *reinterpret_cast<const uint64_t*>(p); p += 8;
    msg.timestamp = static_cast<int64_t>(ntohll(ts_raw));

    // Защита от слишком больших длин (защита от атак)
    if (data.size() < 13 + static_cast<size_t>(sender_len) + static_cast<size_t>(content_len)) {
        throw std::runtime_error("Truncated packet");
    }

    msg.sender.assign(p, sender_len); p += sender_len;
    msg.content.assign(p, content_len);

    return msg;
}
