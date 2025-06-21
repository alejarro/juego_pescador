#include "pch.h"
#include "MiBiblioteca_V1.h"


//MAIN
int main()
{//tamaño de la pantalla
	int d;
	//Coordenadas del personaje
	int xp = 35, yp = 6;
	int max = 1; //maximo de palos que se pueden dibujar
	//tamaño de la pantalla
	Console::SetWindowSize(150, 49);

	//actualizacion  06/06 21:55
	srand(time(nullptr));
	while (1)
	{
		if (kbhit())
		{
			//borrar
			borra_personaje(xp, yp);
			borra_palo(xp + 6, yp + 5, max);
			//mover
			char tecla = getch();
			if (tecla == DERECHA && xp!=135) { d = 1; xp++; }
			if (tecla == IZQUIERDA && xp != 1) { d = 2; xp--; }
			if (tecla == ABAJO && max < 32) { max++; }
			if (tecla == ARRIBA && max > 1) { max--; }
			//dibujar
			dibuja_personaje(xp, yp);
			dibuja_palo(xp + 6, yp + 5, max);
			_sleep(1);
		}
	}

	//Podriamos generar un mapa aqui
	// crear_mapaX();
	//Podriamos usar una funcion para meter al personaje
	// bote();
	//O podriamos meter a todo el personaje incluyendo arreglos y otras funciones que use



	system("pause>0");
	return 0;
}