/* Test execution times and performance of greedy and greedy with hill_climbing on this problem.
   We have a N x N matrix. We want to find the path starting top to bottom that adds up to the minimum
   sum. 
   
   Example:

    Matrix --> [1, 2, 3]
               [4, 5, 6]
               [7, 8, 9]

   One can choose to start from any of top row numbers {1, 2, 3} and every move the path is being 
   travelled going either to the number directly down the column, or down to the right or down to
   the left. In every move it is not possible to go horizzontaly or go to numbers that are more than
   one move away
   
   In this case the minimum sum is the one created by the path  {1, 4, 7} adding up to 12.

   The matrix will be randomly generated, with all numbers being positive (for now, make it optional
   later) and mapped to a MAX_VAL constant.    


   Arguments: ./greedy 0/1 N
   0 --> Greedy
   1 --> greedy with hill_climbing

   Returns:
   0 --> Program executed successfully
   1 --> Invalid argument
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 3
#define MAX_VAL 10

void fill_matrix(int matrix[][N]) {
    printf("\nGenerating Matrix\n");
    //Randomly fill the matrix
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            matrix[i][j] = rand() % MAX_VAL;
        }
    }
}

void print_matrix(int matrix[][N]) {
    for (int i = 0; i < N; i++) {
        printf("\n [ ");
        for(int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf(" ]");
    }
    printf("\n\n");
}

int main(int argc, char *argv[]) {

    srand(time(NULL));

    //Create the matrix
    int matrix[N][N];

    fill_matrix(matrix);
    print_matrix(matrix);
    
    // // Greedy
    // if ((argv[1] == '0') {
        

    // }

    // // Greedy with hill climbing
    // else if(rgv[1] == '1') {

    // }

    // //Invalid character
    // else {
    //     printf("\nInvalid Argument. Exiting.");
    //     return 1
    // }

    return 0;

}