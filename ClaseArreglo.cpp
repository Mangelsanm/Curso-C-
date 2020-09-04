#include <iostream>
using namespace std;

class Arreglo {
private:
    int *Elementos;
    int nElem;
    int longitud;
public:
    Arreglo();
    Arreglo(int valor);
    ~Arreglo();
    void obtenerElementos(int longitud);
    void imprimir();
    void agregar(int valor);
    void insertar(int indice, int valor);
    void eliminar(int indice);
    void burbuja();
    int bLineal(int valor);
    int bBinaria(int valor);
};

Arreglo::Arreglo(){
    nElem = 20;
    longitud = 0;
    Elementos = new int[nElem];
}

Arreglo::Arreglo(int valor){
    nElem = valor;
    longitud = 0;
    Elementos = new int[nElem];
}

Arreglo::~Arreglo() {
    delete []Elementos;
}

void Arreglo::obtenerElementos(int longitud) {
    this -> longitud = longitud;

    for(int i = 0; i < longitud; i++) {
        cout << "Elemento[" << i << "]: ";
        cin >> *(Elementos+i);
    }
}

void Arreglo::imprimir() {
    for(int i = 0; i < longitud; i++) {
        printf("%d, ", Elementos[i]);
    }
}

void Arreglo::agregar(int valor) {
    if(longitud < nElem)
        Elementos[longitud++] = valor; 
}

void Arreglo::insertar(int indice, int valor) {
    if(indice >= 0 && indice <= nElem) {
        for(int i = longitud; i > indice; i--) {
            Elementos[i] = Elementos[i-1];
        }
        Elementos[indice] = valor;
        longitud++;
    }
}

void Arreglo::eliminar(int indice) {
    if(indice >= 0 && indice <= longitud) {
        for(int i = indice; i < longitud; i++) {
            Elementos[i] = Elementos[i+1];
        }
    }
    longitud--;
}

void Arreglo::burbuja() {
    for(int i = 0; i < longitud; i++) {
        for(int j = 0; j < longitud - 1; j++) {
            if(Elementos[j] > Elementos[j+1]) {
                int auxiliar = Elementos[j];
                Elementos[j] = Elementos[j+1];
                Elementos[j+1] = auxiliar;
            }
        }
    }  
}

int Arreglo::bLineal(int valor) {
    for(int i = 0; i < longitud; i++) {
        if(valor == Elementos[i])
            return i;
    }
    return -1;
}

int Arreglo::bBinaria(int valor) {
    int bajo = 0;
    int alto = longitud - 1;
    int medio = 0;

    while(bajo <= alto) {
        medio = (bajo + alto) / 2;
        if(valor == Elementos[medio]) {
            return medio;
        }
        else if(valor < Elementos[medio]) {
            alto = medio - 1;
        }
        else {
            bajo = medio + 1;
        }
    }
    return -1;
}

int main() {
    Arreglo arr;
    int longitud = 0;

    cout << "Longitud del arreglo: ";
    cin  >> longitud;

    arr.obtenerElementos(longitud);
    arr.agregar(12);
    arr.imprimir();
    arr.burbuja();
    cout << endl;
    arr.imprimir();

    return 0;
}