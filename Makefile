#############################################################################
#
#  Makefile for AS-test
#
#############################################################################
#
#  If you move this makefile, update the variable below
#  or else depend won't work.
#############################################################################

MAKEFILE	= Makefile
CC		= g++

CFILES		= AS-test.cpp \
		  AStack.cpp \
		  Array.cpp \

#############################################################################
# Flags for Installation
#############################################################################
BINDIR		= .
#############################################################################

DFLAGS		= -g 
IFLAGS          = # -DUSE_TEMPLATES
OPTFLAGS	=  # Enable this flag if compiler supports templates...
LDFLAGS		=  
CFLAGS		= $(IFLAGS) $(OPTFLAGS) $(DFLAGS)

#############################################################################
# G++ directives
#############################################################################
.SUFFIXES: .cpp
.cpp.o:
	$(CC) $(CFLAGS) -c $<
#############################################################################

all: AS-test 

AS-test: AS-test.o AStack.o Array.o
	$(CC) $(LDFLAGS) AS-test.o AStack.o Array.o -o $@

clean:
	rm -f *.o *.out *~ core

realclean: clean
	rm -rf AS-test LS-test

depend:
	o-g++dep -f $(MAKEFILE) $(CFILES)

# DO NOT DELETE THIS LINE -- g++dep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

AS-test.o: AS-test.cpp AStack.h Array.h Array.cpp Array.inl \
 Stack_Exceptions.h AStack.cpp AStack.inl
LS-test.o: LS-test.cpp LStack.h Stack_Exceptions.h LStack.cpp LStack.inl
AStack.o: AStack.cpp AStack.h Array.h Array.cpp Array.inl \
 Stack_Exceptions.h AStack.cpp AStack.inl
LStack.o: LStack.cpp LStack.h Stack_Exceptions.h LStack.cpp LStack.inl
Array.o: Array.cpp Array.h Array.cpp Array.inl

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
