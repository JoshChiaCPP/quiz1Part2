#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
int randNum() 
{ 
    time_t t;
    //init random num generator
    //seeded on time so that it changes and is actually random
    srand((unsigned) time(&t));
    return rand() % 9 + 1;
} 

bool loShuTest(int array[3][3]) {
    int total = array[0][0] + array[0][1] + array[0][2];
    printf("%d\n", total); //test line
    int a[7];
    bool condition = true;

    a[0] = array[1][0] + array[1][1] + array[1][2]; //row2
    a[1] = array[2][0] + array[2][1] + array[2][2]; //row3

    a[2] = array[0][0] + array[1][0] + array[2][0]; //col1
    a[3] = array[0][1] + array[1][1] + array[2][1]; //col2
    a[4] = array[0][2] + array[1][2] + array[2][2]; //col3

    a[5] = array[0][0] + array[1][1] + array[2][2]; //dia1
    a[6] = array[0][2] + array[1][1] + array[2][0]; //dia2

    for(int i = 0; i < 7; i++){
        if(a[i] != total)
            condition = false;
            printf("%d\n", a[i]); //test line
    }

    if(condition==true)
        printf("This is a Lo Shu Magic Square");
    else
        printf("this is not a Lo Shu Magic Square");

    return condition;
}
void populate(int array[3][3]){

    for(int row = 0; row < 3; row++)
        for(int col = 0; col < 3; col++){
                int num = randNum();
                bool canUse = true;
                for(int r = 0; r < row; r++)
                    for(int c = 0; c < col; c++){
                        if(num == array[r][c]){
                            canUse = false;
                        }
                    }
                if(canUse == true){
                    array[row][col] = num;
                }
            }
}

void main(void){
    //test array
    int twoDimArray[3][3] = {4,9,2,3,5,7,8,1,0};
    int count = 0;
    // [00][01][02]
    // [10][11][12]
    // [20][21][22]

    loShuTest(twoDimArray); //test line

    //populate with random numbers
    while(loShuTest(twoDimArray) == false){
        populate(twoDimArray);
        count++;
    }

    printf("Total sqaures generated until success: %d\n", count);

}