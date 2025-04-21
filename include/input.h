#pragma once

#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Platform Windows
#ifdef _WIN32
    #include <conio.h>
// Platform UNIX, Linux, dan Mac
#elif __linux__ || __unix__ || __APPLE__
    #include <termios.h>
    #include <unistd.h>
#else
    #error "Sistem operasi tidak didukung"
#endif


/* Fungsi untuk input char tanpa buffer 
   Berguna untuk buat opsi pilihan kepada user*/
char bufferlessChar();

/* Fungsi untuk menginput string
   Contoh penggunaan: ptrInputString("Nama", 50);
   Contoh di atas akan meminta user untuk menginput nama dengan panjang maksimal 50 */
char *inputString(const char prompt[], unsigned int lengthLimit, bool oneWord);

#endif