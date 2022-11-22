#include <iostream>
using namespace std;

class Lista{
    private:
    class Vertex{
        public:
        
        Vertex(string site, string user, string pass) { 
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

    Lista(){head=nullptr;tail=nullptr;}

    void insertar(string,string,string);
    void eliminar(string);
    void buscar(string);
    void modificar(string);
    void imprimir();
    void inicio_de_sesion();
};


void Lista::imprimir(){
    if(head != nullptr){

        Vertex *aux=head;

        while(aux!=nullptr){
            cout<<"Sitio: "<<aux->sitio<<endl;
            cout<<"Usuario: "<<aux->usuario<<endl;
            cout<<"Constrasena: "<<aux->passsword<<endl;
            cout<<"\n";
            aux=aux->sig;
        }

    }else{
        cout<<"Lista vacia"<<endl;
    }
}

void Lista::insertar(string sitio,string usuario, string password){
    Vertex *nuevo_nodo = new Vertex(sitio,usuario,password);
    if(head==nullptr){
        head = nuevo_nodo; //si esta vacia head toma el lugar de nuevo nodo
        tail = head; // tail y head apuntan al mismo
    }else{
        tail->sig = nuevo_nodo; //tail en su parte siguiente se apunta al nuevo nodo
        nuevo_nodo->back=tail; // hacemos que el nuevo nodo apunte a tail
        tail = nuevo_nodo; // tail pasa a hacer el nuevo nodo 
    }
}

/*AGREGA LA CONDICION DE NOMBRE NO EXISTENTE*/
void Lista::eliminar(string sitio){

    if(head != nullptr){
        Vertex *pre=head; //Iniciamos pre en head
        Vertex *anterior; //creamos un anterior
        while(pre != nullptr && pre->sitio != sitio){ //hacemos un recorrido hasta terminar o encontrar el sitio
            anterior=pre; //capturamos el anterior del encontrado
           pre = pre->sig; //recorremos el pre
        }
        if(pre == nullptr){
        cout<<"Sitio no encontrado [DEL]"<<endl;
         return;
        }
        if (pre == head){ //comparamos si el que vamos es el inicio
            head = head->sig; // igualamos head a su campo siguiente que seria null
            delete pre; //eliminamos la variable que creamos
        }else if(pre == tail){ //comparamos si el que vamos a eliminar es tail
            tail = tail->back; //igualamos head a su campo anteriro que es null
            tail->sig=nullptr; // ponemos un null en su campo siguiente 
            delete pre; //eliminamos la variable que creamos
        }else{      
            Vertex *eliminar = anterior->sig;  //creamos una variable para eliminar el dato encontrado
            Vertex *des = eliminar->sig; //creamos otra para el otro nodo que esta delante del que se va a eliminar

            anterior->sig = des; //reconectamos el anterior con el nodo que va a siguiente
            des->back= anterior;  //reconectamos el siguiente con el anterior

            delete eliminar; //eliminamos el dato que encontramos
        }
    }else{
        cout<<"Lista vacia"<<endl;
    }

}

void Lista::buscar(string sitio){

    Vertex *pre=head; //Iniciamos pre en head
    while(pre != nullptr && pre->sitio != sitio){ //hacemos un recorrido hasta terminar o encontrar el sitio
        pre = pre->sig; //recorremos el pre
    }
    if(pre == nullptr){
    cout<<"Sitio no encontrado [SEARCH]"<<endl;
    return;
    }
    cout<<"Usuario: "<<pre->usuario<<endl;
    cout<<"Constrasena: "<<pre->passsword<<endl;
    cout<<"Sitio: "<<pre->sitio<<endl;    
    system("pause");
}

void Lista::modificar(string sitio){
     Vertex *pre=head; //Iniciamos pre en head
    while(pre != nullptr && pre->sitio != sitio){ //hacemos un recorrido hasta terminar o encontrar el sitio
        pre = pre->sig; //recorremos el pre
    }
        if(pre == nullptr){
    cout<<"Sitio no encontrado [MOD]"<<endl;
    return;
    }
    int opc;
    string auxstring;
    do{
        cout<<"Que quieres modificar del sitio "<<pre->sitio<<":"<<endl;
        cout<<"1) Sitio"<<endl;
        cout<<"2) Usuario"<<endl;
        cout<<"3) Password"<<endl;
        cout<<"4) Salir"<<endl;
        cin>>opc;
        switch(opc){
        case 1:
            cout<<"Digita el nuevo Sitio: "; cin>>auxstring;
            pre->sitio=auxstring;
            break;
        case 2:
            cout<<"Digita el nuevo Usuario: "; cin>>auxstring;
            pre->usuario=auxstring;
            break;
        case 3:
            cout<<"Digita el nuevo Password: "; cin>>auxstring;
            pre->passsword=auxstring;
        break;
        default:
            break;
        }

    }while (opc != 4);
}

