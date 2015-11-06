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
