# Copyright (C) 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002,
# 2003, 2004, 2005, 2006, 2007, 2008  Free Software Foundation, Inc.
# This Makefile is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY, to the extent permitted by law; without
# even the implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE.

srcdir = .
libdir = $(srcdir)/include

CC = gcc -std=gnu99
CFLAGS = -g -O2 -Wall -I $(libdir)/

TTT_OBJS = difficulty.o main.o minimax.o stats.o tictactoe.o

TTTEXEC = tictactoe

$(TTTEXEC): build_msg $(TTT_OBJS) compatability
	@echo "Linking..."
	@echo ""
	$(CC) $(TTT_OBJS) -o $(TTTEXEC)
	@echo ""
	@echo "Successfully compiled: $(TTTEXEC)"
	@echo "Don't forget to check the README file."
	@echo ""

all: $(TTT_OBJS)
	
clean:
	@echo ""
	rm -f $(TTTEXEC)
	rm -f $(TTT_OBJS)
	@echo ""
	@echo "TicTacToe successfully uninstalled!"
	@echo ""

build_msg:
	@echo ""
	@echo "Compiling TicTacToe. Grab a coffee!"
	@echo ""

compatability:
	@echo ""
	@echo "Finished compiling, now linking!"
	@echo ""

.SUFFIXES: .c .h .o

.c.o:
	$(CC) $(CFLAGS) -c $<

# Safety hash
difficulty.o: difficulty.c
main.o: main.c $(libdir)/libttt.h $(libdir)/stats.h $(libdir)/difficulty.h
minimax.o: minimax.c $(libdir)/libttt.h $(libdir)/minimax.h $(libdir)/difficulty.h
stats.o: stats.c
tictactoe.o: tictactoe.c $(libdir)/minimax.h

