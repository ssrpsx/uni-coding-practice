#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// ฟังก์ชันแยกเมทริกซ์ A เป็น L และ U
bool luDecomposition(vector<vector<double>>& A, vector<vector<double>>& L, vector<vector<double>>& U, int n) {
    for (int i = 0; i < n; i++) {
        // คำนวณค่าเมทริกซ์ U
        for (int k = i; k < n; k++) {
            double sum = 0;
            for (int j = 0; j < i; j++) {
                sum += L[i][j] * U[j][k];
            }
            U[i][k] = A[i][k] - sum;
        }

        // คำนวณค่าเมทริกซ์ L
        for (int k = i; k < n; k++) {
            if (i == k) {
                L[i][i] = 1;  // ค่าเส้นทแยงมุมของ L เป็น 1 เสมอ
            } else {
                double sum = 0;
                for (int j = 0; j < i; j++) {
                    sum += L[k][j] * U[j][i];
                }
                if (U[i][i] == 0) {
                    cout << "LU Decomposition failed (zero pivot element)." << endl;
                    return false;
                }
                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }
    return true;
}

// ฟังก์ชัน Forward Substitution แก้ Ly = b
vector<double> forwardSubstitution(vector<vector<double>>& L, vector<double>& b, int n) {
    vector<double> y(n);
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < i; j++) {
            sum += L[i][j] * y[j];
        }
        y[i] = (b[i] - sum);
    }
    return y;
}

// ฟังก์ชัน Backward Substitution แก้ Ux = y
vector<double> backwardSubstitution(vector<vector<double>>& U, vector<double>& y, int n) {
    vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += U[i][j] * x[j];
        }
        x[i] = (y[i] - sum) / U[i][i];
    }
    return x;
}

int main() {
    int n;
    cout << "Enter the number of equations: ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<vector<double>> L(n, vector<double>(n, 0));
    vector<vector<double>> U(n, vector<double>(n, 0));
    vector<double> b(n);

    cout << "Enter the coefficient matrix A:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Enter the constant matrix b:\n";
    for (int i = 0; i < n; i++)
        cin >> b[i];

    if (!luDecomposition(A, L, U, n)) return 1;

    // แสดง L และ U
    cout << "L matrix:\n";
    for (auto& row : L) {
        for (double val : row) cout << setw(8) << val << " ";
        cout << endl;
    }

    cout << "U matrix:\n";
    for (auto& row : U) {
        for (double val : row) cout << setw(8) << val << " ";
        cout << endl;
    }

    // แก้สมการ
    vector<double> y = forwardSubstitution(L, b, n);
    vector<double> x = backwardSubstitution(U, y, n);

    cout << "Solution:\n";
    for (double val : x) {
        cout << fixed << setprecision(4) << val << " ";
    }
    cout << endl;

    return 0;
}