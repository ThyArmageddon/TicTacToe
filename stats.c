/*
 * Tictactoe: or noughts and crosses, human vs. computer game.
 * stats.c: Game related statictics functions
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
#include "include/libttt.h"

int wplayer1 = 0;
int wplayer2 = 0;
int nreplays = 0;
int nstalemates = 0;

void rover_stats(char winner)
{
     if (winner == player1) {
        printf("TicTacToe! %c wins!\n", winner);
        printf("Current winner has won %d game(s) out of %d, ", wplayer1, nreplays);
        printf("%d%% win(s) and %d stalemate(s)\n", wplayer1 * 100 / nreplays, nstalemates);
     } else if (winner == player2) {
        printf("TicTacToe! %c wins!\n", winner);
        printf("Current winner has won %d game(s) out of %d, ", wplayer2, nreplays);
        printf("%d%% win(s) and %d stalemate(s)\n", wplayer2 * 100 / nreplays, nstalemates);
     } else {
        printf("Stalemate... nobody won :(\n");
        printf("%c has won %d game(s), ", player1, wplayer1);
        printf("%c has won %d game(s)\n", player2, wplayer2);
        printf("Stalemate count is %d time(s)\n", nstalemates);
     }
}

void gover_stats(void)
{
     printf("---- Game has ended ----\n");
     printf("%c has won %d game(s) ", player1, wplayer1);
     printf("with a %d%% win(s) and %d%% loss(es)\n", wplayer1 * 100/ nreplays, wplayer2 * 100/ nreplays);
     printf("%c has won %d game(s) ", player2, wplayer2);
     printf("with a %d%% win(s) and %d%% loss(es)\n", wplayer2 * 100/ nreplays, wplayer1 * 100/ nreplays);
     printf("%d game(s) were played resulting in %d stalemate(s)\n\n", nreplays, nstalemates);
}
