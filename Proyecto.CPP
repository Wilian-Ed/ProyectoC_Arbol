#include <iostream>
#include <conio.h>
#include <cstring>

//Declarar variables de tipo global
struct persona{  //declaracion de una estrucutra
        string nombre; //campos de la estructura
        int edad;
    }person;//alias

void Guardar();

void Menu(){
    int opcion;
    clrscr();//clear screen
    system("color 17");
    gotoxy(50,12);
    cout<<"MENU";
    gotoxy(50,14);
    cout<<"1. Ingresar Informacion";
    gotoxy(50,15);
    cout<<"2. Ordenar";
    gotoxy(50,16);
    cout<<"3. Salir";
    gotoxy(50,18);
    cin>>opcion;
    switch (opcion)
    {
    case 1:
        Guardar();
        break;
    case 2:
        Menu();
        break;
    case 3:
    break;
    default:
        cout<<"Opcion incorrecta!!!";
        getch();
        Menu();
        break;
    }
}


void Guardar(){//Funcion guardar la informacion del usuario el nombre y la edad
    clrscr();
    system("color 47");
    gotoxy(50,14);//posicionar las letra en pantalla recibe dos parametros y , x
    cout<<"Ingrese su nombre\n";
    
    gotoxy(50,16);
    cin>>person.nombre;
    
    clrscr();//clear screen
    system("color 17");

    gotoxy(50,14);
    cout<<"Ingrese su edad\n";
    
    gotoxy(50,16);
    cin>>person.edad;
    
    Menu();
}

void imprimir(){ // Funcion imprimir
    cout<<person.nombre<<endl;
    cout<<person.edad<<endl;
}

void main(){ //Funcion principal
    Menu();
   getch();
}