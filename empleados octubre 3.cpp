#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int const trabajador=50;
int const dias=30;
 
struct nacimiento{
int dia;
int mes;
int anyo;
}; 
struct datos {
int id;
string nombre;
string domicilio;
int CP;
char sexo;
nacimiento fecha;
};
void introducir (datos& reg);
bool fecha (datos reg);
int busca_id(datos reg[trabajador], int dni, int inicio, int final);
void imprimirEmpleado (datos reg);
void modificarDatos (datos& reg);
void ordena_sele(datos reg[trabajador], int cont);
void intercambia(int& a, int&b);
 
int main(void){
int opc=1;
datos empleados[trabajador];
int contador_empleados=1;
int job=0;
char continua;
int principio=1;
while(opc!=0){
 
cout << "CONTROL DE PRESENCIA" << endl;
cout << "1. Introducir/modificar datos de empleados " << endl;
cout << "2. Horarios de entrada y salida " << endl;
cout << "3. Consultar datos personal " << endl;
cout << "4. Control laboral de personal " << endl;
cout << "0. Salir " << endl;
cout << "Seleccione una opcion: " <<endl;
cin >> opc;
switch(opc){
case 1:
{
while(opc2!=0){
system("cls"); //limpia la pantalla
cout << "MENU DATOS" << endl;
cout << "1. Introducir datos de empleados" << endl;
cout << "2. Modificar datos de empleados" << endl;
cout << "0. Volver a menu principal "<< endl;
cout << "Seleccione una opcion: "<<endl;
cin >> opc2;
 
switch(opc2){
 
case 1:
{
cout<<"Introduzca los datos del 1er empleado"<<endl;
introducir (empleados[job]);
cout<<"Si no desea introducir m∑s datos pulse N"<<endl;
cin>>continua;
while(job<trabajador && continua!='N')
{ job++;
contador_empleados++;
 
cout<<endl<<"Introduzca los datos del "<<job+1<<"o empleado"<<endl;
introducir (empleados[job]);
ordena_sele(empleados, contador_empleados);
cout<<"Si no desea introducir mas datos pulse N"<<endl;
cin>>continua;
} 
}
break;
 
case 2:
{
int dni;
int pos;
cout<<"Introduzca DNI del empleado que desee modificar(sin letra)"<<endl; 
cin>>dni;
 
pos = busca_id(empleados,dni, principio, contador_empleados);
if (pos!=-1){
cout<< "Los datos del empleado son:"<<endl;
imprimirEmpleado(empleados[pos]);
modificarDatos(empleados[pos]);
}else{ cout <<"No existe empleado"<<endl;
}
}
break;
case 0:
 
break;
default:
cout << endl;
cout << " La opcion es incorrecta, vuelva a seleccionar una opcion " << endl;
cout << endl;
break;
}// fin switch
}// fin while
} // fin case 1 general
break;
 
case 2:
{ int opc3=1;
system("color 0C");
while(opc3!=0){
system("cls"); //limpia la pantalla
cout << "MENU HORARIOS" << endl;
cout << "Si desea introducir el horario de un trabajador pulse 1"<<endl;
cout << "Si desea volver al menu principal pulse 0"<<endl;
cout << "Seleccione una opcion: " <<endl;
cin >> opc3;
 
switch(opc3){
case 1:
 
break;
case 0:
 
break;
default:
cout << endl;
cout << " La opcion es incorrecta, vuelva a seleccionar una opcion " << endl;
cout << endl;
system ("pause");
break;
} //fi del switch
}// fin del while
} // fin case 2 general
break;
 
case 3:
{
system("color 0D");
char opc4='a';
while(opc4!='0'){
system("cls"); //limpia la pantalla
cout << "CONSULTA DE DATOS" << endl;
cout << "1. Un solo empleado por DNI " << endl;
cout << "*. Todos los empleados (pulse ascerisco) " << endl;
cout << "0. Para volver al menu principal " << endl;
cout << "Seleccione una opcion: " <<endl;
cin >> opc4;
switch(opc4){
case '1' :
// buscar e introducir
break;
case '*':
int job;
for(job=0;job<=contador_empleados-1;job++){// si no relleno todos los trabajadores da error
imprimirEmpleado(empleados[job]);
}
system ("pause");
break;
 
case '0':
break;
 
default:
cout << endl;
cout << "La opcion es incorrecta, vuelva a seleccionar una opcion " << endl;
cout << endl;
system ("pause");
break;
}//final while
} //fi del switch
}// fin case 3 general
break;
 
case 4:
{ int opc5=1;
while(opc5!=0){
system("color 0E");
system("cls"); //limpia la pantalla
cout << "CONSULTA HORARIOS" << endl;
cout << " 1. Consulta un dÃa " << endl;
cout << " 2. Consulta la presencia de un empleado " << endl;
cout << " 0. Volver menu pricipal " << endl;
cout << "Seleccione una opcion: " <<endl;
cin >> opc5;
 
switch(opc5){
case 1:
//buscar dÃa
 
break;
case 2:
//buscar dni y mostrar tabla de horarios 
break;
 
case 0:
break;
 
default:
cout << endl;
cout << " La opcion es incorrecta, vuelva a seleccionar una opcion " << endl;
cout << endl;
system ("pause");
break;
} //fi del switch
}// fin del while
} // fin case 4 general
break;
 
case 0:
cout<<"Gracias por utilizar el servicio."<<endl;
break;
 
default:
cout << endl;
cout << " La opcion es incorrecta, vuelva a seleccionar una opcion " << endl;
cout << endl;
system ("pause");
} //fi del switch
}//fin del loop general
system("pause");
} // fin main
void introducir (datos& reg){
string stub; //Para el "ignore"
char stub2; //para la fecha
cout<<endl <<"Introduzca DNI del trabajador (sin letra)" <<endl;
cin >> reg.id;
getline(cin, stub); //Esto es equivalente a cin.ignore()
cout<<endl <<endl <<"Escriba el nombre y apellidos del trabajador "<<endl;
getline(cin, reg.nombre);
cout<<endl <<"Escriba domicilio del trabajador " <<endl;
getline(cin, reg.domicilio);
cout<<endl <<"Escriba codigo postal del trabajador " <<endl;
cin >> reg.CP;
cout<<endl<<"Introduzca fecha nacimiento del trabajador (dd/mm/aaaa)"<< endl;
cin >> reg.fecha.dia;
cin >> stub2 >> reg.fecha.mes;
cin >> stub2 >> reg.fecha.anyo;
while(!fecha(reg)){
cout << "Fecha erronea. Introduzca de nuevo:" << endl;
cin >> reg.fecha.dia;
cin >> stub2 >> reg.fecha.mes;
cin >> stub2 >> reg.fecha.anyo;
}
cout<<endl<<"Intruduzca el sexo del trabajador (m/h)" << endl;
cin>>reg.sexo;
while(reg.sexo!='m' && reg.sexo!='h')
{
cout<<"Letra incorrecta, introduzca m o h"<<endl;
cin>>reg.sexo;
}
}
bool fecha (datos reg){
bool fecha_tra=true;
if((reg.fecha.anyo>2007||reg.fecha.anyo<1947) || reg.fecha.mes>12 ){ //Los trabajadores no pueden tener menos de 16 a“os
fecha_tra=false;}
else if ((reg.fecha.mes==4||reg.fecha.mes==6||reg.fecha.me s==9||reg.fecha.mes==11) && reg.fecha.dia<=30){
fecha_tra=true;
}else if (reg.fecha.mes==2 && reg.fecha.dia<=28){ //suponemos que los bisiestos no existen
fecha_tra=true;
} else if ((reg.fecha.mes==1||reg.fecha.mes==3||reg.fecha.me s==5||reg.fecha.mes==7||reg.fecha.mes==8||reg.fech a.mes==10||reg.fecha.mes==12) && reg.fecha.dia<=31){
fecha_tra=true;
}else{fecha_tra=false;} 
return fecha_tra;
}
int busca_id(datos reg[trabajador], int dni, int inicio, int final){
while(inicio<=final){
int medio=(inicio+final)/2;
if(dni<reg[medio].id){
inicio=medio+1; // buscamos en la segunda mitad de la tabla
}else if (dni>reg[medio].id){
final=medio-1;}
else
return medio;
}
return -1;
}
void modificarDatos (datos& reg){
string stub; //Para el "ignore"
char stub2; //para la fecha 
int opc_acc;
while(opc_acc!=0){ 
system ("clear");
cout << "MODIFICAR"<< endl;
cout << "1. Nombre " << endl;
cout << "2. Direcci€n " << endl;
cout << "3. Codigo postal" << endl;
cout << "4. Fecha de nacimiento " << endl;
cout << "5. Sexo " << endl;
cout << "6. Eliminar datos trabajador"<<endl;
cout << "0. Volver men? anterior" << endl;
cout << "Seleccione una opcion: " <<endl;
cin>>opc_acc;
switch (opc_acc){ 
case 1:{
cout<<endl <<endl <<"Escriba el nombre y apellidos del trabajador "<<endl;
getline(cin, reg.nombre);
}
break;
case 2:{
cout<<endl <<"Escriba domicilio del trabajador " <<endl;
getline(cin, reg.domicilio);
}
break;
case 3:{
cout<<endl <<"Escriba codigo postal del trabajador " <<endl;
cin >> reg.CP;
}
break;
case 4:{
cout<<endl<<"Introduzca fecha nacimiento del trabajador (dd/mm/aaaa)"<< endl;
cin >> reg.fecha.dia;
cin >> stub2 >> reg.fecha.mes;
cin >> stub2 >> reg.fecha.anyo;
while(!fecha(reg)){
cout << "Fecha erronea. Introduzca de nuevo:" << endl;
cin >> reg.fecha.dia;
cin >> stub2 >> reg.fecha.mes;
cin >> stub2 >> reg.fecha.anyo;
}
}
break;
case 5:{
cout<<endl<<"Intruduzca el sexo del trabajador (m/h)" << endl;
cin>>reg.sexo;
while(reg.sexo!='m' && reg.sexo!='h')
{
cout<<"Letra incorrecta, introduzca m o h"<<endl;
cin>>reg.sexo;
}
}break;
case 6:
// Acci€n que elimine todo 
break;
case 0:
break;
default:
cout<<"Opcion incorrecta vuelva a elegir"<<endl;
system ("pause");
break;
}
}
}
void imprimirEmpleado (datos reg){
cout<<"El empleado con dni "<< reg.id << " tiene los siguientes datos almacenados:"<<endl;
cout<<"Nombre y apellidos: "<< reg.nombre<< endl;
cout<<"Direccion: " << reg.domicilio <<" "<<reg.CP<<endl;
cout<<"Fecha nacimiento: " <<reg.fecha.dia<<"/"<<reg.fecha.mes<<"/"<<reg.fecha.anyo<<endl;
cout << "Sexo: "<< reg.sexo<<endl;
}
void ordena_sele(datos reg[trabajador], int cont){
int i, j, posmin;
for (i=0; i<cont-1; i++) {
posmin=i; 
for (j=i+1; j<cont; j++) {
if (reg[posmin].id>reg[j].id) posmin=j;
}
intercambia(reg[i].id,reg[posmin].id);
}
}
void intercambia(int& a, int&b){
int aux; 
aux=a; a=b; b=aux;
}
