#include "array.h"

void randomizeArray(int arr[], unsigned int maxValue, int length) 
{
    // Memastikan srand dipanggil sekali
    static short int init = 0;
    if (!init) {
        srand(time(NULL)); // Inisialisasi seed acak
        init = 1; // Tandai bahwa srand sudah dipanggil
    }
    
    for (int i = 0; i < length; i++)
        arr[i] = rand() % maxValue + 1; // memasukkan elemen random
}

void printArray(int arr[], int length)
{
    printf("[");
    for (int i = 0; i < length - 1; i++)
        printf("%d, ", arr[i]);
    printf("%d]\n", arr[length - 1]);
}

void printArrayStr(char *arr[], int length)
{
    for (int i = 0; i < length; i++)
        printf("%s\n", arr[i]);
}
