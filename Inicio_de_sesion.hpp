#include <iostream>
#include <fstream>
#include <conio.h>
#define USER "Allen"
#define PASS "+John123"

using namespace std;

class Inicio{
    public:
    void Inicio_de_sesion();
    void lectura_de_user();
    void escritura_de_user();
    string pass;
    string user;
    string contra;
    string usuario;
    bool verify = false;
    int cont = 0;
    ifstream read_sesion;
    ofstream write_sesion;
};