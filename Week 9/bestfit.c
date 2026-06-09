#include <stdio.h>

void assign(int a[],int n){
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
}

void best_fit(int prs[],int mem[],int alc[],int p,int m){
    for(int j=1;j<p+1;j++){
        alc[m]=999;
        int min=m;
        for(int i=1;i<m+1;i++){
            if(alc[i-1]==0 && mem[i-1]>=prs[j-1] && mem[i-1]<mem[min]){
                min=i-1;
            }
        }
        alc[min]=j;
    }
}

void main(){
    int p,m;
    printf("Enter number of processes:");
    scanf("%d",&p);
    printf("Enter number of memory blocks:");
    scanf("%d",&m);
    int proc[p],mem_bloc[m],alloc[m+1];
    printf("Enter process size in kb:");
    assign(proc,p);
    printf("Enter memory block sizes(in kb) in order:");
    assign(mem_bloc,m);
    for(int i=0;i<m+1;i++){
        alloc[i]=0;
    }
    best_fit(proc,mem_bloc,alloc,p,m);
    printf("Allocation:");
    for(int i=0;i<m;i++){
        printf("%d ",alloc[i]);
    }
}
