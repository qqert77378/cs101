#include <stdio.h>
#include <stdlib.h>

int* get_int_array(int n) {
    return (int*)calloc(n,sizeof(int));
}

void set_value(int* p, int v) {
    *p = v;
}

void print_array(int* p, int n) {
    printf("[");
    for(int i=0; i<n; i++) {
        if(i == (n-1)) {
            printf("%d]\n", *p+i);
        } else {
            printf("%d, ", *p+i);
        }
    }
}

typedef struct array_list {
    int m;
    int* (*func_ptr1)(int);
    void (*func_ptr2)(int* , int);
    void (*func_ptr3)(int* , int);
    int* ip;
} array_list_t;

int main()
{
    int n = 10;
    
    int* ip = get_int_array(n);
    array_list_t a;
    a.m = 20;
    a.func_ptr1 = get_int_array;
    a.func_ptr2 = set_value;
    a.func_ptr3 = print_array;
    a.ip = a.func_ptr1(a.m);
    
    for (int i = 0; i <a.m; i++) {
        a.func_ptr2(a.ip+i, i+1);
    }
    
    for(int i=0; i<n; i++) {
        set_value(ip+i, i+1);
    }
    printf ("No.1-------------------------\n");
    print_array(ip, n);
    printf ("No.2-------------------------\n");
     a.func_ptr3(a.ip, a.m);
    return 0;
}
