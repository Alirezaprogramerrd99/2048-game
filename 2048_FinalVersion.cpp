#include <iostream>
#include <time.h>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
#include <unistd.h>
#include <windows.h>
#define Exit_REQUSTED  false

using namespace std;
//------------------------------------------------------------------------------------
bool Wining = false, GenerateDone = false, IsMoved = true; // boolean flags for showing movement and wining and executing the function that generates numbers 2 and 4.
bool blocked[4][4] = {0};
int board_array[4][4], score;

FILE *fileptr;  // working with file ...
HANDLE hConsole = GetStdHandle (STD_OUTPUT_HANDLE); // for using colors ...
//------------------------------------------------------------------------------------
void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void bubble_sort(int arr[], int size)
{
    int i, j;

    for(i = 0; i < size - 1; i++)

        for(j = 0 ; j < size - i - 1; j++)
        {
            if (arr[j] < arr[j+1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
}

bool SizeCheck(int x, int y, int currect_number)
{
    if(x < 0 || x > 3 || y < 0 || y > 3)
        return false;
    if(board_array[x][y] == currect_number)
        return true;
    else
        return false;
}
//-----------------------------------------------------------------------------------
bool canMove()
{
    for(int y = 0; y < 4; y++)
        for(int x = 0; x < 4; x++)
            if(!board_array[x][y]) // if array with x,y index was empty return true that we can move ..
                return true;

    for(int y = 0; y < 4; y++)
        for(int x = 0; x < 4; x++)
        {
            if(SizeCheck( x + 1, y, board_array[x][y]))
                return true;
            if(SizeCheck( x - 1, y, board_array[x][y]))
                return true;
            if(SizeCheck( x, y + 1, board_array[x][y]))
                return true;
            if(SizeCheck( x, y - 1, board_array[x][y]))
                return true;
        }
    return false;
}
//--------------------------------------------------------------------------------------------
void DrawBoard_1()
{
    SetConsoleTextAttribute(hConsole, 143);
    cout << "Score: " << score << endl << endl;
    SetConsoleTextAttribute(hConsole, 10);
    for(int y = 0; y < 4; y++)
    {
        cout << "\t\t*------*------*------*------*" << endl << "\t\t| ";
        for(int x = 0; x < 4; x++)
        {
            if(!board_array[x][y]) //if empty ..
                cout << setw(4) << " ";
            else
            {
                if(board_array[x][y] == 2)
                    SetConsoleTextAttribute(hConsole, 6);
                if(board_array[x][y] == 4)
                    SetConsoleTextAttribute(hConsole, 14);
                if(board_array[x][y] == 8)
                    SetConsoleTextAttribute(hConsole, 4);
                if(board_array[x][y] == 16)
                    SetConsoleTextAttribute(hConsole, 12);
                if(board_array[x][y] == 32)
                    SetConsoleTextAttribute(hConsole, 13);
                if(board_array[x][y] == 64)
                    SetConsoleTextAttribute(hConsole, 5);
                if(board_array[x][y] == 128)
                    SetConsoleTextAttribute(hConsole, 11);
                if(board_array[x][y] == 256)
                    SetConsoleTextAttribute(hConsole, 9);
                if(board_array[x][y] == 512)
                    SetConsoleTextAttribute(hConsole, 3);
                if(board_array[x][y] == 1024)
                    SetConsoleTextAttribute(hConsole, 15);
                if(board_array[x][y] == 2048)
                    SetConsoleTextAttribute(hConsole, 7);
                cout << setw(4) << board_array[x][y];
                SetConsoleTextAttribute(hConsole, 10);

            }
            cout << " | ";
        }
        cout << endl;
    }
    cout << "\t\t*------*------*------*------*" << endl << endl;
    SetConsoleTextAttribute(hConsole, 10);
}
//*-----------------------------------------------------------------------------------------
void DrawBoard_2()
{
    SetConsoleTextAttribute(hConsole, 97);
    cout << "Score: " << score << endl << endl;
    SetConsoleTextAttribute(hConsole, 10);
    for(int y = 0; y < 4; y++)
    {
        cout << "\t\t*****************************" << endl << "\t\t* ";
        for(int x = 0; x < 4; x++)
        {
            if(!board_array[x][y]) //if empty ..
                cout << setw(4) << " ";
            else
            {
                if(board_array[x][y] == 2)
                    SetConsoleTextAttribute(hConsole, 6);
                if(board_array[x][y] == 4)
                    SetConsoleTextAttribute(hConsole, 14);
                if(board_array[x][y] == 8)
                    SetConsoleTextAttribute(hConsole, 4);
                if(board_array[x][y] == 16)
                    SetConsoleTextAttribute(hConsole, 12);
                if(board_array[x][y] == 32)
                    SetConsoleTextAttribute(hConsole, 13);
                if(board_array[x][y] == 64)
                    SetConsoleTextAttribute(hConsole, 5);
                if(board_array[x][y] == 128)
                    SetConsoleTextAttribute(hConsole, 11);
                if(board_array[x][y] == 256)
                    SetConsoleTextAttribute(hConsole, 9);
                if(board_array[x][y] == 512)
                    SetConsoleTextAttribute(hConsole, 3);
                if(board_array[x][y] == 1024)
                    SetConsoleTextAttribute(hConsole, 15);
                if(board_array[x][y] == 2048)
                    SetConsoleTextAttribute(hConsole, 7);
                cout << setw( 4 ) << board_array[x][y];
                SetConsoleTextAttribute(hConsole, 10);
            }
            cout << " * ";
        }
        cout << endl;
    }
    cout << "\t\t*****************************" << endl << endl;
    SetConsoleTextAttribute(hConsole, 10);
}
void DrawBoard_3()
{
    SetConsoleTextAttribute(hConsole, 144);
    cout << "Score: " << score << endl << endl;
    SetConsoleTextAttribute(hConsole, 10);
    for(int y = 0; y < 4; y++)
    {
        cout << "\t\t-----------------------------" << endl << "\t\t| ";
        for(int x = 0; x < 4; x++)
        {
            if(!board_array[x][y]) //if empty ..
                cout << setw(4) << " ";
            else
            {
                if(board_array[x][y] == 2)
                    SetConsoleTextAttribute(hConsole, 6);
                if(board_array[x][y] == 4)
                    SetConsoleTextAttribute(hConsole, 14);
                if(board_array[x][y] == 8)
                    SetConsoleTextAttribute(hConsole, 4);
                if(board_array[x][y] == 16)
                    SetConsoleTextAttribute(hConsole, 12);
                if(board_array[x][y] == 32)
                    SetConsoleTextAttribute(hConsole, 13);
                if(board_array[x][y] == 64)
                    SetConsoleTextAttribute(hConsole, 5);
                if(board_array[x][y] == 128)
                    SetConsoleTextAttribute(hConsole, 11);
                if(board_array[x][y] == 256)
                    SetConsoleTextAttribute(hConsole, 9);
                if(board_array[x][y] == 512)
                    SetConsoleTextAttribute(hConsole, 3);
                if(board_array[x][y] == 1024)
                    SetConsoleTextAttribute(hConsole, 15);
                if(board_array[x][y] == 2048)
                    SetConsoleTextAttribute(hConsole, 7);
                cout << setw(4) << board_array[x][y];
                SetConsoleTextAttribute(hConsole, 10);
            }
            cout << " | ";
        }
        cout << endl;
    }
    cout << "\t\t-----------------------------" << endl << endl;
    SetConsoleTextAttribute(hConsole, 10);
}
//------------------------------------------------------------------------------------------------------
void DrawBoard_4()
{
    SetConsoleTextAttribute(hConsole, 160);
    cout << "Score: " << score << endl << endl;
    SetConsoleTextAttribute(hConsole, 10);
    for(int y = 0; y < 4; y++)
    {
        cout << "\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl << "\t\t$ ";
        for(int x = 0; x < 4; x++)
        {
            if(!board_array[x][y]) //if empty ..
                cout << setw(4) << " ";
            else
            {
                if(board_array[x][y] == 2)
                    SetConsoleTextAttribute(hConsole, 6);
                if(board_array[x][y] == 4)
                    SetConsoleTextAttribute(hConsole, 14);
                if(board_array[x][y] == 8)
                    SetConsoleTextAttribute(hConsole, 4);
                if(board_array[x][y] == 16)
                    SetConsoleTextAttribute(hConsole, 12);
                if(board_array[x][y] == 32)
                    SetConsoleTextAttribute(hConsole, 13);
                if(board_array[x][y] == 64)
                    SetConsoleTextAttribute(hConsole, 5);
                if(board_array[x][y] == 128)
                    SetConsoleTextAttribute(hConsole, 11);
                if(board_array[x][y] == 256)
                    SetConsoleTextAttribute(hConsole, 9);
                if(board_array[x][y] == 512)
                    SetConsoleTextAttribute(hConsole, 3);
                if(board_array[x][y] == 1024)
                    SetConsoleTextAttribute(hConsole, 15);
                if(board_array[x][y] == 2048)
                    SetConsoleTextAttribute(hConsole, 7);
                cout << setw( 4 ) << board_array[x][y];
                SetConsoleTextAttribute(hConsole, 10);
            }
            cout << " $ ";
        }
        cout << endl;
    }
    cout << "\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl << endl;
    SetConsoleTextAttribute(hConsole, 10);
}
//----------------------------------------------------------------------------------------------------
void Shift_horizental(int x, int y, int d)
{
    if(board_array[x + d][y] && board_array[x + d][y] == board_array[x][y] && !blocked[x][y] && !blocked[x + d][y])
    {
        board_array[x][y]= 0;
        board_array[x + d][y] *= 2;
        score += board_array[x + d][y];
        blocked[x + d][y] = true;
        IsMoved = true;
    }
    else if(!board_array[x + d][y] && board_array[x][y])
    {
        board_array[x + d][y] = board_array[x][y];
        board_array[x][y] = 0;
        IsMoved = true;
    }
    if(d > 0)
    {
        if(x + d < 3)
            Shift_horizental( x + d, y,  1);
    }
    else
    {
        if(x + d > 0)
            Shift_horizental( x + d, y, -1);
    }
}
//---------------------------------------------------------------------------------------------------
void Shift_vertical(int x, int y, int d)
{
    if( board_array[x][y + d] && board_array[x][y + d] == board_array[x][y] && !blocked[x][y] && !blocked[x][y + d]) // if the same_number
    {
        board_array[x][y] = 0;
        board_array[x][y + d] *= 2;
        score += board_array[x][y + d];
        blocked[x][y + d] = true;
        IsMoved = true;
    }
    else if(!board_array[x][y + d] && board_array[x][y])
    {
        board_array[x][y + d] = board_array[x][y];
        board_array[x][y] = 0;
        IsMoved = true;
    }
    if(d > 0)
    {
        if(y + d < 3)
            Shift_vertical(x, y + d,  1);
    }
    else
    {
        if(y + d > 0)
            Shift_vertical(x, y + d, -1);
    }
}
//--------------------------------------------------------------------------------------------------------
void Game_control()
{
    char Game_Key;
    IsMoved = false;
    cout << "\n" << "         (W)up\n\n";
    cout << "(A)left  (S)down  (D)right" << endl;
    Game_Key = getch();
    Game_Key = toupper(Game_Key);
    switch(Game_Key)
    {
    case 'W':
        for(int x = 0; x < 4; x++)
        {
            int y = 1;
            while( y < 4 )
            {
                if(board_array[x][y])
                    Shift_vertical( x, y, -1 );
                y++;
            }
        }
        break;

    case 'A':
        for(int y = 0; y < 4; y++)
        {
            int x = 1;
            while(x < 4)
            {
                if(board_array[x][y])
                    Shift_horizental( x, y, -1 );
                x++;
            }
        }

        break;

    case 'S':
        for(int x = 0; x < 4; x++)
        {
            int y = 2;
            while(y >= 0)
            {
                if( board_array[x][y] )
                    Shift_vertical( x, y, 1 ); // (|)
                y--;
            }
        }
        break;

    case 'D':
        for(int y = 0; y < 4; y++)
        {
            int x = 2;
            while(x >= 0)
            {
                if(board_array[x][y])
                    Shift_horizental(x, y, 1);
                x--;
            }
        }
    }
    for(int y = 0; y < 4; y++)
        for(int x = 0; x < 4; x++)
            blocked[x][y] = false;
}
//-----------------------------------------------------------------------------------------
void Generate_number()
{
    for(int y = 0; y < 4; y++)
        for(int x = 0; x < 4; x++)
            if(!board_array[x][y])
            {
                int a, b;
                do
                {
                    a = rand() % 4; //-->> generating in the random indexes ..
                    b = rand() % 4;
                }
                while(board_array[a][b]);

                int chance = rand() % 100;
                if(chance > 96)   //** game chance for generating 4 number .
                    board_array[a][b] = 4;
                else
                    board_array[a][b] = 2;
                if(canMove() == true)
                    return;
            }
    GenerateDone = true;  // all of board_array homes are full..
}

void Reset_func()
{
    GenerateDone = false;
    Wining = false;
    IsMoved = true;
    score = 0;

    for(int y = 0; y < 4; y++)
        for( int x = 0; x < 4; x++ )
            blocked[x][y] = true;

    for(int y = 0; y < 4; y++)
        for(int x = 0; x < 4; x++)
            board_array[x][y] = {0};
}
//-----------------------------------------------------------------------------------------------------
void Game_loop()  ///****************** Main Game Loop ******************///
{
    int number_choice;
    system("cls");
    cout <<"\n";
    SetConsoleTextAttribute(hConsole, 2);
    cout << "What game board do you want ? "  << endl;
    SetConsoleTextAttribute(hConsole, 3);
    cout << "(1) for new generation board ." << endl;
    SetConsoleTextAttribute(hConsole, 4);
    cout << "(2) for star board . " << endl;
    SetConsoleTextAttribute(hConsole, 5);
    cout << "(3) for classical board ." << endl;
    SetConsoleTextAttribute(hConsole, 6);
    cout << "(4) for Dollar board ." << endl;
    SetConsoleTextAttribute(hConsole, 10);
    cin >> number_choice;

    Generate_number(); //-->> genarating the first random numbers to begun the game ..
    while(!Exit_REQUSTED)
    {
        if(number_choice == 1)
        {
            system("cls");
            if(IsMoved)  // if the user playing game for any movement of user will generate numbers
                Generate_number();
            DrawBoard_1();
            if(GenerateDone) /// if all elements homes was completed flag wile be true and game will end...
                break;
            Game_control();
        }
        //-------------------------------------------------------------------------------------------
        else if(number_choice == 2)
        {
            system("cls");
            if(IsMoved)  // if the user playing game for any movement of user will generate numbers
                Generate_number();
            DrawBoard_2();
            if(GenerateDone) /// if all elements homes was completed flag wile be true and game will end...
                break;
            Game_control();
        }
        //------------------------------------------------------------------------------------------
        else if(number_choice == 3)
        {
            system("cls");
            if(IsMoved)  // if the user playing game for any movement of user will generate numbers
                Generate_number();
            DrawBoard_3();
            if(GenerateDone) /// if all elements homes was completed flag wile be true and game will end...
                break;
            Game_control();
        }
        //------------------------------------------------------------------------------------------
        else if(number_choice == 4)
        {
            system("cls");
            if(IsMoved)  // if the user playing game for any movement of user will generate numbers
                Generate_number();
            DrawBoard_4();
            if(GenerateDone) /// if all elements homes was completed flag wile be true and game will end...
                break;
            Game_control();
        }
    }
    if(Wining == false)
        cout << "GAME OVER !!" << endl;
    else
        cout << "YOU WIN !!" << endl;
    cout << "\n";
    cout << "press (n) for new game ." << endl;
    cout << "Press (h) to Highscores ." << endl;
    cout << "press (m) to Menu . " << endl;
    cout << "press (e) to Exit ." << endl;

    fileptr = fopen("D:\\2048.txt", "a"); // creating file if does not exist , otherwise go to last record of file..
    fprintf(fileptr, "%d\n", score);
    fclose(fileptr);
}

void Start_menu()
{
    SetConsoleTextAttribute(hConsole, 64);
    cout << "\t\t  << WELCOME TO 2048 GAME >>" << "\n\n\n\n\n" ;
    SetConsoleTextAttribute(hConsole, 7);
    cout << "Loading";
    for(int i = 1; i < 6; i++)
    {
        cout << ".";
        sleep(1.7);
    }
    SetConsoleTextAttribute(hConsole, 10);
    system("cls");

}
void credits()
{
    system("cls");
    cout << "2048 game developed by Alireza Rashidi ";
    cout << "  :";
    for(int i = 0; i < 5; i++)
    {
        SetConsoleTextAttribute(hConsole,  9 + i);
        cout << ")";
        sleep(1);
    }
    SetConsoleTextAttribute(hConsole, 10);
    cout << endl << endl;
    cout << "version     1, 0, 0" << endl;
    cout << "\n\n";
    cout << "Press (n) to Play Game ." << endl;
    cout << "press (m) to Menu. " << endl;
    cout << "press (e) to Exit ." << endl;
}

int main()
{
    srand(( time( NULL )));

    int Score_list[1000] = {0}, i = 0, k = 0;
    SetConsoleTextAttribute(hConsole, 11);
    cout << "\n \n \n \n \n \n \n" << "\t\t\t\t* Press any key to start * ";
    getch();
    system("cls");
    Start_menu();
    char Game_state;
    SetConsoleTextAttribute(hConsole, 6);
    cout << "           << 2048 Game >> " << endl;
    SetConsoleTextAttribute(hConsole, 10);
    cout << "What do you want to do ? " << endl;
    SetConsoleTextAttribute(hConsole, 12);
    cout << "(n). Play The Game " << endl;
    SetConsoleTextAttribute(hConsole, 14);
    cout << "(h). Highscores " << endl;
    SetConsoleTextAttribute(hConsole, 3);
    cout << "(c). Credits " << endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout << "(e). Exit " << endl;
    SetConsoleTextAttribute(hConsole, 10);

    while(true)
    {
        Game_state = getch();
        if(Game_state == 'e' || Game_state == 'E')
            exit(1);
        switch (Game_state)
        {

        case 'm':
        case 'M':
            system("cls");

            SetConsoleTextAttribute(hConsole, 6);
            cout << "           << 2048 Game >> " << endl;
            SetConsoleTextAttribute(hConsole, 10);
            cout << "What do you want to do ? " << endl;
            SetConsoleTextAttribute(hConsole, 12);
            cout << "(n). Play The Game " << endl;
            SetConsoleTextAttribute(hConsole, 14);
            cout << "(h). Highscores " << endl;
            SetConsoleTextAttribute(hConsole, 3);
            cout << "(c). Credits " << endl;
            SetConsoleTextAttribute(hConsole, 15);
            cout << "(e). Exit " << endl;
            SetConsoleTextAttribute(hConsole, 10);

            break;

        case 'n':
        case 'N':
            Game_loop();
            if(Game_state == 'n' || Game_state == 'N')
            {
                Reset_func();
                Game_state = 'n';
            }
            if(Game_state == 'h' || Game_state == 'H')
                Game_state = 'h';

            break;

        case 'h':
        case 'H':
            system("cls");
            for(int i = 0; i < 1000; i++)
            {
                Score_list[i] = 0;

            }
            SetConsoleTextAttribute(hConsole, 28);
            cout << "\t\t\t<< HighSCORES >>" << endl;
            SetConsoleTextAttribute(hConsole, 10);

            fileptr = fopen("D:\\2048.txt", "r"); // reading file ..
            while(!feof(fileptr)) // EOF
            {
                fscanf(fileptr, "%d", &Score_list[i]);

                i++;
            }
            fclose(fileptr);

            bubble_sort(Score_list, i-1);

            if (i < 11 ) // if ( (i - 1) < 10 )
                k = i - 1;
            if (i >= 11)
                k = 10;

            for(int j = 0; j < k ; j++)
            {
                SetConsoleTextAttribute(hConsole, j + 1);
                cout << j+1 << "_ " << Score_list[j] << endl;
            }
            SetConsoleTextAttribute(hConsole, 10);
            if(Game_state == 'm' || Game_state == 'M')
                Game_state = 'm';

            cout << "-------------------------------------" << endl << endl;
            cout << "Press (n) to play game ." << endl;
            cout << "Press (m) to go to Menu ." << endl;
            cout << "Press (e) to Exit ." << endl;

            break;

        case 'c':
        case 'C':
            credits();
            if(Game_state == 'n' || Game_state == 'N')
            {
                Reset_func();
                Game_state = 'n';
            }
            break;

        default:
            break;
        }
    }
    return system("pause");
}
