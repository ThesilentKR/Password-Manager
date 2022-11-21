#include "lista.hpp"

int main(){
    Lista l;
    l.insertar("alan","allen","twitter");
    l.insertar("kevin","lol","google");
    l.insertar("pepe","viktor","coc");
    l.eliminar("XXX");
    l.imprimir();
    cout<<"Buscando..."<<endl;
    l.buscar("XXX");
    l.modificar("XXX");
    //l.imprimir();
}