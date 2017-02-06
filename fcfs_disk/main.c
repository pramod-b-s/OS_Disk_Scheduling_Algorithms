#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{

    int ip[100],op[100],curr,prev,cyl;
    int i,j,n;
    printf("enter number of processes\t");
    scanf("%d",&n);
    printf("enter number of cylinders\t");
    scanf("%d",&cyl);
    printf("enter %d positions\n",n);
    for(i=0;i<n;i++){
        scanf("%d",&ip[i]);
    }
    printf("enter current head position\t");
    scanf("%d",&curr);
    //printf("enter previous head position\t");
    //scanf("%d",&prev);

    op[0]=abs(ip[0]-curr);
    for(j=1;j<n;j++){
        op[j]=op[j-1]+abs(ip[j]-ip[j-1]);
    }

    printf("i/p\to/p\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\n",ip[i],op[i]);
    }

}
