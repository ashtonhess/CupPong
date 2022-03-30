CXXFLAGS := -std=c++14 -Wall -Werror -Wno-unknown-pragmas -ggdb -O0 -pthread

SOURCES := $(wildcard *.cpp)
OBJS := $(SOURCES:%.cpp=%.o)

TARGET := server

.PHONY : all
all : $(TARGET)

$(TARGET) : $(OBJS)
	 $(CXX) $(CXXFLAGS) $^ -o $@

.PHONY : clean
clean :
	rm -rf $(TARGET) $(OBJS)
