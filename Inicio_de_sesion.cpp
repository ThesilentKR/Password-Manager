#include "Inicio_de_sesion.hpp"
#define USER "Allen"
#define PASS "Allen123"

void Inicio::Inicio_de_sesion(){
    do{
        system("cls");
cout<<"\t\t\t\tLOGIN"<<endl;
cout<<endl<<"User: ";
getline(cin, user);

cout<<"Password: ";
char car;
car = getch();
pass = "";
while(car != 13){
    if(car != 8){
    pass.push_back(car);
    cout<<"*";

}else{
    if(pass.length() >0){
        cout<<"\b \b";
        pass = pass.substr(0, pass.length() - 1);
    }
}
    car = getch();
}
if(user == USER && pass == PASS){
    verify = true;
}else{
    cout<<"\n\t usuario y/o contraseña son incorrectos"<<endl;
    system("pause");
    cont++;
}

}while(verify == false && cont < 3);

if(verify == false){
    cout<<endl<<"\tDEMASIADOS INTENTOS FALLIDOS, ADIOS"<<endl;
    exit(EXIT_SUCCESS);
}else{
cout<<endl<<"\tBienvenido :)"<<endl;
_sleep(2000);
system("cls");
}

}