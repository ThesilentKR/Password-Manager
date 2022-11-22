#include <iostream>
#include <fstream>
#include <conio.h>
#define USER "Allen"
#define PASS "+John123"

using namespace std;

class Inicio{
    public:
    void Inicio_de_sesion();
    string pass;
    string user;
    bool verify = false;
    int cont = 0;
};
