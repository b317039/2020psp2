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

int main(void){
    char fname[FILENAME_MAX];
    char buf[256];
    char buf2[256];
    FILE* fp;
    FILE* fp2;
    double heights;
    double ave = 0;
    double ave2= 0;
    double i=1,j=1;
    double var=0,var2=0;
    double tmp,tmp2;
    double t_test;
    double s;

printf("input the filename of male data\n");
fgets(fname,sizeof(fname),stdin);
fname[strlen(fname)-1] = '\0';
printf("the filename of male data : %s\n",fname);
fp = fopen(fname,"r");
if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
}
while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&heights);
        ave = ave_online(heights,ave,i);
        tmp=ave_online(pow(heights,2),tmp,i);
        var =var_online(ave,tmp);
        i++;
}

if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
}

printf("input the filename of female data\n");
fgets(fname,sizeof(fname),stdin);
fname[strlen(fname)-1] = '\0';
printf("the filename of female data : %s\n",fname);
fp2 = fopen(fname,"r");
if(fp2==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
}
while(fgets(buf2,sizeof(buf2),fp2) != NULL){
        sscanf(buf2,"%lf",&heights);
        ave2 = ave_online(heights,ave2,j);
        tmp2 = ave_online(pow(heights,2),tmp2,j);
        var2 = var_online(ave2,tmp2);
        j++;
}

if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
}
var = var*(i-1)/(i-2);
var2 = var2*(i-1)/(i-2);
s= ((i-2)*var+(j-2)*var2)/(i+j-4);
t_test = (ave-ave2)/pow(s*((1/(i-1))+(1/(j-1))),0.5);

if(t_test > 2.681){
printf("工学部20代の男性の身長は女性の身長より大きいと言える\n");    
}
else{
printf("工学部20代の男性の身長は女性の身長より大きいと言えない\n"); 
}
//printf("t_test=%lf\n",t_test);
    return 0;
}