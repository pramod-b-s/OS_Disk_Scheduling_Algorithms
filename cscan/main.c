#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct process{
    int no,pos,ans;
}pr[100],t;

int main()
{
    int n,i,j,t,cyl,curr,ind;
    printf("enter number of requests\t");
    scanf("%d",&n);
    printf("enter number of cylinders\t");
    scanf("%d",&cyl);

    printf("enter %d requests\n",n);
    for(i=0;i<n;i++){
        pr[i].no=i;
        scanf("%d",&pr[i].pos);
        pr[i].ans=0;
    }

    printf("enter current pos\t");
    scanf("%d",&curr);
    printf("assuming forward movement\n");

    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(pr[j].pos>pr[j+1].pos){
                t=pr[j];
                pr[j]=pr[j+1];
                pr[j+1]=t;
            }
        }
    }

    for(i=0;i<n;i++){
        if(pr[i].pos>curr){
            ind=i;
            break;
        }
    }

    for(i=ind;i<n;i++){
        pr[i].ans=pr[i].pos-curr;
    }
    for(i=0;i<ind;i++){
        pr[i].ans=(cyl-curr)+(pr[i].pos);
    }

    printf("pr.no\ti/p\to/p\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\n",pr[i].no,pr[i].pos,pr[i].ans);
    }

}
