#include <stdio.h> 
#include <stdlib.h> 
// Structure for an item which stores weight and profit 
struct Item { 
int profit, weight; 
}; 
// Comparison function to sort Items according to profit/weight ratio 
typedef struct Item Item; 
int cmp(const void *a, const void *b) { 
double r1 = (double)((Item*)a)->profit / ((Item*)a)->weight; 
double r2 = (double)((Item*)b)->profit / ((Item*)b)->weight; 
return (r1 < r2) - (r1 > r2); // Descending order 
} 
// Main greedy function to solve problem 
double fractionalKnapsack(int W, struct Item arr[], int N) { 
// Sorting Items based on profit/weight ratio 
qsort(arr, N, sizeof(struct Item), cmp); 
double finalValue = 0.0; 
printf("Selected items (profit, weight):\n"); 
// Looping through all items 
for (int i = 0; i < N; i++) { 
// If adding Item won't overflow, add it completely 
if (arr[i].weight <= W) { 
W -= arr[i].weight; 
finalValue += arr[i].profit; 
printf("(%d, %d)\n", arr[i].profit, arr[i].weight); 
} 
// If we can't add current Item, add fractional part of it 
else { 
double fraction = (double)W / arr[i].weight; 
finalValue += arr[i].profit * fraction; 
printf("(%d, %d) -> Fraction taken: %.2f%%\n", arr[i].profit, arr[i].weight, 
fraction * 100); 
break; 
} 
} 
// Displaying maximum value 
printf("Maximum Profit: %.2f\n", finalValue); 
return finalValue; 
} 
int main() { 
int W, N; 
printf("Enter the number of items: "); 
scanf("%d", &N); 
struct Item *arr = (struct Item*)malloc(N * sizeof(struct Item)); 
printf("Enter the profit and weight of each item:\n"); 
for (int i = 0; i < N; i++) { 
printf("Item %d: ", i + 1); 
scanf("%d %d", &arr[i].profit, &arr[i].weight); 
} 
printf("Enter the capacity of the knapsack: "); 
scanf("%d", &W); 
// Function call 
fractionalKnapsack(W, arr, N); 
free(arr); 
return 0; 
}
