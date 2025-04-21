#include "sorting.h"

static long unsigned int swap_count = 0; // variabel untuk menghitung jumlah swap
static long unsigned int comparison_count = 0; //variabel untuk menghitung jumlah perbandingan

long unsigned int swapCount()
{
    return swap_count;
}

long unsigned int comparisonCount()
{
    return comparison_count;
}

void resetSwapCount()
{
    swap_count = 0;
}

void resetComparisonCount()
{
    comparison_count = 0;
}

/// Sorting untuk array int

void swap(int arr[], int index1, int index2) 
{
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

void bubbleSort(int arr[], int length)
{
    int swapped; // variabel untuk memeriksa apakah ada swap atau tidak
    for (int i = 0; i < length - 1; i++)
    {
        swapped = 0; 
        for (int j = 0; j < length - i - 1; j++) 
        {
            // Membandingkan suatu elemen dengan elemen di kanannya
            if (arr[j] > arr[j + 1])
            {
                swap(arr, j, j + 1); // swap elemen yang lebih besar ke sebelah kanan
                swap_count++;
                swapped = 1; 
            }
            comparison_count++;
        }
        // Jika tidak ada proses swap, hentikan loop
        if (!swapped)
            break;
    }
}

void selectionSort(int arr[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int min_index = i; // misalkan elemen paling kiri sebagai nilai minimum
        // Mencari elemen yang lebih kecil dari min_index dan jadikan sebagai minimum
        for (int j = i + 1; j < length; j++) 
        {
            if (arr[j] < arr[min_index])
                min_index = j;
            comparison_count++;
        }
        // Periksa apakah elemen minimum terletak di sebelah kiri atau tidak
        if (min_index != i)
        {
            swap(arr, i, min_index); // swap elemen minimum ke paling kiri
            swap_count++;
        }
    }
}

void insertionSort(int arr[], int length)
{
    for (int i = 1; i < length; i++)
    {
        /* Jadikan elemen pertama sebagai array terurut, kemudian 
           sisipkan setiap elemen ke array tersebut */
        for (int j = i; j > 0; j--)
        {
            // Membandingkan elemen yang disisipkan ke elemen sebelah kirinya
            comparison_count++;
            if (arr[j] < arr[j - 1])
            {
                swap(arr, j, j - 1); // swap elemen yang lebih kecil ke kiri
                swap_count++;
            }
            else break; // jika tidak ada swap, hentikan loop dalam dan lanjutkan loop luar
        }
    }
}

// Fungsi untuk menggabungkan dan mengurutkan dua subarray 
void merge(int arr[], int min_index, int mid_index, int max_index) {
    int i, j, k;
    int n1 = mid_index - min_index + 1;
    int n2 = max_index - mid_index;

    // Array sementara
    int leftArr[n1], rightArr[n2];

    // Masukkan data subarray ke array sementara
    for (i = 0; i < n1; i++)
        leftArr[i] = arr[min_index + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid_index + 1 + j];

    // Gabungkan kembali subarray dan urutkan
    i = 0;
    j = 0;
    k = min_index;
    while (i < n1 && j < n2) {
        comparison_count++;
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    // Masukkan elemen yang tersisa di subarray(jika ada)
    while (i < n1)
        arr[k++] = leftArr[i++];
    while (j < n2)
        arr[k++] = rightArr[j++];
}

// Membagi array dengan dua subarray, urutkan kemudian gabungkan
void mergeSort(int arr[], int min_index, int max_index) 
{
    if (min_index < max_index) 
    {
        // Cari index tengah
        int mid_index = min_index + (max_index - min_index) / 2;

        // Sort first and second halves
        mergeSort(arr, min_index, mid_index);
        mergeSort(arr, mid_index + 1, max_index);

        // Merge the sorted halves
        merge(arr, min_index, mid_index, max_index);
    }
}

int partition(int arr[], int min_index, int max_index)
{
    // inisialisasi pivot sebagai elemen pertama
    int pivot = arr[min_index];
    int i = min_index;
    int j = max_index;

    while (i < j) {

        // Mencari elemen yang lebih besar dari pivot (dari awal)
        while (arr[i] <= pivot && i <= max_index - 1)
        {
            i++;
            comparison_count++;
        }
        
        // Mencari elemen yang lebih kecil dari pivot (dari akhir)
        while (arr[j] > pivot && j >= min_index + 1) 
        {
            j--;
            comparison_count++;
        }

        if (i < j) 
        {
            swap(arr, i, j);
            swap_count++;
        }
    }
    swap(arr, min_index, j);
    swap_count++;
    return j;
}

void quickSort(int arr[], int min_index, int max_index) 
{
    if (min_index < max_index) 
    {
        // Memanggil fungsi partition mencari index partisi
        int pi = partition(arr, min_index, max_index);

        // Memanggil fungsi quickSort secara rekursif
        quickSort(arr, min_index, pi - 1);
        quickSort(arr, pi + 1, max_index);
    }
}

/// Sorting untuk array string

void swapStr(char *arr[], int index1, int index2) 
{
    char *temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

void bubbleSortStr(char *arr[], int length)
{
    int swapped; // variabel untuk memeriksa apakah ada swap atau tidak
    for (int i = 0; i < length - 1; i++)
    {
        swapped = 0; 
        for (int j = 0; j < length - i - 1; j++) 
        {
            // Membandingkan suatu string dengan string di kanannya
            if (strcmp(arr[j], arr[j + 1]) > 0)
            {
                swapStr(arr, j, j + 1); // swap string yang lebih besar ke sebelah kanan
                swap_count++;
                swapped = 1; 
            }
            comparison_count++;
        }
        // Jika tidak ada proses swap, hentikan loop
        if (!swapped)
            break;
    }
}

void selectionSortStr(char *arr[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int min_index = i; // misalkan string paling kiri sebagai nilai minimum
        // Mencari string yang lebih kecil dari min_index dan jadikan sebagai minimum
        for (int j = i + 1; j < length; j++) 
        {
            if (strcmp(arr[j], arr[min_index]) < 0)
                min_index = j;
            comparison_count++;
        }
        // Periksa apakah string minimum terletak di sebelah kiri atau tidak
        if (min_index != i)
        {
            swapStr(arr, i, min_index); // swap string minimum ke paling kiri
            swap_count++;
        }
    }
}

void insertionSortStr(char *arr[], int length)
{
    for (int i = 1; i < length; i++)
    {
        /* Jadikan string pertama sebagai array terurut, kemudian 
           sisipkan setiap string ke array tersebut */
        for (int j = i; j > 0; j--)
        {
            // Membandingkan string yang disisipkan ke string sebelah kirinya
            comparison_count++;
            if (strcmp(arr[j], arr[j - 1]) < 0)
            {
                swapStr(arr, j, j - 1); // swap string yang lebih kecil ke kiri
                swap_count++;
            }
            else break; // jika tidak ada swap, hentikan loop dalam dan lanjutkan loop luar
        }
    }
}

// Fungsi untuk menggabungkan dan mengurutkan dua subarray 
void mergeStr(char *arr[], int min_index, int mid_index, int max_index) {
    int i, j, k;
    int n1 = mid_index - min_index + 1;
    int n2 = max_index - mid_index;

    // Array sementara
    char *leftArr[n1], *rightArr[n2];

    // Masukkan data subarray ke array sementara
    for (i = 0; i < n1; i++)
        leftArr[i] = arr[min_index + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid_index + 1 + j];

    // Gabungkan kembali subarray dan urutkan
    i = 0;
    j = 0;
    k = min_index;
    while (i < n1 && j < n2) {
        comparison_count++;
        if (strcmp(leftArr[i], rightArr[j]) <= 0) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    // Masukkan elemen yang tersisa di subarray(jika ada)
    while (i < n1)
        arr[k++] = leftArr[i++];
    while (j < n2)
        arr[k++] = rightArr[j++];
}

// Membagi array dengan dua subarray, urutkan kemudian gabungkan
void mergeSortStr(char *arr[], int min_index, int max_index) 
{
    if (min_index < max_index) 
    {
        // Cari index tengah
        int mid_index = min_index + (max_index - min_index) / 2;

        // Sort first and second halves
        mergeSortStr(arr, min_index, mid_index);
        mergeSortStr(arr, mid_index + 1, max_index);

        // Merge the sorted halves
        mergeStr(arr, min_index, mid_index, max_index);
    }
}

int partitionStr(char *arr[], int min_index, int max_index)
{
    // inisialisasi pivot sebagai elemen pertama
    char *pivot = arr[min_index];
    int i = min_index;
    int j = max_index;

    while (i < j) {

        // Mencari elemen yang lebih besar dari pivot (dari awal)
        while (strcmp(arr[i], pivot) <= 0 && i <= max_index - 1)
        {
            i++;
            comparison_count++;
        }
        
        // Mencari elemen yang lebih kecil dari pivot (dari akhir)
        while (strcmp(arr[j], pivot) > 0 && j >= min_index + 1) 
        {
            j--;
            comparison_count++;
        }

        if (i < j) 
        {
            swapStr(arr, i, j);
            swap_count++;
        }
    }
    swapStr(arr, min_index, j);
    swap_count++;
    return j;
}

void quickSortStr(char *arr[], int min_index, int max_index) 
{
    if (min_index < max_index) 
    {
        // Memanggil fungsi partition mencari index partisi
        int pi = partitionStr(arr, min_index, max_index);

        // Memanggil fungsi quickSortStr secara rekursif
        quickSortStr(arr, min_index, pi - 1);
        quickSortStr(arr, pi + 1, max_index);
    }
}