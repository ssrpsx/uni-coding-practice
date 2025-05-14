#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

// ฟังก์ชันสำหรับ Gauss-Jordan Elimination
void gaussJordan(vector<vector<double>>& mat, int n) {
    for (int i = 0; i < n; i++) {
        // **ขั้นตอนที่ 1: Partial Pivoting**
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (abs(mat[k][i]) > abs(mat[maxRow][i])) {
                maxRow = k;
            }
        }
        swap(mat[i], mat[maxRow]); // สลับแถว

        // **ขั้นตอนที่ 2: ทำให้ตัวหลักเป็น 1**
        double pivot = mat[i][i];
        if (pivot == 0) {
            cout << "No unique solution exists." << endl;
            return;
        }
        for (int j = 0; j <= n; j++) {
            mat[i][j] /= pivot;
        }

        // **ขั้นตอนที่ 3: ทำให้ตัวเลขอื่นในคอลัมน์ i เป็น 0**
        for (int k = 0; k < n; k++) {
            if (k != i) {  // ข้ามแถวปัจจุบันไป
                double factor = mat[k][i];
                for (int j = 0; j <= n; j++) {
                    mat[k][j] -= factor * mat[i][j];
                }
            }
        }
    }

    // **แสดงผลลัพธ์**
    cout << "Solution: ";
    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(4) << mat[i][n] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of equations: ";
    cin >> n;

    vector<vector<double>> mat(n, vector<double>(n + 1));

    cout << "Enter augmented matrix (coefficients and constants):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> mat[i][j];
        }
    }

    gaussJordan(mat, n);

    return 0;
}