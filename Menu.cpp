#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <fstream>

#define FLECHA_ARRIBA 72
#define FLECHA_IZQ 75
#define FLECHA_DER 77
#define FLECHA_ABAJO 80
#define ENTER 13

#define MINCOL 1
#define MAXCOL 211
#define MINREN 1
#define MAXREN 50

using namespace std;
//-----------------------------------------------------------------------------------------------------------------------------------------------------

void gotoxy(short x,short y);
//-----------------------------------------------------------------------------------------------------------------------------------------------------

// Modos del cursor
enum modoCursor{MINI = 5, NORMAL = 20, SOLIDO = 80};
//-----------------------------------------------------------------------------------------------------------------------------------------------------
// Estados del cursor
enum estadoCursor{APAGADO, ENCENDIDO};
//-----------------------------------------------------------------------------------------------------------------------------------------------------

enum simbSimple{BV = 179, ESD = 191, EII, BH = 196, EID = 217, ESI}; //Enumeración para el marco.
//-----------------------------------------------------------------------------------------------------------------------------------------------------

void ImprimeMarco(int ancho, int alto, int x, int y);
//-----------------------------------------------------------------------------------------------------------------------------------------------------

void BorraMarco(int ancho, int largo, int x, int y);
//-----------------------------------------------------------------------------------------------------------------------------------------------------

void CambiaCursor(estadoCursor estado, modoCursor modo = NORMAL);
//-----------------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
    system("pause"); //Pausa para que se ponga en pantalla completa esta madre.
    //Limpié la pantalla porque quedaba un pedazo del mensaje de la pausa anterior en la esquina superior derecha, verás quítenle esta
    //pausa y chequenlo.
    system("cls");
    char tecla; //Este va a se como el centinela que anda checando que tecla presiona el usuario.
    int x = 25, y = 1;//Coordenadas en donde se va a comenzar a imprimir el título "Memorama"

    //Se imprime el título (MEMORAMA) en la misma posición x, solo la y cambiará porque ps, no puedo darle un endl.
    gotoxy(x,y++);
    cout << " .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.";
    gotoxy(x,y++);
    cout << "| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |";
    gotoxy(x,y++);
    cout << "| | ____    ____ | || |  _________   | || | ____    ____ | || |     ____     | || |  _______     | || |      __      | || | ____    ____ | || |      __      | |";
    gotoxy(x,y++);
    cout << "| ||_   \\  /   _|| || | |_   ___  |  | || ||_   \\  /   _|| || |   .'    `.   | || | |_   __ \\    | || |     /  \\     | || ||_   \\  /   _|| || |     /  \\     | |";
    gotoxy(x,y++);
    cout << "| |  |   \\/   |  | || |   | |_  \\_|  | || |  |   \\/   |  | || |  /  .--.  \\  | || |   | |__) |   | || |    / /\\ \\    | || |  |   \\/   |  | || |    / /\\ \\    | |";
    gotoxy(x,y++);
    cout << "| |  | |\\  /| |  | || |   |  _|  _   | || |  | |\\  /| |  | || |  | |    | |  | || |   |  __ /    | || |   / ____ \\   | || |  | |\\  /| |  | || |   / ____ \\   | |";
    gotoxy(x,y++);
    cout << "| | _| |_\\/_| |_ | || |  _| |___/ |  | || | _| |_\\/_| |_ | || |  \\  `--'  /  | || |  _| |  \\ \\_  | || | _/ /    \\ \\_ | || | _| |_\\/_| |_ | || | _/ /    \\ \\_ | |";
    gotoxy(x,y++);
    cout << "| ||_____||_____|| || | |_________|  | || ||_____||_____|| || |   `.____.'   | || | |____| |___| | || ||____|  |____|| || ||_____||_____|| || ||____|  |____|| |";
    gotoxy(x,y++);
    cout << "| |              | || |              | || |              | || |              | || |              | || |              | || |              | || |              | |";
    gotoxy(x,y++);
    cout << "| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |";
    gotoxy(x,y++);
    cout << " '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'";

    //Vuelvo a inicializar las coordendadas para que el siguiente mensaje (Jugar) quede centrado.
    x = 88;
    y+=5;

    //Repito lo mismo que con el texto anterior.
    gotoxy(x,y++);
    cout << "       __                      ";
    gotoxy(x, y++);
    cout << "      / /_  ______ _____ ______";
    gotoxy(x,y++);
    cout << " __  / / / / / __ `/ __ `/ ___/";
    gotoxy(x,y++);
    cout << "/ /_/ / /_/ / /_/ / /_/ / /    ";
    gotoxy(x, y++);
    cout << "\\____/\\__,_/\\__, /\\__,_/_/     ";
    gotoxy(x, y++);
    cout << "           /____/              ";


    //Vuelvo a inicializar las coordenadas para centrar el mensaje "Instrucciones".
    x = 70;
    y+=5;

    //Se repite el proceso de impresión de mensajito.
    gotoxy(x,y++);
    cout << "    ____           __                       _                      ";
    gotoxy(x,y++);
    cout << "   /  _/___  _____/ /________  ____________(_)___  ____  ___  _____";
    gotoxy(x,y++);
    cout << "   / // __ \\/ ___/ __/ ___/ / / / ___/ ___/ / __ \\/ __ \\/ _ \\/ ___/";
    gotoxy(x,y++);
    cout << " _/ // / / (__  ) /_/ /  / /_/ / /__/ /__/ / /_/ / / / /  __(__  ) ";
    gotoxy(x,y++);
    cout << "/___/_/ /_/____/\\__/_/   \\__,_/\\___/\\___/_/\\____/_/ /_/\\___/____/  ";


    //De nuevo y por última vez inicializo las coordenadas para centrar el último mensaje (Salir).
    x = 93;
    y+=5;

    //Imprimo el mensaje.
    gotoxy(x,y++);
    cout << "   _____       ___     ";
    gotoxy(x,y++);
    cout << "  / ___/____ _/ (_)____";
    gotoxy(x,y++);
    cout << "  \\__ \\/ __ `/ / / ___/";
    gotoxy(x,y++);
    cout << " ___/ / /_/ / / / /    ";
    gotoxy(x,y++);
    cout << "/____/\\__,_/_/_/_/     ";

    //Este pequeño bloquecillo llevo el cursor a la posición del mensaje de "Jugar". Se me hizo lógico iniciar allí
    //e imprimo el marco alrededor
    x = 86;
    y = 16;
    gotoxy(x,y);
    ImprimeMarco(35, 7, x, y );
    //Este goto regresa el cursor a la esquina superior izquierda del mensajito "Jugar", porque desde allí se comienza a
    //imprimir el marco y estas coordenadas son las que voy a usar como referencia para saber sobre cuál opción está el usuario
    // así como también para facilitar el borrado del marco cuando el usuario se vaya hacia otra opción y para facilitar la
    //impresión del siguiente marquito.
    gotoxy(x,y);

    CambiaCursor(APAGADO); //Aquí apago el cursor para que no se vea esa madre parpadeando.
    //El ciclito este pues se va a repetir mientras el usuario no le de enter.
    while (tecla != ENTER){
        tecla = getch(); //Esta sentencia es para esperar que el usuario pique algo en el teclado alv. **AHORA SI VIENE LO PERRÓN**
        //Estas coordenadas son las coordenadas del mensajito "Jugar", y si el usuario le pica para abajo pasa lo siguiente:
        if(x == 86 && y == 16 && (tecla == FLECHA_ABAJO )){
            BorraMarco(35, 7, x, y); //Se borra el marquito de "Jugar".
            gotoxy(x-=18,y+=10); //Te vas a la esquina superior izquierda del mensaje de "Instrucciones"
            ImprimeMarco(71, 7, x, y); //Desde allí, imprimes el marco alrededor del mensaje (instrucciones)
            gotoxy(x, y);//Y me regreso a la esquinita superior izquierda para facilitar el proceso, ya se los expliqué
            tecla = getch(); //Y espero a que el usuario teclee otra cosa.
        }

        if(x == 68 && y == 26 && (tecla == FLECHA_ABAJO )){ //Ahora, si el usuario está sobre "Instrucciones" y le da pa abajo:
            BorraMarco(71, 7, x, y); //Se borra el marco de "Instrucciones".
            gotoxy(x+=23,y+=10); //El cursor se va a la esquina superior izquierda del mensajito de abajo o sea "Salir".
            ImprimeMarco(27, 7, x, y); //Desde la esquinita se imprime el marco alrededor de "Salir".
            gotoxy(x, y); //Me regreso a la esquinita
            tecla = getch(); //Espero a que el usuario pique otra cosa.
        }
        //***HASTA AQUÍ SE LE DA CHANCE AL USUARIO DE QUE VAYA HACIA ABAJO, SI LLEGA A ESTE PUNTO Y LE SIGUE PICANDO A LA FLECHA PA ABAJO
        //PUES EL PROGRAMA NO VA A HACER NADA PORQUE NO HAY UN if QUE CONSIDERE ESE EVENTO***

        //Entonces, a partir de aquí hago lo mismo que antes, pero ahora considerando que el usuario le da a la flechita pa arriba.

        //Si está en el mensaje de "Salir" y pica pa abajo, ps no va a pasar nada alv xD, pero si le da pa arriba:
        if(x == 91 && y == 36 && (tecla == FLECHA_ARRIBA )){
            BorraMarco(27, 7, x, y); //Borro el marquito alrededor de "Salir"
            gotoxy(x-=23, y-=10); //Me voy a la esquina superior izquierda del mensaje de arriba o sea "Instrucciones"
            ImprimeMarco(71, 7, x, y); //Le imprimo su marquito correspondiente.
            gotoxy(x, y); //Me voy a la esquinita superior izquierda de "Instrucciones"
            tecla = getch(); //Espero a que el usuario teclee algo.
        }

        if(x == 68 && y == 26 && (tecla == FLECHA_ARRIBA )){ //Ahora, si el usuario está en el mensaje "Instrucciones" ps ya se la saben
            BorraMarco(71, 7, x, y); //Borro el marquito alrededor de "Instrucciones"
            gotoxy(x+=18,y-=10); //Me voy al mensaje de arriba, o sea "Jugar"
            ImprimeMarco(35, 7, x, y); //Le imprimo el marco a la palabrita "Jugar"
            gotoxy(x, y); //Me voy a la esquinita superior izquierda de jugar.
            tecla = getch(); //Espero a que el usuario teclee algo
        }
    }
    //Aquí, se supone que el usuario ya tecleó ENTER eligiendo una opción, entonces, limpio la pantalla para quitar el menú
    system("cls");

    //Y aquí wachen, usando la coordenada en y sabré qué opción eligió, y ps imprimí un mensajito nomas para que vieran que si funcionó.
    //Obviamente le voy a seguir moviendo para ir completando mas esta onda, porque por ejemplo las instrucciones deben tener la opcion de
    //devolverse al menú y así. pero ps es un avance

    //Los quiero.
    if (y == 16) cout << "El usuario eligi\xA2 jugar" << endl;
    if (y == 26) cout << "El usuario eligi\xA2 ver las instrucciones" << endl;
    if (y == 36 ) cout << "El usuario eligi\xA2 salir" << endl;


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
//--------------------------------------------------------------------------------------------------------------------------------------------------

void ImprimeMarco(int ancho, int alto, int x, int y)
{
    // Parte superior del marco
    gotoxy(x,y);
    cout << (char)ESI;
    for(int i = 1 ; i <= ancho - 2 ; ++i) cout << (char)BH;
    cout << (char)ESD;

    // Parte media del marco
    for(int i = 1 ; i <= alto - 1 ; ++i){
        gotoxy(x,++y);
        cout << (char)BV;
        for(int j = 1 ; j <= alto - 1 ; ++j){
            gotoxy(x+ancho-1, y);
            cout << (char)BV;
        }
    }

    // Parte inferior del marco
    gotoxy(x,++y);
    cout << (char)EII;
    for(int i = 1 ; i <= ancho - 2 ; ++i) cout << (char)BH;
    cout << (char)EID;

}
//--------------------------------------------------------------------------------------------------------------------------------------------------

void BorraMarco(int ancho, int alto, int x, int y)
{
    gotoxy(x,y);
    for(int i = 1 ; i <= ancho ; ++i) cout << ' ';

     for(int i = 1 ; i <= alto - 1 ; ++i){
        gotoxy(x,++y);
        cout << ' ';
        for(int j = 1 ; j <= alto - 1 ; ++j){
            gotoxy(x+ancho-1, y);
            cout << ' ';
        }
    }

    // Parte inferior del marco
    gotoxy(x,++y);
    for(int i = 1 ; i <= ancho ; ++i) cout << ' ';
}
//--------------------------------------------------------------------------------------------------------------------------------------------------
