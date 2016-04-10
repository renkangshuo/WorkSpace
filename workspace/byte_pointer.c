#include<stdio.h>

typedef unsigned char * byte_pointer;

int main() {
    short sx = -12345; /* -12345 */
   // unsigned short usx = sx; /*53191*/
    //int  x = sx; /* -12345 */
    //unsigned ux = usx;
    unsigned uy = sx;   /* Mystery */



    printf("uy = %u:\t", uy);
    show_bytes((byte_pointer) &uy, sizeof(unsigned));
   // printf("sx = %d:\t", sx);
    //show_bytes((byte_pointer) &sx, sizeof(short));
    //printf("usx = %u:\t", usx);
  //  show_bytes((byte_pointer) &usx, sizeof(unsigned short));
   // printf("X  = %d:\t", x);
   // show_bytes((byte_pointer) &x, sizeof(int));
   // printf("ux  = %u:\t", ux);
   // show_bytes((byte_pointer) &ux, sizeof(unsigned));
}
void show_bytes(byte_pointer start, int len) {
    int i;
    for (i = 0; i < len; i++)
        printf("%.2x", start[i]);
    printf("\n");
}

void show_int1(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float1(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer1(void *x) {
    show_bytes((byte_pointer) &x,sizeof(void *));
}
