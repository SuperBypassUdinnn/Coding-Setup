#include "input.h"

/* Fungsi untuk input char tanpa buffer 
   Berguna untuk buat opsi pilihan kepada user*/
char bufferlessChar()
{
    char input;
    #ifdef _WIN32
        input = _getch(); // input char tanpa buffer dan echo
    #elif __linux__ || __unix__ || __APPLE__
        struct termios oldt, newt;
        tcgetattr(STDIN_FILENO, &oldt);           // Simpan pengaturan terminal saat ini
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);         // Nonaktifkan mode kanonik dan echo
        tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Terapkan pengaturan baru

        input = getchar();                        // Ambil karakter dari input
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Kembalikan pengaturan terminal lama
    #endif
    
    return input;
}

char *inputString(const char prompt[], unsigned int lengthLimit, bool oneWord)
{
    // Mengalokasikan memori untuk mengembalikan inputan
    char *input = malloc(lengthLimit + 1);
    if (input == NULL) {
        perror("Gagal mengalokasikan memori\n");
        return NULL;
    }

    // Input dari user
    printf("%s: ", prompt); 
    fgets(input, lengthLimit + 2, stdin);
    
    // Menghilangkan newline akhir dari inputan fgets()
    input[strcspn(input, "\n")] = '\0';

    // Memastikan input tidak kosong
    if (strlen(input) == 0) 
    {
        printf("%s tidak boleh kosong\n", prompt);
        free(input);
        return NULL;
    }

    // Input hanya satu kata
    if (oneWord == true)
    {
        if (strchr(input, ' ') != NULL)
        {
            printf("%s harus dalam satu kata\n", prompt);
            free(input);
            return NULL;
        }
    }

    // Memastikan input tidak melebihi batas panjang
    if (strlen(input) > lengthLimit) 
    {
        printf(  "%s tidak boleh lebih dari %d karakter\n", prompt, lengthLimit);
        free(input);
        return NULL;
    }

    return input;
}