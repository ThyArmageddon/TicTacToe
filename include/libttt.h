/*
 * Tictactoe: or noughts and crosses, human vs. computer game.
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

/* Diffines both players' symbols */
#define PLAYER1    'X'
#define PLAYER2    'O'

/* Nummber of rows and collums in the game field */
#define NUM_ROWS   3
#define NUM_COLS   3

/* Expected return if no winner is eliminated */
#define NONE       ' '

/* Relaces boolean type */
#define TRUE       1
#define FALSE      0

/* Set stone in an empty cell for the player */
int set_stone(char [NUM_ROWS][NUM_COLS], char, int, int);

/* Show the current status of the game */
int game_ended(char,  int);

/* Switch players after each successfull round */
char player_next(char);

/* Search for the game's winner */
char game_winner(char [NUM_ROWS][NUM_COLS], char);

/* Computer player's move */
void computer_player2(char [NUM_ROWS][NUM_COLS], char, int);

/* Simulate the game */
void simulate(char [NUM_ROWS][NUM_COLS]);
