#include "lista.hpp"
#include<fstream>
#include <time.h>
#include "Inicio_de_sesion.cpp"


int main(){
    Lista l; Inicio d;
    d.Inicio_de_sesion();
    ifstream archivo;
    fstream f;
    int opc,opc2;
    string Sitio,Usuario,Password,global,v,PasswordRandom;
    string Encryptado;
    bool val = false;
    
    do{
        cout<<"1) Agregar"<<endl;
        cout<<"2) Buscar"<<endl;
        cout<<"3) Modificar"<<endl;
        cout<<"4) Eliminar"<<endl;
        cout<<"5) Imprimir"<<endl;
        cout<<"6) Imprimir Sitios"<<endl;
        cout<<"7) Imprimir Ususarios y contraseñas"<<endl;
        cout<<"8) Salir"<<endl;
        cin>>opc;
        switch(opc){
        case 1:
        f.open("confidencial.txt",ios::app);
        cout<<"Dame el nombre del sitio: ";
           cin.ignore(); getline(cin,Sitio);
        cout<<"Dame el usuario: ";
           getline(cin,Usuario);
        cout<<"Quieres poner la contraseña tu o una generada"<<endl;
        cout<<"1-[Si] 2-[No]"<<endl;
        cin>>opc2; //agregar validacion
        if(opc2==1){
        cout<<"Dame la constraseña: ";
           cin.ignore(); getline(cin,Password);
           l.insertar(Sitio,Usuario,Password);
        }else{
            srand(time(NULL));
            int coca;
            cout<<"Dame la longitud de la cadena"<<endl;
            cin>>coca;
            for(int i=0;i<coca;i++){
                PasswordRandom += 47 + rand() % 76;
            }
            l.insertar(Sitio,Usuario,PasswordRandom);
        }
            break;
        case 2:
            cout<<"Dame el nombre del sitio a buscar: ";
            cin.ignore(); getline(cin,Sitio);
            l.buscar(Sitio,Encryptado);
            break;
        case 3:
            cout<<"Dame el nombre del sitio a modificar: ";
            cin.ignore(); getline(cin,Sitio);
           l.buscar(Sitio,Encryptado);
        break;
        case 4:
            cout<<"Dame el nombre del sitio a eliminar: ";
            cin.ignore();getline(cin,Sitio);
            l.eliminar(Sitio,Encryptado);
        break;
        case 5:
            l.imprimirTodo();
        break;
        case 6:
            l.imprimirSitios();
        break;
        case 7:
            l.imprimirUsuariosycontrasenas();
        break;
        default:
            break;
        }
    }while (opc != 8);
    
}
