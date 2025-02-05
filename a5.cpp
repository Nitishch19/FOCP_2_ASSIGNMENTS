#include <iostream>
int main() {
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // original matrix
    std::cout << "Original Matrix:\n";
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            std::cout << arr[r][c] << " ";
        }
        std::cout << '\n';
    }

    // Perform rotation
    // 1. Transpose the matrix(row to column)
    for (int r = 0; r < 3; r++) {
        for (int c = r + 1; c < 3; c++) {
            int temp = arr[r][c];
            arr[r][c] = arr[c][r];
            arr[c][r] = temp;
        }
    }

    // 2. Reverse each row(Swap arr[r][c] with arr[r][2 - c])
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3 / 2; c++) {
            int temp = arr[r][c];
            arr[r][c] = arr[r][2 - c];
            arr[r][2 - c] = temp;
        }
    }

    // rotated matrix
    std::cout << "\nRotated Matrix (90 degrees clockwise):\n";
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            std::cout << arr[r][c] << " ";
        }
        std::cout << '\n';
    }

    return 0;
}
