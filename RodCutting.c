//Rod Cutting Problem
/*
Example
 Input
 10
 1 5 8 9 10 17 17 20 24 30
 
 
 Output
 30
 1
 10=10
 
 i           0  1   2   3   4   5   6   7   8   9   10
 p[i]        0  1   5   8   9   10  17  17  20  24  30
 newPrice[i] 0  1   5   8   10  13  17  18  22  25  30
 cutpoint[i] 0  1   2   3   2   2   6   1   2   3   10
 
 */


#include <stdio.h>

int main() {
    
    int k,i,j,max,temp;
    int p[101],cutPoint[101],newPrice[101];
    
    scanf("%d",&k);
    for (i=1; i<=k; i++) scanf("%d",&p[i]);
    
    //remember the max cutting point & new price for each
    newPrice[0]=0;
    
    for (i=1; i<=k; i++) {
        
        max=0;
        //length=i 每一個切法都試試看(一次只切一刀)
        for (j=1; j<=i; j++) {
            
            temp=p[j]+newPrice[i-j];
            if (temp>max) {
                max=temp;
                cutPoint[i]=j;
            }
        }
        newPrice[i]=max;
    }
    printf("%d\n",newPrice[k]);
    
    //k=cutPoint[k]+cutPoint[k-cutPoint[k]]
    temp=k-cutPoint[k];
    for (i=0 ; temp>0; temp-=cutPoint[k]) i++;
    
    printf("%d\n",i);
    printf("%d=",k);
    
    for (i=0 ; k>0; k-=cutPoint[k]) {
        
        printf("%d",cutPoint[k]);
        if ((k-cutPoint[k])>0) printf("+");
    }
    return 0;
}