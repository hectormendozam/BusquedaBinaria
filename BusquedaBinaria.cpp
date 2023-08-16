#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

int countNumbersFromFile(char* filename) {
    ifstream fin;
    fin.open(filename);
    int dato, i = 0;

    do {
        fin >> dato;    /// Se saca dato del buffer (necesario para vaciar el buffer)
        i++;            /// Se contabiliza el dato obtenido
    } while (!fin.eof()); /// Se verifica si es fin de archivo (end of file)

    fin.close();

    return i;
}
void numbersFromFile(int A[], int N, char* filename) {
    ifstream fin;
    fin.open(filename);
    for (int i = 0; i < N; i++) {
        fin >> A[i];
    }
    fin.close();
}

int BusquedaBinaria(int arr[], int n, int x) {
    int left = 0;
    int right = n - 1;
    int pos = n;
    bool found = false;
    while (left <= right && !found) {
        int medio = (left + right) / 2;
        if (arr[medio] == x) {
            found = true;
            pos = medio;
        }
        else if (arr[medio] < x) {
            left = medio + 1;
        }
        else {
            right = medio - 1;
        }
    }
    return pos;
}

void mostrarArreglo(const int arreglo[], int tamano)
{
    for (int i = 0; i < tamano; i++) {
        cout << arreglo[i] << endl;
    }
}
int main()
{
    /*const int tamano = 7;
    int arreglo[] = { 6, 9, 12, 67, 3, 0, 2 };
    int prueba = busquedaLineal(arreglo, 7, 67);
    cout << "Elementos del arreglo: " << endl;
    mostrarArreglo(arreglo, tamano);

    cout << " El numero buscado se encuentra en la posicion " << prueba << " del arreglo " << endl;*/

    unsigned t0, t1;
    t0 = clock();

    char archivo[] = "numerosC2.txt";
    int  N = countNumbersFromFile(archivo);
    cout << "\Datos: " << N << "\n";
    int Arr[50001];
    numbersFromFile(Arr, N, archivo);
    cout << "BusquedaBinaria NumerosC2: posicion del numero 7: " << BusquedaBinaria(Arr, N, 7) << endl;

    t1 = clock();
    double time = (double(t1 - t0) / CLOCKS_PER_SEC);
    cout << "\nExecution Time: " << time << " (" << t1 << "-" << t0 << ")" << endl;

    return 0;
}
