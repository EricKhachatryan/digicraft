CXX = g++
CXXFLAGS = -Wall  -Wextra -Iinclude

SRC_dir = src
BUILD_DIR = build
LIB_DIR = libs

LIB_NAME = libmath.a
TARGET = app

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

all: $(BUILD_DIRi)/$(TARGET)	
	
$(BUILD_DIR)/$(TARGET) : $(OBJS)
	@mkdir -p $(BUILD_DIR)
	ar rcs $(LIB_DIR)/$(LIB_NAME) $(filter-out $(BUILD_DIR)/main.o, $(OBJS))
	$(CXX) $(CXXFLAGS) $(BUILD_DIR)/main.o -L$(LIB_DIR) -lmath -o $@

$(BUILD_DIR)/%.o : $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm-rf $(BUILD_DIR) $(LIB_DIR)/$(LIB_NAME)

rebuild: clean all



