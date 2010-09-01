/*
 * Tictactoe: or noughts and crosses
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


void rover_stats(char winner, int player1, int player2, int wplayer1,
                 int wplayer2, int nreplays, int nstalemates, int mode)
{
     int p1stats, p2stats;

     p1stats = wplayer1 * 100 / nreplays;
     p2stats = wplayer2 * 100 / nreplays;
     if (winner == player1) {
        printf("TicTacToe! %c wins!\n", winner);
        printf("Current winner has won %d game(s) out of %d, ", wplayer1, nreplays);
        printf("%d%% win(s) including %d stalemate(s)\n", p1stats, nstalemates);
     } else if (winner == player2) {
        printf("TicTacToe! %c wins!\n", winner);
        printf("Current winner has won %d game(s) out of %d, ", wplayer2, nreplays);
        printf("%d%% win(s) including %d stalemate(s)\n", p2stats, nstalemates);
     } else {
        printf("Stalemate... nobody won :(\n");
        if (mode == 1) {
           printf("Human player has won %d game(s), ", wplayer1);
           printf("Computer player has won %d game(s)\n", wplayer2);
        } else {
           printf("Player 1 has won %d game(s), ", wplayer1);
           printf("Player 2 has won %d game(s)\n", wplayer2);
        }
        printf("Stalemate count is %d time(s)\n", nstalemates);
     }
}

void gover_stats(int wplayer1, int wplayer2, int nreplays,
                 int nstalemates, int mode)
{
     int p1stats, p2stats;

     p1stats = wplayer1 * 100/ nreplays;
     p2stats = wplayer2 * 100/ nreplays;
     printf("\n---- Game has ended ----\n");
     if (mode == 1) {
        printf("Human player has won %d game(s) ", wplayer1);
        printf("with a %d%% win(s) and %d%% loss(es)\n", p1stats, p2stats);
        printf("Computer player has won %d game(s) ", wplayer2);
        printf("with a %d%% win(s) and %d%% loss(es)\n", p2stats, p1stats);
     } else {   
        printf("Player 1 has won %d game(s) ", wplayer1);
        printf("with a %d%% win(s) and %d%% loss(es)\n", p1stats, p2stats);
        printf("Player 2 has won %d game(s) ", wplayer2);
        printf("with a %d%% win(s) and %d%% loss(es)\n", p2stats, p1stats);
     }
     printf("%d game(s) were played resulting in ", nreplays);
     printf("%d stalemate(s)\n\n", nstalemates);
}
