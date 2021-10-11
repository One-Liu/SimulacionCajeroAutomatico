#include<iostream>
using namespace std;
#include<stdlib.h>

class Cola {
	private:
		int cima;
		int fondo;
		int tope;
		string cola[25];
		string clientes[50] = {"Freddie Mercury",
								"Roger Waters",
								"Syd Barret",
								"John Lenon",
								"Paul McCartney",
								"Jimmy Page",
								"Axl Rose",
								"Slash",
								"Kevin Parker",
								"Marcus Fenix",
								"Master Chief",
								"Simon Riley",
								"Lain Iwakura",
								"John Price",
								"Edward Richtofen",
								"Nikolai Belinski",
								"Tank Dempsey",
								"Friedrich Nietzsche",
								"Noble Seis",
								"Legolas Hojaverde",
								"Frodo Bolson",
								"Shinji Ikari",
								"Rei Ayanami",
								"Pato Lucas",
								"Bugs Bunny",
								"Patricio Estrella",
								"Bob Esponja",
								"Mojo Jojo",
								"Ladybug",
								"Cat Noir",
								"Jose Jose",
								"Julieta Venegas",
								"Juanes",
								"Shakira",
								"Luis Miguel",
								"Chayanne",
								"Mark Renton",
								"Francis Begbie",
								"Bojack Horseman",
								"Todd Chavez",
								"Diane Nguyen",
								"Sarah Lynn",
								"Jesse Pinkman",
								"Walter White",
								"Saul Goodman",
								"Gustavo Fring",
								"Hank Schrader",
								"Mike Ehrmantraut",
								"Tuco Salamanca",
								"Huell Babineaux"};
	
		bool ColaLlena() {
			if(cima > tope) {
				return true;
			}else {
				return false;
			}
		}
		
		void ReorganizarCola(int indice) {
			if(indice == cima) {
				cola[indice] = "";
				return;
			}else {
				cola[indice] = cola[indice+1];
				ReorganizarCola(++indice);
			}
		}
		
	public:
		void Inicializar() {
			cima = 0;
			fondo = 0;
			int longitud = sizeof(cola)/sizeof(*cola);
			tope = longitud-1;
		}
		
		int Push() {
			if(!ColaLlena()) {
				cola[cima] = clientes[rand() % 50];
				++cima;
				return 0;
			}else {
				return -1;
			}
		}
		
		int Pop() {
			if(!ColaVacia()) {
				cola[fondo] = "";
				--cima;
				ReorganizarCola(0);
				return 0;
			}else {
				return -1;
			}
		}
		
		bool ColaVacia() {
			if(cima == fondo) {
				return true;
			}else {
				return false;
			}
		}
		
		string FondoCola() {
			return cola[fondo];
		}
		
		string CimaCola() {
			return cola[cima-1];
		}
		
		int Cima() {
			return cima;
		}
		
		void MostrarCola(int indice) {
			if(indice == cima) {
				return;
			}else {
				cout<<"Lugar "<<indice+1<<": "<<cola[indice]<<endl;
				MostrarCola(++indice);
			}
		}
};
