#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

bool is_lo_shu_magic_square(int arr[][COLS])
{
    // Tính tổng các phần tử trên đường chéo chính
    int main_diag_sum = arr[0][0] + arr[1][1] + arr[2][2];
    // Tính tổng các phần tử trên đường chéo phụ
    int other_diag_sum = arr[0][2] + arr[1][1] + arr[2][0];
    // Nếu tổng các phần tử trên đường chéo chính và đường chéo phụ không bằng nhau, mảng không phải là Mã Lục Thư Ma Trận
    if (main_diag_sum != other_diag_sum) {
        return false;
    }
    // Tính tổng các phần tử trên mỗi hàng
    int row_sum = 0;
    for (int i = 0; i < ROWS; i++) {
        int curr_row_sum = 0;
        for (int j = 0; j < COLS; j++) {
            curr_row_sum += arr[i][j];
        }
        // Nếu tổng các phần tử trên một hàng khác với tổng các phần tử trên đường chéo chính và đường chéo phụ, mảng không phải là Mã Lục Thư Ma Trận
        if (curr_row_sum != main_diag_sum) {
            return false;
        }
    }
    // Tính tổng các phần tử trên mỗi cột
    int col_sum = 0;
    for (int j = 0; j < COLS; j++) {
        int curr_col_sum = 0;
        for (int i = 0; i < ROWS; i++) {
            curr_col_sum += arr[i][j];
        }
        // Nếu tổng các phần tử trên một cột khác với tổng các phần tử trên đường chéo chính và đường chéo phụ, mảng không phải là Mã Lục Thư Ma Trận
        if (curr_col_sum != main_diag_sum) {
            return false;
        }
    }
    // Nếu mảng thỏa mãn các điều kiện trên, mảng là Mã Lục Thư Ma Trận
    return true;
}

int main()
{
    // Khởi tạo mảng
    int arr[ROWS][COLS] = { {4, 9, 2}, {3, 5, 7}, {8, 1, 6} };
    // Kiểm tra xem mảng có phải là Mã Lục Thư Ma Trận hay không
    if (is_lo_shu_magic_square(arr)) {
        cout << "Day la Ma Luc Thu Ma Tran\n";
    } else {
        cout << "Day khong phai la Ma Luc Thu Ma Tran\n";
    }
    return 0;
}
