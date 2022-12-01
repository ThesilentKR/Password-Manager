#include "Archivo.hpp"
#include "lista.hpp"

    Lista a;

void Files::escribir_en_archivo(string s, string u, string c){ ///ESCRITURA de archivos
write.open("confidencial.txt",ios::app | ios::binary);
if(!write){
cout<<"ERROR Archivo confidencial [Archivo.cpp/ESCRITURA]"<<endl;
exit(1);
}

    size_s = (s.size());
    size_u = (u.size());
    size_c = (c.size());

	write.write(reinterpret_cast<char *>(&size_s), sizeof(int)); ///ESRIBE EL SITIO
	write.write(s.c_str(), size_s);

	write.write(reinterpret_cast<char *>(&size_u), sizeof(int)); ///ESCRIBE EL USUARIO
	write.write(u.c_str(), size_u);

	write.write(reinterpret_cast<char *>(&size_c), sizeof(int)); ///ESCRIBE LA CONTRASEÑA
	write.write(c.c_str(), size_c);

	s = u = c = "";
	size_s = size_u = size_c = 0;

write.flush();
write.close();
}



void Files::lectura_de_archivo(){
read.open("confidencial.txt", ios::in | ios::binary);
if(!read){
cout<<"ERROR Archivo confidencial [Archivo.cpp/LECTURA]"<<endl;
exit(1);
}
    string s, u, c;
	read.read(reinterpret_cast<char *>(&size_s), sizeof(int)); ///AQUI CAPTURA EL SITIO 
	buffer = new char[size_s];
	read.read( buffer, size_s);
	s = "";
	s.append(buffer, size_s);

	read.read(reinterpret_cast<char *>(&size_u), sizeof(int)); ///AQUI CAPTURA EL USER
	buffer = new char[size_u];
	read.read( buffer, size_u);
	u = "";
	u.append(buffer, size_u);

	read.read(reinterpret_cast<char *>(&size_c), sizeof(int)); ///AQUI CAPTURA EL PASSWORD
	buffer = new char[size_c];
	read.read( buffer, size_c);
	c = "";
	c.append(buffer, size_c);

while(!read.eof()){	
	cout<<"site:  "<<s<<" User: "<<u<<" pass: "<<c<<endl;
                    system("pause");
a.insertar(s,u,c);
	read.read(reinterpret_cast<char *>(&size_s), sizeof(int)); ///AQUI CAPTURA EL SITIO 
	buffer = new char[size_s];
	read.read( buffer, size_s);
	s = "";
	s.append(buffer, size_s);

	read.read(reinterpret_cast<char *>(&size_u), sizeof(int)); ///AQUI CAPTURA EL USER
	buffer = new char[size_u];
	read.read( buffer, size_u);
	u = "";
	u.append(buffer, size_u);

	read.read(reinterpret_cast<char *>(&size_c), sizeof(int)); ///AQUI CAPTURA EL PASSWORD
	buffer = new char[size_c];
	read.read( buffer, size_c);
	c = "";
	c.append(buffer, size_c);
}
read.close();
}
