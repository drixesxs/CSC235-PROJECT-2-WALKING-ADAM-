#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
    //define loop counters and an array to store each test case 
    int l, test_cases;
    char order_of_hands[100];
    int a;

    //define a file variable and assign it to funtion to open the input file
    FILE *input_file;
    input_file = fopen("adam.txt", "r");

    /*If file is not found or the file can't be read
     the funtion returns NULL, check if the file opening 
    function returns NULL, print the error to the user 
    and stop running the code*/ 
    if (input_file == NULL) 
    {
        printf("Error! File cannot be opened Check if file path is correct or if file exists.");
        exit(1);
    }

    
    //read the first line of the input file which is the number of test cases
    fscanf (input_file, "%i", &test_cases);
    
    //create an integer array (with the size of the number of test cases)
    //to store the number of 'U' characters for each test case
    int hands_up[test_cases];

    //define counter i and line_counter
    int i = 0;
    int line_counter = 0;


    //while loop to read the input file till the end of the file 
    while (fgets(order_of_hands, 100, input_file)) 
    {
        //increament the value of line counter by 1
        line_counter++;

        //if statement to calculate number of 'U' characters only 
        //if the line number is greater than or equals to 2 because 
        //each test case starts from the second line of the input file.
        //The number of 'U' characters for each test case is then saved to
        //the integer array defined earlier.
        if (line_counter >= 2)
        {
            int standing_steps = 0;
            for (l = 0; l < strlen(order_of_hands)-1; l++ ) 
            {
                if (order_of_hands[l] == 'U')
                {
                    standing_steps++;
                }
                else 
                {
                    break;
                }
            }
            hands_up[i] = standing_steps;
            i++;
        }

    }

    //for loop to print the number of 'U' characters for each test case
    //line by line from the integer array
    for (a = 0; a < sizeof(hands_up)/sizeof(int); a++) 
    {
        printf("\n%i", hands_up[a]);
    }

    return 0;

}