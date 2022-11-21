#include "lista.hpp"

int main(){
    Lista l;
    l.insertar("alan","allen","twiter");
    l.insertar("kevin","lol","google");
    l.insertar("pepe","viktor","coc");
    l.eliminar("coc");
    l.imprimir();
    cout<<"Buscando..."<<endl;
    l.buscar("coc");
}