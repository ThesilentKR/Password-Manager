#include <iostream>

using namespace std;

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

class Lista{
    public:    
    Lista(){head=nullptr;tail=nullptr;}
    Vertex *head;
    Vertex *tail;
    void insertar(string,string,string);
    void eliminar(string);
    void buscar(string,string);
    void modificar(string);
    string encryptado(string, string);
    void imprimirTodo();
    void imprimirSitios();
    void imprimirUsuariosycontrasenas();
    void inicio_de_sesion();
    void guardar();
};


void Lista::imprimirTodo(){
    if(head != nullptr){

        Vertex *aux=head;

        while(aux!=nullptr){
            cout<<"Sitio: "<<aux->sitio<<endl;
            cout<<"Usuario: "<<aux->usuario<<endl;
            cout<<"Constrasena: "<<aux->passsword<<endl;
            cout<<"\n";
            aux=aux->sig;
        }
                    system("pause");
    }else{
        cout<<"Lista vacia"<<endl;
        system("pause");
    }
}

void Lista::imprimirSitios(){
    if(head != nullptr){

        Vertex *aux=head;

        while(aux!=nullptr){
            cout<<"Sitio: "<<aux->sitio<<endl;
            cout<<"\n";
            aux=aux->sig;
        }
                    system("pause");
    }else{
        cout<<"Lista vacia"<<endl;
            system("pause");
    }
}
void Lista::imprimirUsuariosycontrasenas(){
    if(head != nullptr){

        Vertex *aux=head;

        while(aux!=nullptr){
            cout<<"Usuario: "<<aux->usuario<<endl;
            cout<<"Constrasena: "<<aux->passsword<<endl;
            cout<<"\n";
            aux=aux->sig;
        }
                    system("pause");
    }else{
        cout<<"Lista vacia"<<endl;
            system("pause");
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
            system("pause");
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
            system("pause");
        system("cls");
    }

}

void Lista::buscar(string sitio,string Encryptado){
    if(head == nullptr){
        cout<<"LA LISTA ESTA VACIA"<<endl;
        return;
    }
    Vertex *pre=head; //Iniciamos pre en head
    while(pre != nullptr && pre->sitio != sitio){ //hacemos un recorrido hasta terminar o encontrar el sitio
        pre = pre->sig; //recorremos el pre
    }
    if(pre == nullptr){
    cout<<"Sitio no encontrado [SEARCH]"<<endl;
    return;
    }
    pre->usuario = encryptado(pre->usuario, Encryptado);
    pre->passsword = encryptado(pre->passsword, Encryptado);
    cout<<"Usuario: "<<pre->usuario<<endl;
    cout<<"Constrasena: "<<pre->passsword<<endl;
    cout<<"Sitio: "<<pre->sitio<<endl;    

    pre->usuario = encryptado(pre->usuario, Encryptado);
    pre->passsword = encryptado(pre->passsword, Encryptado);
    system("pause");
}

void Lista::modificar(string sitio){
    if(head == nullptr){
        cout<<"LA LISTA ESTA VACIA"<<endl;
        system("pause");
        return;
    }
     Vertex *pre=head; //Iniciamos pre en head
    while(pre != nullptr && pre->sitio != sitio){ //hacemos un recorrido hasta terminar o encontrar el sitio
        pre = pre->sig; //recorremos el pre
    }
        if(pre == nullptr){
    cout<<"Sitio no encontrado [MOD]"<<endl;
            system("pause");
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

string Lista::encryptado(string toEncrypt,string pass) {
    string key = pass; //Any char will work
    string output = toEncrypt;
    int mod = key.size();
    int d;
    for (int i = 0; i < toEncrypt.size(); i++){
        d = mod % i;
        output[i] = toEncrypt[i] ^ key[d];

    }
    return output;    
}