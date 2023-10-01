#include <stdio.h>
#include <stdlib.h>

int main() {
    int m,n,p,q;
    printf("Enter no. of row for first sparse matrix\n");
    scanf("%d",&m);
    printf("Enter no. of column for first sparse matrix\n");
    scanf("%d",&n);
    printf("Enter no. of row for second sparse matrix\n");
    scanf("%d",&p);
    printf("Enter no. of column for second sparse matrix\n");
    scanf("%d",&q);
    int a[m][n];
    int b[p][q];

    printf("enter the values in first sparse matrix\n");
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("enter the values in second sparse matrix\n");
    
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            scanf("%d",&b[i][j]);
        }
    }
     int size=0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]!=0){
                size++;
            }
        }
    }

    int triplet[size+1][3];  
    int count = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != 0) {
                triplet[count][0] = i;
                triplet[count][1] = j;
                triplet[count][2] = a[i][j];
                count++;
            }
        }
    }
    triplet[0][0]=m;
    triplet[0][1]=n;
    triplet[0][2]=count-1;

    printf("Triplet form of the sparse matrix:\n");
    for(int i=0;i<count;i++){
        for(int j=0;j<3;j++){
            printf("%d ",triplet[i][j]);
            }
        printf("\n");
    }

    
    int triplet2[size+1][3];  
    int count1 = 1;

    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            if (b[i][j] != 0) {
                triplet2[count1][0] = i;
                triplet2[count1][1] = j;
                triplet2[count1][2] = b[i][j];
                count1++;
            }
        }
    }
    triplet2[0][0]=p;
    triplet2[0][1]=q;
    triplet2[0][2]=count1-1;

    printf("Triplet form of the sparse matrix:\n");
    for(int i=0;i<count1;i++){
        for(int j=0;j<3;j++){
            printf("%d ",triplet2[i][j]);
            }
        printf("\n");
    }
    int triplet3[size+1][3];
    for(int i=0;i<count;i++){
        for(int j=0;j<3;j++){
                triplet3[i][j]=triplet[i][j]+triplet[i][j];
        }
    }
    printf("\n");

    for(int i=0;i<count1;i++){
        for(int j=0;j<3;j++){
            printf("%d ",triplet3[i][j]);
            }
        printf("\n");
    }


    return 0;
}