#include <stdio.h>

// Function which takes ints for TD, FG, Safety, TD_CON, and TD_FG and prints them in a well formatted way
void print_scores(int TD, int FG, int Safety, int TD_CON, int TD_FG) {
    printf("TD: %d, FG: %d, Safety: %d, TD w/ 2pt Conversion: %d, TD w/ FG: %d\n",TD,FG,Safety,TD_CON,TD_FG);
}
// Function which will take a int for the score of a game and use the print_scores function to print all possible score combinations
void find_combinations(int score) {
    // Create variables to hold the various ways to score
    int TD,FG,Safety,TD_CON,TD_FG;
    // Five nested for loops which will iterate through all potential point combinations for a given score
    for (TD = 0; TD * 6 <= score; TD++) {
        for (FG = 0; FG * 3 <= score; FG++){
            for (Safety = 0; Safety * 2 <= score; Safety++){
                for (TD_CON = 0; TD_CON * 8 <= score; TD_CON++){
                    for (TD_FG = 0; TD_FG * 7 <= score; TD_FG++){
                        // If the current iteration for TD, FG, Safety, TD_CON, and TD_FG are equal to the given score print the current iterations
                        if (TD*6 + FG*3 + Safety*2 + TD_CON*8 + TD_FG*7 == score){
                            print_scores(TD,FG,Safety,TD_CON,TD_FG);
                        }
                    }
                }
            }
        }
    }
}

// Main function
int main(){
    // Create variable for the score
    int score;
    // Do while loop which asks the user for the NFL score until they enter 0 or 1
    do {
        printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
        scanf("%d", &score);
        // If the entered score is greater than 1 call find_combinations function passing given score as parameter
        if (score > 1) {
            printf("Possible combinations of scoring plays:\n");
            find_combinations(score);
        }
    } while (score > 1);
    return 0;
}