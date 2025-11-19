CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -pthread -Iinclude

SRC_DIR = src

all: server client

server: $(SRC_DIR)/server.cpp
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/server.cpp -o server

client: $(SRC_DIR)/client.cpp
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/client.cpp -o client

clean:
	rm -f server client

