#include "pch.h"
#include "MiBiblioteca_v2.h"


//MAIN
int main()
{//tama�o de la pantalla
	int d;
	//Coordenadas del personaje
	int xp = 35, yp = 6;
	int max = 1; //maximo de palos que se pueden dibujar
	//tama�o de la pantalla
	Console::SetWindowSize(150, 48);
	//presentacion
	nombre_juego(25, 2);
	presentación(5, 20);
	colores_logo(90, 15);
	_sleep(4000);
	//instrucciones	1
	Console::Clear();
	ventana_instrucciones1(20, 10);
	_sleep(4000);
	//instrucciones	2
	Console::Clear();
	ventana_instrucciones2(20, 10);
	_sleep(4000);
	//mapa 1
	Console::Clear();
	crear_mapa1();
	_sleep(4000);
	//cargando 1
	Console::Clear();
	cargando2(40, 2);
	cargando1(45, 10);
	_sleep(4000);
	//mapa 2
	Console::Clear();
	crear_mapa2();
	_sleep(4000);
	//cargando 2	
	Console::Clear();
	cargando2(40, 2);
	dibujo_de_carga(45, 10);
	noticia2(30, 40);
	_sleep(4000);
	//mapa 3
	Console::Clear();
	crear_mapa3();	
	_sleep(4000);
	//cargando3
	Console::Clear();
	cargando2(40, 2);
	ventana_cargando3(45, 10);
	_sleep(4000);
	//ganaste
	Console::Clear();
	ventana_youwin(20, 20);
	_sleep(4000);
	//perdiste
	Console::Clear();
	ventana_youlose(20, 20);
	_sleep(4000);
	//creadores
	Console::Clear();
	ventana_creadores(20, 20);	
	_sleep(4000);


	//actualizacion  06/06 21:55
	while (1)
	{
		if (kbhit())
		{
			//borrar
			borra_personaje(xp, yp);
			borra_palo(xp + 6, yp + 5, max);
			//mover
			char tecla = getch();
			if (tecla == DERECHA) { d = 1; xp++; }
			if (tecla == IZQUIERDA) { d = 2; xp--; }
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
