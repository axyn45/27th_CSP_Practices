#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(){
    int count;
    scanf("%d",&count);

    double sum=0,ave=0,sqr_variance=0;

    double data[1200];
    // data=(int*)malloc(sizeof(int)*count);
    for(int i=0;i<count;i++){
        scanf("%lf",&data[i]);
        sum+=data[i];
    }

    ave=sum/count;
    for(int i=0;i<count;i++){
        sqr_variance+=pow(ave-data[i],2);
    }
    sqr_variance=sqrt(sqr_variance/count);

    for(int i=0;i<count;i++){
        data[i]=(data[i]-ave)/sqr_variance;
        printf("%lf\n",data[i]);
    }

    return 0;
}

