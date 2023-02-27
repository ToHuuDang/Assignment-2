#include <iostream>

using namespace std;

bool isLoShuMagicSquare(int arr[][3]) {
    const int targetSum = 15; // The sum of each row, column, and diagonal in a Lo Shu Magic Square
    int rowSums[3] = {0, 0, 0};
    int colSums[3] = {0, 0, 0};
    int diag1Sum = 0;
    int diag2Sum = 0;

    // Iterate over each element in the array
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int num = arr[i][j];

            // Check if the number is in the range 1-9
            if (num < 1 || num > 9) {
                return false;
            }

            // Update the row and column sums
            rowSums[i] += num;
            colSums[j] += num;

            // Update the diagonal sums
            if (i == j) {
                diag1Sum += num;
            }
            if (i + j == 2) {
                diag2Sum += num;
            }
        }
    }

    // Check if all the row, column, and diagonal sums are equal to the target sum
    int sums[8] = {rowSums[0], rowSums[1], rowSums[2], colSums[0], colSums[1], colSums[2], diag1Sum, diag2Sum};
    for (int i = 0; i < 8; i++) {
        if (sums[i] != targetSum) {
            return false;
        }
    }
    return true;
}
int main()
{
   int arr[3][3] = {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}};
cout << boolalpha << isLoShuMagicSquare(arr) << endl; // true

int arr2[3][3] = {{4, 9, 2}, {3, 5, 8}, {8, 1, 6}};
cout << boolalpha << isLoShuMagicSquare(arr2) << endl; // false

}
