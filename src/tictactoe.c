/*
 * Tictactoe: or noughts and crosses
 * tictactoe.c: Game related functions
 *
 * Copyright (C) 2010 Dani Soufi <danisoufi@gmail.com>
 * Copyright (C) 2010 Elijah El-Lazkani <thyarmageddon@gmail.com>
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
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "minimax.h"


bool set_stone(char *br, char stone, int pos)
{
     if (*(br + pos) == ' ') {
        *(br + pos) = stone;
        return true;
     } else {
        return false;
     }
}

char player_next(char currnt_player, char player1, char player2)
{
     char next;

     if (currnt_player == player1) {
        next = player2;
     } else {
        next = player1;
     }
     return next;
}

int select_mode(void)
{
     char buff[5];

     printf("\n\n---- Welcome to TicTacToe ----\n");
     do {
           printf("\nChoose your game mode:\n");
           printf("(1) Single player     (2) 2 player\n");
           printf("Choose: ");
           if (fgets(buff, sizeof(buff), stdin) != NULL) {
              switch (strtol(buff, NULL, 10)) {
                 case 1:
                    return 1;
                 case 2:
                    return 2;
                 default:
                    printf("Invalid choice (no match), try again\n");
              }
           }
     } while (1);
}

void human_turn(char *br, char current, int *round)
{
     char buff[5];
     int x, y;
     bool input;

     printf("Enter moves as \"<row> <col>\" (no quotes)\n");
     do {
           input = true;
           printf("%c\'s move: ", current);
           if (fgets(buff, sizeof(buff), stdin) != NULL) {
              sscanf(buff, "%i%i", &x, &y);
              if ((x > 0 && x < NUM_ROWS + 1) && (y > 0 && y < NUM_COLS + 1)) {
                 if (!set_stone(br, current, ((NUM_ROWS * (x - 1)) + (y - 1)))) {
                    printf("Illegal move (already taken), try again\n");
                    input = false;
                 }
              } else {
                 printf("Illegal move (off board), try again\n");
                 input = false;
              }
           }
     } while (!input);
     ++*round;
}

void computer_turn(char *br, char player1, char current, int *round)
{
     printf("%c\'s move:\n", current);
     max(br, player1, current, *round, *round);
     set_stone(br, current, position);
     ++*round;
}

char game_winner(char *br, char player1, char player2)
{
     char p[] = {player1, player2};

     for (int i = 0; i < 2; ++i) {

        /* Row */
        if (((*br == p[i]) && (*(br + 1) == p[i]) && (*(br + 2) == p[i])) ||
           ((*(br + 3) == p[i]) && (*(br + 4) == p[i]) && (*(br + 5) == p[i])) ||
           ((*(br + 6) == p[i]) && (*(br + 7) == p[i]) && (*(br + 8) == p[i]))) {
           return p[i];
        }

        /* Collumn */
        else if (((*br == p[i]) && (*(br + 3) == p[i]) && (*(br + 6) == p[i])) ||
           ((*(br + 1) == p[i]) && (*(br + 4) == p[i]) && (*(br + 7) == p[i])) ||
           ((*(br + 2) == p[i]) && (*(br + 5) == p[i]) && (*(br + 8) == p[i]))) {
           return p[i];
        }

        /* Diagonal */
        else if ((*br == p[i]) && (*(br + 4) == p[i]) && (*(br + 8) == p[i])) {
           return p[i];
        }

        /* Anti-Diagonal */
        else if ((*(br + 2) == p[i]) && (*(br + 4) == p[i]) && (*(br + 6) == p[i])) {
           return p[i];
        }
     }
     return NO_MATCH;
}

bool game_ended(char winner, int nrounds)
{
     if (winner == NO_MATCH && nrounds < 9) {
        return false;
     } else {
        return true;
     }
}

void simulate(char *p)
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
           printf("  %c  ", *(p++));
        }
        printf("\n");
     }
     printf("\n");
}

bool restart(void)
{
     char c, buff[5];

     do {
           printf("\nDo you want to play again? [Y\\n] ");
           if (fgets(buff, sizeof(buff), stdin) != NULL) {
              sscanf(buff, "%c", &c);
              switch (c) {
                 case 'y': case 'Y':
                    return true;
                 case 'n': case 'N':
                    return false;
              }
           }
     } while (1);
}

void nround_announce(char winner, char player1, char player2, char next_player)
{
     printf("\n---- New Round ----\n");
     if (winner == NOUGHT) {
        if (winner == player1) {
           printf("%c switches stones with %c\n", winner, next_player);
        } else if (winner == player2) {
           printf("%c switches stones with %c\n", winner, next_player);
        } else {
           printf("Round stones remain unchanged.\n");
        }
     } else {
        printf("Round stones remain unchanged.\n");
     }
}
