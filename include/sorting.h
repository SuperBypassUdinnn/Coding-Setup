#pragma once

#ifndef SORTING_H
#define SORTING_H

#include <string.h>

// Fungsi Menampilkan jumlah swap sorting
long unsigned int swapCount();

// Fungsi Menampilkan jumlah perbandingan sorting
long unsigned int comparisonCount();

// Fungsi untuk reset jumlah swap;
void resetSwapCount();

// Fungsi untuk reset jumlah perbandingan;
void resetComparisonCount();

/// Algoritma Sorting untuk array int

// Bubble Sort
void bubbleSort(int arr[], int length);

// Selection Sort
void selectionSort(int arr[], int length);

// Insertion Sort
void insertionSort(int arr[], int length);

// Merge Sort
void merge(int arr[], int min_index, int mid_index, int max_index);
void mergeSort(int arr[], int min_index, int max_index);

// Quick Sort
int partition(int arr[], int min_index, int max_index);
void quickSort(int arr[], int min_index, int max_index);

/// Algoritma Sorting untuk array string

// Bubble Sort
void bubbleSortStr(char *arr[], int length);

// Selection Sort
void selectionSortStr(char *arr[], int length);

// Insertion Sort
void insertionSortStr(char *arr[], int length);

// Merge Sort
void mergeStr(char *arr[], int min_index, int mid_index, int max_index);
void mergeSortStr(char *arr[], int min_index, int max_index);

// Quick Sort
int partitionStr(char *arr[], int min_index, int max_index);
void quickSortStr(char *arr[], int min_index, int max_index);

#endif