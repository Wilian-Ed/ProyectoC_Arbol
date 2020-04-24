#include <iostream>
#include <conio.h>
#include <cstring>
#include <fstream>

//Declarar variables de tipo global

struct arbolPersona{  //declaracion de una estrucutra
        string nombre; //campos de la estructura
        int edad;
        arbolPersona *izq;//puntero apuntando a la izquierda
        arbolPersona *der; //puntero apuntando a la derecha
    };//alias

arbolPersona *arbolDatos = NULL;

void insertarNodos(arbolPersona *&,string,int);
void Guardar();
void MenuOrdenar();

void escribirArchivo(string nombre, int edad){
    ofstream ArchivoUsuarios;//Declarar variable tipo archivo para escritura
    ArchivoUsuarios.open("datosUsuarios.txt",ios::app);//Abrir archivo
    ArchivoUsuarios<<nombre<<endl;//Escribiendo en el archivo
    ArchivoUsuarios<<edad<<endl;
    ArchivoUsuarios.close();//Cerrar Archivo
}

void leerArchivo(){
    string datos;
    ifstream DatosUsuarios;//declaracion de archivo para lectura
    DatosUsuarios.open("datosUsuarios.txt",ios::in);//Leer archivo
    
    if(DatosUsuarios.fail()){
        cout<<"Error al abrir archivo";
        getch();
    }
    else{
        while(!DatosUsuarios.eof()){
            getline(DatosUsuarios,datos);
            cout<<datos<<endl;
        }
        getch();
    }
    DatosUsuarios.close();
}

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
        MenuOrdenar();
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

void MenuOrdenar(){
    int opcion;
    clrscr();//clear screen
    system("color 17");
    gotoxy(50,12);
    cout<<"MENU";
    gotoxy(50,14);
    cout<<"1. Ordenar en Pre-orden";
    gotoxy(50,15);
    cout<<"2. Ordenar en Post-orden";
    gotoxy(50,16);
    cout<<"3. Ordenar en In-orden";
    gotoxy(50,17);
    cout<<"4. Regresar al menu anterior";
    gotoxy(50,19);
    cin>>opcion;
    switch (opcion)
    {
    case 1:
        MenuOrdenar();
        break;
    case 2:
        MenuOrdenar();
        break;
    case 3:
        MenuOrdenar();
        break;
    case 4:
        Menu();
        break;
    default:
        cout<<"Opcion incorrecta!!!";
        getch();
        MenuOrdenar();
        break;
    }
}

void Guardar(){//Funcion guardar la informacion del usuario el nombre y la edad
    string Nombre;
    int Edad;
    clrscr();
    system("color 47");
    gotoxy(50,14);//posicionar las letra en pantalla recibe dos parametros y , x
    cout<<"Ingrese su nombre\n";
    gotoxy(50,16);
    cin>>Nombre;
    clrscr();//clear screen
    system("color 17");
    gotoxy(50,14);
    cout<<"Ingrese su edad\n";
    gotoxy(50,16);
    cin>>Edad;
    escribirArchivo(Nombre,Edad);
    insertarNodos(arbolDatos,Nombre,Edad);
    Menu();
}

arbolPersona *insertarPrimerNodo(string Name,int Age){//Funcion que inserta el primer Nodo
    arbolPersona *Nodo = new arbolPersona();
    Nodo -> nombre = Name;
    Nodo -> edad = Age;
    //Nodo -> id= id;
    Nodo -> izq = NULL;
    Nodo -> der = NULL;
    return Nodo;
}

void insertarNodos(arbolPersona *&arbol,string Name,int Age)//Funcion que inserta nodos
{
    if(arbol!=NULL){//Si el arbol ya tiene un dato
        int nodoPadre = arbolDatos -> edad;
        if (Age<nodoPadre){
            insertarNodos(arbol->izq,Name,Age);//Insertar a la izquierda
        }
        else
        {
            insertarNodos(arbol->der,Name,Age);//Insertar a la derecha
        }
        
        {
            /* code */
        }
    }
    else //Si el arbol esta vacio
    {
        arbolPersona *NodoRaiz = insertarPrimerNodo(Name,Age);
        arbolDatos = NodoRaiz;
    }
}

void main(){ //Funcion principal
    Menu();
   getch();
}