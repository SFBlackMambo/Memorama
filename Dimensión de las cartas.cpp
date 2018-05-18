#include <iostream>
#include <cstdlib>
#include <limits>
#include <ctime>
#include <windows.h>

#define MAXANCHO 211
#define MAXALTO 50

using namespace std;

enum simbSimple{BV = 179, ESD = 191, EII, BH = 196, EID = 217, ESI}; //Enumeración para el marco.


void gotoxy(int x,int y);
void MarcoCarta(int ancho, int alto, int x, int y);

int main()
{
    system("pause");
    int anchoPrin = 25, largoPrin = 15, x = 1, y = 1;

    for (int i = 0 ; i < 5 ; ++i){
        MarcoCarta(anchoPrin, largoPrin, x, y);
        x+=30;

    }

    system("pause");
    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------
void gotoxy(int x,int y)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {x-1,y-1};
    SetConsoleCursorPosition(handle,coord);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------

void MarcoCarta(int ancho, int alto, int x, int y)
{
    // Parte superior del marco
    gotoxy(x,y);
    cout << (char)ESI;
    for(int i = 1 ; i <= ancho - 2 ; ++i) cout << (char)BH;
    cout << (char)ESD;

    // Parte media del marco
    for(int i = 1 ; i <= alto - 2 ; ++i){
        gotoxy(x,++y);
        cout << (char)BV;
        for(int j = 1 ; j <= ancho - 2 ; ++j) cout << ' ';
        cout << (char)BV;
    }

    // Parte inferior del marco
    gotoxy(x,++y);
    cout << (char)EII;
    for(int i = 1 ; i <= ancho - 2 ; ++i) cout << (char)BH;
    cout << (char)EID;

}
//--------------------------------------------------------------------------------------------------------------------------------------------------
