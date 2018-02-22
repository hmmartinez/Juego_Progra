#include <iostream>
#include "windows.h"
#include <conio.h>
#include "funcionalidad.h"
#include "juego.h"

using namespace std;

int main() {
	int opc;

	do {
		startInput();

		gotoxy(20, 10); cout << " =================================== BRICK GAME ===================================" << endl;
		gotoxy(20, 11); cout << "1. Jugar" << endl;
		gotoxy(20, 12); cout << "2. Estadisticas" << endl;
		gotoxy(20, 13); cout << "3. Salir" << endl;
		gotoxy(20, 14); cout << "Su opcion: ";
		cin >> opc;

		switch (opc) {
		case 1: 
			instrucciones();
			inicio();
			break;

		case 2:
			break;

		case 3:
			salir();
			break;
		}
	} while (opc != 3);
}
