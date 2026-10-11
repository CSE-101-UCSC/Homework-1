# Makefile for CSE 101 Programming Assignment 1
#
#   make         check the rules, then build ./LinkedList
#   make test    build, then run every test in tests/
#   make clean   remove the program and test output
#
# Do not modify this file. Gradescope builds your code with the original Makefile.

CXX      := g++
override CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic-errors
TARGET   := LinkedList
SRCS     := main.cpp movies.cpp

.PHONY: all check test clean

all: check $(TARGET)

check:
	@bash scripts/check_rules.sh

$(TARGET): $(SRCS) movies.h
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)
	@bash scripts/check_rules.sh --binary || (rm -f $(TARGET); exit 1)

test: all
	@bash run_tests.sh

clean:
	rm -f $(TARGET) $(TARGET).exe
	rm -rf test_output
