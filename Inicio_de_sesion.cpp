#include "Inicio_de_sesion.hpp"

void Inicio::Inicio_de_sesion(){ ///INTERFAZ E INICIO DE SESION
    lectura_de_user();
    do{  
        system("cls");
cout<<"\t\t\t\tLOGIN"<<endl;
cout<<endl<<"User: ";
getline(cin, user);
cout<<"Password: ";
char car;
car = getch();
pass = "";
while(car != 13){
    if(car != 8){
    pass.push_back(car);
    cout<<"*";

}else{
    if(pass.length() >0){
        cout<<"\b \b";
        pass = pass.substr(0, pass.length() - 1);
    }
}
    car = getch();
}
if(user == usuario && pass == contra){ ///VALIDACION
    verify = true;
}else{
    cout<<"\n\t usuario y/o contraseña son incorrectos"<<endl;
    system("pause");
    cont++;
}

}while(verify == false && cont < 3);

if(verify == false){///PARA SACAR AL USUARIO DESPUES DE 3 INTENTOS
    cout<<endl<<"\tDEMASIADOS INTENTOS FALLIDOS, ADIOS"<<endl;
    exit(EXIT_SUCCESS);
}else{
cout<<endl<<"\tBienvenido :)"<<endl;
_sleep(2000);
system("cls");
}

}

void Inicio::escritura_de_user(){ ///REGISTRO DE NUEVO USUARIO
write_sesion.open("User.txt",ios::app);
if(!write_sesion){
    cout<<"Error al abrir el archivo [USER W]"<<endl;
    exit(1);
}
              system("cls");
        cout<<"\t\t\t\tSIGN UP"<<endl;
        cout<<endl<<"User: ";
        getline(cin, usuario);
        cout<<"Password: ";
        getline(cin,contra);
write_sesion<<usuario<<"-";write_sesion<<contra;
write_sesion.close();
}

void Inicio::validacion_de_user_existente(){ ///FUNCION PARA VER SI HAY ALGUN USUARIOR REGISTRADO
string v;
read_sesion.open("User.txt",ios::in);
if(!read_sesion){
    cout<<"Error al abrir el archivo [USER V]";
    exit(1);
}

}

void Inicio::lectura_de_user(){ ///LECTURA INFORMACION DEL USUARIO
string u; string p;
read_sesion.open("User.txt",ios::in);
if(!read_sesion){
    cout<<"Error al abrir el archivo [USER R]";
    exit(1);
}
    if(val == false){ 
    getline(read_sesion, u, '-');
    getline(read_sesion, p);
    usuario = u;
    contra = p;
    cout<<usuario<<" - "<<contra;
    system("pause");
    read_sesion.close();        
    }else{
        escritura_de_user();
        return;
    }
}