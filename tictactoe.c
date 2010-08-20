/*
 * Tictactoe: or noughts and crosses
 * tictactoe.c: Game related functions
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
#include <stdio.h>
#include <stdbool.h>
#include "include/libttt.h"
#include "include/minimax.h"

int tolower(int c);

bool set_stone(char board[NUM_ROWS][NUM_COLS], char stone, int x, int y)
{
     if (board[x][y] == ' ') {
        board[x][y] = stone;
        return true;
     } else {
        return false;
     }
}

char player_next(char currnt_player)
{
     char next;

     if (currnt_player == player1) {
        next = player2;
     } else {
        next = player1;
     }
     return next;
}

int gmode(void)
{
     int mode;
     bool input = true;

     do {
           printf("Choose your game mode:\n");
           printf("(1) Single player     (2) 2 player\n");
           printf("Choose: ");
           fflush(stdout);
           if (scanf(" %d", &mode) == 1) {
              if (mode < 1 || mode > 2) {
                 printf("Illegal choice (no match), try again\n");
                 input = false;
              } else {
                 input = true;
              }
           } else {
              printf("Illegal choice (too much input), try again\n");
              input = false;
           }
     } while (!input);

     return mode;
}

void human_turn(char board[NUM_ROWS][NUM_COLS], char current)
{
     int x, y;
     bool valid_input = true;

     printf("Enter moves as \"<row> <col>\" (no quotes)\n");
     do {
           valid_input = true;
           printf("%c\'s move: ", current);
           fflush(stdout);
           if (scanf("%d %d", &x, &y) == 2) {
              if ((x > 0 && x < NUM_ROWS + 1) && (y > 0 && y < NUM_COLS + 1)) {
                 if (!set_stone(board, current, (x - 1), (y - 1))) {
                    printf("Illegal move (already taken), try again\n");
                    valid_input = false;
                 }
              } else {
                 printf("Illegal move (off board), try again\n");
                 valid_input = false;
              }
           }
     } while (!valid_input);
     ++nrounds;
}

void computer_turn(char board[NUM_ROWS][NUM_COLS], char current)
{
     printf("%c\'s move:\n", current);
     max(board, player1, current, nrounds);
     set_stone(board, current, xnext, ynext);
     ++nrounds;
}

char game_winner(char board[NUM_ROWS][NUM_COLS])
{
     char p[] = {player1, player2};

     for (int j = 0; j < 2; ++j) {

        /* Row */
        for (int x = 0; x < 3; ++x) {
           for (int i = 0; i < 3; ++i) {
              if (board[x][i] != p[j]) {
                 break;
              } else if (i == 2) {
      	         return p[j];
              }
           }
        }

        /* Collumn */
        for (int y = 0; y < 3; ++y) {
           for (int i = 0; i < 3; ++i){
              if (board[i][y] != p[j]) {
                 break;
              } else if (i == 2) {
                 return p[j];
              }
           }
        }

        /* Diagonal */
        for (int i = 0; i < 3; ++i) {
           if (board[i][i] != p[j]) {
              break;
           } else if (i == 2) {
              return p[j];
           }
        }

        /* Anti-Diagonal */
        for (int i = 0; i < 3; ++i) {
           if (board[i][2 - i] != p[j]) {
              break;
           } else if (i == 2) {
              return p[j];
           }
        }
     }
     return NO_MATCH;
}

bool game_ended(char winner)
{
     if (winner == NO_MATCH && nrounds < 9) {
        return false;
     } else {
        return true;
     }
}

void simulate(char board[NUM_ROWS][NUM_COLS])
{
     printf("\n");
     for (int i = 0; i < NUM_ROWS; ++i) {
        if (i > 0) {
           for (int k = 0; k < NUM_COLS; ++k) {
              if (k > 0) {
                 printf("+");
              }
              for (int l = 0; l < NUM_ROWS + 2; ++l) {
                 printf("-");
              }
           }
           printf("\n");
        }
        for (int j = 0; j < NUM_COLS; ++j) {
           if (j > 0) {
              printf("|");
           }
           printf("  %c  ", board[i][j]);
        }
        printf("\n");
     }
     printf("\n");
}

bool restart(void)
{
     char c;

     printf("\nDo you want to play again? [Y\\N] ");
     fflush(stdout);
     if (scanf(" %c", &c) ==  1) {
        printf("\n");
        c = tolower(c);
        if (c == 'y') {
           return true;
        } else {
           return false;
        }
     } else {
        return false;
     }
}

int tolower(int c)
{
   if (c == 'N' || c == 'Y')
      return c + 'a' - 'A';
   else
      return c;
}

