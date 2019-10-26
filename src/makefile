# cse3310 project sample makefile



CXX=g++
# note the below asio package may be in a 
# different place
CPPFLAGS=-I../asio-1.13.0/include
CXXFLAGS=-Wall -g -std=c++11 -O0

GTKLINKFLAGS=$(shell pkg-config --libs gtk+-2.0)
GTKCOMPILEFLAGS=$(shell pkg-config --cflags gtk+-2.0)

TARGETS=chat_client chat_server gtk_chat gtk_chat2 gtk_chat3 test_example

all:${TARGETS}


# these compile and link in the same command.
# no intermediate object code files
# (sacrifice compilation speed for not having to
#  deal with dependencies)

chat_client: chat_client.cpp chat_message.hpp
	${CXX} ${CXXFLAGS} ${CPPFLAGS} -o $@ $< -lpthread

chat_server: chat_server.cpp chat_message.hpp
	${CXX} ${CXXFLAGS} ${CPPFLAGS} -o $@ $< -lpthread

gtk_chat:  gtk_chat.cpp
	${CXX} ${CXXFLAGS} ${GTKCOMPILEFLAGS} ${CPPFLAGS} -o $@ $< \
           ${GTKLINKFLAGS} -lpthread 

gtk_chat2:  gtk_chat2.cpp
	${CXX} ${CXXFLAGS} ${GTKCOMPILEFLAGS} ${CPPFLAGS} -o $@ $< \
           ${GTKLINKFLAGS} -lpthread 

gtk_chat3:  gtk_chat3.cpp
	${CXX} ${CXXFLAGS} ${GTKCOMPILEFLAGS} ${CPPFLAGS} -o $@ $< \
           ${GTKLINKFLAGS} -lpthread 

blackjack.o: blackjack.cpp blackjack.h

test_example: test_example.cpp blackjack.o 
	${CXX} ${CXXFLAGS} ${CPPFLAGS} -o $@ $< \
				blackjack.o \
            -lboost_unit_test_framework


clean:
	-rm -f ${TARGETS} 
