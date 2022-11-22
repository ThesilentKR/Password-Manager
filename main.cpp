#include "lista.hpp"
#include<fstream>
#include "Inicio_de_sesion.cpp"


int main(){
    Lista l; Inicio d;
    d.Inicio_de_sesion();
    ifstream archivo;
    fstream f;
    int opc;
    string Sitio,Usuario,Password,global;
    string Encryptado;

    cout<<"Dame la clave para desencriptar la informacion"<<endl;
    cin.ignore(); getline(cin,Encryptado);

    archivo.open("confidencial.txt",ios::in);
    if(archivo.fail()){
        cout<<"\nNo se pudo abrir el archivo.";
        exit(1);
    }
    while(!archivo.eof()){
        string Sitio,Usuario,Password;
        getline(archivo, Sitio,'-');
        //auxsite = Sitio;
        getline(archivo, Usuario,'-');
        //auxuser = '-' + Usuario;
        getline(archivo, Password);
        //auxcontra = '-' + Password;
        //cout<<global<<endl;system("pause");
        //global= l.encryptado(global,Encryptado);
        //cout<<global<<endl; system("pause");
        //global= l.encryptado(global,Encryptado);
        //cout<<global<<endl; system("pause");
        l.insertar(Sitio,Usuario,Password);
    }
    
    archivo.close();
    do{
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
           getline(cin,Sitio);

           l.buscar(Sitio);
            break;
        case 3:
            cout<<"Dame el nombre del sitio a buscar: ";
           getline(cin,Sitio);
           l.buscar(Sitio);
        break;
        case 4:
            cout<<"Dame el nombre del sitio a eliminar: ";
           getline(cin,Sitio);
            l.eliminar(Sitio);
        break;
        case 5:
            l.imprimir();
        break;
        default:
            break;
        }
    l.guardar();
    }while (opc != 6);
    
}
