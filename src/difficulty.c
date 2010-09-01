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
#include <stdlib.h>

int set_diff(void)
{
   char buff[5];

   do {
         printf("Choose your game difficulty:\n");
         printf("(1) Easy     (2) Medium     (3) Hard     (4) Extreme\n");
         printf("Choose: ");
         if (fgets(buff, sizeof(buff), stdin) != NULL) {
            switch(sscanf(buff, NULL, 10)) {
            case 1:
               return 5;
            case 2:
               return 6;
            case 3:
               return 7;
            case 4:
               return 8;
            default:
               printf("Invalid choice (no match), try again\n");
            }
         }
   } while (1);
}
