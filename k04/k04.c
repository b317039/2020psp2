#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct list{
    int gender;
    double heights;
    }list;

int main(void)
{
    char fname[FILENAME_MAX];
    char buf[256];
    char buf2[256];
    FILE* fp;
    FILE* fp2;
    int ID,ID2;
    int flag=0;
    int n=1;
    int i=0;
    list Data[256];


    printf("input the filename of sample height\n");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample height: %s\n",fname);
    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }
    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%d,%lf",&Data[i].gender,&Data[i].heights);
        i++;
    }
    
    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("input the filename of sample ID\n");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample ID: %s\n",fname);
    fp2 = fopen(fname,"r");
    if(fp2==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }
    printf("Which data do you want?\n");
    scanf("%d",&ID);
    while(fgets(buf2,sizeof(buf2),fp2) != NULL){
        sscanf(buf2,"%d",&ID2);
        if(ID==ID2){
        flag=1;
        break;
        }
        else{
            n++;
        }
    }
if(flag==0){
printf("================================\n");
printf("No data\n");
}
else{
    if(Data[n].gender==1){
    printf("================================\n");
    printf("ID : %d\n",ID);
    printf("gender : male\n");
    printf("height : %lf\n",Data[n].heights);
    }
    else
    {
    printf("================================\n");
    printf("ID : %d\n",ID);
    printf("gender : female\n");
    printf("height : %lf\n",Data[n].heights);
    }
    
}
    if(fclose(fp2) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

       printf("============================\n");

    return 0;

}
