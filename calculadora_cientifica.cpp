+#include <iostream>
+#include <math.h>
+#define PI 3.1415926
+#include <conio.h>
+#include <cstdlib>
+using namespace std;
+void suma(float a, float b, float resul);
+void resta(float a, float b, float resul);
+void division(float a, float b, float resul);
+void multiplicacion(float a, float b, float resul);
+void raiz(float a, float resul);
+void potencia(float a, float b, float resul);
+void seno(float a, float resul);
+void coseno(float a, float resul);
+void tangente(float a, float resul);
+void cosecante(float a, float resul);
+void secante(float a, float resul);
+void cotangente(float a, float resul);
+void logna(float a, float resul);
+void logdec(float a, float resul);
+
+int main(){
+	float num1,num2,sol;
+	char menu;
+	int opcion;
+	do{
+	cout<<"---------------Calculadora Multifuncional---------------"<<endl<<endl;
+	cout<<"OPCIONES DE OPERACIONES MATEMATICAS:"<<endl;
+	cout<<"1. Suma"<<endl;
+	cout<<"2. Resta"<<endl;
+	cout<<"3. Multiplicacion"<<endl;
+	cout<<"4. Division"<<endl;
+	cout<<"5. Potencia"<<endl;
+	cout<<"6. Raiz cuadrada"<<endl<<"\n";
+	cout<<"OPCIONES DE OPERACIONES TRIGONOMETRICAS:"<<endl;
+	cout<<"7. Seno"<<endl;
+	cout<<"8. Coseno"<<endl;
+	cout<<"9. Tangente"<<endl;
+	cout<<"10. Cosecante"<<endl;
+	cout<<"11. Secante"<<endl;
+	cout<<"12. Cotangente"<<endl<<"\n";
+	cout<<"OPCIONES DE OPERACIONES LOGARITMICAS:"<<endl;
+	cout<<"13. Logaritmo Natural"<<endl;
+	cout<<"14. Logaritmo decimal"<<endl<<"\n";
+	cout<<"Ingresa una opcion: "; cin>>opcion;
+	
+	switch(opcion){
+		case 1: suma(num1,num2,sol);
+		break;
+		case 2: resta(num1,num2,sol);
+		break;
+		case 3: multiplicacion(num1,num2,sol);
+		break;
+		case 4: division(num1,num2,sol);
+		break;
+		case 5: potencia(num1,num2,sol);
+		break;
+		case 6: raiz(num1,sol);
+		break;
+		case 7: seno(num1,sol);
+		break;
+		case 8: coseno(num1,sol);
+		break;
+		case 9: tangente(num1,sol);
+		break;
+		case 10: cosecante(num1,sol);
+		break;
+		case 11: secante(num1,sol);
+		break;
+		case 12: cotangente(num1,sol);
+		break;
+		case 13: logna(num1,sol);
+		break;
+		case 14: logdec(num1,sol);
+		break;
+		default: cout<<"Opcion no valida";
+	}
+	cout<<endl;
+
+
+	cout<<"Deseas continuar?(S:si/N:no): "; cin>>menu;
+	if(menu=='S')
+	system("cls");
+	else
+	system("PAUSE");
+	
+}while(menu=='S');}
+	
+	
+void suma(float a, float b, float resul){
+	cout<<"Ingrese el primer numero a sumar: "; cin>>a;
+	cout<<"Ingrese el segundo numero a sumar: "; cin>>b;
+	resul=a+b;
+	cout<<"El resultado es: "<<resul<<endl;
+}
+
+void resta(float a, float b, float resul){
+	cout<<"Ingrese el primer numero a restar: "; cin>>a;
+	cout<<"Ingrese el segundo numero a restar: "; cin>>b;
+	resul=a-b;
+	cout<<"El resultado es: "<<resul<<endl;
+}
+
+void multiplicacion(float a, float b, float resul){
+	cout<<"Ingrese el primer numero a multiplicar: "; cin>>a;
+	cout<<"Ingrese el segundo numero a multiplicar: "; cin>>b;
+	resul=a*b;
+	cout<<"El resultado es: "<<resul<<endl;
+}
+
+void division(float a, float b, float resul){
+	cout<<"Ingrese el primer numero a dividir: "; cin>>a;
+	cout<<"Ingrese el segundo numero a dividir: "; cin>>b;
+	resul=a/b;
+	cout<<"El resultado es: "<<resul<<endl;
+}
+
+void potencia(float a, float b, float resul){
+	cout<<"Ingrese la base: "; cin>>a;
+	cout<<"Ingrese el exponente: "; cin>>b;
+	resul=pow(a,b);
+	cout<<"El resultado es: "<<resul<<endl;
+}
+
+void raiz(float a, float resul){
+	cout<<"Ingrese el numero a radicar: "; cin>>a;
+	if(a<0)
+	cout<<"Error de sintaxis";
+	else{
+	resul=sqrt(a);
+	cout<<"El resultado es: "<<resul<<endl;}
+}
+
+void seno(float a, float resul){
+	cout<<"Ingrese el angulo en sexagesimales: "; cin>>a;
+	resul=sin(a*PI/180);
+	cout<<"El resultado es: "<<resul<<endl;
+}
+
+void coseno(float a, float resul){
+	cout<<"Ingrese el angulo en sexagesimales: "; cin>>a;
+	resul=cos(a*PI/180);
+	cout<<"El resultado es: "<<resul<<endl;
+}
+
+void tangente(float a, float resul){
+	cout<<"Ingrese el angulo en sexagesimales: "; cin>>a;
+	if(a==90 or a==270)
+	cout<<"Error de sintaxis";
+	else{
+	resul=tan(a*PI/180);
+	cout<<"El resultado es: "<<resul<<endl;}
+}
+
+void cosecante(float a, float resul){
+	cout<<"Ingrese el angulo en sexagesimales: "; cin>>a;
+	if(a==0 or a==180 or a==360)
+	cout<<"Error de sintaxis";
+	else{
+	resul=1/sin(a*PI/180);
+	cout<<"El resultado es: "<<resul<<endl;	}
+}
+
+void secante(float a, float resul){
+	cout<<"Ingrese el angulo en sexagesimales: "; cin>>a;
+	if(a==90 or a==270)
+	cout<<"Error de sintaxis";
+	else{
+	resul=1/cos(a*PI/180);
+	cout<<"El resultado es: "<<resul<<endl;}		
+}
+
+void cotangente(float a, float resul){
+	cout<<"Ingrese el angulo en sexagesimales: "; cin>>a;
+	if(a==0 or a==180 or a==360)
+	cout<<"Error de sintaxis";
+	else{
+	resul=1/cos(a*PI/180);
+	cout<<"El resultado es: "<<resul<<endl;}		
+}
+
+void logna(float a, float resul){
+	cout<<"Ingrese el modulo del logaritmo natural: "; cin>>a;
+	resul=log(a);
+	cout<<"El resultado es: "<<resul<<endl;	
+}
+
+void logdec(float a, float resul){
+	cout<<"Ingrese el modulo del logaritmo decimal: "; cin>>a;
+	resul=log10(a);
+	cout<<"El resultado es: "<<resul<<endl;	
+}
