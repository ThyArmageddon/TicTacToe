/*
 * Tictactoe: or noughts and crosses
 * difficulty.c: Adjusting the game's difficulty
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
#include "minimax.h"
#include "difficulty.h"

int max_depth;

void set_diff(void)
{
   int diff;
   bool input = true;

   do {
         input = true;
         printf("Choose your game difficulty:\n");
         printf("(1) Easy     (2) Medium     (3) Hard     (4) Extreme\n");
         printf("Choose: ");
         fflush(stdout);
         /* FIXME */
         if (scanf(" %d", &diff) == 1) {
            switch(diff) {
            case 1:
               max_depth = 5;
               break;
            case 2:
               max_depth = 6;
               break;
            case 3:
               max_depth = 7;
               break;
            case 4:
               max_depth = 8;
               break;
            default:
               printf("Invalid choice (no match), try again\n");
               input = false;
               break;
            }
         } else {
            printf("Invalid (too much input), try again\n");
            input = false;
         }
   } while (!input);
}
