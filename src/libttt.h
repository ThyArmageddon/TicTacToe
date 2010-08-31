/*
 * Tictactoe: or noughts and crosses
 * libttt.h: The game header
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
#include <stdbool.h>

/* Diffines both players' symbols */
#define CROSS     'X'
#define NOUGHT    'O'

/* Nummber of rows and collums in the game field */
#define NUM_ALL      9
#define NUM_ROWS     3
#define NUM_COLS     3

/* Expected return if no winner is eliminated */
#define NO_MATCH       ' '

/* Set stone in an empty cell for the player */
bool set_stone(char *, char, int);

/* Show the current status of the game */
bool game_ended(char, int);

/* Switch players after each successfull round */
char player_next(char, char, char);

/* Search for the game's winner */
char game_winner(char *, char, char);

/* Human's best move */
void human_turn(char *, char, int *);

/* Computer player's move */
void computer_turn(char *, char, char, int *);

/* Simulate the game */
void simulate(char *);

/* Replay the game */
bool restart(void);

/* Game modes */
int select_mode(void);

/* Announce the next player on the next round */
void nround_announce(char, char, char, char);
