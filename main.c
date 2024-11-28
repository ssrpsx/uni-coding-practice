#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#define max_value 256
struct username
{
    char id[max_value];
    char pass[max_value];
    char gmail[max_value];
    char credit[max_value];
} user;

void ft_welcome();
void ft_login();
void ft_register();
void ft_main();
void ft_valorant();
void ft_rov();
void ft_roblox();
void ft_lineranger();
void ft_genshin();
void successfully();
void ft_topup();
void ft_history();
void ft_split(char str[100], char outputstr[][max_value]);
void ft_split_13(char str[100], char outputstr[][max_value]);
void ft_termgame(char username[max_value], int int_game, int int_value);
char *ft_replace(char input[max_value]);
char *ft_comma(char str[max_value]);

void disableEcho() {
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, mode & ~ENABLE_ECHO_INPUT);
    }

void enableEcho() {
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, mode | ENABLE_ECHO_INPUT);
}

void red () {
  printf("\e[1;91m");
}

void green() {
  printf("\e[1;92m");
}

void yellow() {
  printf("\e[1;93m");
}

void blue () {
  printf("\e[1;94m");
}

void purple() {
  printf("\e[1;95m");
}

void cyan() {
  printf("\e[1;96m");
}

void cyan1() {
  printf("\033[1;38m");
}
void white()
{
  printf("\e[1;97m");
}

void reset() {
  printf("\033[0m");
}

void ft_split(char str[100], char outputstr[][max_value])
{
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    char *token = strtok(str, ",");
    int i = 0;
    while (token != NULL && i < 4)
    {
        strncpy(outputstr[i], token, max_value - 1);
        outputstr[i][max_value - 1] = '\0'; // ให้แน่ใจว่า null-terminated
        token = strtok(NULL, ",");
        i++;
    }
}

void ft_split_13(char str[100], char outputstr[][max_value])
{
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    char *token = strtok(str, ",");
    int i = 0;
    while (token != NULL && i < 14)
    {
        strncpy(outputstr[i], token, max_value - 1);
        outputstr[i][max_value - 1] = '\0'; // ให้แน่ใจว่า null-terminated
        token = strtok(NULL, ",");
        i++;
    }
}

void ft_welcome()
{
    int userinput;

    system("cls");
    reset();
    cyan1();
    red();
    printf("\n");
    printf("    ===============================================================================================================\n");
    printf("    ===                                                                                                         ===\n");
    printf("    ===                                                                                                         ===\n");
    printf("    ===         ###         ###  #########  ###         #######      ######     ###     ###  #########          ===\n");
    printf("    ===         ###   ###   ###  ###        ###       ####   ###   ####  ####   ####   ####  ###                ===\n");
    yellow();
    cyan1();
    printf("    ===         ###   ###   ###  ###        ###       ###         ###      ###  ##### #####  ###                ===\n");
    printf("    ===         ###   ###   ###  ########   ###       ###         ###      ###  ### ### ###  ########           ===\n");
    green();
    cyan1();
    printf("    ===         ###   ###   ###  ###        ###       ###         ###      ###  ###     ###  ###                ===\n");
    printf("    ===         ###   ###   ###  ###        ###       ####   ###   ####  ####   ###     ###  ###                ===\n");
    blue();
    cyan1();
    printf("    ===           ####    ####   #########  #########   #######      ######     ###     ###  #########          ===\n");
    printf("    ===                                                                                                         ===\n");
    purple();
    cyan1();
    printf("    ===                                                                                                         ===\n");
    printf("    ===============================================================================================================\n");   
    printf("                 |      Exit Program[0]      |          Login[1]         |        Register[2]        |      \n");
    printf("    ===============================================================================================================\n\n\n");
    reset();
    cyan1();    
    printf("    User input : ");
    scanf("%d", &userinput);
    if(userinput == 1) ft_login();
    else if(userinput == 2) ft_register();
}

void ft_login()
{
    char str[4][max_value], readfile[max_value];
    int check = 0;
    FILE *useroutputfile;
    useroutputfile = fopen("user.txt", "r");

    if (useroutputfile == NULL) {
    perror("Error opening file");
    return;
    }

    system("cls");
    reset();
    printf("\e[0;31m");
    printf("\n");
    printf("    ===============================================================================================================\n");
    printf("    ===                                                                                                         ===\n");
    printf("    ===                                                                                                         ===\n");
    printf("    ===         ###         ###  #########  ###         #######      ######     ###     ###  #########          ===\n");
    printf("    ===         ###   ###   ###  ###        ###       ####   ###   ####  ####   ####   ####  ###                ===\n");
    printf("\e[0;33m");
    printf("    ===         ###   ###   ###  ###        ###       ###         ###      ###  ##### #####  ###                ===\n");
    printf("    ===         ###   ###   ###  ########   ###       ###         ###      ###  ### ### ###  ########           ===\n");
    printf("\e[0;32m");
    printf("    ===         ###   ###   ###  ###        ###       ###         ###      ###  ###     ###  ###                ===\n");
    printf("    ===         ###   ###   ###  ###        ###       ####   ###   ####  ####   ###     ###  ###                ===\n");
    printf("\e[0;34m");
    printf("    ===           ####    ####   #########  #########   #######      ######     ###     ###  #########          ===\n");
    printf("    ===                                                                                                         ===\n");
    printf("\e[0;35m");
    printf("    ===                                                                                                         ===\n");
    printf("    ===============================================================================================================\n\n\n");
    purple();
    printf("                                                       Login                                                        \n");
    printf("                                                 __________________                                                 \n\n");
    printf("                                               Username : ");
    scanf("%s", &user.id);

    if(user.id[0] == '*')
    {
      system("main.exe");
      exit(0);
    }

    disableEcho();
    printf("                                               Password : ");
    scanf("%s", &user.pass);
    enableEcho();

    while (1)
    {
        fgets(readfile, sizeof(readfile), useroutputfile);
        if(feof(useroutputfile)) break;

        ft_split(readfile, str);
        if (strcmp(user.id, str[0]) == 0 && strcmp(user.pass, str[1]) == 0)
        {
            strcpy(user.gmail, str[2]);
            strcpy(user.credit, str[3]);
            check = 1;
            break;
        }
    }

    fclose(useroutputfile);
    if(check == 0)
    {
        printf("\n\nUsername or password is incorrect.\n");
        printf("If you want to return welcome page, enter * in the username.\n");
        system("pause");
        ft_login();
    }
    else ft_main();
}

void ft_register()
{
    char userid[max_value], userpass[max_value], usergmail[max_value], str[4][max_value], readfile[max_value];
    int check = 0;

    FILE *userinputfile, *useroutputfile;

    userinputfile = fopen("user.txt", "at");
    useroutputfile = fopen("user.txt", "r");

    if (userinputfile == NULL || useroutputfile == NULL) {
    perror("Error opening file");
    return;
    }
    system("cls");
    reset();
    printf("\e[0;31m");
    printf("\n");
    printf("    ===============================================================================================================\n");
    printf("    ===                                                                                                         ===\n");
    printf("    ===                                                                                                         ===\n");
    printf("    ===         ###         ###  #########  ###         #######      ######     ###     ###  #########          ===\n");
    printf("    ===         ###   ###   ###  ###        ###       ####   ###   ####  ####   ####   ####  ###                ===\n");
    printf("\e[0;33m");
    printf("    ===         ###   ###   ###  ###        ###       ###         ###      ###  ##### #####  ###                ===\n");
    printf("    ===         ###   ###   ###  ########   ###       ###         ###      ###  ### ### ###  ########           ===\n");
    printf("\e[0;32m");
    printf("    ===         ###   ###   ###  ###        ###       ###         ###      ###  ###     ###  ###                ===\n");
    printf("    ===         ###   ###   ###  ###        ###       ####   ###   ####  ####   ###     ###  ###                ===\n");
    printf("\e[0;34m");
    printf("    ===           ####    ####   #########  #########   #######      ######     ###     ###  #########          ===\n");
    printf("    ===                                                                                                         ===\n");
    printf("\e[0;35m");
    printf("    ===                                                                                                         ===\n");
    printf("    ===============================================================================================================\n\n\n");
    purple();
    printf("                                                      Register                                                     \n");
    printf("                                                 __________________                                                \n\n");
    printf("                                               Gmail : ");
    scanf("%s", &usergmail);

    if(usergmail[0] == '*')
    {
      fclose(userinputfile);
      system("main.exe");
      exit(0);
    }

    printf("                                               Username : ");
    scanf("%s", &userid);

    if(userid[0] == '*')
    {
      fclose(userinputfile);
      system("main.exe");
      exit(0);
    }

    disableEcho();
    printf("                                               Password : ");
    scanf("%s", &userpass);
    enableEcho();

    while (1)
    {
        fgets(readfile, sizeof(readfile), useroutputfile);
        if(feof(useroutputfile)) break;

        ft_split(readfile, str);
        if (strcmp(userid, str[0]) == 0 || strcmp(usergmail, str[2]) == 0)
        {
          check = 1;
        }
    }
    if(check == 1)
    {
      printf("\n\nThis username or email is already in use.\n");
        system("pause");
        ft_register();
    }
    else
    {
      fprintf(userinputfile, "%s,%s,%s,0\n", userid, userpass, usergmail);
      fclose(userinputfile);
      printf("\n\nRegistered Successfully;\n");
      system("pause");
      system("main.exe");
      exit(0);
    }
}

void ft_main()
{
    int userinput_1;
    reset();
    system("cls");
    red();
    cyan1();
    printf("\n");
    printf("     ===============================================================================================================\n");
    printf("     ===                                                                                                         ===\n");
    yellow();
    printf("     ===               _____   _____      _____            __  __  ______      _____  _    _   ____   _____      ===\n");
    printf("     ===        /\\    / ____| / ____|    / ____|    /\\    |  \\/  ||  ____|    / ____|| |  | | / __ \\ |  __ \\     ===\n");
    green();
    printf("     ===       /  \\  | |     | (___     | |  __    /  \\   | \\  / || |__      | (___  | |__| || |  | || |__) |    ===\n");
    printf("     ===      / /\\ \\ | |      \\___ \\    | | |_ |  / /\\ \\  | |\\/| ||  __|      \\___ \\ |  __  || |  | ||  ___/     ===\n");
    blue();
    cyan1();
    printf("     ===     / ____ \\| |____  ____) |   | |__| | / ____ \\ | |  | || |____     ____) || |  | || |__| || |         ===\n");
    printf("     ===    /_/    \\_\\\\_____||_____/     \\_____|/_/    \\_\\|_|  |_||______|   |_____/ |_|  |_| \\____/ |_|         ===\n");
    purple();
    cyan1();
    printf("     ===                                                                                                         ===\n");
    printf("     ===                                                                                                         ===\n");
    printf("     ===============================================================================================================\n");
    yellow();
    cyan1();
    printf("                                                                   ===                                           ===\n");
    printf("                                                                   ===   %12s%25s   ===\n", "Username : ", user.id);
    printf("                                                                   ===   %12s%25s   ===\n", "Gmail : ", user.gmail);
    printf("                                                                   ===   %12s%25s   ===\n", "Credit : ", ft_comma(user.credit));
    printf("                                                                   ===                                           ===\n");
    printf("                                                                   -------------------------------------------------\n");
    green();
    printf("                                                                      | [7]TOP-UP INTO ACCOUNT");
    red();
    printf("       [0]Log out |\n");
    yellow();
    cyan1();
    printf("                                                                   -------------------------------------------------\n\n\n");
    white();
    printf("                   ========================================================================================\n");
    printf("                   [1]VALORANT    [2]GENSHIN IMPACT    [3]LINE RANGER    [4]ROBLOX    [5]ROV     [6]History\n");
    printf("                   ========================================================================================\n\n\n\n");
    printf("   SELECT MENU NUMBER : ");
    scanf("%d", &userinput_1);
    if(userinput_1 == 1) ft_valorant();
    else if(userinput_1 == 2) ft_genshin();
    else if(userinput_1 == 3) ft_lineranger();
    else if(userinput_1 == 4) ft_roblox();
    else if(userinput_1 == 5) ft_rov();
    else if(userinput_1 == 6) ft_history();
    else if(userinput_1 == 7) ft_topup();
    else 
    {
      system("main.exe");
      exit(0);
    };
}

void ft_valorant()
{
  char username[max_value];
  int int_value, int_game = 0;

  system("cls");
  red();
  cyan1();
  printf("\n\n\n");
  printf("                  ====================================================================================\n");
  printf("                    |                                                                              |\n");
  yellow();
  printf("                    |   ,--.   ,--.,---.  ,--.    ,-----. ,------.   ,---.  ,--.  ,--.,--------.   |\n");
  printf("                    |    \\  `.'  //  O  \\ |  |   '  .-.  '|  .--. ' /  O  \\ |  ,'.|  |'--.  .--'   |\n");
  green();
  printf("                    |     \\     /|  .-.  ||  |   |  | |  ||  '--'.'|  .-.  ||  |' '  |   |  |      |\n");
  printf("                    |      \\   / |  | |  ||  '--.'  '-'  '|  |\\  \\ |  | |  ||  | `   |   |  |      |\n");
  blue();
  printf("                    |       `-'  `--' `--'`-----' `-----' `--' '--'`--' `--'`--'  `--'   `--'      |\n");
  purple();
  printf("                    |                                                                              |\n");
  printf("                  ====================================================================================\n\n\n");
  cyan();
  printf("         Supersaver set    [1] 11500 Vp / 1000 Bath       [2] 1100 Vp  / 100  Bath                                          \n");
  printf("         Classic    set    [3] 11000 Vp / 2640 Bath       [4] 5350 Vp  / 1320 Bath      [5] 3650 Vp  / 920 Bath                  \n");
  printf("                           [6] 2050  Vp / 520  Bath       [7] 1000 Vp  / 260  Bath      [8] 475  Vp  / 130 Bath                  \n\n");
  printf("         ======================================================================================================\n\n");
  printf("                                             SELECT PACKET THAT YOU WANT!                               [0]BACK\n\n");
  white();
  printf("     INPUT PACK NUMBER : ");
  scanf("%d", &int_value);
  if(int_value == 0) ft_main();
  printf("     INPUT YOUR USERNAME IN GAME : ");
  getchar();
  gets(username);
  ft_termgame(username, int_game, int_value);
}

void ft_rov()
{
  char username[max_value];
  int int_value, int_game = 4;

  system("cls");
  red();
  cyan1();
  printf("\n\n\n");
  printf("                                         ========================================\n");
  printf("                                           |                                  |\n");
  yellow();
  printf("                                           |   ,------.  ,-----.,--.   ,--.   |\n");
  printf("                                           |   |  .--. ''  .-.  '\\  `.'  /    |\n");
  green();
  printf("                                           |   |  '--'.'|  | |  | \\     /     |\n");
  printf("                                           |   |  |\\  \\ '  '-'  '  \\   /      |\n");
  blue();
  printf("                                           |   `--' '--' `-----'    `-'       |\n");
  purple();
  printf("                                           |                                  |\n");
  printf("                                         ========================================\n\n\n");
  cyan();
  printf("         Supersaver set    [1] 226 Coupon  / 35   Bath       [2] 35  Coupon  / 5   Bath                                 \n");
  printf("         Classic    set    [3] 3720 Coupon / 2910 Bath       [4] 680 Coupon  / 549 Bath      [5] 555 Coupon / 449 Bath\n\n");
  printf("                           [6] 370 Coupon  / 299  Bath       [7] 110 Coupon  / 89  Bath      [8] 24  Coupon / 20  Bath\n\n\n");
  printf("         ======================================================================================================\n\n");
  printf("                                             SELECT PACKET THAT YOU WANT!                               [0]BACK\n\n");
  white();
  printf("     INPUT PACK NUMBER : ");
  scanf("%d", &int_value);
  if(int_value == 0) ft_main();
  printf("     INPUT YOUR USERNAME IN GAME : ");
  getchar();
  gets(username);
  ft_termgame(username, int_game, int_value);
}

void ft_roblox()
{
  char username[max_value];
  int int_value, int_game = 3;

  system("cls");
  reset();
  red();
  cyan1();
  printf("\n\n\n");
  printf("                           =================================================================\n");
  printf("                             |                                                           |\n");
  cyan1();
  yellow();
  printf("                             |   ,------.  ,-----. ,-----.  ,--.    ,-----.,--.   ,--.   |\n");
  printf("                             |   |  .--. ''  .-.  '|  |) /_ |  |   '  .-.  '\\  `.'  /    |\n");
  green();
  printf("                             |   |  '--'.'|  | |  ||  .-.  \\|  |   |  | |  | .'    \\     |\n");
  printf("                             |   |  |\\  \\ '  '-'  '|  '--' /|  '--.'  '-'  '/  .'.  \\    |\n");
  blue();
  cyan1();
  printf("                             |   `--' '--' `-----' `------' `-----' `-----''--'   '--'   |\n");
  purple();
  printf("                             |                                                           |\n");
  printf("                           =================================================================\n\n\n");
  cyan();
  printf("         Supersaver set    [1] 1000 Robux / 300 Bath       [2] 450  Robux / 150 Bath                              \n\n");
  printf("         Classic    set    [3] 2750 Robux / 970 Bath       [4] 1000 Robux / 400 Bath      [5] 500 Robux / 200 Bath\n\n");
  printf("                           [6] 400  Robux / 160 Bath       [7] 200  Robux / 80  Bath      [8] 100 Robux / 40  Bath\n\n\n");
  printf("         ======================================================================================================\n\n");
  printf("                                             SELECT PACKET THAT YOU WANT!                               [0]BACK\n\n");
  white();
  printf("     INPUT PACK NUMBER : ");
  scanf("%d", &int_value);
  if(int_value == 0) ft_main();
  printf("     INPUT YOUR USERNAME IN GAME : ");
  getchar();
  gets(username);
  ft_termgame(username, int_game, int_value);
}

void ft_lineranger()
{
  char username[max_value];
  int int_value, int_game = 2;

  system("cls");
  cyan1();
  red();
  printf("\n\n\n");
  printf("        ============================================================================================================\n");
  printf("          |                                                                                                      |\n");
  yellow();
  printf("          |   ,--.   ,--.,--.  ,--.,------.    ,------.   ,---.  ,--.  ,--. ,----.   ,------.,------.  ,---.     |\n");
  printf("          |   |  |   |  ||  ,'.|  ||  .---'    |  .--. ' /  O  \\ |  ,'.|  |'  .-./   |  .---'|  .--. ''   .-'    |\n");
  green();
  printf("          |   |  |   |  ||  |' '  ||  `--,     |  '--'.'|  .-.  ||  |' '  ||  | .---.|  `--, |  '--'.'`.  `-.    |\n");
  printf("          |   |  '--.|  ||  | `   ||  `---.    |  |\\  \\ |  | |  ||  | `   |'  '--'  ||  `---.|  |\\  \\ .-'    |   |\n");
  blue();
  printf("          |   `-----'`--'`--'  `--'`------'    `--' '--'`--' `--'`--'  `--' `------' `------'`--' '--'`-----'    |  \n");
  printf("          |                                                                                                      |  \n");
  purple();
  printf("        ============================================================================================================\n\n\n");
  cyan();
  printf("         Supersaver set    [1] 780 Ruby / 759  Bath       [2] 312 Ruby / 359  Bath                                 \n\n");
  printf("         Classic    set    [3] 760 Ruby / 1800 Bath       [4] 440 Ruby / 1100 Bath      [5] 300 Ruby / 749 Bath   \n\n");
  printf("                           [6] 120 Ruby / 349  Bath       [7] 65  Ruby / 219  Bath      [8] 20  Ruby / 65 Bath   \n\n\n");
  printf("        ============================================================================================================\n\n");
  printf("                                             SELECT PACKET THAT YOU WANT!                                    [0]BACK\n\n");
  white();
  printf("     INPUT PACK NUMBER : ");
  scanf("%d", &int_value);
  if(int_value == 0) ft_main();
  printf("     INPUT YOUR USERNAME IN GAME : ");
  getchar();
  gets(username);
  ft_termgame(username, int_game, int_value);
}

void ft_genshin()
{
  char username[max_value];
  int int_value, int_game = 1;

  system("cls");
  red();
  cyan1();
  printf("\n\n\n");
  printf("    ================================================================================================================\n");
  printf("      |                                                                                                          |\n");
  yellow();
  printf("      |    ,----.                         ,--.     ,--.            ,--.                                 ,--.     |\n");
  printf("      |   '  .-./    ,---. ,--,--,  ,---. |  ,---. `--',--,--,     |  |,--,--,--. ,---.  ,--,--. ,---.,-'  '-.   |\n");
  green();
  printf("      |   |  | .---.| .-. :|      \\(  .-' |  .-.  |,--.|      \\    |  ||        || .-. |' ,-.  || .--''-.  .-'   |\n");
  printf("      |   '  '--'  |\\   --.|  ||  |.-'  `)|  | |  ||  ||  ||  |    |  ||  |  |  || '-' '\\ '-'  |\\ `--.  |  |     |\n");
  blue();
  cyan1();
  printf("      |    `------'  `----'`--''--'`----' `--' `--'`--'`--''--'    `--'`--`--`--'|  |-'  `--`--' `---'  `--'     |\n");
  purple();
  printf("      |                                                                          `--'                            |\n");
  printf("    ================================================================================================================\n\n\n");
  cyan();
  printf("   Supersaver set    [1] 1960  Crystal / 399  Bath       [2] 600  Crystal / 100  Bath                                 \n\n");
  printf("   Classic    set    [3] 12960 Crystal / 3000 Bath       [4] 6560 Crystal / 1600 Bath      [5] 3960 Crystal / 899 Bath\n\n");
  printf("                     [6] 1960  Crystal / 449  Bath       [7] 600  Crystal / 149  Bath      [8] 120  Crystal / 29  Bath\n\n\n");
  printf("    =================================================================================================================\n\n");
  printf("                                             SELECT PACKET THAT YOU WANT!                                     [0]BACK\n\n");
  white();
  printf("     INPUT PACK NUMBER : ");
  scanf("%d", &int_value);
  if(int_value == 0) ft_main();
  printf("     INPUT YOUR USERNAME IN GAME : ");
  getchar();
  gets(username);
  ft_termgame(username, int_game, int_value);
}

void successfully(){
  green();
  cyan1();
  system("cls");
  printf("\n\n\n\n\n\n\n\n\n\n");
  printf("                                                                       __           _   _         \n");
  printf("                                                                      / _|         | | | |        \n");
  printf("                       ___   _   _    ___    ___    ___   ___   ___  | |_   _   _  | | | |  _   _ \n");
  printf("                      / __| | | | |  / __|  / __|  / _ \\ / __| / __| |  _| | | | | | | | | | | | |\n");
  printf("           _   _   _  \\__ \\ | |_| | | (__  | (__  |  __/ \\__ \\ \\__ \\ | |   | |_| | | | | | | |_| |  _   _   _ \n");
  printf("          (_) (_) (_) |___/  \\__,_|  \\___|  \\___|  \\___| |___/ |___/ |_|    \\__,_| |_| |_|  \\__, | (_) (_) (_)\n");
  printf("                                                                                             __/ |\n");
  printf("                                                                                            |___/ \n");
  printf("\n\n\n\n\n\n\n\n\n");
  reset();
  system("pause");
  ft_main();
}

void ft_topup()
{
  int value, total;
  char buff[max_value], yesorno;
  time_t mytime;
	mytime = time(NULL);
    
    system("cls");
    white();
    printf("\n\n");
    printf("                                                                ============================================== \n");
    printf("                                                                    ______   ___   ____       __ __  ____  \n");
    printf("                                                                   |      | /   \\ |    \\     |  |  ||    \\ \n");
    printf("              # # # # # # # # #     # # # # # # # # #              |      ||     ||  o  )    |  |  ||  o  ) \n");
    printf("              #               #     #               #              |_|  |_||  O  ||   _/     |  |  ||   _/ \n");
    printf("              #   # # # # #   # ### #   # # # # #   #                |  |  |     ||  |       |  :  ||  | \n");
    printf("              #   # # # # #   # ### #   # # # # #   #                |  |  |     ||  |       |     ||  |  \n");
    printf("              #   # # # # #   #     #   # # # # #   #                |__|   \\___/ |__|        \\__,_||__| \n");
    printf("              #               #######               #                                                         \n");
    printf("              # # # # # # # # #     # # # # # # # # #           ==============================================\n");
    printf("                  # # #      # #  # # #   # # #                                                           \n");
    printf("              # # #     # # #       # #  # # #      #                               KBank                 \n");
    printf("              # #  # #  # # # #  # #    # # # #   # #                 ---------------------------------- \n");
    printf("                  # #     # #   # # # #     # #                        Account Name   :  Sarawut Ponsan  \n");
    printf("              # # #     #   # # #   # # #       # # #                  Account number :  071-815-3301    \n");
    printf("              # # # # # # # # #     # # # # # # # # #                 ---------------------------------- \n");
    printf("              #               #     #               #                                                    \n");
    printf("              #   # # # # #   # ### #   # # # # #   #                                                    \n");
    printf("              #   # # # # #   # ### #   # # # # #   #                                                    \n");
    printf("              #   # # # # #   #     #   # # # # #   #                                                    \n");
    printf("              #               #######               #                                                    \n");
    printf("              # # # # # # # # #     # # # # # # # # #                                                    \n");
    printf("\n\n");
    printf("    How much do you want to top up ? : ");
    scanf("%d", &value);
    getchar();
    printf("    Have you transferred the money ? [ Y / N ] : ");
    scanf("%c", &yesorno);

    if(yesorno == 'Y')
    {
      FILE *readfileuser, *writefileuser, *writefilelog , *rewrite;

      readfileuser = fopen("user.txt", "rt");
      writefileuser = fopen("user.txt", "at");
      writefilelog = fopen("log.txt", "at");
      if (readfileuser && writefileuser) 
      {
        rewrite = fopen("temp.txt", "w");
        while(fgets(buff, sizeof(buff), readfileuser))
        {
          char str[4][max_value], check[max_value], va_str[max_value], check1[max_value], check2[max_value], check3[max_value];

          strcpy(va_str, buff);
          ft_split(va_str, str);

          strcpy(check, str[0]);
          strcpy(check1, str[1]);
          strcpy(check2, str[2]);
          strcpy(check3, str[3]);

          if(strcmp(user.id, check) != 0) fprintf(rewrite, "%s,%s,%s,%s\n", check, check1, check2, check3);
          if(feof(readfileuser)) break;
        }

        total = atoi(user.credit) + value;
        fprintf(writefilelog, "topup,%s,%s,%s,%d\n",
            user.id, ft_replace(ctime(&mytime)),user.credit, total);

        fprintf(rewrite, "%s,%s,%s,%d\n", user.id, user.pass, user.gmail, total);
        sprintf(user.credit, "%d", total);
        fclose(readfileuser);
        fclose(writefileuser);
        fclose(writefilelog);
        fclose(rewrite);
        remove("user.txt");
        rename("temp.txt", "user.txt");
        successfully();
      } 
      else
      {
        printf("Somethings Error!!\n");
        system("pause");
      }

    }
    else ft_main();
}

void ft_history()
{
  char buff[max_value];
  FILE *readfilelog;

  readfilelog = fopen("log.txt", "rt");
  system("cls");
  red();
  printf("\n");
  printf("                                               _     _     _                                   \n");
  printf("                                    ______    | |   (_)   | |                      ______      \n"); 
  yellow();    
  printf("                                   |______|   | |__  _ ___| |_ ___  _ __ _   _    |______|     \n");
  green();     
  printf("                                    ______    | '_ \\| / __| __/ _ \\| '__| | | |    ______    \n");
  printf("                                   |______|   | | | | \\__ | || (_) | |  | |_| |   |______|    \n");
  blue();     
  printf("                                              |_| |_|_|___/\\__\\___/|_|   \\__, |             \n");
  purple();     
  printf("                                                                          __/ |                \n");
  printf("                                                                         |___/                 \n");
  white();
  printf("                                                ___________________________                    \n");   
  printf("\n                                                   Username : %10s                           \n", user.id);
  printf("                                                ___________________________                    \n");
	if (readfilelog) 
  {
    while(fgets(buff, sizeof(buff), readfilelog))
    {
      char str[13][max_value], type[max_value], username[max_value], typeday[max_value], month[max_value], day[max_value], date[max_value], year[max_value], info1[max_value], info2[max_value], info3[max_value], info4[max_value], info5[max_value], info6[max_value];
      
      ft_split_13(buff, str);
      strcpy(username, str[1]);
      if(strcmp(username, user.id) == 0)
      {
        strcpy(type, str[0]);
        printf("                                                                                                          \n");
        if(strcmp(type, "purchased") == 0)
        {
          strcpy(typeday, str[2]);
          strcpy(month, str[3]);
          strcpy(day, str[4]);
          strcpy(date, str[5]);
          strcpy(year, str[6]);
          strcpy(info1, str[7]); // เกมอะไร
          strcpy(info2, str[8]); // id เกมที่เติม เช่น id : sarawut
          strcpy(info3, str[9]); // pack ที่เติม เช่น 2500vp
          strcpy(info4, str[10]); // ราคา pack เช่น 1000bath
          strcpy(info5, str[11]); // ยอดเงินก่อนเติม
          strcpy(info6, str[12]); // ยอดเงินหลังเติม
          red();
          printf("     USER ID : %s\n",info2);
          printf("     GAME : ");
          if(strcmp(info1, "0") == 0) printf("%s", "Valorant");
          else if(strcmp(info1, "1") == 0) printf("%s", "Genshin impact");
          else if(strcmp(info1, "2") == 0) printf("%s", "Line Ranger");
          else if(strcmp(info1, "3") == 0) printf("%s", "Roblox");
          else if(strcmp(info1, "4") == 0) printf("%s", "Rov");
          printf("\n");
          printf("     TYPE : purchased\n");
          printf("     COST : %s\n",info4);
          printf("     PACK : %s\n",info3);
          printf("     DATE : %2s / %2s / %4s / %8s\n\n",day,month,year,date);
          white();
          printf("     ----------------------------------\n");
        }     
        else if(strcmp(type, "topup") == 0)
        {
          strcpy(typeday, str[2]);
          strcpy(month, str[3]);
          strcpy(day, str[4]);
          strcpy(date, str[5]);
          strcpy(year, str[6]);
          strcpy(info1, str[7]); // ยอดเงิน ก่อนเติมเงินเข้า
          strcpy(info2, str[8]); // ยอดเงิน หลังเติมเงินเข้า
          green();
          printf("     TYPE : topup\n");
          printf("     Beforepay : %s\n", info1);
          printf("     Afterpay : %s\n", info2);
          printf("     DATE : %2s / %2s / %4s / %8s\n\n",day,month,year,date); 
          white();
          printf("     ----------------------------------\n");         
        }                              
      }
    }
  }
  else
  {
    printf("Somethings Error!!\n");
    system("pause");
  }
  fclose(readfilelog);
  system("pause");
  ft_main();
}

char *ft_comma(char str[max_value])
{
    int i, j, len, commacount;
    static char output[60];
    
    len = strlen(str);
    commacount = (len - 1) / 3;
    j = len + commacount - 1;

    for(i = len - 1; i >= 0; i--, j--)
    {
      output[j] = str[i];
      if((len - i) % 3 == 0 && i != 0)
      {
        j--;
        output[j] = ',';
      }
    }

    return output;
}

char *ft_replace(char input[max_value])
{
  int i, len;
  static char output[60];

  len = strlen(input);

  for(i = 0; i < len; i++)
  {
    output[i] = input[i];
    if(input[i] == ' ') output[i] = ',';
    else if(input[i] == '\n') output[i] = '\0';
  }

  return output;
}

void ft_termgame(char username[max_value], int int_game, int int_value)
{
  int total;
  char buff[max_value];
  time_t mytime;
	mytime = time(NULL);

  int main_value[5][10] = {
    {0, 11500, 1100, 11000, 5350, 3650, 2050, 1000, 475},
    {0, 1960, 600, 12960, 6560, 3960, 1960, 600, 120},
    {0, 780, 312, 760, 440, 300, 120, 65, 20},
    {0, 1000, 450, 2750, 1000, 500, 400, 200, 100},
    {0, 226, 35, 3720, 680, 555, 370, 110, 24},
  	};
	int main_credit[5][10] = {
    {0, 1000, 100, 2640, 1320, 920, 520, 260, 130},
    {0, 399, 100, 3000, 1600, 899, 449, 149, 29},
    {0, 759, 359, 1800, 1100, 749, 349, 219, 65},
    {0, 300, 150, 970, 400, 200, 160, 80, 40},
    {0, 35, 5, 2910, 549, 449, 299, 89, 20},
  	};
  
  FILE *readfileuser, *writefileuser, *writefilelog, *rewrite;

  readfileuser = fopen("user.txt", "rt");
  writefileuser = fopen("user.txt", "at");
  writefilelog = fopen("log.txt", "at");

  total = atoi(user.credit) - main_credit[int_game][int_value];
  if (total < 0) {
      printf("Insufficient credit!\n");
      system("pause");
      system("main.exe");
      exit(0);
  }
	if (readfileuser && writefileuser && writefilelog) 
  {
    rewrite = fopen("temp.txt", "w");
    while(fgets(buff, sizeof(buff), readfileuser))
    {
      char str[4][max_value], check[max_value], va_str[max_value], check1[max_value], check2[max_value], check3[max_value];

      strcpy(va_str, buff);
      ft_split(va_str, str);

      strcpy(check, str[0]);
      strcpy(check1, str[1]);
      strcpy(check2, str[2]);
      strcpy(check3, str[3]);
      
      if(strcmp(user.id, check) != 0) fprintf(rewrite, "%s,%s,%s,%s\n", check, check1, check2, check3);
      if(feof(readfileuser)) break;
    }
    fprintf(rewrite, "%s,%s,%s,%d\n", user.id, user.pass, user.gmail, total);
    fprintf(writefilelog, "purchased,%s,%s,%d,%s,%d,%d,%s,%d\n",
            user.id, ft_replace(ctime(&mytime)), int_game, username,
            main_value[int_game][int_value],
            main_credit[int_game][int_value], user.credit, total);
    sprintf(user.credit, "%d", total);
    fclose(readfileuser);
    fclose(writefileuser);
    fclose(writefilelog);
    fclose(rewrite);
    remove("user.txt");
    rename("temp.txt", "user.txt");
    successfully();
  } 
  else
  {
    printf("Somethings Error!!\n");
    system("pause");
  }
}

int main()
{
  ft_welcome();
  return 0;
}