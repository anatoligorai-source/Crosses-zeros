//#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>


int repeat = 0;
int repeat_printf = 0;
int number_mass_printf = 0;
char crosses_zeros[9] = { '_','_','_','_','_','_','_','_','_' };
int number_mass;
int index_check = 0;
char number = 0;
int error = 0;
char buffer;

typedef enum
{
    PLAYER_1 = 1,
    PLAYER_2
}Number_player;

typedef enum
{
    WINNER_NO = 0,
    WINNER_YES = 2
}Chek_winner;

   void player_1_turn(void)
   {
       printf("Игрок 1 нажмите клавишу свободного поля от 1 до 9...\n");
       scanf_s(" %d", &number_mass);
   }

   void player_2_turn(void)
   {
       printf("Игрок 2 нажмите клавишу свободного поля от 1 до 9...\n");
       scanf_s(" %d", &number_mass);
   }

   void validation_button(void)
   {
       while ((number = scanf_s(" %d", &number_mass)) != 1)
       {
           printf("Ошибка! Вы нажали недопустимую клавишу\n");
         while (getchar() != '\n');
        //   while ((buffer = getchar()) != '\n' && buffer != EOF);
           printf("Попробуйте еще раз:\n ");
       }
   }
   void validation_number_player_1(void)
   {
       do
       {
           error = 0;
           if (('X' == crosses_zeros[number_mass - 1]) || ('0' == crosses_zeros[number_mass - 1]))
           {
               error = 1;
           }
           if (error == 1)
           {
               printf("Ошибка! Игрок 1 введите другое число...\n");
               scanf_s("%d", &number_mass);
           }
           else crosses_zeros[number_mass - 1] = 'X';

       } while (error == 1);
   }

   void validation_number_player_2(void)
   {
       do
       {
           error = 0;
           if (('X' == crosses_zeros[number_mass - 1]) || ('0' == crosses_zeros[number_mass - 1]))
           {
               error = 1;
           }
           if (error == 1)
           {
               printf("Ошибка! Игрок 2 введите другое число...\n");
               scanf_s("%d", &number_mass);
           }
           else crosses_zeros[number_mass - 1] = '0';

       } while (error == 1);
   }

   void print_game_board(void)
   {
       while (repeat_printf < 9)
       {
           if ((number_mass_printf == 2) || (number_mass_printf == 5) || (number_mass_printf == 8))
           {
               printf("%c\n", crosses_zeros[number_mass_printf]);
           }
           else
           {
               printf("%c", crosses_zeros[number_mass_printf]);
           }
           repeat_printf++;
           number_mass_printf++;
       }
       repeat_printf = 0;
       number_mass_printf = 0;
   }

   void print_game_over(void)
   {
       printf("Игра завершена\n");
   }

   void print_champion(int number_player)
   {
       switch (number_player)
       {
           case PLAYER_1:
           {
           printf("ПОБЕДИТЕЛЬ ИГРОК 1!!!!!\n");
           }break;
           case PLAYER_2:
           {
           printf("ПОБЕДИТЕЛЬ ИГРОК 2!!!!!\n");
           }break;
       }
   }

   int chek_winner(void)
   {
       int number = 0;
       if (
             ((crosses_zeros[0] == 'X') && (crosses_zeros[1] == 'X') && (crosses_zeros[2] == 'X')) ||
             ((crosses_zeros[3] == 'X') && (crosses_zeros[4] == 'X') && (crosses_zeros[5] == 'X')) ||
             ((crosses_zeros[6] == 'X') && (crosses_zeros[7] == 'X') && (crosses_zeros[8] == 'X')) ||
             ((crosses_zeros[0] == 'X') && (crosses_zeros[3] == 'X') && (crosses_zeros[6] == 'X')) ||
             ((crosses_zeros[1] == 'X') && (crosses_zeros[4] == 'X') && (crosses_zeros[7] == 'X')) ||
             ((crosses_zeros[2] == 'X') && (crosses_zeros[5] == 'X') && (crosses_zeros[8] == 'X')) ||
             ((crosses_zeros[0] == 'X') && (crosses_zeros[4] == 'X') && (crosses_zeros[8] == 'X')) ||
             ((crosses_zeros[2] == 'X') && (crosses_zeros[4] == 'X') && (crosses_zeros[6] == 'X')) ||
             ((crosses_zeros[0] == '0') && (crosses_zeros[1] == '0') && (crosses_zeros[2] == '0')) ||
             ((crosses_zeros[3] == '0') && (crosses_zeros[4] == '0') && (crosses_zeros[5] == '0')) ||
             ((crosses_zeros[6] == '0') && (crosses_zeros[7] == '0') && (crosses_zeros[8] == '0')) ||
             ((crosses_zeros[0] == '0') && (crosses_zeros[3] == '0') && (crosses_zeros[6] == '0')) ||
             ((crosses_zeros[1] == '0') && (crosses_zeros[4] == '0') && (crosses_zeros[7] == '0')) ||
             ((crosses_zeros[2] == '0') && (crosses_zeros[5] == '0') && (crosses_zeros[8] == '0')) ||
             ((crosses_zeros[0] == '0') && (crosses_zeros[4] == '0') && (crosses_zeros[8] == '0')) ||
             ((crosses_zeros[2] == '0') && (crosses_zeros[4] == '0') && (crosses_zeros[6] == '0'))
           )
       {
           number = WINNER_YES;
           return number;
       }
          
       else
       {
           number = WINNER_NO;
           return number;
       }
       
   }


int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    while (repeat < 9)
    {
        player_1_turn();
   //     validation_button();
        validation_number_player_1();
        if (chek_winner() == 2)
        {
            print_champion(PLAYER_1);
            repeat = 8;
        }
        print_game_board();

        repeat++;

        if (repeat == 9)
        {
            print_game_over();
        }

        if (repeat != 9)
        {
        player_2_turn();
  //      validation_button();
        validation_number_player_2();
            if (chek_winner() == 2)
            {
            print_champion(PLAYER_2);
            repeat = 8;
            }
        print_game_board();
        }
        repeat++;
    }
    return 0;
}
