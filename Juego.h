#pragma once

using namespace std;

DWORD WINAPI ThreadFn(LPVOID vpParam)
{
	while (1) {
		for (int i = 8; i <= 190; i++)
		{
			if (GetAsyncKeyState(i) == -32767) {
				if (i == 37) {
					l = 0;
				}
				else if (i == 39) {
					l = 3;
				}
			}
		}
	}
	return 0;
}


DWORD qThreadID;
HANDLE hThread;

void startInput() {
	hThread = CreateThread(0, 0, ThreadFn, 0, 0, &qThreadID);
}

void instrucciones() {
	system("cls");
	gotoxy(7, 2); cout << "Use las teclas izquierda (<-) y derecha (->) para moverse entre los carriles";

	for (int i = 4; i >= 0; i--) {
		gotoxy(50, 8); cout << i;
		gotoxy(14, 14);
		Sleep(1000);
	}
	system("cls");
}

void inicio() {

	while (vidas > 0) {
		gotoxy(17, 4); cout << "PUNTAJE:" << puntaje;
		gotoxy(17, 5); cout << "NIVEL:" << nivel;
		gotoxy(17, 6); cout << "VIDAS: " << vidas;
		refrescar();
		carros(r, g);
		carros(l, 12);

		for (int j = 0; j<16; j++) {
			gotoxy(4, j + 1); cout << "*"; //primer borde
			gotoxy(5, j + 1);
			for (int i = 0; i<6; i++) {
				if (mat[i][j] == 1) {
					cout << "0"; //Funcion carros
				}
				else {
					cout << " ";
				}
			} gotoxy(15, j + 1); cout << "*"; //Segundo borde
			if (g >= 12 & l == r) {
				vidas--;
			}
		}
		g++;

		if (g == 15) {
			g = -4; r = randomn(); puntaje++;
		}

		if (puntaje % 5 == 0 & (g == 15 | g == -4)) {
			nivel++; dela = dela - 15;
		}

		if (dela<0) {
			gotoxy(14, 4); cout << "GANASTE!" << endl;
		}

		Sleep(dela);
	}

	if (dela>0) {
		gotoxy(14, 4); cout << "GAME OVER" << endl;
	}

	g = 0, l = 0, r;
	puntaje = 1, nivel = 1, dela = 100;
	Sleep(1000);
	system("cls");
	gotoxy(14, 4); cout << "GAME OVER" << endl;
	Sleep(1500);

}

void salir() {
	CloseHandle(hThread);
	system("cls");
	gotoxy(3, 3); cout << "GOOD BYE!";
	Sleep(2500);
}
