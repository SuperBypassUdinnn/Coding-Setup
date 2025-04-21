#pragma once

#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fungsi untuk memberi elemen bilangan asli acak dari 1-maxValue pada array
void randomizeArray(int arr[], unsigned int maxValue, int length);

// Fungsi untuk menampilkan array int
void printArray(int arr[], int length);

// Fungsi untuk menampilkan array string
void printArrayStr(char *arr[], int length);

#endif