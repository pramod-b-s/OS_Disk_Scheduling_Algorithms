#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct process{
    int no,pos,ans;
}pr[100],t;

int main()
{
    int n,i,j,cyl,curr,ind,prev,lf,rf,fwd=0,bwd=0;
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
    printf("enter previous pos\t");
    scanf("%d",&prev);

    if(curr>prev){
        fwd=1;
        printf("forward movement\n");
    }
    else{
        bwd=1;
        printf("backward movement\n");
    }

    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(pr[j].pos>pr[j+1].pos){
                t=pr[j];
                pr[j]=pr[j+1];
                pr[j+1]=t;
            }
        }
    }

    if(fwd){
        for(i=0;i<n;i++){
            if(pr[i].pos>curr){
                ind=i;
                break;
            }
        }
        for(i=ind;i<n;i++){
            pr[i].ans=pr[i].pos-curr;
        }
        for(i=ind-1;i>=0;i--){
            pr[i].ans=(pr[n-1].pos-curr)+(pr[n-1].pos-pr[i].pos);
        }
    }

    if(bwd){
        for(i=n-1;i>=0;i--){
            if(pr[i].pos<curr){
                ind=i;
                break;
            }
        }
        for(i=ind;i>=0;i--){
            pr[i].ans=curr-pr[i].pos;
        }
        for(i=ind+1;i<n;i++){
            pr[i].ans=(curr-pr[0].pos)+(pr[i].pos-pr[0].pos);
        }
    }

    printf("pr.no\ti/p\to/p\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\n",pr[i].no,pr[i].pos,pr[i].ans);
    }

}

