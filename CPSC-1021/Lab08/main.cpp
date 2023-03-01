#include <iostream>
#include <stdio.h>
#include <omp.h>


int main() {
    int h = 480;
    int w = 640;
    float R[h][w];
    float G[h][w];
    float B[h][w];
    int tid;
    int ncores;
    unsigned char r, g, b;
    
    FILE *out = fopen("color.ppm", "w");

    if (!out) {
        printf("Error in opening output image\n");
        return 1;
    }

    //---Absolutely no idea
     #pragma omp parallel private(tid)
     {
     if((tid=omp_get_thread_num())==0)
         ncores = omp_get_num_threads();
     }
     
    
    //---Outputs header for ppm image as well as print num cores
    fprintf(stderr,"num cores: %d\n",ncores);
    int chunk = h/ncores;
    fprintf(stderr,"h: %d\n",h);
    fprintf(stderr,"chunk (%d/%d): %d\n",h,ncores,chunk);
    
    fprintf(out, "P6\n%d %d\n255\n", w, h);
    
    //---Absolutely no idea
    #pragma omp parallel \
    shared(w,h,R,G,B) \
    private(tid)
    
    #pragma omp for schedule(static,chunk) nowait
    
    //Switches image color based on which thread is running
    for (int y = h - 1; y >= 0; y--) {
        for (int x = 0; x < w; x++) {
            tid = omp_get_thread_num() % 8;
            switch(tid){
                case 0:
                    R[y][x] = 1.0;
                    G[y][x] = 1.0;
                    B[y][x] = 1.0;
                    break;
                case 1:
                    R[y][x] = 0.0;
                    G[y][x] = 1.0;
                    B[y][x] = 1.0;
                    break;
                case 2:
                    R[y][x] = 1.0;
                    G[y][x] = 0.0;
                    B[y][x] = 1.0;
                    break;
                case 3:
                    R[y][x] = 1.0;
                    G[y][x] = 1.0;
                    B[y][x] = 0.0;
                    break;
                case 4:
                    R[y][x] = 0.0;
                    G[y][x] = 0.0;
                    B[y][x] = 1.0;
                    break;
                case 5:
                    R[y][x] = .5;
                    G[y][x] = 1.0;
                    B[y][x] = .5;
                    break;
                case 6:
                    R[y][x] = 1.0;
                    G[y][x] = 0.25;
                    B[y][x] = 0.25;
                    break;
                case 7:
                    R[y][x] = .5;
                    G[y][x] = .5;
                    B[y][x] = .5;
                    break;
            }
        }
    }

    //outputs stored pixels onto ppm image
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            r = (unsigned char) (R[i][j] * 255.0);
            g = (unsigned char) (G[i][j] * 255.0);
            b = (unsigned char) (B[i][j] * 255.0);
            fwrite(&r, sizeof(unsigned char), 1, out);
            fwrite(&g, sizeof(unsigned char), 1, out);
            fwrite(&b, sizeof(unsigned char), 1, out);
        }
    }
}
