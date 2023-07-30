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
#include <string.h>

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

// Returns the minimum number from an array of integers with n lenght of the array
int min(int *array, int n) {
    int min = 0;
    min = array[0];
    for(int i = 0; i < n; i++) {
        if(array[i] <= min) {
            min = array[i];
        }
    }
    return min;
} 

/* This function returns a dynamic allocated array with the following structure:
    int *array = {sum, elem1, elem2, ..., elemN}

    with:
    sum = minimal sum of the matrix
    elem1, elem2, ..., elemN = Elements that have been crossed by the algorithm (in order from the top)
*/
int * greedy(int matrix[][N]) {
    int *array = malloc((N + 1) * sizeof(int));
    int sum = 0;
    int min_index = 0;

    //Choose the lowest number from the top row
    sum = min(matrix[0], N);
    array[1] = sum; //First number encountered

    /* 
    Now we can go in 3 possible directions
                       [ * n * ]
                       [ x x x ]
                       [ * * * ]
    
    with:
    * -> random numbers
    n -> already processed number
    x -> possible future positions

    Of course there can be exceptions like n being on the 1 column or last. So we have to check
    out of bounds conditions

    
    */

    int current_index = min_index;
    for (int i = 1; i < N; i++) {
        int min_value = matrix[i][current_index];
        int min_offset = 0;

        if (current_index > 0 && matrix[i][current_index - 1] < min_value) {
            min_value = matrix[i][current_index - 1];
            min_offset = -1;
        }
        if (current_index < N - 1 && matrix[i][current_index + 1] < min_value) {
            min_value = matrix[i][current_index + 1];
            min_offset = 1;
        }

        sum += min_value;
        array[i + 1] = min_value;
        current_index += min_offset;
    }

    // for(int i = 1; i < N; i++) {

        
    //     // General case (for now i will just choose the minimum number from the bottom line without
    //     // it being on the 3 possible positions under the starting number)
    //     int number = min(matrix[i], N);
    //     sum += number;
    //     array[i+1] = number;
    // }

    //Saving the final sum
    array[0] = sum;
    return array;
    
}

int main(int argc, char *argv[]) {

    srand(time(NULL));

    //Create the matrix
    int matrix[N][N];

    fill_matrix(matrix);
    print_matrix(matrix);
    
    // Greedy
    char algo = argv[1][0];
    if (algo == '0') {
        printf("\nStandard Greedy: \n\n");
        int *array = greedy(matrix);
        int final_sum = array[0];
        printf("Lowest sum: %d \n", final_sum);

        printf("Path: { ");
        for(int i = 0; i < N; i++) {
            printf("%d, ", array[i+1]);
        }
        printf("}\n");

        return 0;

    }

    // Greedy with hill climbing
    else if(algo == '1') {
        printf("\nGreedy with hill climbing");
        return 0;
    }

    //Invalid character
    else {
        printf("\nInvalid Argument. Exiting.");
        return 1;
    }

    return 0;

}