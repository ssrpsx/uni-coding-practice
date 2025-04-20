#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

// ฟังก์ชันสำหรับ Gauss Elimination with Partial Pivoting
void gaussElimination(vector<vector<double>>& mat, int n) {
    for (int i = 0; i < n; i++) {
        // **ขั้นตอนที่ 1: Partial Pivoting (เลือกแถวที่มี Pivot ดีที่สุด)**
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
        for (int j = i; j <= n; j++) {
            mat[i][j] /= pivot;
        }

        // **ขั้นตอนที่ 3: ทำให้ตัวเลขใต้เส้นทแยงมุมเป็น 0**
        for (int k = i + 1; k < n; k++) {
            double factor = mat[k][i];
            for (int j = i; j <= n; j++) {
                mat[k][j] -= factor * mat[i][j];
            }
        }
    }

    // **ขั้นตอนที่ 4: Back Substitution เพื่อหาค่าตัวแปร**
    vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = mat[i][n];
        for (int j = i + 1; j < n; j++) {
            x[i] -= mat[i][j] * x[j];
        }
    }

    // **แสดงผลลัพธ์**
    cout << "Solution: ";
    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(4) << x[i] << " ";
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

    gaussElimination(mat, n);

    return 0;
}