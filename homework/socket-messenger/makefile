CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude -pthread
LDFLAGS = -lsqlite3
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj

# Создаём папки автоматически при любом запуске make
$(shell mkdir -p $(BUILD_DIR) $(OBJ_DIR))

SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(SOURCES:src/%.cpp=$(OBJ_DIR)/%.o)

all: $(BUILD_DIR)/messenger_server $(BUILD_DIR)/messenger_client

$(BUILD_DIR)/messenger_server: $(filter-out $(OBJ_DIR)/main_client.o, $(OBJECTS))
	$(CXX) $^ -o $@ $(LDFLAGS)

$(BUILD_DIR)/messenger_client: $(filter-out $(OBJ_DIR)/main_server.o, $(OBJECTS))
	$(CXX) $^ -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: src/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Принудительно создаём папку obj перед компиляцией объектов
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

rebuild: clean all

clean:
	rm -rf $(BUILD_DIR)

run-server: $(BUILD_DIR)/messenger_server
	./$<

run-client: $(BUILD_DIR)/messenger_client
	./$<

.PHONY: all clean rebuild run-server run-client
