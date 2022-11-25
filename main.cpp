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
    string Encryptado = d.contra;    ///PARA QUE SEA IGUAL A LA CONTRASEÑA DEL USUARIO
    bool val = false;

    archivo.open("confidencial.txt",ios::in);
    if(archivo.fail()){
        cout<<"\nNo se pudo abrir el archivo.";
        exit(1);
    }

    getline(archivo, v);
    archivo.close();
    if(v == ""){
        val = true;
    }
    //Si esta vacio o no
    if(val == false){
        archivo.open("confidencial.txt",ios::in);
        //Lee el archivo encriptado

        while(!archivo.eof()){
            string Sitio,Usuario,Password;
            getline(archivo, Sitio,'-');
            getline(archivo, Usuario,'-');
            getline(archivo, Password);
            getline(archivo,v);
            l.insertar(Sitio,Usuario,Password);
        }
        archivo.close();
    }
    
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
          Usuario = l.encryptado(Usuario,Encryptado);
        cout<<"Quieres poner la contraseña tu o una generada"<<endl;
        cout<<"1-[Si] 2-[No]"<<endl;
        cin>>opc2;
        if(opc2==1){
        cout<<"Dame la constraseña: ";
           cin.ignore(); getline(cin,Password);
           Password = l.encryptado(Password,Encryptado);
           l.insertar(Sitio,Usuario,Password);
           f<<"\n"<<Sitio<<"-";f<<Usuario<<"-";f<<Password;
           f.close();
        }else{
            srand(time(NULL));
            int coca;
            cout<<"Dame la longitud de la cadena"<<endl;
            cin>>coca;
            for(int i=0;i<coca;i++){
                PasswordRandom += 47 + rand() % 76;
            }
            PasswordRandom = l.encryptado(PasswordRandom,Encryptado);
            l.insertar(Sitio,Usuario,PasswordRandom);
            f<<"\n"<<Sitio<<"-";f<<Usuario<<"-";f<<PasswordRandom;
            f.close();
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
    remove("confidencial.txt");
    l.guardar();
    }while (opc != 8);
    
}
