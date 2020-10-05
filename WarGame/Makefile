#------------------------------------------------------------------------------
# Makefile for War
#------------------------------------------------------------------------------

CLIENT1        = War
ADT1           = Card
SOURCE1        = $(CLIENT1).cpp
OBJECT1        = $(CLIENT1).o
ADT1_SOURCE    = $(ADT1).cpp
ADT1_OBJECT    = $(ADT1).o
ADT1_HEADER    = $(ADT1).h
COMPILE        = g++ -Wall -std=c++11
LINK           = g++ -o
REMOVE         = rm -f
MEMCHECK       = valgrind --leak-check=full --track-origins=yes

$(CLIENT1) : $(OBJECT1) $(ADT1_OBJECT)
	$(LINK) $(CLIENT1) $(OBJECT1) $(ADT1_OBJECT)

$(OBJECT1) : $(SOURCE1) $(ADT1_HEADER) $(ADT1_OBJECT)
	$(COMPILE) -c $(SOURCE1)

$(ADT1_OBJECT) : $(ADT1_SOURCE) $(ADT1_HEADER)
	$(COMPILE) -c $(ADT1_SOURCE)

clean :
	$(REMOVE) $(CLIENT1) $(OBJECT1) $(ADT1_OBJECT)

memcheck : $(CLIENT1)
	$(MEMCHECK) $(CLIENT1)




