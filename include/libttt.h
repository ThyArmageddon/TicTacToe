/*
 * Tictactoe: or noughts and crosses, human vs. computer game.
 *
 * Copyright (C) 2010 Dani Soufi <danisoufi@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* Nummber of rows and collums in the game field */
#define NUM_ROWS   3
#define NUM_COLS   3

/* Expected return if no winner is eliminated */
#define NONE       ' '

/* Relaces boolean type */
#define TRUE       1
#define FALSE      0

int set_stone(char board[][], char stone, int x, int y);

int game_ended(char winner,  int round);

char next_player(char currnt_player, char player1, char player2);

char game_winner(char board[][], char currnt_player);

void computer_player2(char board[][], int player, int round);

void simulate(char board[][]);
