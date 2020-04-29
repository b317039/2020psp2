#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



double ave_online(double val,double ave,double N){
    ave = ((N-1)/N)*ave + (1/N)*val; 
    return ave;    
    }
double var_online(double ave,double ave2){
    double var = 0;
    var = ave2 - pow(ave,2);
    return var;
}

int main(void)
{
    double N = 1;
    double val = 0;
    double val2= 0;
    double ave = 0;
    double ave2= 0;
    double var = 0;
    double var2= 0;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    
    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);
        ave = ave_online(val,ave,N);
        val2 = pow(val,2);
        ave2 = ave_online(val2,ave2,N);
        var =var_online(ave,ave2);
        N++;
    }
    
    var2=var*(N-1)/(N-2);

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }


    printf("標本平均=%lf\n",ave);
    printf("標本分散=%lf\n",var);
    printf("母集団分散=%lf\n",var2);
    printf("母集団の平均推定値=%lf\n",ave);

    return 0;


}

