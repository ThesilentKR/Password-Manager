#include "lista.hpp"
#include<fstream>

int main(){
    Lista l;
    ifstream archivo;
    fstream f;
    int opc;
    string Sitio,Usuario,Password;
    archivo.open("confidencial.txt",ios::in);
    if(archivo.fail()){
        cout<<"\nNo se pudo abrir el archivo.";
        exit(1);
    }
    while(!archivo.eof()){
        string Sitio,Usuario,Password;
        getline(archivo, Sitio,'-');
        getline(archivo, Usuario,'-');
        getline(archivo, Password);
        l.insertar(Sitio,Usuario,Password);
    }
    archivo.close();
    do{
        system("cls");
        cout<<"1) Agregar"<<endl;
        cout<<"2) Buscar"<<endl;
        cout<<"3) Modificar"<<endl;
        cout<<"4) Eliminar"<<endl;
        cout<<"5) Imprimir"<<endl;
        cout<<"6) Salir"<<endl;
        cin>>opc;
        switch(opc){
        case 1:
        f.open("confidencial.txt",ios::app);
        cout<<"Dame el nombre del sitio: ";
           cin.ignore(); getline(cin,Sitio);
        cout<<"Dame el usuario: ";
           getline(cin,Usuario);
        cout<<"Dame la constraseña: ";
           getline(cin,Password);
        l.insertar(Sitio,Usuario,Password);
            f<<"\n"<<Sitio<<"-";f<<Usuario<<"-";f<<Password;
           f.close();
            break;
        case 2:
            cout<<"Dame el nombre del sitio a buscar: ";
           cin.ignore();getline(cin,Sitio);
        
           l.buscar(Sitio);
            break;
        case 3:
            cout<<"Dame el nombre del sitio a modificar: ";
          cin.ignore();getline(cin,Sitio);
           l.buscar(Sitio);
        break;
        case 4:
            cout<<"Dame el nombre del sitio a eliminar: ";
           cin.ignore();getline(cin,Sitio);
            l.eliminar(Sitio);
        break;
        case 5:
            l.imprimir();
        break;
        default:
            break;
        }

    }while (opc != 6);
    
}