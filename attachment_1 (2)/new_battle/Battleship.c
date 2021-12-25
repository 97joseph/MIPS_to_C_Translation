#include"Battleship.h"
void welcome_screen(void)
{
   printf("\n\t\t\tBATTLESHIP!!!\n");
   printf("\n\t\t\tRules of Battleship: \n\n");
   printf("Players place their 'fleet' of 5 ships on their 'ocean', hidden from the\n");
   printf("opponent's view. Taking turns, players call out their 'shots' attempting to\n");
   printf("get 'hits' on the opponent's ships in order to sink them. Strategy and some\n");
   printf("luck must be combined to be the first to locate and sink all 5 opponent's\n");
   printf("ships to win the game. The object of the game is to be the first player to\n");
   printf("sink all five of his opponent's ships. Each player SECRETLY places his fleet\n");
   printf("of 5 ships on his ocean grid. Ships may be placed in any horizontal or vertical\n");
   printf("position - but NOT diagonally. You MAY NOT change the position of any ship.\n");
   printf("To do so would be cheating!\n\n");
      printf("Game Play options vs computer\n 3 player game In which one will compete with two others \n one player will compete with \n\n");
   printf("This is a one player game where you are player1, and the computer is player2.\n\n");
   printf("Types of Ships: \tSize:\n\n");
   printf("Aircraft Carrier \t5 \nBattleship \t\t4 \nCruiser \t\t3 \nSubmarine \t\t3 \nDestroyer \t\t2\n\n");
   printf("Symbols: \n c - Aircraft Carrier\n b - Battleship\n r - Cruiser\n s - Submarine\n d - Destroyer\n");
   printf("\n ~ - Water\n * - Hit\n m - Miss\n");
}
char initialize_game_board(int x1, int y1, int x2, int y2, char board[10][10], int print, int player,
   int xtarget, int ytarget, int *hits, char visible[10][10], char type)
{
   int x = 0, y = 0;
   if (print != 0)
   {
       printf("\n\t    0 1 2 3 4 5 6 7 8 9\n");
       printf("\t +---------------------+\n\t");
   }
   for (x = 0; x < 10; x++)
   {
       if ((x < 9) && (print != 0))
       {
           printf("%d | ", x);
       }
       if ((x == 9) && (print != 0))
       {
           printf("%d | ", x);
       }
       for (y = 0; y < 10; y++)
       {
           if ((board[x][y] != 'c') && (board[x][y] != 'b') && (board[x][y] != 'r') && (board[x][y] != 's') && (board[x][y] != 'd')
               && (board[x][y] != '*') && (board[x][y] != 'm'))
           {
               board[x][y] = '~';
               if ((((x == x1) && (y == y1)) || ((x == x2) && (y == y2))) && (print != -1))
               {
                   board[x][y] = type;
               }
               if ((((x < x1) && (x > x2) && (y == y1)) || ((x > x1) && (x < x2) && (y == y1))) && (print != -1))
               {
                   board[x][y] = type;
               }
               if ((((y < y1) && (y > y2) && (x == x1)) || ((y > y1) && (y < y2) && (x == x1))) && (print != -1))
               {
                   board[x][y] = type;
               }
           }
           if (board[x][y] == '~')
           {
               visible[x][y] = '~';
           }
           if ((board[x][y] >= 'b') && (board[x][y] <= 's') && (board[x][y] != 'm'))
           {
               visible[x][y] = '~';
           }
           if (board[x][y] == 'm')
           {
               visible[x][y] = 'm';
           }
           if (board[x][y] == '*')
           {
               visible[x][y] = '*';
           }
           if ((x == xtarget) && (y == ytarget))
           {
               if ((board[x][y] >= 'b') && (board[x][y] <= 's'))
               {
                   visible[x][y] = '*';
                   board[x][y] = '*';
                   *hits = *hits + 1;
               }
               if (board[x][y] == '~')
               {
                   visible[x][y] = 'm';
                   board[x][y] = 'm';
               }
           }

           if ((print != 0) && (player == 1))
           {
               printf("%c ", board[x][y]);
           }
           if ((print != 0) && (player == 2))
           {
               printf("%c ", visible[x][y]);
           }
           if ((y == 9) && (print != 0))
           {
               printf("| %d\n\t", x);
           }
       }
   }
   if (print != 0)
   {
       printf(" +---------------------+\n");
        printf("\t    0 1 2 3 4 5 6 7 8 9\n");
   }
   return board;
}

int select_who_starts_first(void)
{
   int select = 0, player = 0;
   select = rand() % 2;
   if (select == 0)
   {
       printf("Player1 (Human) goes first. . .\n\n");
       player = 1;
   }
   if (select == 1)
   {
       printf("Player2 (CPU) goes first. . .\n\n");
       player = 2;
   }
   return player;
}

int select_who_starts_firstM(char name1[],char name2[],char name3[])
{
   int select = 0, player = 0;
   select = rand() % 3;
   if (select == 0)
   {
        printf("Player %s goes First", name1);
       player = 1;
   }
   if (select == 1)
   {
         printf("Player %s goes First", name2);
       player = 2;
   }
      if (select == 2)
   {
         printf("Player %s goes First", name3);
       player = 3;
   }
   return player;
}

int deploy_ships(void)
{
   int deploy = 0;
   printf("How would you like to deploy your ships?\n1) Manually\n2) Randomly\n\n");
   scanf("%d", &deploy);
   return deploy;
}
int deploy_ships_M(char name[])
{
   int deploy = 0;
   printf(" %s how would you like to deploy your ships?\n1) Manually\n2) Randomly\n\n",name);
   scanf("%d", &deploy);
   return deploy;
}



void manually_place_ships_on_board(int *x1, int *y1, int *x2, int *y2, int size, char board[10][10])
{
   int check = 0, x_1 = 0, y_1 = 0, x_2 = 0, y_2 = 0, x_3 = 0, y_3 = 0, x = 0, y = 0;
   do
   {
       do
       {
           check = 0; x_1 = 0, y_1 = 0, x_2 = 0, y_2 = 0, x_3 = 0, y_3 = 0, *x1 = 0, *y1 = 0, *x2 = 0, *y2 = 0;
           printf("Enter the endpoint coordinates for your Ship, size: %d: \n", size);
           scanf("%d %d %d %d", y1, x1, y2, x2);
           if ((*x1 != *x2) && (*y1 != *y2))
           {
               printf("The ship cannot be diagonal!\n");
           }
           if (*y1 == *y2)
           {
               check = abs(*x1 - *x2) + 1;
           }
           if (*x1 == *x2)
           {
               check = abs(*y1 - *y2) + 1;
           }
           if (check != size)
           {
               printf("The ship does not fit those coordinates!\n");
           }
       } while (((*x1 < 0) || (*x1 > 9)) || ((*y1 < 0) && (*y1 > 9)) || ((*x2 < 0) || (*x2 > 9)) || ((*y2 < 0) && (*y2 > 9)) ||
           ((*x1 != *x2) && (*y1 != *y2)) || (check != size));
       if (*y1 == *y2)
       {
           if (*x1 > *x2)
           {
               if (size > 2)
               {
                   x_1 = *x2 + 1;
                   y_1 = *y1;
               }
               if (size > 3)
               {
                   x_2 = *x2 + 2;
                   y_2 = *y1;
               }
               if (size > 4)
               {
                   x_3 = *x2 + 3;
                   y_3 = *y1;
               }
           }
           if (*x1 < *x2)
           {
               if (size > 2)
               {
                   x_1 = *x1 + 1;
                   y_1 = *y1;
               }
               if (size > 3)
               {
                   x_2 = *x1 + 2;
                   y_2 = *y1;
               }
               if (size > 4)
               {
                   x_3 = *x1 + 3;
                   y_3 = *y1;
               }
           }
       }
       if (*x1 == *x2)
       {
           if (*y1 < *y2)
           {
               if (size > 2)
               {
                   x_1 = *x1;
                   y_1 = *y1 + 1;
               }
               if (size > 3)
               {
                   x_2 = *x1;
                   y_2 = *y1 + 2;
               }
               if (size > 4)
               {
                   x_3 = *x1;
                   y_3 = *y1 + 3;
               }
           }
           if (*y1 > *y2)
           {
               if (size > 2)
               {
                   x_1 = *x1;
                   y_1 = *y2 + 1;
               }
               if (size > 3)
               {
                   x_2 = *x1;
                   y_2 = *y2 + 2;
               }
               if (size > 4)
               {
                   x_3 = *x1;
                   y_3 = *y2 + 3;
               }
           }
       }
       if ((((board[*x1][*y1] > 'a') && (board[*x1][*y1] < 'z')) || ((board[*x2][*y2] > 'a') && (board[*x2][*y2] < 'z')) || (((board[x_1][y_1] > 'a') && (board[x_1][y_1] < 'z')) && (size > 2)) ||
           (((board[x_2][y_2] > 'a') && (board[x_2][y_2] < 'z')) && (size > 3)) || (((board[x_3][y_3] > 'a') && (board[x_3][y_3] < 'z') && (size > 4)))))
       {
           printf("Your ships cannot overlap!\n");
       }
   } while ((((board[*x1][*y1] > 'a') && (board[*x1][*y1] < 'z')) || ((board[*x2][*y2] > 'a') && (board[*x2][*y2] < 'z')) || (((board[x_1][y_1] > 'a') && (board[x_1][y_1] < 'z')) && (size > 2)) ||
       (((board[x_2][y_2] > 'a') && (board[x_2][y_2] < 'z')) && (size > 3)) || (((board[x_3][y_3] > 'a') && (board[x_3][y_3] < 'z') && (size > 4)))));
}

void randomly_place_ships_on_board(int *x1, int *y1, int *x2, int *y2, int size, char board[10][10])
{
   int way = 0, x_1 = 0, y_1 = 0, x_2 = 0, y_2 = 0, x_3 = 0, y_3 = 0;
   do
   {
       *x1 = rand() % 10;
       *y1 = rand() % 10;
       way = rand() % 2;
       if (way == 0)
       {
           *x2 = *x1 - size + 1;
           *y2 = *y1;
           if (size > 2)
           {
               x_1 = *x2 + 1;
               y_1 = *y1;
           }
           if (size > 3)
           {
               x_2 = *x2 + 2;
               y_2 = *y1;
           }
           if (size > 4)
           {
               x_3 = *x2 + 3;
               y_3 = *y1;
           }
       }
       if (way == 1)
       {
           *y2 = *y1 - size + 1;
           *x2 = *x1;
           if (size > 2)
           {
               x_1 = *x1;
               y_1 = *y2 + 1;
           }
           if (size > 3)
           {
               x_2 = *x1;
               y_2 = *y2 + 2;
           }
           if (size > 4)
           {
               x_3 = *x1;
               y_3 = *y2 + 3;
           }
       }
   } while ((*x2 < 1) || (*y2 < 1) || (*x2 > 9) || (*y2 > 9) || ((board[*x1][*y1] > 'a') && (board[*x1][*y1] < 'z')) ||
       ((board[*x2][*y2] > 'a') && (board[*x2][*y2] < 'z')) || ((board[x_1][y_1] > 'a') && (board[x_1][y_1] < 'z')) ||
       ((board[x_2][y_2] > 'a') && (board[x_2][y_2] < 'z')) || ((board[x_3][y_3] > 'a') && (board[x_3][y_3] < 'z')));
}

void shoot_manual(int *xtarget, int *ytarget, char board[10][10])
{
   do
   {
       do
       {
           printf("Enter target coordinates: \n");
           scanf("%d %d", ytarget, xtarget);
           if ((*xtarget > 9) || (*xtarget < 0) || (*ytarget > 9) || (*ytarget < 0))
           {
               printf("Your target coordinates must be from 0-9!\n");
           }
       } while ((*xtarget > 9) || (*xtarget < 0) || (*ytarget > 9) || (*ytarget < 0));
       if ((board[*xtarget][*ytarget] == '*') || (board[*xtarget][*ytarget] == 'm'))
       {
           printf("A shot is already there! \n");
       }
   } while ((board[*xtarget][*ytarget] == '*') || (board[*xtarget][*ytarget] == 'm'));
}
void shoot_random(int *xtarget, int *ytarget, char board[10][10])
{
   do
   {
       *xtarget = rand() % 10;
       *ytarget = rand() % 10;
   } while ((board[*xtarget][*ytarget] == '*') || (board[*xtarget][*ytarget] == 'm'));
}
int check_ship(char board[10][10], int *sunkc, int *sunkb, int *sunkr, int *sunks, int *sunkd)
{
   int x = 0, y = 0, c = 0, b = 0, r = 0, s = 0, d = 0;
   for (x = 0; x < 10; x++)
   {
       for (y = 0; y < 10; y++)
       {
           if ((board[x][y] == 'c') && (*sunkc == 0))
           {
               c++;
           }
           if ((board[x][y] == 'b') && (*sunkb == 0))
           {
               b++;
           }
           if ((board[x][y] == 'r') && (*sunkr == 0))
           {
               r++;
           }
           if ((board[x][y] == 's') && (*sunks == 0))
           {
               s++;
           }
           if ((board[x][y] == 'd') && (*sunkd == 0))
           {
               d++;
           }
       }
   }
   if ((c == 0) && (*sunkc != -1))
   {
       printf("You sunk my Aircraft Carrier!\n");
       *sunkc = 1;
   }
   if ((b == 0) && (*sunkb != -1))
   {
       printf("You sunk my Battleship!\n");
       *sunkb = 1;
   }
   if ((r == 0) && (*sunkr != -1))
   {
       printf("You sunk my Cruiser!\n");
       *sunkr = 1;
   }
   if ((s == 0) && (*sunks != -1))
   {
       printf("You sunk my Submarine!\n");
       *sunks = 1;
   }
   if ((d == 0) && (*sunkd != -1))
   {
       printf("You sunk my Destroyer!\n");
       *sunkd = 1;
   }
}

void output_move(FILE *outfile, int xtarget, int ytarget, int player, int hit, int *sunkc, int *sunkb, int *sunkr, int *sunks, int *sunkd)
{
   if ((xtarget != -1) && (ytarget != -1))
   {
       fprintf(outfile, "Player%d: (%d,%d)\t", player, xtarget, ytarget);
   }
   if (hit == 1)
   {
       fprintf(outfile, "Hit!\n");
   }
   if (hit == 0)
   {
       fprintf(outfile, "Miss...\n");
   }
   if (*sunkc == 1)
   {
       fprintf(outfile, "Sunk Aircraft Carrier!\n");
       *sunkc = -1;
   }
   if (*sunkb == 1)
   {
       fprintf(outfile, "Sunk Battleship!\n");
       *sunkb = -1;
   }
   if (*sunkr == 1)
   {
       fprintf(outfile, "Sunk Cruiser!\n");
       *sunkr = -1;
   }
   if (*sunks == 1)
   {
       fprintf(outfile, "Sunk Submarine!\n");
       *sunks = -1;
   }
   if (*sunkd == 1)
   {
       fprintf(outfile, "Sunk Destroyer!\n");
       *sunkd = -1;
   }
   fprintf(outfile, "\n");
}

void output_stats(FILE *outfile, stats player)
{
   if (player.win == 1)
   {
       fprintf(outfile, "\nPlayer %s %d Wins!!\n", player.fname,player.player_num);
   }
//Added Name attribute to the stats of players   
   if (player.win == 0)
   {
       fprintf(outfile, "\nPlayer %s %d Losses... \n",player.fname, player.player_num);
   }
   fprintf(outfile, "\n***Player%d Stats***\nHits: %d\nMisses: %d\nTotal Shots: %d\nAccuracy: %.2lf%%\n\n",
       player.player_num, player.hits, player.misses, player.shots, player.accuracy);
}
/*************** File name: BattleShip.c ***************/
#include"Battleship.h"

int main(void)
{
   int select = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0, deploy = 0, carrier = 5, battleship = 4, cruiser = 3, submarine = 3, destroyer = 2, x = 0, y = 0,
       shots1 = 0, shots2 = 0, status = 0, player = 0, player1_hits = 0, player2_hits = 0, xtarget = -1, ytarget = -1,
       sunkc = 0, sunkb = 0, sunkr = 0, sunks = 0, sunkd = 0, misses1 = 0, misses2 = 0, hit = 0, hit2 = 0,
       c = 0, b = 0, r = 0, s = 0, d = 0;
   stats player_1, player_2;
   char player1[10][10], player2[10][10], visible[10][10], carr = 'c', battle = 'b', cruise = 'r', sub = 's', destroy = 'd',
       initial = '\0', type = '\0';
   double accuracy1 = 0.0, accuracy2 = 0.0;
   FILE *output_file = NULL;
   srand(time(NULL));
   output_file = fopen("Battleship.log", "w");

   welcome_screen();
 //  system("Pause");
  // system("cls");
  int game_type=1;
  printf(" \n\n Enter 1 to play vs computer \n\n Enter 2 For multiplayer( 3 players gameplay) game\n ");
   scanf("%d", &game_type);
   if(game_type==2){
       multi_player_gameplay();
   }
   else if(game_type==1)
  {
   deploy = deploy_ships();
   printf("\t **** Enemy's Board ****\n");
   randomly_place_ships_on_board(&x1, &y1, &x2, &y2, carrier, player2);
   player2[10][10] = initialize_game_board(x1, y1, x2, y2, player2, 0, 2, xtarget, ytarget, &player2_hits, visible, carr);
   randomly_place_ships_on_board(&x1, &y1, &x2, &y2, battleship, player2);
   player2[10][10] = initialize_game_board(x1, y1, x2, y2, player2, 0, 2, xtarget, ytarget, &player2_hits, visible, battle);
   randomly_place_ships_on_board(&x1, &y1, &x2, &y2, cruiser, player2);
   player2[10][10] = initialize_game_board(x1, y1, x2, y2, player2, 0, 2, xtarget, ytarget, &player2_hits, visible, cruise);
   randomly_place_ships_on_board(&x1, &y1, &x2, &y2, submarine, player2);
   player2[10][10] = initialize_game_board(x1, y1, x2, y2, player2, 0, 2, xtarget, ytarget, &player2_hits, visible, sub);
   randomly_place_ships_on_board(&x1, &y1, &x2, &y2, destroyer, player2);
   player2[10][10] = initialize_game_board(x1, y1, x2, y2, player2, 1, 2, xtarget, ytarget, &player2_hits, visible, destroy);
   //Places Enemy's ships on his board
   printf("\n\t **** Your Board ****\n");
   if (deploy == 1)
   {
       manually_place_ships_on_board(&x1, &y1, &x2, &y2, carrier, player1);
       player1[10][10] = initialize_game_board(x1, y1, x2, y2, player1, 1, 1, xtarget, ytarget, &player1_hits, visible, carr);
       manually_place_ships_on_board(&x1, &y1, &x2, &y2, battleship, player1);
       player1[10][10] = initialize_game_board(x1, y1, x2, y2, player1, 1, 1, xtarget, ytarget, &player1_hits, visible, battle);
       manually_place_ships_on_board(&x1, &y1, &x2, &y2, cruiser, player1);
       player1[10][10] = initialize_game_board(x1, y1, x2, y2, player1, 1, 1, xtarget, ytarget, &player1_hits, visible, cruise);
       manually_place_ships_on_board(&x1, &y1, &x2, &y2, submarine, player1);
       player1[10][10] = initialize_game_board(x1, y1, x2, y2, player1, 1, 1, xtarget, ytarget, &player1_hits, visible, sub);
       manually_place_ships_on_board(&x1, &y1, &x2, &y2, destroyer, player1);
       player1[10][10] = initialize_game_board(x1, y1, x2, y2, player1, 1, 1, xtarget, ytarget, &player1_hits, visible, destroy);
   }//Manually places your ships on your board
   if (deploy == 2)
   {
       randomly_place_ships_on_board(&x1, &y1, &x2, &y2, carrier, player1);
       player1[10][10] = initialize_game_board(x1, y1, x2, y2, player1, 0, 1, xtarget, ytarget, &player1_hits, visible, carr);
       randomly_place_ships_on_board(&x1, &y1, &x2, &y2, battleship, player1);
       player1[10][10] = initialize_game_board(x1, y1, x2, y2, player1, 0, 1, xtarget, ytarget, &player1_hits, visible, battle);
       randomly_place_ships_on_board(&x1, &y1, &x2, &y2, cruiser, player1);
       player1[10][10] = initialize_game_board(x1, y1, x2, y2, player1, 0, 1, xtarget, ytarget, &player1_hits, visible, cruise);
       randomly_place_ships_on_board(&x1, &y1, &x2, &y2, submarine, player1);
       player1[10][10] = initialize_game_board(x1, y1, x2, y2, player1, 0, 1, xtarget, ytarget, &player1_hits, visible, sub);
       randomly_place_ships_on_board(&x1, &y1, &x2, &y2, destroyer, player1);
       player1[10][10] = initialize_game_board(x1, y1, x2, y2, player1, 1, 1, xtarget, ytarget, &player1_hits, visible, destroy);
   }
   //Randomly places your ships on your board
   x1 = -1, y1 = -1, x2 = -1, y2 = -1;
   player = select_who_starts_first();
   system("Pause");
   if (player == 2)
   {
       shots2 = 1;
   }
   switch (player)//Runs game based on who goes first
   {
   //Player 1 goes first
   case 1: do
   {
       xtarget = -1, ytarget = -1;
      // system("cls");
       printf("\t **** Enemy's Board ****\n");
       initialize_game_board(x1, y1, x2, y2, player2, 1, 2, xtarget, ytarget, &player1_hits, visible, initial);
       printf("Hits: %d\tShots: %d\n", player2_hits, shots2);
       printf("\n\t **** Your Board ****\n");
       initialize_game_board(x1, y1, x2, y2, player1, 1, 1, xtarget, ytarget, &player2_hits, visible, initial);
       printf("Hits: %d\tShots: %d\n", player1_hits, shots1);
       //Prints Boards

       shoot_manual(&xtarget, &ytarget, player2);
       shots1++;
       //system("cls");
       printf("\t **** Enemy's Board ****\n");
       player2[10][10] = initialize_game_board(x1, y1, x2, y2, player2, 1, 2, xtarget, ytarget, &player1_hits, visible, initial);
       printf("Hits: %d\tShots: %d Target(%d,%d)", player2_hits, shots2, ytarget, xtarget);
       if (player2[xtarget][ytarget] == '*')
       {
           printf("\tHit!\n");
           hit = 1;
       }
       if (player2[xtarget][ytarget] == 'm')
       {
           printf("\tMiss...\n");
           hit = 0;
       }
       check_ship(player2, &sunkc, &sunkb, &sunkr, &sunks, &sunkd);
       output_move(output_file, xtarget, ytarget, 1, hit, &sunkc, &sunkb, &sunkr, &sunks, &sunkd);
       xtarget = -1, ytarget = -1;
       printf("\n\t **** Your Board ****\n");
       initialize_game_board(x1, y1, x2, y2, player1, 1, 1, xtarget, ytarget, &player2_hits, visible, initial);
       printf("Hits: %d\tShots: %d\n", player1_hits, shots1);
       system("Pause");
       system("cls");
       //Player1 shot
       if (player1_hits < 17)
       {
           printf("\t **** Enemy's Board ****\n");
           xtarget = -1, ytarget = -1;
           initialize_game_board(x1, y1, x2, y2, player2, 1, 2, xtarget, ytarget, &player1_hits, visible, initial);
           printf("Hits: %d\tShots: %d\n", player2_hits, shots2);
           printf("\n\t **** Your Board ****\n");
           shoot_random(&xtarget, &ytarget, player1);
           shots2++;
           player1[10][10] = initialize_game_board(x1, y1, x2, y2, player1, 1, 1, xtarget, ytarget, &player2_hits, visible, initial);
           printf("Hits: %d\tShots: %d Target: (%d,%d)", player1_hits, shots1, ytarget, xtarget);
           if (player1[xtarget][ytarget] == '*')
           {
               printf("\tHit!\n");
               hit = 1;
           }
           if (player1[xtarget][ytarget] == 'm')
           {
               printf("\tMiss...\n");
               hit = 0;
           }
           check_ship(player1, &sunkc, &sunkb, &sunkr, &sunks, &sunkd);
           output_move(output_file, xtarget, ytarget, 2, hit, &sunkc, &sunkb, &sunkr, &sunks, &sunkd);
       }
       system("Pause");
       system("cls");
       //Player2 shot
   } while ((player1_hits < 17) && (player2_hits < 17));
   break;
   //Player 2 goes first:
   case 2: do
   {
       xtarget = -1, ytarget = -1;
       system("cls");
       printf("\t **** Enemy's Board ****\n");
       initialize_game_board(x1, y1, x2, y2, player2, 1, 2, xtarget, ytarget, &player1_hits, visible, initial);
       printf("Hits: %d\tShots: %d\n", player2_hits, shots2);
       printf("\n\t **** Your Board ****\n");
       initialize_game_board(x1, y1, x2, y2, player1, 1, 1, xtarget, ytarget, &player2_hits, visible, initial);
       printf("Hits: %d\tScore: %d\n", player1_hits, shots1);
       system("cls");
       //Prints Boards

       printf("\t **** Enemy's Board ****\n");
       initialize_game_board(x1, y1, x2, y2, player2, 1, 2, xtarget, ytarget, &player1_hits, visible, initial);
       printf("Hits: %d\tShots: %d\n", player2_hits, shots2);
       printf("\n\t **** Your Board ****\n");
       shoot_random(&xtarget, &ytarget, player1);
       player1[10][10] = initialize_game_board(x1, y1, x2, y2, player1, 1, 1, xtarget, ytarget, &player2_hits, visible, initial);
       printf("Hits: %d\tShots: %d Target: (%d,%d)", player1_hits, shots1, ytarget, xtarget);
       if (player1[xtarget][ytarget] == '*')
       {
           printf("\tHit!\n");
           hit = 1;
       }
       if (player1[xtarget][ytarget] == 'm')
       {
           printf("\tMiss...\n");
           hit = 0;
       }
       check_ship(player1, &sunkc, &sunkb, &sunkr, &sunks, &sunkd);
       output_move(output_file, xtarget, ytarget, 2, hit, &sunkc, &sunkb, &sunkr, &sunks, &sunkd);
       //Player2 shot
       if (player2_hits < 17)
       {
           shoot_manual(&xtarget, &ytarget, player2);
           shots1++;
           system("cls");
           printf("\t **** Enemy's Board ****\n");
           player2[10][10] = initialize_game_board(x1, y1, x2, y2, player2, 1, 2, xtarget, ytarget, &player1_hits, visible, initial);
           printf("Hits: %d\tShots: %d Target: (%d,%d)", player2_hits, shots2, ytarget, xtarget);
           if (player2[xtarget][ytarget] == '*')
           {
               printf("\tHit!\n");
               hit = 1;
           }
           if (player2[xtarget][ytarget] == 'm')
           {
               printf("\tMiss...\n");
               hit = 0;
           }
           check_ship(player2, &sunkc, &sunkb, &sunkr, &sunks, &sunkd);
           printf("\n\t **** Your Board ****\n");
           initialize_game_board(x1, y1, x2, y2, player1, 1, 1, xtarget, ytarget, &player2_hits, visible, initial);
           printf("Hits: %d\tShots: %d\n", player1_hits, shots1);
           output_move(output_file, xtarget, ytarget, 1, hit, &sunkc, &sunkb, &sunkr, &sunks, &sunkd);
       }
       shots2++;
       system("Pause");
       system("cls");
       //Player1 shot
   } while ((player1_hits < 17) && (player2_hits < 17));
   break;
   }
   if (player1_hits == 17)
   {
       printf("\nPlayer1 Wins!!!\n\n");
       player_1.win = 1;
       player_2.win = 0;
   }
   if (player2_hits == 17)
   {
       printf("\nPlayer2 Wins!!!\n\n");
       player_1.win = 0;
       player_2.win = 1;
   }
   misses1 = shots1 - player1_hits;
   misses2 = shots2 - player2_hits;
   accuracy1 = 100 * ((double)player1_hits) / ((double)shots1);
   accuracy2 = 100 * ((double)player2_hits) / ((double)shots2);
   player_1.player_num = 1;
   player_1.hits = player1_hits;
   player_1.misses = misses1;
   player_1.shots = shots1;
   player_1.accuracy = accuracy1;

   player_2.player_num = 2;
   player_2.hits = player2_hits;
   player_2.misses = misses2;
   player_2.shots = shots2;
   player_2.accuracy = accuracy2;
   output_stats(output_file, player_1);
   output_stats(output_file, player_2);
   printf("***Player1 Stats***\nHits: %d\nMisses: %d\nShots: %d\nAccuracy: %.2lf%%\n\n", player1_hits, misses1, shots1, accuracy1);
   printf("***Player2 Stats***\nHits: %d\nMisses: %d\nShots: %d\nAccuracy: %.2lf%%\n\n", player2_hits, misses2, shots2, accuracy2);
   //Prints stats to screen and to file
   fclose(output_file);
}
   return 0;
}
//code for Multiplayer Game Play:
void multi_player_gameplay(){
    
   int select = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0, deploy = 0, carrier = 5, battleship = 4, cruiser = 3, submarine = 3, destroyer = 2, x = 0, y = 0,
       shots1 = 0, shots2 = 0, shots3 = 0, status = 0, player = 0, player1_hits = 0,player3_hits = 0, player2_hits = 0, xtarget = -1, ytarget = -1,
       sunkc = 0, sunkb = 0, sunkr = 0, sunks = 0, sunkd = 0, misses1 = 0,misses3 = 0, misses2 = 0, hit = 0, hit2 = 0, hit3 = 0,
       c = 0, b = 0, r = 0, s = 0, d = 0;
   stats player_1, player_2, player_3;
   char player1[10][10], player2[10][10],player3[10][10], visible[10][10], carr = 'c', battle = 'b', cruise = 'r', sub = 's', destroy = 'd',
       initial = '\0', type = '\0';
   double accuracy1 = 0.0, accuracy2 = 0.0,accuracy3 = 0.0;
   FILE *output_file = NULL;
   srand(time(NULL));
   
   output_file = fopen("Battleship.log", "w");

printf("\nmulti player game play starts here\n");
 char name1[20],name2[20],name3[20];
    printf("Enter First Player name: ");
    scanf("%s", name1);
  
    // printf("Your name is %s.\n", name1);
     printf("Enter Second Player name: ");
    scanf("%s", name2);
   
    // printf("Your name is %s. \n", name2);
     printf("Enter Third Player name: ");
    scanf("%s",name3);
    // printf("Your name is %s. \n", name3);
    int turn=1;
    //turn= select_who_starts_firstM(name1,name2,name3);
    bool start=false;
    bool start1=true;
    bool start2=false;
    bool start3=false;
    //Flag variable to change turns of players
    while(player1_hits<17 && player2_hits<17 && player3_hits<17){//terimnation condition if one of the players gets 17 hits then he wins
        if(turn==1){
            deploy = deploy_ships_M(name1);//same as previous deploy function
                printf("\n\t **** Player %s Board ****\n",name1);
                if (deploy == 1)
                {
                    manually_place_ships_on_board(&x1, &y1, &x2, &y2, carrier, player1);
                    player1[10][10] = initialize_game_board(x1, y1, x2, y2, player1, 1, 1, xtarget, ytarget, &player1_hits, visible, carr);
                    manually_place_ships_on_board(&x1, &y1, &x2, &y2, battleship, player1);
                    player1[10][10] = initialize_game_board(x1, y1, x2, y2, player1, 1, 1, xtarget, ytarget, &player1_hits, visible, battle);
                    manually_place_ships_on_board(&x1, &y1, &x2, &y2, cruiser, player1);
                    player1[10][10] = initialize_game_board(x1, y1, x2, y2, player1, 1, 1, xtarget, ytarget, &player1_hits, visible, cruise);
                    manually_place_ships_on_board(&x1, &y1, &x2, &y2, submarine, player1);
                    player1[10][10] = initialize_game_board(x1, y1, x2, y2, player1, 1, 1, xtarget, ytarget, &player1_hits, visible, sub);
                    manually_place_ships_on_board(&x1, &y1, &x2, &y2, destroyer, player1);
                    player1[10][10] = initialize_game_board(x1, y1, x2, y2, player1, 1, 1, xtarget, ytarget, &player1_hits, visible, destroy);
                }//Manually places your ships on your board
                if (deploy == 2)
                {
                    randomly_place_ships_on_board(&x1, &y1, &x2, &y2, carrier, player1);
                    player1[10][10] = initialize_game_board(x1, y1, x2, y2, player1, 0, 1, xtarget, ytarget, &player1_hits, visible, carr);
                    randomly_place_ships_on_board(&x1, &y1, &x2, &y2, battleship, player1);
                    player1[10][10] = initialize_game_board(x1, y1, x2, y2, player1, 0, 1, xtarget, ytarget, &player1_hits, visible, battle);
                    randomly_place_ships_on_board(&x1, &y1, &x2, &y2, cruiser, player1);
                    player1[10][10] = initialize_game_board(x1, y1, x2, y2, player1, 0, 1, xtarget, ytarget, &player1_hits, visible, cruise);
                    randomly_place_ships_on_board(&x1, &y1, &x2, &y2, submarine, player1);
                    player1[10][10] = initialize_game_board(x1, y1, x2, y2, player1, 0, 1, xtarget, ytarget, &player1_hits, visible, sub);
                    randomly_place_ships_on_board(&x1, &y1, &x2, &y2, destroyer, player1);
                    player1[10][10] = initialize_game_board(x1, y1, x2, y2, player1, 1, 1, xtarget, ytarget, &player1_hits, visible, destroy);
                }
        turn++;

        }else if(turn==2){
            deploy = deploy_ships_M(name2);
            printf("\n\t **** Player %s  Board****\n",name2);
            if (deploy == 1)
            {
                manually_place_ships_on_board(&x1, &y1, &x2, &y2, carrier, player2);
                player2[10][10] = initialize_game_board(x1, y1, x2, y2, player2, 1, 1, xtarget, ytarget, &player2_hits, visible, carr);
                manually_place_ships_on_board(&x1, &y1, &x2, &y2, battleship, player2);
                player2[10][10] = initialize_game_board(x1, y1, x2, y2, player2, 1, 1, xtarget, ytarget, &player2_hits, visible, battle);
                manually_place_ships_on_board(&x1, &y1, &x2, &y2, cruiser, player2);
                player2[10][10] = initialize_game_board(x1, y1, x2, y2, player2, 1, 1, xtarget, ytarget, &player2_hits, visible, cruise);
                manually_place_ships_on_board(&x1, &y1, &x2, &y2, submarine, player1);
                player2[10][10] = initialize_game_board(x1, y1, x2, y2, player2, 1, 1, xtarget, ytarget, &player2_hits, visible, sub);
                manually_place_ships_on_board(&x1, &y1, &x2, &y2, destroyer, player2);
                player2[10][10] = initialize_game_board(x1, y1, x2, y2, player2, 1, 1, xtarget, ytarget, &player2_hits, visible, destroy);
            }//Manually places your ships on your board
            if (deploy == 2)
            {
                randomly_place_ships_on_board(&x1, &y1, &x2, &y2, carrier, player2);
                player2[10][10] = initialize_game_board(x1, y1, x2, y2, player2, 0, 1, xtarget, ytarget, &player2_hits, visible, carr);
                randomly_place_ships_on_board(&x1, &y1, &x2, &y2, battleship, player2);
                player2[10][10] = initialize_game_board(x1, y1, x2, y2, player2, 0, 1, xtarget, ytarget, &player2_hits, visible, battle);
                randomly_place_ships_on_board(&x1, &y1, &x2, &y2, cruiser, player2);
                player2[10][10] = initialize_game_board(x1, y1, x2, y2, player2, 0, 1, xtarget, ytarget, &player2_hits, visible, cruise);
                randomly_place_ships_on_board(&x1, &y1, &x2, &y2, submarine, player2);
                player2[10][10] = initialize_game_board(x1, y1, x2, y2, player2, 0, 1, xtarget, ytarget, &player2_hits, visible, sub);
                randomly_place_ships_on_board(&x1, &y1, &x2, &y2, destroyer, player2);
                player2[10][10] = initialize_game_board(x1, y1, x2, y2, player2, 1, 1, xtarget, ytarget, &player2_hits, visible, destroy);
            }
        turn++;
        }else if(turn==3){
            deploy = deploy_ships_M(name3);
            printf("\n\t **** Player %s  Board****\n",name3);
            if (deploy == 1)
            {
                manually_place_ships_on_board(&x1, &y1, &x2, &y2, carrier, player3);
                player3[10][10] = initialize_game_board(x1, y1, x2, y2, player3, 1, 1, xtarget, ytarget, &player3_hits, visible, carr);
                manually_place_ships_on_board(&x1, &y1, &x2, &y2, battleship, player3);
                player3[10][10] = initialize_game_board(x1, y1, x2, y2, player3, 1, 1, xtarget, ytarget, &player3_hits, visible, battle);
                manually_place_ships_on_board(&x1, &y1, &x2, &y2, cruiser, player3);
                player3[10][10] = initialize_game_board(x1, y1, x2, y2, player3, 1, 1, xtarget, ytarget, &player3_hits, visible, cruise);
                manually_place_ships_on_board(&x1, &y1, &x2, &y2, submarine, player3);
                player3[10][10] = initialize_game_board(x1, y1, x2, y2, player3, 1, 1, xtarget, ytarget, &player3_hits, visible, sub);
                manually_place_ships_on_board(&x1, &y1, &x2, &y2, destroyer, player3);
                player3[10][10] = initialize_game_board(x1, y1, x2, y2, player3, 1, 1, xtarget, ytarget, &player3_hits, visible, destroy);
            }//Manually places your ships on your board
            if (deploy == 2)
            {
                randomly_place_ships_on_board(&x1, &y1, &x2, &y2, carrier, player3);
                player3[10][10] = initialize_game_board(x1, y1, x2, y2, player3, 0, 1, xtarget, ytarget, &player3_hits, visible, carr);
                randomly_place_ships_on_board(&x1, &y1, &x2, &y2, battleship, player3);
                player3[10][10] = initialize_game_board(x1, y1, x2, y2, player3, 0, 1, xtarget, ytarget, &player3_hits, visible, battle);
                randomly_place_ships_on_board(&x1, &y1, &x2, &y2, cruiser, player3);
                player3[10][10] = initialize_game_board(x1, y1, x2, y2, player3, 0, 1, xtarget, ytarget, &player3_hits, visible, cruise);
                randomly_place_ships_on_board(&x1, &y1, &x2, &y2, submarine, player3);
                player3[10][10] = initialize_game_board(x1, y1, x2, y2, player3, 0, 1, xtarget, ytarget, &player3_hits, visible, sub);
                randomly_place_ships_on_board(&x1, &y1, &x2, &y2, destroyer, player3);
                player3[10][10] = initialize_game_board(x1, y1, x2, y2, player3, 1, 1, xtarget, ytarget, &player3_hits, visible, destroy);
            }
            turn++;
            start=true;

        }

        if(start && start1){
                    system("cls");

            printf("\nTurn===%s\n1st Attack on player %s \n",name1,name2);
              xtarget = -1, ytarget = -1;
      // system("cls");
        
            initialize_game_board(x1, y1, x2, y2, player2, 1, 2, xtarget, ytarget, &player1_hits, visible, initial);
            printf(" %s Hits: %d\tShots: %d\n",name1, player1_hits, shots1);
          //  printf("\n\t **** %s Board ****\n",name1);
          //  initialize_game_board(x1, y1, x2, y2, player1, 1, 1, xtarget, ytarget, &player2_hits, visible, initial);
          //  printf("Hits: %d\tShots: %d\n", player1_hits, shots1);
            //Prints Boards

            shoot_manual(&xtarget, &ytarget, player2);
            shots1++;
          
            printf("\n\t **** %s  Enemy Board  After Attack1 ****\n",name2);
            player2[10][10] = initialize_game_board(x1, y1, x2, y2, player2, 1, 2, xtarget, ytarget, &player1_hits, visible, initial);
    //        printf("Hits: %d\tShots: %d Target(%d,%d)", player2_hits, shots2, ytarget, xtarget);
     //         system("cls");
            printf("\nTurn===%s \n 2nd Attack on player %s \n",name1,name3);
              xtarget = -1, ytarget = -1;
       //    system("cls");
        
            initialize_game_board(x1, y1, x2, y2, player3, 1, 2, xtarget, ytarget, &player1_hits, visible, initial);
            printf("%s Hits: %d\tShots: %d\n",name1, player1_hits, shots1);
         //   printf("\n\t **** %s Board ****\n",name1);
          //  initialize_game_board(x1, y1, x2, y2, player1, 1, 1, xtarget, ytarget, &player2_hits, visible, initial);
         //   printf("Hits: %d\tShots: %d\n", player1_hits, shots1);
            //Prints Boards

            shoot_manual(&xtarget, &ytarget, player3);
            shots1++;
         //   system("cls");
            printf("\n\t **** %s  Enemy Board After 2nd Attack****\n",name3);
            player3[10][10] = initialize_game_board(x1, y1, x2, y2, player3, 1, 2, xtarget, ytarget, &player1_hits, visible, initial);
            printf("%s  Hits: %d\tShots: %d Target(%d,%d)",name1, player1_hits, shots1, ytarget, xtarget);

            start1=false;
            start2=true;
        
        }else if(start && start2){
                    system("cls");

            printf("\nTurn===%s\n 1st Attack on player %s \n",name2,name1);
              xtarget = -1, ytarget = -1;
      // system("cls");
        
            initialize_game_board(x1, y1, x2, y2, player1, 1, 2, xtarget, ytarget, &player2_hits, visible, initial);
            printf("%s Hits: %d\tShots: %d\n",name2, player2_hits, shots2);
        //    printf("\n\t **** %s Board ****\n",name2);
         //   initialize_game_board(x1, y1, x2, y2, player2, 1, 1, xtarget, ytarget, &player1_hits, visible, initial);
         //   printf("Hits: %d\tShots: %d\n", player2_hits, shots2);
            //Prints Boards

            shoot_manual(&xtarget, &ytarget, player1);
            shots2++;
            //system("cls");
                printf("\n\t **** %s  Enemy Board After Attack 1 ****\n",name1);
            player1[10][10] = initialize_game_board(x1, y1, x2, y2, player1, 1, 2, xtarget, ytarget, &player2_hits, visible, initial);
            printf("%s  Hits: %d\tShots: %d Target(%d,%d)",name2, player2_hits, shots2, ytarget, xtarget);

            printf("Turn==%s\n 2nd Attack on player %s \n",name2,name3);
              xtarget = -1, ytarget = -1;
      // system("cls");
        
            initialize_game_board(x1, y1, x2, y2, player3, 1, 2, xtarget, ytarget, &player2_hits, visible, initial);
            printf("%s Hits: %d\tShots: %d\n",name2, player2_hits, shots2);
        //    printf("\n\t **** %s Board ****\n",name2);
        //    initialize_game_board(x1, y1, x2, y2, player2, 1, 1, xtarget, ytarget, &player3_hits, visible, initial);
        //    printf("Hits: %d\tShots: %d\n", player2_hits, shots2);
            //Prints Boards

            shoot_manual(&xtarget, &ytarget, player3);
            shots2++;
        //    system("cls");
                printf("\n\t **** %s  Enemy Board After 2nd Attack ****\n",name3);
            player3[10][10] = initialize_game_board(x1, y1, x2, y2, player3, 1, 2, xtarget, ytarget, &player2_hits, visible, initial);
            printf("%s Hits: %d\tShots: %d Target(%d,%d)",name2, player2_hits, shots2, ytarget, xtarget);

            start1=false;
            start2=false;
            start3=true;
        }else if(start && start3){
                    system("cls");

            printf("Turn === %s \n 1st Attack on player %s \n",name3,name1);
              xtarget = -1, ytarget = -1;
      // system("cls");
        
            initialize_game_board(x1, y1, x2, y2, player1, 1, 2, xtarget, ytarget, &player3_hits, visible, initial);
            // printf("Hits: %d\tShots: %d\n", player1_hits, shots1);
            // printf("\n\t **** %s Board ****\n",name3);
            // initialize_game_board(x1, y1, x2, y2, player3, 1, 1, xtarget, ytarget, &player1_hits, visible, initial);
            // printf("Hits: %d\tShots: %d\n", player3_hits, shots3);
            //Prints Boards

            shoot_manual(&xtarget, &ytarget, player1);
            shots3++;
            //system("cls");
                printf("\n\t **** %s  Enemy Board ****\n",name1);
            player1[10][10] = initialize_game_board(x1, y1, x2, y2, player1, 1, 2, xtarget, ytarget, &player3_hits, visible, initial);
            printf("Hits: %d\tShots: %d Target(%d,%d)", player1_hits, shots1, ytarget, xtarget);

            printf("\nThis is %s Turn \n Second Attack on player %s \n",name3,name2);
              xtarget = -1, ytarget = -1;
      // system("cls");
        
            initialize_game_board(x1, y1, x2, y2, player2, 1, 2, xtarget, ytarget, &player3_hits, visible, initial);
            // printf("Hits: %d\tShots: %d\n", player2_hits, shots2);
            // printf("\n\t **** %s Board ****\n",name3);
            // initialize_game_board(x1, y1, x2, y2, player3, 1, 1, xtarget, ytarget, &player2_hits, visible, initial);
            // printf("Hits: %d\tShots: %d\n", player3_hits, shots3);
            // //Prints Boards

            shoot_manual(&xtarget, &ytarget, player2);//function to get input from user to attack
            shots3++;
            system("cls");
            printf("\n\t **** %s  Enemy Board After 2nd Attack****\n",name2);
            player2[10][10] = initialize_game_board(x1, y1, x2, y2, player2, 1, 2, xtarget, ytarget, &player3_hits, visible, initial);
            printf("%s Hits: %d\tShots: %d Target(%d,%d)",name3, player3_hits, shots3, ytarget, xtarget);

            start1=true;
            start3=false;
        }
    }
      if (player1_hits >= 17)  // winning condition
   {
       printf("\n%s Wins!!!\n\n",name1);
       player_1.win = 1;
       player_2.win = 0;
        player_3.win = 0;
   }
   if (player2_hits >= 17)
   {
       printf("\n%s Wins!!!\n\n",name2);
       player_1.win = 0;
       player_2.win = 1;
        player_3.win = 0;
   }
      if (player3_hits >= 17)
   {
       printf("\n%s Wins!!!\n\n",name3);
       player_1.win = 0;
       player_2.win = 0;
        player_2.win = 1;
   }
   misses1 = shots1 - player1_hits;
   misses2 = shots2 - player2_hits;
     misses3 = shots3 - player3_hits;
   accuracy1 = 100 * ((double)player1_hits) / ((double)shots1);
   accuracy2 = 100 * ((double)player2_hits) / ((double)shots2);
   accuracy3 = 100 * ((double)player3_hits) / ((double)shots3);
   
     player_1.fname=name1;
   player_1.player_num = 1;
   player_1.hits = player1_hits;
   player_1.misses = misses1;
   player_1.shots = shots1;
   player_1.accuracy = accuracy1;
   
      player_2.fname=name2;
   player_2.player_num = 2;
   player_2.hits = player2_hits;
   player_2.misses = misses2;
   player_2.shots = shots2;
   player_2.accuracy = accuracy2;
   
   player_3.fname=name3;
   player_3.player_num = 3;
   player_3.hits = player3_hits;
   player_3.misses = misses3;
   player_3.shots = shots3;
   player_3.accuracy = accuracy3;
   output_stats(output_file, player_1);
   output_stats(output_file, player_2);
   output_stats(output_file, player_3);
   printf("***%s Stats***\nHits: %d\nMisses: %d\nShots: %d\nAccuracy: %.2lf%%\n\n",name1, player1_hits, misses1, shots1, accuracy1);
   printf("***%s2 Stats***\nHits: %d\nMisses: %d\nShots: %d\nAccuracy: %.2lf%%\n\n",name2, player2_hits, misses2, shots2, accuracy2);
   printf("***%s2 Stats***\nHits: %d\nMisses: %d\nShots: %d\nAccuracy: %.2lf%%\n\n",name3, player3_hits, misses3, shots3, accuracy3);
   //Prints stats to screen and to file
   fclose(output_file);
 
    
}
