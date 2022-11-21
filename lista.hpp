#include <iostream>

using namespace std;

class Lista{
    private:
    class Vertex{
        public:
        
        Vertex(string pass, string site, string user) { 
            passsword = pass; sitio=site; usuario=user;  sig=nullptr; back=nullptr;
        }

        string passsword;
        string sitio;
        string usuario;

        Vertex *sig;
        Vertex *back;
    };
    Vertex *head;
    Vertex *tail;
    public:

    void insertar(string,string,string);
};