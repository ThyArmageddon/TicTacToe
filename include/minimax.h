/*
 * Tictactoe: or noughts and crosses, human vs. computer game.
 * minimax.h: A header file for the computer algorithm
 *
 * Copyright (C) 2010 Dani Soufi <danisoufi@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* Maximal search depth */
#define MAX_DEPTH 8

/* Computer's next best move */
extern int xnext, ynext;

int max(char [NUM_ROWS][NUM_COLS], char, char, int);
