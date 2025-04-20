#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// ฟังก์ชันหา Inverse Matrix ด้วย Gauss-Jordan Elimination
bool inverseMatrix(vector<vector<double>>& A, vector<vector<double>>& inverse, int n) {
    // สร้างเมทริกซ์เอกลักษณ์
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            inverse[i][j] = (i == j) ? 1 : 0;

    // ใช้ Gauss-Jordan Elimination
    for (int i = 0; i < n; i++) {
        // หาค่า pivot
        double pivot = A[i][i];
        if (pivot == 0) {
            cout << "Matrix is singular and cannot be inverted.\n";
            return false;
        }

        // แบ่งทั้งแถวด้วย pivot
        for (int j = 0; j < n; j++) {
            A[i][j] /= pivot;
            inverse[i][j] /= pivot;
        }

        // กำจัดค่าด้านล่างและด้านบนของ pivot
        for (int k = 0; k < n; k++) {
            if (k == i) continue;
            double factor = A[k][i];
            for (int j = 0; j < n; j++) {
                A[k][j] -= factor * A[i][j];
                inverse[k][j] -= factor * inverse[i][j];
            }
        }
    }

    return true;
}

int main() {
    int n;
    cout << "Enter matrix size (n x n): ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<vector<double>> inverse(n, vector<double>(n));

    cout << "Enter matrix A:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    if (inverseMatrix(A, inverse, n)) {
        cout << "Inverse Matrix:\n";
        for (const auto& row : inverse) {
            for (double val : row)
                cout << setw(10) << fixed << setprecision(4) << val << " ";
            cout << endl;
        }
    }

    return 0;
}
