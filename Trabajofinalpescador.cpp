#include "pch.h"
#include "bibliotecaa.h"

//MAIN
int main()
{//tamaño de la pantalla
	int d;
	//Coordenadas del personaje
	int xp = 35, yp = 6;
	int max = 1; //maximo de palos que se pueden dibujar
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




	//NIVEL 2
		//mapa 2
		Console::Clear();
		crear_mapa2();
		_sleep(2000);
		int puntaje = 0;

		//SISTEMA DE TICKS PARA RECOGER LA BASURA DEL NIVEL 2(se puede aplicar en todos los niveles)
		int tick_milisegundo = 10;
		int tick_basura = 1000;

		//basura 1
		int x1 = 10, y1 = 30;
		bool paloDetectado1 = false; // declararla fuera del while
		bool existe_basura1 = true; // Variable para controlar la existencia de basura
		int contador_tick1 = 0;
		basura_1(x1, y1, paloDetectado1, existe_basura1);

		//basura 2

		int x2 = 25, y2 = 20;
		bool paloDetectado2 = false; // declararla fuera del while
		bool existe_basura2 = true; // Variable para controlar la existencia de basura
		int contador_tick2 = 0;
		basura_2(x2, y2, paloDetectado2, existe_basura2);

		//basura 3
		int x3 = 31, y3 = 30;
		bool paloDetectado3 = false; // declararla fuera del while
		bool existe_basura3 = true; // Variable para controlar la existencia de basura
		int contador_tick3 = 0;
		basura_3(x3, y3, paloDetectado3, existe_basura3);

		//basura 4
		int x4 = 41, y4 = 30;
		bool paloDetectado4 = false; // declararla fuera del while
		bool existe_basura4 = true; // Variable para controlar la existencia de basura
		int contador_tick4 = 0;
		basura_4(x4, y4, paloDetectado4, existe_basura4);

		//Ciclo de juego del nivel 2
		while (2)
		{
			contador_tick1++;      ////contador_tick[4];
			contador_tick2++;
			contador_tick3++;
			contador_tick4++;
			if (contador_tick1 >= tick_basura && !paloDetectado1 && existe_basura1)
			{
				char hay_palo = obtenerCaracterEnPosicion(x1, y1);
				if (hay_palo == '|') {
					puntaje = puntaje + 1;
					paloDetectado1 = true; // Desactiva futuras ejecuciones
					cursor(10, 1); cout << "Puntaje: " << puntaje;

				}
			}

			if (contador_tick2 >= tick_basura && !paloDetectado2 && existe_basura2)
			{
				char hay_palo = obtenerCaracterEnPosicion(x2, y2);
				if (hay_palo == '|') {
					puntaje = puntaje + 1;
					paloDetectado2 = true; // Desactiva futuras ejecuciones
					cursor(10, 1); cout << "Puntaje: " << puntaje;

				}
			}
			if (contador_tick3 >= tick_basura && !paloDetectado3 && existe_basura3)
			{
				char hay_palo = obtenerCaracterEnPosicion(x3, y3);
				if (hay_palo == '|') {
					puntaje = puntaje + 1;
					paloDetectado3 = true; // Desactiva futuras ejecuciones
					cursor(10, 1); cout << "Puntaje: " << puntaje;

				}
			}
			if (contador_tick4 >= tick_basura && !paloDetectado4 && existe_basura4)
			{
				char hay_palo = obtenerCaracterEnPosicion(x4, y4);
				if (hay_palo == '|') {
					puntaje = puntaje + 1;
					paloDetectado4 = true; // Desactiva futuras ejecuciones
					cursor(10, 1); cout << "Puntaje: " << puntaje;

				}
			}

			if (kbhit())
			{

				//borrar
				borra_personaje(xp, yp);
				borra_palo(xp + 6, yp + 5, max);
				//mover
				char tecla = getch();
				if (tecla == DERECHA && xp != 135) { d = 1; xp++; }
				if (tecla == IZQUIERDA && xp != 1) { d = 2; xp--; }
				if (tecla == ABAJO && max < 32) { max++; }
				if (tecla == ARRIBA && max > 1) { max--; }
				//dibujar
				char basura = obtenerCaracterEnPosicion(xp + 6, yp + 5 + max - 1);


				//Para recoger la basura1
				if (basura == '*') {
					puntaje = puntaje + 1;
					cursor(10, 1); cout << "Puntaje: " << puntaje;
					existe_basura1 = false; // Cambia el estado de la basura a no existente
					borra_basura_1(x1, y1);
				};


				//Para recoger la basura2
				if (basura == '8') {
					puntaje = puntaje + 1;
					cursor(10, 1); cout << "Puntaje: " << puntaje;
					existe_basura2 = false; // Cambia el estado de la basura a no existente
					borra_basura_2(x2, y2);
				};

				//Para recoger la basura3
				if (basura == '@') {
					puntaje = puntaje + 1;
					cursor(10, 1); cout << "Puntaje: " << puntaje;
					existe_basura3 = false; // Cambia el estado de la basura a no existente
					borra_basura_3(x3, y3);
				};


				//Para recoger la basura4
				if (basura == '3') {
					puntaje = puntaje + 1;
					cursor(10, 1); cout << "Puntaje: " << puntaje;
					existe_basura4 = false; // Cambia el estado de la basura a no existente
					borra_basura_4(x4, y4);
				};
				dibuja_personaje(xp, yp);
				dibuja_palo(xp + 6, yp + 5, max);
				_sleep(1);
			}
			if (puntaje == 4) {
				_sleep(3000);
				break;
			}


		}
		Console::Clear();
		ventana_youwin(20, 3); // Ventana de victoria al completar el nivel 1
		_sleep(4000);



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
