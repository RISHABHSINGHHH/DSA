#include <stdio.h>
#include <stdlib.h>

int main(){

    int arr[10][3];

    for(int i = 0; i < 10; i++){
        printf("Enter %d th row ", i + 1);
        scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
    }

    printf("--------\nThe input array is: \n");

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    int arr_tr[3][10];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 10; j++){
            arr_tr[i][j] = arr[j][i];
        }
    }

    printf("The transpose of the matrix is: \n");

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 10; j++){
            printf("%d ", arr_tr[i][j]);
        }
        printf("\n");
    }

        for(int i = 1; i < 10; i++){
            for(int j = 1; j < 9; j++){
                if(arr_tr[1][j] > arr_tr[1][j + 1]){
                    int temp = arr_tr[1][j];
                    arr_tr[1][j] = arr_tr[1][j + 1];
                    arr_tr[1][j + 1] = temp;
                }
            }
        }

    printf("The 2nd row (excluding 1st element) sorted transpose of the matrix is: \n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 10; j++){
            printf("%d ", arr_tr[i][j]);
        }
        printf("\n");
    }
    printf("The original matrix with the 2nd column sorted(excluding 1st row) is: \n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 10; j++){
            arr[j][i] = arr_tr[i][j];
        }
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}