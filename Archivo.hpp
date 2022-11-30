#include <fstream>
#include <iostream>

using namespace std;

class Files{
    public:
    ifstream read;
    ofstream write;
    fstream temp;
    void escribir_en_archivo(string, string, string);
    void lectura_de_archivo();
    int size_s;
    int size_u;
    int size_c;
    char *buffer;
    bool val = true;
};