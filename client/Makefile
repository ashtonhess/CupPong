CXXFLAGS := -std=c++14 -Wall -Werror -ggdb -O0 -pthread

SOURCES := $(wildcard *.cpp)
OBJS := $(SOURCES:%.cpp=%.o)

TARGET := client

.PHONY : all
all : $(TARGET)

$(TARGET) : $(OBJS)
	 $(CXX) $(CXXFLAGS) $^ -o $@

.PHONY : clean
clean :
	rm -rf $(TARGET) $(OBJS)
