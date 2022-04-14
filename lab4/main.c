#include <stdio.h>

int main() {
    int n[] = {6,4,7,2,0,9,8,1,5,3};
    int x = 6;
    int* p = n;
    for (int i = 0; i <= 10; i++) {
        if (*(p++) == x) {
            printf("No.1 ---------------\n");
            printf("&n[%d]->%p, n[%d]=%d; p->%p, *p=%d\n",i,&n[i],i,n[i],&n[i],n[i]);
            printf("No.2 ---------------\n");
        }
    }
    int *ap[10];
    for(int i = 0, j = 0; i < 10; i++) {
		ap[i] = &n[j++];
	}
    for(int i = 0; i < 10; i++) {
		for(int j = i + 1; j < 10; j++) {
			if(*ap[i] > *ap[j]) {
				int* temp = ap[i];
				ap[i] = ap[j];
				ap[j] = temp;
			}
		}
		printf("&n[%d]->%p, n[%d] = %d, ", i, ap[i], i, *(ap[i]));
		printf("ap[%d]->%p, *ap[%d] = %d\n", i, ap[i], i, *(ap[i]));
	}
    return 0;
}
