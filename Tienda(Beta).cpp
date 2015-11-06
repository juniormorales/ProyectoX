# ProyectoX
#include <stdio.h>
#include <stdlib.h>
#include <windows.h> 
#include <iostream>

using namespace std;

struct app{
 	string nom;
 	string desar;
 	string anyo;
 	float precio, tam, puntaje;
 };

void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos); 
}

void marco(){
	system ("color 3F");
	for(int j=4;j<76;j++){
			gotoxy(j,3);
			cout<<"=";
			gotoxy(j,21);
			cout<<"=";
	}
	for(int k=3;k<20;k++){
			gotoxy(3,k);
			cout<<endl;
			gotoxy(3,k+1);
			cout<<"|";
			gotoxy(76,k+1);
			cout<<"|";
	}
}

void inicio(app [], float [], string [],int, int);
void tusaplicaciones(app[], float [], string [], int, int );
void compraraplicaciones(app [], float [], string [], int &, int);
void carrito(app[], float [], string [], int, int &);
void tusaldo(app[], float [], string [], int, int);
void MenuAplicacion(app [], float [], string [], int  &, char, int);

int main(){
	app aplic[100];
	int i=0, saldo=20;
	float precioJuego[8]={10.0, 12.0, 2.0, 1.0, 25.0, 30.0, 2.0, 3.0};
	string nombreJuego[8]={"Minecraft", "Left4Dead", "BlackOps III", "Grand thef auto V", "Calculadora", "Convertor", "Pacman", "Naves"};
	//aplic[i].precio = 0.0;
	inicio(aplic, precioJuego, nombreJuego, i, saldo);
	
}

void inicio(app aplic[100], float precioJuego[8], string nombreJuego[8], int i, int saldo){
	char opcion1;
	system("cls");
	marco();
	gotoxy(30,5);cout<<"Bienvenido a la tienda"<<endl;
	gotoxy(10,7);cout<<"a. Comprar Aplicaciones";
	gotoxy(10,9);cout<<"b. En carrito";
	gotoxy(10,11);cout<<"c. Tu saldo disponible";
	gotoxy(10,13);cout<<"d. Tus aplicaciones";
	gotoxy(10,15);cout<<"e. Salir de la tienda";
	gotoxy(10,17);cout<<"Opcion a ingresar [   ]";
	gotoxy(30,17);cin>>opcion1;
	switch(opcion1){
		case 'a' : case 'A' : compraraplicaciones(aplic, precioJuego, nombreJuego, i, saldo);
			break;
		case 'b' : case 'B' : carrito(aplic, precioJuego, nombreJuego, i, saldo);
			break;
		case 'c' : case 'C' : tusaldo(aplic, precioJuego, nombreJuego, i, saldo);
			break;
		case 'd' : case 'D' : tusaplicaciones(aplic, precioJuego, nombreJuego, i, saldo);
			break;
		case 'e' : case 'E' : system("pause");//SALIR AL MENU PRINCIPAL
			break;
		default : inicio(aplic, precioJuego, nombreJuego, i, saldo);
	}
}

void compraraplicaciones(app aplic[100], float precioJuego[8], string nombreJuego[8], int &i, int saldo){
	int opcion;
	system("cls");
	marco();
	gotoxy(70,4);cout<<saldo<<" $";
	gotoxy(30,5);cout<<"Compra de aplicaciones"<<endl;
	gotoxy(10,7);cout<<"Aplicaciones en oferta";
	gotoxy(7,9);cout<<"1 . Minecraft";
	gotoxy(7,10);cout<<"2 . Left4Dead";
	gotoxy(7,11);cout<<"3 . BlackOps III";
	gotoxy(7,12);cout<<"4 . Grand thef auto V";
	
	gotoxy(45,7);cout<<"De mayor compra";
	gotoxy(42,9);cout<<"5 . Calculadora";
	gotoxy(42,10);cout<<"6 . Convertor";
	gotoxy(42,11);cout<<"7 . Pacman";
	gotoxy(42,12);cout<<"8 . Naves";
	gotoxy(42,13);cout<<"0. Salir";
	
	gotoxy(12,14);cout<<"Opcion a ingresar [   ]";
	gotoxy(32,14);cin>>opcion;
	if(opcion==0){
		inicio(aplic, precioJuego, nombreJuego, i, saldo);
	}
	MenuAplicacion(aplic, precioJuego, nombreJuego,i, opcion, saldo);
}

void carrito(app aplic[100], float precioJuego[8], string nombreJuego[8], int i, int &saldo){
	float compraTotal=0;
	string opcion1, opcion2;
	system("cls");
	marco();
	gotoxy(70,4);cout<<saldo<<" $";
	gotoxy(30,5);cout<<"Carrito de Compras";
	gotoxy(10,7);cout<<"En el carrito : ";
	for(int j=9;j<i+9;j++){
		gotoxy(7,j);cout<<aplic[j-9].nom<<"   -Con precio de $ "<<aplic[j-9].precio;
		compraTotal = compraTotal + aplic[j-9].precio;
	}
	gotoxy(12,16);cout<<"Desea adquirir el carrito? si/no  [   ]";
	gotoxy(47,16);cin>>opcion1;
	if(opcion1=="si"||opcion1=="SI"){
		if(saldo>=compraTotal){
			gotoxy(12,18);cout<<"Juego(s) Comprados ...";
			saldo=saldo - compraTotal;
			gotoxy(12,20);system("pause");
			inicio(aplic, precioJuego, nombreJuego, i, saldo);
		}else
			gotoxy(12,18);cout<<"No tiene saldo disponible";
		
	}else{
		gotoxy(12,18);cout<<"Deseas limpiar el carrito? si/no  [   ]";
		gotoxy(47,18);cin>>opcion2;
		if(opcion1=="si"||opcion1=="SI")
			main();
		else{
			gotoxy(12,20);system("pause");
			inicio(aplic, precioJuego, nombreJuego, i, saldo);
		}
	}
}

void tusaldo(app aplic[100], float precioJuego[8], string nombreJuego[8], int i, int saldo){
	string opcion2;
	system("cls");
	marco();
	gotoxy(70,4);cout<<saldo<<" $";
	gotoxy(10,7);cout<<"Aprovecha las ofertas ";
	gotoxy(7,9);cout<<"1 . Minecraft";
	gotoxy(7,10);cout<<"2 . Left4Dead";
	gotoxy(7,11);cout<<"3 . BlackOps III";
	gotoxy(7,12);cout<<"4 . Grand thef auto V";
	gotoxy(12,14);cout<<"Deseas ingresar a la tienda ? si/no [   ]";
	gotoxy(49,14);cin>>opcion2;
	if(opcion2=="si"||opcion2=="SI")
		compraraplicaciones(aplic, precioJuego, nombreJuego, i, saldo);
	else
		inicio(aplic, precioJuego, nombreJuego, i, saldo);
}

void tusaplicaciones(app aplic[100], float precioJuego[8], string nombreJuego[8], int i, int saldo){
	int opcion1;
	system("cls");
	marco();
	gotoxy(70,4);cout<<saldo<<" $";
	gotoxy(10,7);cout<<"Tus Aplicaciones";
	for(int k=9;k<i+9;i++){
		gotoxy(7,k);cout<<k-8<<" . "<<aplic[k-9].nom;
	}
	gotoxy(10,17);cout<<"Aplicacion a ingresar [   ]";
	gotoxy(10,18);cout<<"Digite 0 para salir";
	gotoxy(34,17);cin>>opcion1;
	
	if(opcion1==0)
		inicio(aplic, precioJuego, nombreJuego, i, saldo);
	switch(opcion1){
		case 1 : 
			break;
	}
}

void MenuAplicacion(app aplic[100], float precioJuego[8], string nombreJuego[8], int &i, char opcion, int saldo){
	string opcion1;
	system("cls");
	marco();
	gotoxy(70,4);cout<<saldo<<" $";
	gotoxy(34,5);cout<<nombreJuego[opcion-1];
	gotoxy(10,7);cout<<"DESCRIPCION DE LA APLICACION";
	
	
	gotoxy(12,14);cout<<"Desea mandar al carrito ? si/no [    ]";
	gotoxy(46,14);cin>>opcion1;
	if(opcion1=="si"||opcion1=="SI"){
		aplic[i].precio = precioJuego[opcion-1]; aplic[i].nom = nombreJuego[opcion-1];
		i++;
		carrito(aplic, precioJuego, nombreJuego, i, saldo);
	}
	else
		compraraplicaciones(aplic, precioJuego, nombreJuego, i, saldo);
}
