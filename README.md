# ProyectoX
#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
using namespace std;
void gotoxy(int x,int y){  
       HANDLE hcon;  
       hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
       COORD dwPos;  
       dwPos.X = x;  
       dwPos.Y= y;  
       SetConsoleCursorPosition(hcon,dwPos);  
}
void cargando(){
  	int cont=0;
  	gotoxy(38,22);cout<<"CARGANDO";
  	while(cont<2){
  		for(int i=47;i<=58;i++){
  			gotoxy(i,22);cout<<". ";
  			Sleep(50);
  			i++;
  			if(i==58) gotoxy(47,22);cout<<"\t"<<"\t"<<"\t";
  		}
  		cont++;
  	}
  	gotoxy(38,22);cout<<"\t"<<"\t"<<"\t";
  }
void marco(){
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
	gotoxy(2,26);cout<<"Version 0.02b";  	
 	for(int k=0;k<26;k++){
 			gotoxy(1,k);
 			cout<<endl;
 			gotoxy(1,k+1);
 			cout<<char(186);
 			gotoxy(110,k+1);
 			cout<<char(186);
 	}
 	gotoxy(48,24);cout<<"PROYECTO X";
}
struct tipocambio{
	float sol;
	float dolar;
	float euro;
	float libra;

};
struct cuenta{
	string nombre;
	string apell;
	string usua;
	string contra;
	string pin;
	string correo;
	string cod;
	int verificador;
};
struct app{
	string nom;
	string desar;
	string anyo;
	float precio,tam,puntaje;
};
cuenta usu[100];
void ingreso(cuenta []);
void tienda(cuenta [],int );
void menutienda(app [], float [], string [],int, int,int);
void tusaplicaciones(app[], float [], string [], int, int,int );
void compraraplicaciones(app [], float [], string [], int &, int,int);
void carrito(app[], float [], string [], int, int &,int );
void tusaldo(app[], float [], string [], int, int,int);
void MenuAplicacion(app [], float [], string [], int &, char, int,int);
void crear(cuenta [],int &);
char menuprinc();
char menuusu(int );
void mainusuario(int );
char mainadmin(int );
void menuadmin();
void PERFIL(cuenta usu[],int ind);
void MODIFICANDOPERFIL(cuenta usu[],int ind,char num);
void OPCIONESPERFILMODIFICABLES(cuenta usu[],int ind);
void VERIFICANDOCUENTA(cuenta usu[],int ind);
char MenuCambioA();
void menucambio(tipocambio);
int convertidor();
int main(){
	usu[0]={"Franco","Mecca","francosmp","francosmp","9876","stha-182@hotmail.com","leonardo",0};
	usu[1]={"Hector","Huapaya","hackerman","bitcoins","1234","hecdan89@hotmail.com","crack",0};
	int v=1,usuCont=5;
	char o;
	while(v==1){
	marco();	
	o=menuprinc();
		switch(o){
			case '1': ingreso(usu); break;
			case '2': crear(usu,usuCont); break;
			case '3': v=0; break;		
		}
	}
}
char menuprinc(){
	char a;
	system("cls");
	marco();
	gotoxy(36,3);cout<<"-.-.-.-.-.-.BIENVENIDOS-.-.-.-.-.-"<<endl;
	gotoxy(36,8);cout<<"[1] INGRESAR"<<endl;
	gotoxy(36,13);cout<<"[2] CREAR USUARIO"<<endl;
	gotoxy(36,18);cout<<"[3] SALIR"<<endl;
	gotoxy(57,24);a=getch();
	system("cls");
	return a;
}
void ingreso(cuenta usu[]){
	string u="",p="",n="";
	char resp;
	int i,t=0,ind;
	system("cls");
	marco();
	gotoxy(38,2);cout<<"INGRESANDO"<<endl;
	gotoxy(38,4);cout<<"USUARIO : ";
	for(int i=38;i<67;i++){
 		gotoxy(i,6);cout<<"-";
 		gotoxy(i,8);cout<<"-";
 	}
 	gotoxy(38,7);cout<<"|";
 	gotoxy(66,7);cout<<"|";
	
	gotoxy(38,10);cout<<"PASSWORD : ";
	for(int i=38;i<67;i++){
 		gotoxy(i,12);cout<<"-";
 		gotoxy(i,14);cout<<"-";
 	}
 	gotoxy(38,13);cout<<"|";
 	gotoxy(66,13);cout<<"|";
	gotoxy(38,16);cout<<"PIN : ";
	for(int i=38;i<67;i++){
 	gotoxy(i,18);cout<<"-";
 	gotoxy(i,20);cout<<"-";
 	}
 	gotoxy(38,19);cout<<"|";
 	gotoxy(66,19);cout<<"|";
	while(u=="")gotoxy(39,7),getline(cin,u);
	while(p=="")gotoxy(39,13),getline(cin,p);
	while(n=="")gotoxy(39,19),getline(cin,n);
	for(i=0;i<100;i++){
		if(u==usu[i].usua && usu[i].verificador>=3){
			system("cls");
			ind=i;
			cout<<"Cuenta Bloqueada"<<endl;
			cout<<"Sera redirigido para recuperar su cuenta"<<endl;
			Sleep(3000);
			VERIFICANDOCUENTA(usu,ind);			
		}
		else{
			if(u==usu[i].usua && p==usu[i].contra && n==usu[i].pin && n!="g2e"){
				cargando();
				gotoxy(26,7);cout<<"(Valido)";
				gotoxy(26,13);cout<<"(Valido)";
				gotoxy(26,19);cout<<"(Valido)";
				Sleep(400);
				system("cls");
				cout<<"Bienvenido, "<<u<<endl;
				t=1;
				ind=i;
				mainusuario(ind);
			}
			if(u==usu[i].usua && p==usu[i].contra && n=="g2e"){
				cargando();
				gotoxy(26,7);cout<<"(Valido)";
				gotoxy(26,13);cout<<"(Valido)";
				gotoxy(26,19);cout<<"(Valido)";
				Sleep(400);
				system("cls");
				cout<<"Bienvenido, "<<u<<endl;
				t=1;
				ind=i;
			mainadmin(ind);
			}
			if(u==usu[i].usua && (p!=usu[i].contra or n!=usu[i].pin))
				usu[i].verificador++;
		}
	}
	while(t==0){
				cargando();
				gotoxy(24,7);cout<<"(Invalido)";
				gotoxy(24,13);cout<<"(Invalido)";
				gotoxy(24,19);cout<<"(Invalido)";
				Sleep(400);
				system("cls");
		marco();		
		gotoxy(37,5);cout<<"Usuario erroneo/no existe!"<<endl;
		gotoxy(37,10);cout<<"[1] Desea volver a intentar?"<<endl;
		gotoxy(37,15);cout<<"[2] Volver al menu principal"<<endl;
		gotoxy(57,24);resp=getch();
		system("cls");
		if(resp=='1'){
			ingreso(usu);
		}
		else{
			t=1;
		}
	}
}
void mainusuario(int ind){
	char o;
	int v=1;
	while(v==1){
	o=menuusu(ind);
		switch(o){
			case '1': PERFIL(usu,ind); break;
			case '2': tienda(usu,ind); break;
			case '3': v=0; break;		
		}
	}
}
char menuusu(int ind){
	int t=0;
	char a,x,y,z;
	string respo;
	while(t==0){
	system("cls");
	marco();
	gotoxy(36,3);cout<<"-.-.-.-.-.-.BIENVENIDO, "<<usu[ind].nombre<<".-.-.-.-.-.-"<<endl;
	gotoxy(36,8);cout<<"[1] Perfil"<<endl;
	gotoxy(36,13);cout<<"[2] Tienda"<<endl;
	gotoxy(36,18);cout<<"[3] Cerrar sesion"<<endl;	
	gotoxy(57,24);cin.clear(),a=getch();
	if(a=='3'){
		gotoxy(57,18);cout<<"Deseas cerrar sesion?";
		gotoxy(79,18);cin>>respo;
		if(respo=="si") t=1;
	}
	return a;
	system("cls");
	}
	}
void crear(cuenta usu[],int &usuCont){
	string u,uv;
	int i,j,t=0,a=0,f=0;
	marco();
	gotoxy(36,2);cout<<"-.-.-.-.-.-.CREA TU CUENTA.-.-.-.-.-.-"<<endl;
	gotoxy(22,4);cout<<"Nombre: ";
	gotoxy(22,6);cout<<"Apellido: ";
	gotoxy(22,8);cout<<"Usuario: ";
	gotoxy(22,10);cout<<"Contraseña: ";
	gotoxy(22,12);cout<<"Reingrese su Contraseña: "<<endl;
	gotoxy(22,14);cout<<"PIN: ";
	gotoxy(22,16);cout<<"Correo: ";
	gotoxy(22,18);cout<<"Codigo de Seguridad: "<<endl;
	while(usu[usuCont].nombre=="")gotoxy(31,4),getline(cin,usu[usuCont].nombre);
	while(usu[usuCont].apell=="")gotoxy(33,6),getline(cin,usu[usuCont].apell);
	while(usu[usuCont].usua=="")gotoxy(33,8),getline(cin,usu[usuCont].usua);
	while(t==0){
	for(j=0;j<100;j++){
		if(usu[usuCont].usua==usu[j].usua && usuCont!=j){
			gotoxy(60,8);cout<<"Nombre de usuario no disponible!"<<endl;
			Sleep(1000);
			gotoxy(60,8);cout<<"\t\t\t\t\t\t";
			gotoxy(33,8);cout<<"\t\t\t\t\t\t";
			gotoxy(22,8);cout<<"Usuario: ";
			while(usu[usuCont].usua=="")gotoxy(33,8),getline(cin,usu[usuCont].usua);
		}
		else t=1;
		}
	}
	while(usu[usuCont].contra=="")gotoxy(36,10),getline(cin,usu[usuCont].contra);
	while(u=="")gotoxy(50,12),getline(cin,u);
	while(a==0){
		if(u!=usu[usuCont].contra){
			gotoxy(60,12);cout<<"Las contraseñas no son iguales"<<endl;
			Sleep(1000);
			gotoxy(60,12);cout<<"\t\t\t\t\t\t";
			gotoxy(50,12);cout<<"\t\t\t\t\t\t";
			gotoxy(22,12);cout<<"Reingrese su Contraseña : "<<endl;
			while(u=="")gotoxy(50,12),getline(cin,u);
			}
		else a=1;
	}
	while(usu[usuCont].pin=="")gotoxy(28,14),getline(cin,usu[usuCont].pin);
	while(usu[usuCont].correo=="")gotoxy(31,16),getline(cin,usu[usuCont].correo);
	while(f==0){
		for(i=0;i<100;i++){
			if(usu[usuCont].correo==usu[i].correo && usuCont!=i){
				gotoxy(60,16);cout<<"Ya existe una cuenta con este correo!"<<endl;
				Sleep(1000);
				gotoxy(60,16);cout<<"\t\t\t\t\t\t";
				gotoxy(31,16);cout<<"\t\t\t\t\t\t";
				gotoxy(22,16);cout<<"Correo: ";
				while(usu[usuCont].correo=="")gotoxy(31,16),getline(cin,usu[usuCont].correo);	
			}
		else f=1;
		}
	}
	while(usu[usuCont].cod=="")gotoxy(44,18),getline(cin,usu[usuCont].cod);
	usuCont++;
	gotoxy(22,22);cout<<"Cuenta Creada Exitosamente!"<<endl;
	Sleep(1500);
	system("cls");
}
char mainadmin(int ind){
	char a;
	cout<<"-.-.-.-.-.-.BIENVENIDO-.-.-.-.-.-"<<endl;
	cout<<"(1) Administrar cuentas"<<endl;
	cout<<"(2) Tienda"<<endl;
	cout<<"(3) Cerrar sesion"<<endl;
	cin>>a;
	system("cls");
	return a;}
void menuadmin(int ind){
	char o;
	int v=1;
	while(v==1){
	o=mainadmin(ind);
	switch(o){
		case '1': //administrar(usu); break;
		case '2': //tienda(usu); break;
		case '3': v=0; break;
		default: mainadmin(ind);	
	}
	}
}
void PERFIL(cuenta usu[],int ind){ // int ind
	string codPermisos;
	char opc;
	cin.ignore(256,'\n');
	system("cls");
	marco();
	gotoxy(24,13);cout<<"Ingrese codigo de seguridad : ";
	gotoxy(55,13);getline(cin,codPermisos);
	if(codPermisos==usu[ind].cod){
		system("cls");
		marco();
		gotoxy(14,3);cout<<"Nombre : "<<usu[ind].nombre<<endl;
		gotoxy(14,5);cout<<"Apellido : "<<usu[ind].apell<<endl;
		gotoxy(14,7);cout<<"Usuario : "<<usu[ind].usua<<endl;
		gotoxy(14,9);cout<<"Contraseña : "<<usu[ind].contra<<endl;
		gotoxy(14,11);cout<<"PIN : "<<usu[ind].pin<<endl;
		gotoxy(14,13);cout<<"Correo : "<<usu[ind].correo<<endl;
		gotoxy(14,15);cout<<"Codigo de Permisos : "<<usu[ind].cod<<endl;
		gotoxy(14,24);cout<<"Para Modificar presione 'S', sino presione otra tecla : ";opc=getch();
		if(opc=='s' or opc=='S') OPCIONESPERFILMODIFICABLES(usu,ind);
	}
	else{
		system("cls");
		gotoxy(24,12);cout<<"Codigo Errado."<<endl,gotoxy(24,13);cout<<"Sera Redirigido."<<endl;
		Sleep(2000);
	}	
}

void MODIFICANDOPERFIL(cuenta usu[],int ind,char num){
	cin.ignore(256,'\n');	
	switch(num){
		case '1': gotoxy(65,3);cout<<"Nuevo Nombre :";gotoxy(81,3);cin>>usu[ind].nombre; break;
		case '2': gotoxy(65,5);cout<<"Nuevo Apellido :";gotoxy(83,5);cin>>usu[ind].apell; break;
		case '3': gotoxy(65,7);cout<<"Nuevo Usuario :";gotoxy(82,7);cin>>usu[ind].usua; break;
		case '4': gotoxy(65,9);cout<<"Nuevo Contraseña :";gotoxy(84,9);cin>>usu[ind].contra; break;
		case '5': gotoxy(65,11);cout<<"Nuevo PIN :";gotoxy(78,11);cin>>usu[ind].pin; break;
		case '6': gotoxy(65,13);cout<<"Nuevo Correo :";gotoxy(81,13);cin>>usu[ind].correo; break;
		case '7': gotoxy(65,15);cout<<"Nuevo Codigo de Permisos :";gotoxy(92,15);cin>>usu[ind].cod; break;
		default : gotoxy(14,19);cout<<"Opcion Errada."<<endl,gotoxy(14,20);cout<<"Sera Redirigido"<<endl,Sleep(2000); break;
	}
}

void OPCIONESPERFILMODIFICABLES(cuenta usu[],int ind){
	char num;	
	system("cls");
	gotoxy(14,3);cout<<"[1] Nombre"<<endl;
	gotoxy(14,5);cout<<"[2] Apellido"<<endl;
	gotoxy(14,7);cout<<"[3] Usuario"<<endl;
	gotoxy(14,9);cout<<"[4] Contraseña"<<endl;
	gotoxy(14,11);cout<<"[5] PIN"<<endl;
	gotoxy(14,13);cout<<"[6] Correo"<<endl;
	gotoxy(14,15);cout<<"[7] Codigo de Permisos"<<endl;
	gotoxy(14,17);cout<<"Ingrese el numero del dato a modificar :";gotoxy(55,17);cin>>num;
	MODIFICANDOPERFIL(usu,ind,num);
}

void VERIFICANDOCUENTA(cuenta usu[],int ind){
	string nom,ape,usuc,con,pon,cor,cud;
	system("cls");
	cin.ignore(1024,'\n');
	cout<<"Nombre : ";
	getline(cin,nom);
	cout<<"Apellido : ";
	getline(cin,ape);
	cout<<"Usuario : ";
	getline(cin,usuc);
	cout<<"Contraseña : ";
	getline(cin,con);
	cout<<"PIN : ";
	getline(cin,pon);
	cout<<"Correo : ";
	getline(cin,cor);
	cout<<"Codigo de Seguridad : ";
	getline(cin,cud);
	if(nom==usu[ind].nombre && ape==usu[ind].apell && usuc==usu[ind].usua && con==usu[ind].contra && pon==usu[ind].pin && cor==usu[ind].correo && cud==usu[ind].cod){
		cout<<"Ingrese nueva contraseña : ";cin>>usu[ind].contra;
		usu[ind].verificador=0;
		cout<<"Guardado"<<endl;
	}
	else{
		cout<<"Datos errados"<<endl;
		cout<<"Ingrese nuevamente y sera redirigido"<<endl;		
	}
	Sleep(2000);
	system("cls");
	main();
}
void tienda(cuenta usu[],int ind){
	app aplic[100];
	int h=0, saldo=20;
	float precioJuego[8]={10.0, 12.0, 2.0, 1.0, 25.0, 30.0, 2.0, 3.0};
	string nombreJuego[8]={"Minecraft", "Left4Dead", "Black Ops III", "Grand thef auto V", "Calculadora", "Convertidor de monedas", "Pacman", "Naves"};
	menutienda(aplic, precioJuego, nombreJuego, h, saldo,ind);
}

void menutienda(app aplic[100], float precioJuego[8], string nombreJuego[8], int h, int saldo,int ind){
	char opcion1;
	int t=0;
	system("cls");
	marco();
	gotoxy(32,3);cout<<"Bienvenido a la tienda"<<endl;
	gotoxy(15,7);cout<<"a. Comprar Aplicaciones";
	gotoxy(15,9);cout<<"b. En carrito";
	gotoxy(15,11);cout<<"c. Tu saldo disponible";
	gotoxy(15,13);cout<<"d. Tus aplicaciones";
	gotoxy(15,15);cout<<"e. Salir de la tienda";
	gotoxy(15,19);cout<<"Opcion a ingresar [  ]";
	gotoxy(34,19);cin>>opcion1;
	while(t==0){
	switch(opcion1){
		case 'a' : case 'A' : compraraplicaciones(aplic, precioJuego, nombreJuego, h, saldo,ind);
			break;
		case 'b' : case 'B' : carrito(aplic, precioJuego, nombreJuego, h, saldo,ind);
			break;
		case 'c' : case 'C' : tusaldo(aplic, precioJuego, nombreJuego, h, saldo,ind);
			break;
		case 'd' : case 'D' : tusaplicaciones(aplic, precioJuego, nombreJuego, h, saldo,ind);
			break;
		case 'e' : case 'E' : t=1;//SALIR AL MENU PRINCIPAL
			break;
	}
	}
}
void compraraplicaciones(app aplic[100], float precioJuego[8], string nombreJuego[8], int &h, int saldo,int ind){
	char opcion;
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
	gotoxy(42,10);cout<<"6 . Convertidor de monedas";
	gotoxy(42,11);cout<<"7 . Pacman";
	gotoxy(42,12);cout<<"8 . Naves";
	gotoxy(42,13);cout<<"0. Salir";
	gotoxy(12,14);cout<<"Opcion a ingresar [  ]";
	gotoxy(31,14),cin>>opcion;
	if(opcion=='0'){
		menutienda(aplic, precioJuego, nombreJuego, h, saldo,ind);
	}
	MenuAplicacion(aplic, precioJuego, nombreJuego,h, opcion, saldo,ind);
}
void carrito(app aplic[100], float precioJuego[8], string nombreJuego[8], int h, int &saldo,int ind){
	float compraTotal=0;
	string opcion1, opcion2;
	system("cls");
	marco();
	gotoxy(70,4);cout<<saldo<<" $";
	gotoxy(30,5);cout<<"Carrito de Compras";
	gotoxy(10,7);cout<<"En el carrito : ";
	for(int j=9;j<h+9;j++){
		gotoxy(7,j);cout<<aplic[j-9].nom<<" -Con precio de $ "<<aplic[j-9].precio;
		compraTotal = compraTotal + aplic[j-9].precio;
	}
	gotoxy(12,16);cout<<"Desea adquirir el carrito? si/no [   ]";
	gotoxy(46,16),cin>>opcion1;
	if(opcion1=="si"||opcion1=="SI"){
		if(saldo>=compraTotal){
			gotoxy(12,18);cout<<"Juego(s) Comprados ...";
			saldo=saldo - compraTotal;
			menutienda(aplic, precioJuego, nombreJuego, h, saldo,ind);
		}else
			gotoxy(12,18);cout<<"No tiene saldo disponible";
	}else{
		gotoxy(12,18);cout<<"Deseas limpiar el carrito? si/no [   ]";
		gotoxy(46,18);cin>>opcion2;
		if(opcion1=="si"||opcion1=="SI")
			tienda(usu,ind);
		else{
			menutienda(aplic, precioJuego, nombreJuego, h, saldo,ind);
		}
	}
}
void tusaldo(app aplic[100], float precioJuego[8], string nombreJuego[8], int h, int saldo,int ind){
	string opcion2;
	system("cls");
	marco();
	gotoxy(70,4);cout<<saldo<<" $";
	gotoxy(10,7);cout<<"Aprovecha las ofertas ";
	gotoxy(7,9);cout<<"1 . Minecraft";
	gotoxy(7,10);cout<<"2 . Left4Dead";
	gotoxy(7,11);cout<<"3 . BlackOps III";
	gotoxy(7,12);cout<<"4 . Grand thef auto V";
	gotoxy(12,14);cout<<"Deseas ingresar a la tienda ? si/no [  ]";
	gotoxy(48,14),cin>>opcion2;
	if(opcion2=="si"||opcion2=="SI")
		compraraplicaciones(aplic, precioJuego, nombreJuego, h, saldo,ind);
	else
		menutienda(aplic, precioJuego, nombreJuego, h, saldo,ind);
}
void tusaplicaciones(app aplic[100], float precioJuego[8], string nombreJuego[8], int h, int saldo,int ind){
	char opcion1;
	system("cls");
	marco();
	gotoxy(70,4);cout<<saldo<<" $";
	gotoxy(10,7);cout<<"Tus Aplicaciones";
	for(int k=9;k<h+9;k++){
		gotoxy(7,k);cout<<char(k+88)<<". "<<aplic[k-9].nom;
	}
	gotoxy(10,17);cout<<"Aplicacion a ingresar [  ]";
	gotoxy(10,18);cout<<"Digite 0 para salir";
	gotoxy(33,17),cin>>opcion1;
	if(opcion1=='0')
		menutienda(aplic, precioJuego, nombreJuego, h, saldo,ind);
	switch(opcion1){
		case 'a' : convertidor(); 
			break;
	}
}
void MenuAplicacion(app aplic[100], float precioJuego[8], string nombreJuego[8], int &h, char opcion, int saldo,int ind){
	string opcion1;
	system("cls");
	marco();
	gotoxy(70,4);cout<<saldo<<" $";
	gotoxy(34,5);cout<<nombreJuego[opcion-1];
	gotoxy(10,7);cout<<"DESCRIPCION DE LA APLICACION";
	gotoxy(12,14);cout<<"Desea mandar al carrito ? si/no [  ]";
	gotoxy(45,14),cin>>opcion1;
	if(opcion1=="si"||opcion1=="SI"){
		aplic[h].precio = precioJuego[opcion-1]; aplic[h].nom = nombreJuego[opcion-1];
		h++;
		carrito(aplic, precioJuego, nombreJuego, h, saldo,ind);
	}
	else
		compraraplicaciones(aplic, precioJuego, nombreJuego, h, saldo,ind);
}
int convertidor(){
tipocambio valores={1,3.28,3.5,4};
menucambio(valores);
}
void menucambio(tipocambio valores){
	cin.ignore(256,'\n');
	int v=1;
	int s,d,e,l,b;
	char opc,o;
	while(v==1){
	o=MenuCambioA();
	switch(o){
		case '1':
			system("cls");
			marco();
        	gotoxy(24,6); cout<<"Ingrese Cantidad de Soles: "; cin>>s;
			gotoxy(24,8);cout<<"Ingrese Moneda a Cambiar:"<<endl;
			gotoxy(24,9);cout<<"[1]..Dolar"<<endl;
			gotoxy(24,10);cout<<"[2]..Euro"<<endl;
			gotoxy(24,11);cout<<"[3]..Libra"<<endl;
       	 	gotoxy(24,12),cout<<"Opcion: ";cin>>b;
				switch(b){
					case 1:
					gotoxy(8,14);cout<<"Total de dolares: ";
					gotoxy(28,14);cout<< s/valores.dolar<<endl;
					break;
					case 2:
					gotoxy(8,14);cout<<"Total de Euros: ";
					gotoxy(28,14);cout<< s/valores.euro<<endl;
					break;
					case 3:
					gotoxy(8,14);cout<<"Total de Libras: ";
					gotoxy(28,14);cout<< s/valores.libra<<endl;
					break;
				}
				break;
		case '2':
		system("cls");
        gotoxy(24,6);cout<<"Ingrese Cantidad de Dolares: ";cin>>d;
        gotoxy(24,8);cout<<"Ingrese Moneda a Cambiar:"<<endl;
        gotoxy(24,9);cout<<"[1]..Soles"<<endl;
        gotoxy(24,10);cout<<"[2]..Euro"<<endl;
        gotoxy(24,11); cout<<"[3]..Libra"<<endl;
        gotoxy(24,12),cout<<"Opcion: ";cin>>b;
				switch(b){
					case 1:
                    gotoxy(8,14);cout<<"Total de Soles: ";
                    gotoxy(28,14);cout<< d*valores.dolar<<endl;
					break;
					case 2:
                    gotoxy(8,14);cout<<"Total de Euros: ";
                    gotoxy(28,14);cout<< (d*valores.dolar)/valores.euro<<endl;
					break;
					case 3:
                    gotoxy(8,14);cout<<"Total de Libras: ";
					gotoxy(28,14);cout<< (d*valores.dolar)/valores.libra<<endl;
					break;
				}
				break;

		case '3':
		system("cls");
        gotoxy(24,6);cout<<"Ingrese Cantidad de Euros: ";cin>>e;
        gotoxy(24,8); cout<<"Ingrese Moneda a Cambiar:"<<endl;
        gotoxy(24,9);cout<<"[1]..Soles"<<endl;
        gotoxy(24,10);cout<<"[2]..Dolares"<<endl;
        gotoxy(24,11);cout<<"[3]..Libra"<<endl;
        	gotoxy(24,12),cout<<"Opcion: ";cin>>b;
				switch(b){
					case 1:
					gotoxy(8,14);cout<<"Total de Soles: ";
					gotoxy(28,14);cout<< e*valores.euro<<endl;
					break;
					case 2:
					gotoxy(8,14);cout<<"Total de dolares: ";
					gotoxy(28,14);cout<< (e*valores.euro)/valores.dolar<<endl;
					break;
					case 3:
					gotoxy(8,14);cout<<"Total de Libras: ";
					gotoxy(28,14);cout<< (e*valores.euro)/valores.libra<<endl;
					break;
				}
				break;
		case '4':
		system("cls");
         gotoxy(24,6);cout<<"Ingrese Cantidad de Libras: ";cin>>l;
         gotoxy(24,8);cout<<"Ingrese Moneda a Cambiar:"<<endl;
         gotoxy(24,9);cout<<"[1]..Soles"<<endl;
         gotoxy(24,10);cout<<"[2]..Dolares"<<endl;
         gotoxy(24,11);cout<<"[3]..Euros"<<endl;
        	gotoxy(24,12),cout<<"Opcion: ";cin>>b;
				switch(b){
					case 1:
					gotoxy(8,14);cout<<"Total de Soles: ";
					gotoxy(28,14);cout<< l*valores.libra<<endl;
					break;
					case 2:
					gotoxy(8,14);cout<<"Total de Dolares: ";

					gotoxy(28,14);cout<< (l*valores.libra)/valores.dolar<<endl;
					break;
					case 3:
					gotoxy(8,14);cout<<"Total de Euros: ";
					gotoxy(28,14);cout<< (l*valores.libra)/valores.euro<<endl;
					break;
				}
				break;
	}
	gotoxy(4,16);cout<<"Si desea volver al convertidor presione la tecla S: ";cin>>opc;
	if(opc == 'S' or opc == 's')
	v=1;
	else v=0;
	}
}
char MenuCambioA(){
	char a;
	system("cls");
	marco();
	gotoxy(28,8);cout<<"Ingrese Moneda a Cambiar"<<endl;
	gotoxy(28,9);cout<<"[1]..Nuevo Sol"<<endl;
	gotoxy(28,10);cout<<"[2]..Dolar"<<endl;
	gotoxy(28,11);cout<<"[3]..Euro"<<endl;
	gotoxy(28,12);cout<<"[4]..Libra"<<endl;
    gotoxy(28,14);cout<<"Opcion: ";cin>>a;
system("cls");
	return a;
	}
