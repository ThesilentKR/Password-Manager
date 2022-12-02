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
//contra=encryptado(contra,pass);
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
_sleep(1000);
system("cls");
}

}

void Inicio::escritura_de_user(){ ///REGISTRO DE NUEVO USUARIO
write_sesion.open("confidencial.txt",ios::app | ios::binary);
if(!write_sesion){
    cout<<"Error al abrir el archivo [USER W]"<<endl;
    exit(1);
}
              system("cls");
        cout<<"\t\t\t\tSIGN UP"<<endl;
        cout<<endl<<"User: ";
        getline(cin, usuario_);
        cout<<"Password: ";
        getline(cin,contra_);
        usuario = usuario_;
        contra = contra_;
        usuario_ = Encr_log(usuario, "X/8");
        contra_ = Encr_log(contra, "X/8");
     size_user = (usuario.size());  
     size_pass = (contra.size());
     size_site = (fake_site.size());

write_sesion.write(reinterpret_cast<char *>(&size_site), sizeof(int));
write_sesion.write(fake_site.c_str(), size_site);

write_sesion.write(reinterpret_cast<char *>(&size_user), sizeof(int));
write_sesion.write(usuario_.c_str(), size_user);

write_sesion.write(reinterpret_cast<char *>(&size_pass), sizeof(int));
write_sesion.write(contra_.c_str(), size_pass);

	usuario_ = contra_ = fake_site = "";
	size_user = size_pass = size_site = 0;
    
write_sesion.flush();
write_sesion.close();
}

void Inicio::validacion_de_user_existente(){ ///FUNCION PARA VER SI HAY ALGUN USUARIOR REGISTRADO
string v;
read_sesion.open("confidencial.txt",ios::in | ios::binary);
if(!read_sesion){
    cout<<"Error al abrir el archivo [USER V]";
    exit(1);
}
    size_user = 0;
	read_sesion.read(reinterpret_cast<char *>(&size_user), sizeof(int));
	buf = new char[size_user];
	read_sesion.read( buf, size_user);
	v = "";
	v.append(buf, size_user);
if(v == ""){
    val = false;
}
read_sesion.close();
}

void Inicio::lectura_de_user(){ ///LECTURA INFORMACION DEL USUARIO
string u; string p; string s;
validacion_de_user_existente();
read_sesion.open("confidencial.txt",ios::in | ios::binary);
if(!read_sesion){
    cout<<"Error al abrir el archivo [USER R]";
    exit(1);
}

    if(val == true){ 
	read_sesion.read(reinterpret_cast<char *>(&size_site), sizeof(int)); ///AQUI CAPTURA EL SITIO FALSO
	buf = new char[size_site];
	read_sesion.read( buf, size_site);
	s = "";
	s.append(buf, size_site);

	read_sesion.read(reinterpret_cast<char *>(&size_user), sizeof(int));///AQUI CAPTURA EL USER
	buf = new char[size_user];
	read_sesion.read( buf, size_user);
	u = "";
	u.append(buf, size_user);

	read_sesion.read(reinterpret_cast<char *>(&size_pass), sizeof(int));///AQUI CAPTURA LA CONTRASEÑA
	buf = new char[size_pass];
	read_sesion.read( buf, size_pass);
	p = "";
	p.append(buf, size_pass);
    
    read_sesion.close();        
    usuario = Encr_log(u, "X/8");
    contra = Encr_log(p, "X/8");
    }else{
        escritura_de_user();
        return;
    }
}

string Inicio::Encr_log(string e, string k){
    string key = k;
    string output = e;
    int s = k.size();int mod = 0;
    for (int i = 0; i < e.size(); i++){
     mod = i % s;
        output[i] = e[i] ^ key[mod];
    }
    return output;

}
//hola