/*
 * Tictactoe: or noughts and crosses, human vs. computer game.
 * stats.h: Game statistics header
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

/* Number of times PLAYER1 has won */
extern int wplayer1;

/* Number of times PLAYER2 has won */
extern int wplayer2;

/* Number of time the game was replayed */
extern int nreplays;

/* Number of stalemates in the game */
extern int nstalemates;

/* End round stats */
void rover_stats(char);

/* Game over stats */
void gover_stats(void);
