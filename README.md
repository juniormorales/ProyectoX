# ProyectoX
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
 	char c[10], id[10];
	system ("color 9F");
	for(int j=4;j<76;j++){
			gotoxy(j,3);
			cout<<"=";
			gotoxy(j,21);
			cout<<"=";
	}
	gotoxy(76,3);cout<<"+";
	gotoxy(3,3);cout<<"+";
	gotoxy(3,20);cout<<"+";
	gotoxy(76,20);cout<<"+";
	
	for(int k=3;k<20;k++){
			gotoxy(3,k);
			cout<<endl;
			gotoxy(3,k+1);
			cout<<"|";
			gotoxy(76,k+1);
			cout<<"|";
	}
	gotoxy(34,5);cout<<"PROSHEKTO X";
	gotoxy(10,9);cout<<"Ingrese su id : ";
	for(int i=38;i<65;i++){
		gotoxy(i,8);cout<<"-";
		gotoxy(i,10);cout<<"-";
	}
	gotoxy(37,9);cout<<"|";
	gotoxy(65,9);cout<<"|";
	gotoxy(40,9);cin>>id;
	
	gotoxy(10,15);cout<<"Ingrese su contrasenha : ";
	for(int i=38;i<65;i++){
		gotoxy(i,14);cout<<"-";
		gotoxy(i,16);cout<<"-";
	}
	gotoxy(37,15);cout<<"|";
	gotoxy(65,15);cout<<"|";
	gotoxy(40,15);cin>>c;
	


 }  
