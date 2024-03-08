#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MONTHS 12

// Function to sort the sales array from highest to lowest while also sorting the array containing the names of the months in correlation with the sales numbers
// This function takes the array of sales numbers in arr1, the length of the arrays n, and the array of month names as parameters
void sort_descending(float arr1[], int n, char arr2[][20], int m) {
    // For loop which iterates through every element is the sales array except the last one
    for (int i = 0; i < n - 1; i++) {
        // For loop which iterates through every element after the current iteration of i
        for (int j = i + 1; j < n; j++) {
            // If the current iteration of i is less than the current iteration of j it should appear after it in the new array
            if (arr1[i] < arr1[j]) {
                // Temporary variable to hold current iteration of i
                float temp1 = arr1[i];
                char temp2[20];
                // Use strcopy to swap the names of the strings in the month names array
                strcpy(temp2, arr2[i]);
                // Swap values
                arr1[i] = arr1[j];
                strcpy(arr2[i], arr2[j]);
                arr1[j] = temp1;
                strcpy(arr2[j], temp2);
            }
        }
    }
}

// Main function
int main() {
    // Create all the variables needed to complete the calculations and pass to sort_descending
    float sales[MONTHS];
    float moving_averages[MONTHS];
    float sum = 0;
    float min, max, avg;
    char month_names[][20] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    // Open the sales data file in read mode an for every line store it in the sales array
    FILE *file = fopen("sales_data.txt", "r");
    for (int i = 0; i < MONTHS; i++) {
        fscanf(file, "%f", &sales[i]);
    }
    // Close the file
    fclose(file);

    // Set the min and max variable to the first element in the sales array
    min = max = sales[0];
    // Create variables to store the indexs of the max and min values in sales array to later find their corresponding months
    int min_index = 0;
    int max_index = 0;
    // For loop which iterates through the sales array
    for (int i = 0; i < MONTHS; i++) {
        // If the current element is less than min change min to the current index and set the min index to the current index
        if (sales[i] < min) {
            min = sales[i];
            min_index = i;
        }
        // If the current element is greater than max change max to the current index and set the max index to the current index
        if (sales[i] > max) {
            max = sales[i];
            max_index = i;
        }
        // Add the current iteration of the sales array to find the sum
        sum += sales[i];
        // Finds the average of the sales
        avg = sum / (i + 1);
    }

    // Find moving average by iterating through each month and then iterates back through the previous 6 months
    for (int i = 0; i < MONTHS; i++) {
        float sum = 0;
        int count = 0;
        for (int j = i; j >= 0 && j > i - 6; j--) {
            // find sum
            sum += sales[j];
            count++;
        }
        // Find the moving average
        moving_averages[i] = sum / count;
    }

    // Print the sales for each month formatted in a nice way
    printf("Monthly Sales Report:\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%-9s $%.2f\n", month_names[i], sales[i]);
    }

    // Print the min, max, and average sales in a nice way
    printf("\nSales Summary:");
    printf("\nMinimum Sales: $%.2f (%s)\n", min, month_names[min_index]);
    printf("Maximum Sales: $%.2f (%s)\n", max, month_names[max_index]);
    printf("Average Sales: $%.2f\n\n", avg);

    // Print the moving averages in a nice way
    printf("Six-Month Moving Average Report:\n");
    for (int i = 0; i < 7; i++) {
        printf("%-9s - %-9s $%.2f\n", month_names[i], month_names[i+5], moving_averages[i+5]);
    }

    // Call sort descending function to sort the sales array and month names array
    sort_descending(sales, MONTHS, month_names, 20);

    // Print the sales report from highest to lowest in a nice way
    printf("\nSales Report (Highest to Lowest):\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%-9s $%.2f\n", month_names[i], sales[i]);
    }
    return 0;
}
