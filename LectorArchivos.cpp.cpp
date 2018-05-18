#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;


 void ImprimeArchivo (fstream&)
{
  string linea;
  ifstream myfile ("Memorama.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,linea) )
    {
      cout << linea << '\n';
    }
    myfile.close();
  }

  else cout << "no abrido el archivo";
}




