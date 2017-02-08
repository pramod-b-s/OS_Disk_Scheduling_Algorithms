#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct process{
    int no,pos,ans,fin;
}pr[100],curr;

int near(int n){
    int i,min=999,ind;
    for(i=0;i<n;i++){
        if(pr[i].fin==0){
            if(abs(pr[i].pos-curr.pos)<min){
                ind=i;
                min=abs(pr[i].pos-curr.pos);
            }
        }
        else{
            continue;
        }
    }
    return ind;
}

int notdone(int n){
    int i;
    for(i=0;i<n;i++){
        if(pr[i].fin==0){
            return 1;
        }
    }
    return 0;
}

int main()
{
    int n,i,j,cyl,prev,pres,ts=0,x,ind,min=999;
    printf("enter number of requests\t");
    scanf("%d",&n);
    printf("enter number of cylinders\t");
    scanf("%d",&cyl);

    printf("enter %d requests\n",n);
    for(i=0;i<n;i++){
        pr[i].no=i;
        scanf("%d",&pr[i].pos);
        pr[i].ans=0;
        pr[i].fin=0;
    }

    printf("enter current pos\t");
    scanf("%d",&pres);
    printf("enter previous pos\t");
    scanf("%d",&prev);

    for(i=0;i<n;i++){
        if(abs(pr[i].pos-pres)<min){
            min=abs(pr[i].pos-pres);
            ind=i;
        }
    }
    curr=pr[ind];
    ts+=min;
    pr[ind].ans=ts;
    pr[ind].fin=1;

    while(notdone(n)){
        x=near(n);
        ts+=abs(pr[x].pos-curr.pos);
        pr[x].fin=1;
        pr[x].ans=ts;
        curr=pr[x];
    }

    printf("pr.no\ti/p\to/p\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\n",pr[i].no,pr[i].pos,pr[i].ans);
    }
}
