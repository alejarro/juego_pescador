#include "pch.h"
#include "MiBiblioteca_v2.h"

//MAIN
int main()
{//tamaño de la pantalla
	//tamaño de la pantalla
	Console::SetWindowSize(150, 48);
	//presentacion
	nombre_juego(25, 2);
	colores_logo(90, 15);
	presentación(5, 20);
	_sleep(4000);


	//mapa 1
	_sleep(3000);
	Console::Clear();
	crear_mapa1();
	_sleep(2000);

	//cargando 2	
	Console::Clear();
	cargando(40, 2);
	dibujo_de_carga(45, 10);
	noticia2(30, 40);
	_sleep(4000);
	jugar_nivel2();


	Console::Clear();
	cargando(40, 2);
	ventana_cargando3(45, 10);
	noticia3(0, 10);
	_sleep(4000);
	//mapa 3
	Console::Clear();
	crear_mapa3();
	_sleep(4000);

	//ganaste
	Console::Clear();
	ventana_youwin(45, 5);
	_sleep(4000);
	//perdiste
	Console::Clear();
	ventana_youlose(45, 5);
	_sleep(4000);
	//creadores
	Console::Clear();
	ventana_creadores(20, 20);
	_sleep(4000);



	//Podriamos generar un mapa aqui
	// crear_mapaX();
	//Podriamos usar una funcion para meter al personaje
	// bote();
	//O podriamos meter a todo el personaje incluyendo arreglos y otras funciones que use



	system("pause>0");
	return 0;
}
