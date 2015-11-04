# ProyectoX
#include <conio.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <windows.h> 
 #include <iostream>
 using namespace std;
  void gotoxy(int x,int y){  
       HANDLE hcon;  
       hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
       COORD dwPos;  
       dwPos.X = x;  
       dwPos.Y= y;  
       SetConsoleCursorPosition(hcon,dwPos);  
  }
  
  int registro(char,char);
  int main(){
  	string u,p,n;
 	for(int j=1;j<110;j++){
 			gotoxy(j,0);
 			cout<<char(205);
 			gotoxy(j,27);
 			cout<<char(205);
 	}
 	gotoxy(110,0);cout<<char(187);
 	gotoxy(1,0);cout<<char(201);
 	gotoxy(1,27);cout<<char(200);
 	gotoxy(110,27);cout<<char(188);
 	
 	for(int k=0;k<26;k++){
 			gotoxy(1,k);
 			cout<<endl;
 			gotoxy(1,k+1);
 			cout<<char(186);
 			gotoxy(110,k+1);
 			cout<<char(186);
 	}
 	gotoxy(48,1);cout<<"PROYECTO X";
 	gotoxy(5,3);cout<<"Ingrese su ID: ";
 	for(int i=29;i<56;i++){
 		gotoxy(i,2);cout<<"-";
 		gotoxy(i,4);cout<<"-";
 	}
 	gotoxy(28,3);cout<<"|";
 	gotoxy(56,3);cout<<"|";
 	gotoxy(30,3);cin>>u;
 	
 	gotoxy(5,8);cout<<"Ingrese su password: ";
 	for(int i=29;i<56;i++){
 		gotoxy(i,7);cout<<"-";
 		gotoxy(i,9);cout<<"-";
 	}
 	gotoxy(28,8);cout<<"|";
 	gotoxy(56,8);cout<<"|";
 	gotoxy(30,8);cin>>p;
 	
	gotoxy(5,8);cout<<"Ingrese su pin unico: ";
 	for(int i=29;i<56;i++){
 		gotoxy(i,7);cout<<"-";
 		gotoxy(i,9);cout<<"-";
 	}
 	gotoxy(28,8);cout<<"|";
 	gotoxy(56,8);cout<<"|";
 	gotoxy(30,8);cin>>p;
	getch(); 
  }  

 //parte inicial
#include <iostream>
#include <windows.h>
using namespace std;
struct cuenta{
	string nombre;
	string apell;
	string usua;
	string contra;
	string pin;
	string correo;
	string cod;
};
struct app{
	string nom;
	string desar;
	string anyo;
	float precio,tam,punto;
};
cuenta usu[100];
void ingreso(cuenta []);
void crear(cuenta []);
int menuprinc();
int menuusu();
void mainusuario();
int mainadmin();
void menuadmin();
int main(){
	usu[0]={"Franco","Mecca","francois","oliveros1000","g2e","sthp","turno4"};
	int o,v=1;
	while(v==1){
	o=menuprinc();
	switch(o){
		case 1: ingreso(usu); break;
		case 2: crear(usu); break;
		case 3: v=0; break;		
	}
	}
	system("pause");
}
int menuprinc(){
	int a;
	cout<<"-.-.-.-.-.-.BIENVENIDOS-.-.-.-.-.-"<<endl;
	cout<<"(1) INGRESAR"<<endl;
	cout<<"(2) CREAR USUARIO"<<endl;
	cout<<"(3) SALIR"<<endl;
	cin>>a;
	system("cls");
	return a;
}
void ingreso(cuenta usu[]){
	string u,p,n;
	char resp;
	int i,t=0;
	cout<<"INGRESE USUARIO Y CLAVE:"<<endl;
	cout<<"Usuario:";
	cin>>u;
	cout<<"Password:";
	cin>>p;
	cout<<"Pin:";
	cin>>n;
	system("cls");
	for(i=0;i<100;i++){
		if(u==usu[i].usua && p==usu[i].contra && n==usu[i].pin && n!="g2e"){
			cout<<"Bienvenido, "<<u<<endl;
			t=1;
			mainusuario();
		}
		if(u==usu[i].usua && p==usu[i].contra && n=="g2e"){
			cout<<"Bienvenido, "<<u<<endl;
			t=1;
		mainadmin();
		}

	}
	while(t==0){
	cout<<"Usuario erroneo/no existe!"<<endl;
	cout<<"(a) Desea volver a intentar?"<<endl;
	cout<<"(b) Volver al menu principal"<<endl;
	cin>>resp;
		if(resp=='a'){
			cout<<"Ingrese sus datos nuevo!"<<endl;
		cout<<"Usuario:";
		cin>>u;
		cout<<"Password:";
		cin>>p;
		cout<<"Pin:";
		cin>>n;
			for(i=0;i<100;i++){
				if(u==usu[i].usua && p==usu[i].contra && n==usu[i].pin){
					cout<<"valido!";
					t=1;
				}
			}
		}
		else{
			main();
		}
}
	system("cls");
}
void mainusuario(){
	int o,v=1;
	while(v==1){
	o=menuusu();
	switch(o){
		case 1: //apps(usu); break;
		case 2: //tienda(usu); break;
		case 3: v=0; break;		
	}
	}
	main();
}
int menuusu(){
	int a;
	cout<<"-.-.-.-.-.-.BIENVENIDO-.-.-.-.-.-"<<endl;
	cout<<"(1) Mis apps"<<endl;
	cout<<"(2) Tienda"<<endl;
	cout<<"(3) Cerrar sesion"<<endl;
	cin>>a;
	system("cls");
	return a;}
void crear(cuenta usu[]){
	cin.ignore(256,'\n');
	static int k=3;
	string u;
	int i,j,t=0;
	cout<<"-.-.-.-.-.CREA TU CUENTA.-.-.-.-.-.-"<<endl;
	cout<<"nombre:";
	getline(cin,usu[k].nombre);
	cout<<"apellido:";
	getline(cin,usu[k].apell);
	cout<<"usuario:";
	getline(cin,usu[k].usua);
	while(t==0){
		for(j=0;j<100;j++){
		if(usu[k].correo==usu[j].correo && k!=j){
			cout<<"Nombre de usuario no disponible!"<<endl;
			cout<<"usuario:";
			getline(cin,usu[k].usua);	
		}
		else {t=1;}
		}
	}	
	cout<<"password:";
	getline(cin,usu[k].contra);
	cout<<"reingrese su password: "<<endl;
	getline(cin,u);
	if(u!=usu[k].contra){
		cout<<"el password no son iguales"<<endl;
		cout<<"reingrese su password: "<<endl;
		getline(cin,u);
		}
	cout<<"pin unico:";
	getline(cin,usu[k].pin);
	cout<<"correo:";
	getline(cin,usu[k].correo);
	for(i=0;i<100;i++){
		if(usu[k].correo==usu[i].correo && k!=i){
			cout<<"ya se ha creado una cuenta con este correo!"<<endl;
		}
	}
	k++;
	cout<<"cuenta creada exitosamente!"<<endl;
	Sleep(2000);
	system("cls");
}
int mainadmin(){
	int a;
	cout<<"-.-.-.-.-.-.BIENVENIDO-.-.-.-.-.-"<<endl;
	cout<<"(1) Administrar cuentas"<<endl;
	cout<<"(2) Tienda"<<endl;
	cout<<"(3) Cerrar sesion"<<endl;
	cin>>a;
	system("cls");
	return a;}
void menuadmin(){
	int o,v=1;
	while(v==1){
	o=mainadmin();
	switch(o){
		case 1: //administrar(usu); break;
		case 2: //tienda(usu); break;
		case 3: v=0; break;		
	}
	}
	main();
}
