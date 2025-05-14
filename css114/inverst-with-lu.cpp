#include <iostream>
#include <vector>

using namespace std;

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


// คูณเมทริกซ์กับเวกเตอร์
vector<double> multiplyMatrixVector(vector<vector<double>>& A, vector<double>& b, int n) {
    vector<double> result(n, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i] += A[i][j] * b[j];
    return result;
}

int main() {
    int n;
    cout << "Enter matrix size (n x n): ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<vector<double>> inverse(n, vector<double>(n));
    vector<double> b(n);

    cout << "Enter matrix A:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Enter vector b:\n";
    for (int i = 0; i < n; i++)
        cin >> b[i];

    if (inverseMatrix(A, inverse, n)) {
        // คำนวณ x = A^(-1) * b
        vector<double> x = multiplyMatrixVector(inverse, b, n);

        cout << "Solution x:\n";
        for (double val : x)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}