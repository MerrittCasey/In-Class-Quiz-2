/*
* @Author Casey Merritt
* Lo Shu Magic Square Generator
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printLoShu(int x[3][3]);
int checkForValue(int val, int arr[9]);
int checkLoShu(int x[3][3]);

int main(){
    time_t t;
    srand((unsigned) time(&t));
    
    int failCheck[3][3] = {{1,3,1}, {2,5,1}, {1,1,1}};
    int successCheck[3][3] = {{4,9,2}, {3,5,7}, {8,1,6}};
    int loshu[3][3] = {0};
    int checker[9] = {0};
    int count = 0;

    if(checkLoShu(failCheck) == 1){
        printf("This Is A Lo Shu Magic Square\n");
        printLoShu(failCheck);
    }else{
        printf("This Is Not A Lo Shu Magic Square\n");
        printLoShu(failCheck);
    }

    printf("\n");
    
    if(checkLoShu(successCheck) == 1){
        printf("This Is A Lo Shu Magic Square\n");
            printLoShu(successCheck);
    }else{
        printf("This Is Not A Lo Shu Magic Square\n");
        printLoShu(successCheck);
    }

    printf("\n");
    printf("Generating Lo Shu Magic Square...\n");


    int mainCheck = 1;
    while(mainCheck == 1){
        for(int h = 0; h < 3; h++){
            for(int l = 0; l < 3; l++){
                
                int cont = 1;
                while(cont == 1){
                    int val = (rand() % 9 + 1);
                    if(checkForValue(val, checker) == 1){
                        for(int i = 0; i < 9; i++){
                            if(checker[i] == 0){
                                checker[i] = val;
                                loshu[h][l] = val;
                                cont = 0;
                                break;
                            }
                        }
                    }
                }
            }
        }

        for(int f = 0; f < 9; f++){
            checker[f] = 0;
        }
    
        if(checkLoShu(loshu) == 1){
            count++;
            printf("\n");
            printf("Success!\n");
            printf("We Generated %d Squares!\n", count);
            printLoShu(loshu);
            mainCheck = 0;
        }else{
            count++;
        }
    }

    printf("\n");
    char x[10];
    printf("Enter anything to close...");
    scanf("%s", &x);

    return 0;
}

int checkLoShu(int x[3][3]){
    int rowCheck = 0;
    int columnCheck = 0;
    int diagnolCheck1 = 0;
    int diagnolCheck2 = 0;
    
    int one = 0;
    int two = 0;
    int three = 0;
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i == 0){
                one += x[i][j];
            }else if(i == 1){
                two += x[i][j];
            }else{
                three += x[i][j];
            }
        }
    }
    
    if(one == two && two == three && three == one){
        rowCheck = 1;
    }else{
        return 0;
    
    }
    one = 0;
    two = 0;
    three = 0;
    
    for(int l = 0; l < 3; l++){
        for(int k = 0; k < 3; k++){
            if(k == 0){
                one += x[l][k];
            }else if(k == 1){
                two += x[l][k];
            }else{
                three += x[l][k];
            }
        }
    }
    
    if(one == two && two == three && three == one){
        columnCheck = 1;
    }else{
        return 0;
    }
    
    int diag1 = 0;
    diag1 += (x[0][0] + x[1][1] + x[2][2]);
    if(one == diag1){
        diagnolCheck1 = 1;
    }else{
        return 0;
    }
    
    int diag2 = 0;
    diag2 += (x[2][0] + x[1][1] + x[0][2]);
    if(one == diag2){
        diagnolCheck1 = 1;
    }else{
        return 0;
    }
    
    return 1;
}

void printLoShu(int x[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ",x[i][j]);
        }
        printf("\n");
    }

}

int checkForValue(int val, int arr[9]){
    for(int i = 0; i < 9; i++){
        if(arr[i] == val){
            return 0;
            break;
        }
    }

    return 1;
}