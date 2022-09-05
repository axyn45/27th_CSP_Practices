#include<stdio.h>
#include<stdbool.h>
// #include<stdlib.h>
// const int Lmax=1000000010;
// const int Smax=55;

int main(){
    int n,L,S;
    scanf("%d%d%d",&n,&L,&S);
    bool A[1000000010][1000000010]={0};
    bool B[55][55];
    int trees[2005][2];

    int tx,ty;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&tx,&ty);
        trees[i-1][0]=tx,trees[i-1][1]=ty;
        A[tx][ty]=true;
    }

    int t;
    for(int i=S;i>=0;i--){
        for(int j=0;j<=S;j++){
            scanf("%d",&t);
            if(t==1){
                B[i][j]=true;
            }else{
                B[i][j]=false;
            }
        }
    }

    int count=0;
    for(int i=0;i<n;i++){
        bool break_flag=false;
        if(trees[i][0]>L-S+1||trees[i][1]>L-S+1){
            continue;
        }
        for(int p=0;p<S&&break_flag;p++){
            for(int q=0;q<S&&break_flag;q++){
                if(A[trees[i][0]+p][trees[i][1]+q]!=B[p][q]){
                    break_flag=true;
                }
            }
        }
        if(!break_flag) count++;
    }
    printf("%d",count);
}