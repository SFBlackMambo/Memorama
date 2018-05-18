#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>

#define FLECHA_ARRIBA 72
#define FLECHA_IZQ 75
#define FLECHA_DER 77
#define FLECHA_ABAJO 80
#define ENTER 13

#define MINCOL 10
#define MAXCOL 80
#define MINREN 15
#define MAXREN 35

using namespace std;


int * CreaArreglo(int n);
//-----------------------------------------------------------------------------------------------------------------------------------------------------

void gotoxy(short x,short y);

//-----------------------------------------------------------------------------------------------------------------------------------------------------

enum estadoCursor{APAGADO, ENCENDIDO};
//-----------------------------------------------------------------------------------------------------------------------------------------------------

// Modos del cursor
enum modoCursor{MINI = 5, NORMAL = 20, SOLIDO = 80};
//-----------------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
    char tecla;
    int *Principiante = NULL;
    int *Intermedio = NULL;
    int *Experto = NULL;
    int x = MINCOL, y = MINREN;

    gotoxy(x,y);
    while (true){
        tecla = getch();

        if(y > MINREN && (tecla == FLECHA_ARRIBA )) gotoxy(x,--y);
        if(x > MINCOL && (tecla == FLECHA_IZQ  )) gotoxy(--x,y);
        if(y < MAXREN && (tecla == FLECHA_ABAJO )) gotoxy(x,++y);
        if(x < MAXCOL && (tecla == FLECHA_DER )) gotoxy(++x,y);


    }
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

int * CreaArreglo(int n)
{
    return new int [n]; //Se crea el arreglo de tamaño n + 1 pues se considera el término independiente del polinomio.
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------

void gotoxy(short x,short y)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {x-1,y-1};
    SetConsoleCursorPosition(handle,coord);
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------

void CambiaCursor(estadoCursor estado, modoCursor modo)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConCurInf;

    ConCurInf.dwSize = modo;
    ConCurInf.bVisible = estado;

    SetConsoleCursorInfo(hOut, &ConCurInf);
}
