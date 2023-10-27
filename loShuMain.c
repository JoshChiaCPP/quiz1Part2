#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int grid[3][3] = {
    {0,0,0},
    {0,0,0},
    {0,0,0}
};
int numbers[9] = {1,2,3,4,5,6,7,8,9};

int loShuTest(int array[3][3]) {
    int total = array[0][0] + array[0][1] + array[0][2];
    //printf("%d\n", total); //test line
    int a[7];
    int condition = 1;

    a[0] = array[1][0] + array[1][1] + array[1][2]; //row2
    a[1] = array[2][0] + array[2][1] + array[2][2]; //row3

    a[2] = array[0][0] + array[1][0] + array[2][0]; //col1
    a[3] = array[0][1] + array[1][1] + array[2][1]; //col2
    a[4] = array[0][2] + array[1][2] + array[2][2]; //col3

    a[5] = array[0][0] + array[1][1] + array[2][2]; //dia1
    a[6] = array[0][2] + array[1][1] + array[2][0]; //dia2

    for(int i = 0; i < 7; i++){
        if(a[i] != total)
            condition = 0;
            //printf("%d\n", a[i]); //test line
    }

    //if(condition==true)
    //    printf("This is a Lo Shu Magic Square");
    //else
    //    printf("this is not a Lo Shu Magic Square");

    return condition;
}

void shuffle() {

    for(int i = 8; i > 0; i--) {
      int r = (rand() % (i + 1));
      //swap
      int temp = numbers[i];
      numbers[i] = numbers[r];
      numbers[r] = temp;
    }
}

void populate(){
    shuffle();
    int n = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++) {
            grid[i][j] = numbers[n];
            n++;
        }
    }
}

void printSquare(int array[3][3]){
    printf("[%d][%d][%d]\n", array[0][0], array[0][1], array[0][2]);
    printf("[%d][%d][%d]\n", array[1][0], array[1][1], array[1][2]);
    printf("[%d][%d][%d]\n\n", array[2][0], array[2][1], array[2][2]);
}

void main(void){
    srand(time(0));
    //test array
    int twoDimArray[3][3] = {4,6,2,3,7,5,8,1,9};
    //int twoDimArray[3][3] = {4,9,2,3,5,7,8,1,6};
    int count = 0;
    int found = 0;
    // [00][01][02]
    // [10][11][12]
    // [20][21][22]

    //loShuTest(twoDimArray); //test line

    //populate with random numbers
    while(!found) {
        populate();
        count++;
        if(count > INT_MAX - 1000)  {
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    grid[i][j] = twoDimArray[i][j];
        }
        //if(count > 10) found = 1;
        //printArr(grid);
        if(loShuTest(grid) == 1) found = 1;
    }

    printf("Total sqaures generated until success: %d\n", count);
    printf("The magic square is: \n");
    printSquare(twoDimArray);

}