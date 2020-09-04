#include <stdlib.h>
#include <iostream>
using namespace std;


struct Arreglo {
    //int *Elem;
    int Elem[10];
    int nElem;
    int longitud;
};

void imprimir(struct Arreglo arr);
void agregar(int valor);

void imprimir(struct Arreglo arr) {
    for(int i = 0; i < arr.longitud; i++) {
        printf("%d, ", arr.Elem[i]);
    }
}

void agregar(struct Arreglo *arr, int valor) {
    if(arr->longitud < arr->nElem)
        arr->Elem[arr->longitud++] = valor;
}

void insertar(struct Arreglo *arr, int indice, int valor) {
    if(indice >= 0 && indice <= arr->nElem) {
        for(int i = arr->longitud; i > indice; i--) {
            arr->Elem[i] = arr->Elem[i-1];
        }
        arr->Elem[indice] = valor;
        arr->longitud++;
    }
}

void eliminar(struct Arreglo *arr, int indice) {
    if(indice >= 0 && indice <= arr->longitud) {
        for(int i = indice; i < arr->longitud; i++) {
            arr->Elem[i] = arr->Elem[i+1];
        }
    }
    arr->longitud--;
}

int bLineal(struct Arreglo *arr, int valor) {
    for(int i = 0; i < arr->longitud; i++) {
        if(valor == arr->Elem[i])
            return i;
    }
    return -1;
}

int bBinaria(struct Arreglo *arr, int valor) {
    int bajo = 0;
    int alto = arr->longitud - 1;
    int medio = 0;

    while(bajo <= alto) {
        medio = (bajo + alto) / 2;
        if(valor == arr->Elem[medio]) {
            return medio;
        }
        else if(valor < arr->Elem[medio]) {
            alto = medio - 1;
        }
        else {
            bajo = medio + 1;
        }
    }
    return -1;
}

int main() {
    struct Arreglo arr = {{2, 4, 6, 8, 10}, 10, 5};
    /*printf("Tamaño del arreglo: ");
    scanf("%d", &arr.nElem);
    arr.Elem = (int *)malloc(arr.nElem * sizeof(int));
 
    printf("Longitud del arreglo:\n");
    scanf("%d", &arr.longitud);

    for(int i = 0; i < arr.longitud; i++) {
        printf("Elemento [%d]: ", i);
        scanf("%d", &arr.Elem[i]);
    }*/

    agregar(&arr, 25);
    insertar(&arr, 2, 5);
    eliminar(&arr, 6);
    imprimir(arr);
    cout << "\nEl valor esta en el indice: " << bLineal(&arr, 8) << endl;
    cout << "\nEl valor esta en el indice: " << bBinaria(&arr, 15) << endl;
    
    return 0;
}