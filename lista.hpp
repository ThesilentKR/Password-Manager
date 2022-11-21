#include <iostream>

using namespace std;

class Lista{
    private:
    class Vertex{
        public:
        
        Vertex(string user, string pass, string site) { 
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
    void buscar(string);
    void imprimir();
    void inicio_de_sesion();
};

void Lista::imprimir(){
    if(head != nullptr){

        Vertex *aux=head;

        while(aux->sig!=nullptr){
            cout<<aux->usuario;
            cout<<aux->passsword;
            cout<<aux->sitio;
            aux=aux->sig;
        }

    }else{
        cout<<"Lista vacia"<<endl;
    }
}

void Lista::insertar(string usuario,string password, string sitio){
    Vertex *nuevo_nodo = new Vertex(usuario,password,sitio);

    if(head == nullptr){
        head->back = nuevo_nodo;
        head=nuevo_nodo;
        tail=head;
    }else{
        tail->sig = nuevo_nodo;
        nuevo_nodo = nuevo_nodo->back=tail;
        tail=nuevo_nodo;
    }
}
