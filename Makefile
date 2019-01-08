# Copyright (c) 2015 Younes Hassani Abdollahi
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.

###########################################################################
# This Makefile is just for compiling and running this program.
###########################################################################


# The -O0 option speeds up the compile, which is good for testing.  This should
# never be used for production since the generated code is extremely slow!
CXXFLAGS+=-Wall -Wextra -O0 -g -D_GLIBCXX_DEBUG
#CXXFLAGS+=-Wall
#LDFLAGS+=-lutil -lboost_iostreams -lboost_system -lboost_filesystem
CXX=g++

# This makes the examples and tests more complete, but only works if you have the corresponding
# libraries installed.
#CXXFLAGS+=--std=c++11 -DUSE_ARMA=1 -DUSE_BLITZ=1

BASE = $(shell pwd)

INC = $(BASE)/include/header.h
CPP = $(BASE)/src
CCS = $(shell ls $(CPP))
SRCS = $(CCS:%.cpp=$(CPP)/%.cpp)

#objective files
OBJS = $(CCS:.cpp=.o)

#Library file location
LIB = $(BASE)/lib/lib.a

#Main file
MAIN_3D = $(BASE)/MD_3D.cpp
MAIN_2D = $(BASE)/MD_2D.cpp

all: install-fedora install-ubuntu Run 

Run_2D: MD_2D
	@echo "Running ..."
	@rm -r data_2D
	@mkdir ./data_2D
	@./MD_2D
	@mv *.data *.xyz *.png ./data_2D

Run_3D: MD_3D
	@echo "Running ..."
	@rm -r data_3D
	@mkdir ./data_3D
	@./MD_3D
	@mv *.data *.xyz *.png ./data_3D

obj:
	@echo "Compiling ..."	
	@$(CXX) $(CXXFLAGS) -c $(SRCS) 

lib: obj
	@rm -f $(LIB)
	@ar ruv $(LIB) $(OBJS)
	@ranlib $(LIB)
	@rm -f $(OBJS)

MD_3D: lib
	@rm -f *.o
	@$(CXX) -o MD_3D $(INC) $(MAIN_3D) $(LIB) $(LDFLAGS)
	
MD_2D: lib
	@rm -f *.o
	@$(CXX) -o MD_2D $(INC) $(MAIN_2D) $(LIB) $(LDFLAGS) 

clean:
	@rm -f *.o

install-fedora:
	@chmod +x ./install/fedora.sh
	@./install/fedora.sh

install-ubuntu:
	@chmod +x ./install/ubuntu.sh
	@./install/ubuntu.sh
	
