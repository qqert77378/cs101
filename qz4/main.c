#include <stdio.h>
#include <stdlib.h>

void swap_int (int num1, int num2) {
    int tmp = 0;
    tmp = num2;
    num2 = num1;
    num1 = tmp;
    printf("after swap, n = %d, m = %d", num1 , num2);
}

int swap_array (int* num1, int* num2, int size) {
    printf("\nN0.2 ------------------\n");
    for(int i = 0; i < size; i++) {
        int tmp = 0;
        tmp = *num1;
        *num1 = *num2;
        *num2 = tmp;
        *num1++;
        *num2++;
    }
}

void printArray(int arraynum[10], int size) {
    for(int i = 0; i < size; i++)
        i != size-1 ? printf("%d, ", arraynum[i]) : printf("%d]\n", arraynum[size-1]);
}

char* swap_string (char* str) {
    int slen = 0;
    while(*(str+slen)) slen++;
    char* ch = (char*)calloc(slen, sizeof(char));
    for(int i = 0; i < slen; i++) {
        ch[i] = *str++;
    }
    return ch;
}

int main () {
    int n, m;
    n = 1;
    m = 2;
    printf("N0.1 ------------------\n");
    swap_int(n, m);
    int size = 10;
    int source[10] = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int dest[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    swap_array(source, dest, size);
    printf("after swap_array, source array = [");
    printArray(source, size);
    printf("after swap_array, dest array = [");
    printArray(dest, size);
    printf("N0.3 ------------------\n");
    char str[] = "IU!IU!IU!IU!";
    char* cp_str = swap_string(str);
    printf("copy string = %s\n", cp_str);
    free(cp_str);
    return 0;
}
