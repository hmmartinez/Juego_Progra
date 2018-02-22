#pragma once


int mat[6][16];
int g = 0, l = 0, r;
int puntaje = 1, nivel= 1, dela = 100, vidas = 3;
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}



void refrescar() //Refresca carriles
{
	for (int j = 0; j<16; j++) {
		for (int i = 0; i<6; i++) { mat[i][j] = 0; }
	}
}


void dibujar(int x, int y)
{
	if (x >= 0 & x<6 & y >= 0 & y<16) {
		mat[x][y] = 1; 
	}
}


void carros(int x, int y)
{
	dibujar(1 + x, 0 + y); //Primera parte de los carros
	dibujar(0 + x, 1 + y); dibujar(1 + x, 1 + y); dibujar(2 + x, 1 + y); //Segunda parte de los carros
	dibujar(1 + x, 2 + y); //Tercera parte de los carros
	dibujar(0 + x, 3 + y); dibujar(1 + x, 3 + y); dibujar(2 + x, 3 + y);
}


int randomn() { //Generar random
	int n;
	if (rand() % 2 == 0) {
		n = 0; 
	}
	else { 
		n = 3; 
	}

	return n;
}
/////////////////////////////////////////////////
HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
int index = 1;
