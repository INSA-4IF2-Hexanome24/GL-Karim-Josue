# Makefile for GL-Karim-Josue

CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -g -O2 -I.
LDFLAGS :=
RM := rm -f

SRCS := $(wildcard *.cpp) $(wildcard etats/*.cpp)
OBJS := $(SRCS:.cpp=.o)
DEPS := $(OBJS:.o=.d)

TARGET := automate

.PHONY: all clean distclean run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

-include $(DEPS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEPS)

distclean: clean
	$(RM) $(TARGET)

run: all
	./$(TARGET)
