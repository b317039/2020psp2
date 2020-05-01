#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


double p_stdnorm(double z)
{
    return 1/sqrt(2*M_PI) * exp(-z*z/2);
}

int main(void)
{
    double val;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    double he_a=170.8,var_a=5.43;
    double he_b=169.7,var_b=5.5;
    double ya,yb=0;
    double L_A=1,L_B=1;

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

        ya=(val-he_a)/var_a;
        yb=(val-he_b)/var_b;

        L_A=L_A*p_stdnorm(ya);
        L_B=L_B*p_stdnorm(yb);



    }


    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    

    printf("Likehood_A: %lf\n",L_A);
    printf("Likehood_B: %lf\n",L_B);

    return 0;


}


