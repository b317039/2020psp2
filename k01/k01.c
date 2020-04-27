#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//extern double ave_online(double val,double ave,int N)
//extern double var_online()

double ave_online(double val,double ave,int N){
    ave = ((N-1)/N)*ave + (1/N)*val; 
    return ave;    
    }

int main(void)
{
    int N = 0;
    double val = 0;
    double ave = 0;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    
    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);
    printf("running");

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);
        printf("val=%lf\n",val);
        ave_online(val,ave,N);
        N++;
        printf("val=%lf\n",val);
    



    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    
    return 0;


}

