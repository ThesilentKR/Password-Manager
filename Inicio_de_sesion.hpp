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
    string pass;
    string user;
    string contra;
    string usuario;
    string fake_site = "Opera.com";
    bool verify = false;
    bool val = false;
    int cont = 0;
    int size_user;  
    int size_pass;
    int size_site;
    char *buf;
    ifstream read_sesion;
    ofstream write_sesion;
};