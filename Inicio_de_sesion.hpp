#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

class Inicio{
    public:
    void Inicio_de_sesion();
    void lectura_de_user();
    void escritura_de_user();
    void validacion_de_user_existente();
    string Encr_log(string, string);
    string pass;
    string user;
    string contra; ///ESCRITURA DE ARCHIVO PRIMERO/CUANDO CREAS USUARIO 
    string usuario; //ESCRITURA DE ARCHIVO PRIMERO/CUANDO CREAAS USUARIO
    string contra_;
    string usuario_;
    string fake_site = "Opera";
    bool verify = false;
    bool val = true; ///VERIFICAR USUARIOS EXISTENTES
    int cont = 0;
    int size_user;  
    int size_pass;
    int size_site;
    char *buf;
    ifstream read_sesion;
    ofstream write_sesion;
};