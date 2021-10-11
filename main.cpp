#include<iostream>
using namespace std;
#include"Cola.h"
#include<unistd.h>
#include<stdlib.h>
#include<time.h>

void MostrarTiempoTrabajo(int*,int*);
void MostrarReporte(int,string,Cola);
void GenerarNum2a4(int*);
void GenerarNum3a5(int*);

int main() {
	string clienteEnCajero = "";
	int minutos = 0;
	int horas = 0;
	bool terminarProceso = false;
	bool cajeroVacio = true;
	int clienteLlegaEn = 0;
	int tiempoUsoCajero = 0;
	int numClientesAtendidos = 0;
	Cola cola;
	cola.Inicializar();
	
	do {
		srand(time(NULL));
		system("cls");
		cout<<"[ CAJERO AUTOMATICO ]"<<"	Hora: ";
		
		MostrarTiempoTrabajo(&horas,&minutos);
		
		//Clientes que van llegando
		if(clienteLlegaEn == 0) {
			GenerarNum2a4(&clienteLlegaEn); //Determina el tiempo de llegada del siguiente cliente (2-4 min)
			cola.Push();
		}
		
		//Cajero automático
		if(cajeroVacio && !cola.ColaVacia()) {
			cajeroVacio = false;
			clienteEnCajero = cola.FondoCola();
			cola.Pop();
			GenerarNum3a5(&tiempoUsoCajero); //Determina el tiempo que se va a usar el cajero (3-5 min)
		}else {
			if(tiempoUsoCajero == 0) {
				cajeroVacio == true;
				clienteEnCajero = cola.FondoCola();
				cola.Pop();
				GenerarNum3a5(&tiempoUsoCajero);
				++numClientesAtendidos; //Cada vez que un cliente termina de ser atendido se suma 1 a numClientesAtendidos
			}
		}
		
		cout<<"	Clientes atendidos: "<<numClientesAtendidos<<endl;
		
		if(!cajeroVacio) {
			cout<<"Cajero en uso por: "<<clienteEnCajero<<endl;
			if(tiempoUsoCajero == 1) {
				cout<<"Tiempo de uso: "<<tiempoUsoCajero<<" minuto"<<endl;
			}else {
				cout<<"Tiempo de uso: "<<tiempoUsoCajero<<" minutos"<<endl;
			}
		}else {
			cout<<"Cajero disponible."<<endl;
		}
		
		//Clientes en cola
		if(!cola.ColaVacia()) {
			cout<<"\n[ Cola ]"<<endl;
			cola.MostrarCola(0);
		}else {
			cout<<"\n[ Cola vacia ]"<<endl;
		}
		
		if(clienteLlegaEn == 1) {
			cout<<"Siguiente cliente llega en "<<clienteLlegaEn<<" minuto";
		}else {
			cout<<"Siguiente cliente llega en "<<clienteLlegaEn<<" minutos";
		}
		
		
		--clienteLlegaEn;
		--tiempoUsoCajero;
		
		//Controla el tiempo
		sleep(1);
		
		if(horas == 2 && minutos == 1) {
			terminarProceso = true; //Termina el proceso 1min después de que el reloj marque las 2:00
		}
		
	}while(!terminarProceso);
	
	cout<<endl<<endl;
	MostrarReporte(numClientesAtendidos, clienteEnCajero, cola);
	
	return 0;
}

void MostrarTiempoTrabajo(int *horas, int *minutos) {
	if(*horas < 10) {
		cout<<"0"<<*horas;
	}else {
		cout<<*horas;
	}
	
	cout<<":";
	
	if(*minutos < 10) {
		cout<<"0"<<*minutos;
	}else {
		cout<<*minutos;
	}
	
	++*minutos;
	
	if(*minutos == 60) {
		++*horas;
		*minutos = 0;
	}
	
	return;
}

void MostrarReporte(int numClientesAtendidos, string clienteEnCajero, Cola cola) {
	cout<<"[ REPORTE DEL DIA ]"<<endl;
	cout<<"Total clientes atendidos: "<<numClientesAtendidos<<endl;
	cout<<"Total clientes en cola: "<<cola.Cima()<<endl;
	cout<<"Cliente en cajero: "<<clienteEnCajero<<endl;
	cout<<"Cliente en inicio de cola: "<<cola.FondoCola()<<endl;
	cout<<"Cliente en final de cola: "<<cola.CimaCola()<<endl;
	return;
}

void GenerarNum2a4(int *clienteLlegaEn) {
	*clienteLlegaEn = rand() % 3 + 2;
	return;
}

void GenerarNum3a5(int *tiempoUsoCajero) {
	*tiempoUsoCajero = rand() % 3 + 3;
	return;
}
