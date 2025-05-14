#include <bits/stdc++.h> // รวมไลบรารีมาตรฐานทั้งหมด
using namespace std;

const double EPS = 1e-6; // ค่าความคลาดเคลื่อนสำหรับการเปรียบเทียบเลขทศนิยม

// ฟังก์ชันพิมพ์เวกเตอร์ออกมาในรูป [x, y, z]
void printVector(const vector<double>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i)
        cout << fixed << setprecision(5) << v[i] << (i + 1 < v.size() ? ", " : "]");
    cout << "\n";
}

// ฟังก์ชันพิมพ์เมทริกซ์ออกมา
void printMatrix(const vector<vector<double>>& M) {
    for (const auto& row : M) {
        for (double val : row)
            cout << setw(10) << fixed << setprecision(5) << val << " ";
        cout << "\n";
    }
}

// คลาสสำหรับเมทริกซ์ 2x2
class Matrix2x2 {
private:
    vector<vector<double>> A; // เก็บเมทริกซ์ A

public:
    Matrix2x2(const vector<vector<double>>& mat) : A(mat) {}

    // หาค่า eigenvalues โดยใช้สูตรจากพหุนามลักษณะเฉพาะ
    vector<double> eigenvalues() {
        double a = A[0][0], b = A[0][1];
        double c = A[1][0], d = A[1][1];
        double trace = a + d;
        double det = a * d - b * c;
        double disc = trace * trace - 4 * det;

        if (disc < 0) return {}; // ไม่มีรากจริง
        double sqrt_disc = sqrt(disc);
        return { (trace + sqrt_disc) / 2, (trace - sqrt_disc) / 2 };
    }

    // หา eigenvector สำหรับ eigenvalue ที่ระบุ
    vector<double> eigenvector(double lambda) {
        double a = A[0][0] - lambda;
        double b = A[0][1];
        double c = A[1][0];
        double d = A[1][1] - lambda;

        // แก้สมการเชิงเส้น (Ax = 0) โดยสมมุติ x = 1 แล้วแก้ y
        if (fabs(a) > EPS || fabs(b) > EPS) {
            double x = 1;
            double y = (fabs(b) > EPS) ? -a / b : 0;
            return {x, y};
        } else if (fabs(c) > EPS || fabs(d) > EPS) {
            double x = 1;
            double y = (fabs(d) > EPS) ? -c / d : 0;
            return {x, y};
        }
        return {1, 0}; // กรณีพิเศษ: ทุกเวกเตอร์เป็น eigenvector
    }

    // หา inverse ของเมทริกซ์ 2x2
    vector<vector<double>> inverse(const vector<vector<double>>& M) {
        double det = M[0][0] * M[1][1] - M[0][1] * M[1][0];
        if (fabs(det) < EPS) return {};
        return {
            { M[1][1] / det, -M[0][1] / det },
            { -M[1][0] / det, M[0][0] / det }
        };
    }

    // คูณเมทริกซ์ A กับ B
    vector<vector<double>> multiply(const vector<vector<double>>& B) {
        vector<vector<double>> C(2, vector<double>(2, 0));
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                for (int k = 0; k < 2; ++k)
                    C[i][j] += A[i][k] * B[k][j];
        return C;
    }

    // คำนวณและพิมพ์ผลลัพธ์การทำ Diagonalization
    void computeDiagonalization() {
        auto lambdas = eigenvalues();
        if (lambdas.empty()) {
            cout << "No real eigenvalues.\n";
            return;
        }

        cout << "Eigenvalues:\n";
        for (size_t i = 0; i < lambdas.size(); ++i)
            cout << "Lambda_" << i + 1 << " = " << lambdas[i] << "\n";

        vector<vector<double>> P(2, vector<double>(2));
        cout << "\n";
        for (int i = 0; i < 2; ++i) {
            auto v = eigenvector(lambdas[i]);
            cout << "Eigenvector for Lambda = " << lambdas[i] << ":\n";
            printVector(v);
            P[0][i] = v[0];
            P[1][i] = v[1];
        }

        auto Pinv = inverse(P);
        if (Pinv.empty()) {
            cout << "Matrix is not diagonalizable. ❌\n";
            return;
        }

        // คำนวณ D = P^-1 * A * P
        vector<vector<double>> temp(2, vector<double>(2));
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                for (int k = 0; k < 2; ++k)
                    temp[i][j] += Pinv[i][k] * A[k][j];

        vector<vector<double>> D(2, vector<double>(2));
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                for (int k = 0; k < 2; ++k)
                    D[i][j] += temp[i][k] * P[k][j];

        cout << "\nThe matrix is diagonalizable. ✅\nMatrix P:\n";
        printMatrix(P);
        cout << "\nDiagonal matrix D = P^-1 * A * P:\n";
        printMatrix(D);
    }
};

// คลาสสำหรับจัดการเมทริกซ์ 3x3
class Matrix3x3 {
private:
    vector<vector<double>> A; // เมทริกซ์ A ขนาด 3x3

public:
    Matrix3x3(const vector<vector<double>>& mat) : A(mat) {}

    // ฟังก์ชันย่อย: หาค่า determinant ของเมทริกซ์ 3x3
    double determinant(const vector<vector<double>>& M) {
        return M[0][0] * (M[1][1] * M[2][2] - M[1][2] * M[2][1])
             - M[0][1] * (M[1][0] * M[2][2] - M[1][2] * M[2][0])
             + M[0][2] * (M[1][0] * M[2][1] - M[1][1] * M[2][0]);
    }

    // ฟังก์ชันประมาณค่า eigenvalues โดยใช้การหา determinant ของ (A - λI)
    vector<double> eigenvalues() {
        // ค้นหาค่า lambda จาก -10 ถึง 10 โดยใช้สเต็ป 0.01
        vector<double> lambdas;
        for (double lambda = -10; lambda <= 10; lambda += 0.01) {
            // สร้างเมทริกซ์ B = A - λI
            vector<vector<double>> B(3, vector<double>(3));
            for (int i = 0; i < 3; ++i)
                for (int j = 0; j < 3; ++j)
                    B[i][j] = A[i][j] - (i == j ? lambda : 0);

            // ถ้าค่า determinant ใกล้ 0 แสดงว่าเป็น eigenvalue
            if (fabs(determinant(B)) < EPS)
                if (lambdas.empty() || fabs(lambda - lambdas.back()) > 0.1)
                    lambdas.push_back(lambda); // เพิ่มเข้าไปหากยังไม่ซ้ำ
        }
        return lambdas;
    }

    // ฟังก์ชันหา eigenvector จาก eigenvalue โดยใช้ Gaussian Elimination
    vector<double> eigenvector(double lambda) {
        // สร้างเมทริกซ์ B = A - λI
        vector<vector<double>> B(3, vector<double>(4, 0)); // 3x4 สำหรับ augmented matrix

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j)
                B[i][j] = A[i][j] - (i == j ? lambda : 0);
            B[i][3] = 0; // ด้านขวาของสมการ (Ax = 0)
        }

        // ทำ Gaussian elimination เพื่อลดรูป
        for (int i = 0; i < 3; ++i) {
            // หาค่า pivot
            int pivot = i;
            for (int j = i + 1; j < 3; ++j)
                if (fabs(B[j][i]) > fabs(B[pivot][i]))
                    pivot = j;
            if (fabs(B[pivot][i]) < EPS) continue; // ข้ามถ้า pivot เป็น 0

            swap(B[i], B[pivot]); // สลับแถว

            // ทำให้ค่า pivot = 1 แล้วลบแถวอื่นให้เป็น 0
            double div = B[i][i];
            for (int j = 0; j < 4; ++j)
                B[i][j] /= div;
            for (int j = 0; j < 3; ++j) {
                if (j != i) {
                    double factor = B[j][i];
                    for (int k = 0; k < 4; ++k)
                        B[j][k] -= factor * B[i][k];
                }
            }
        }

        // จากรูปแบบลดแล้ว ดึงค่า eigenvector ออกมา
        vector<double> x(3, 0);
        bool freeVarFound = false;

        for (int i = 2; i >= 0; --i) {
            int pivot_col = -1;
            for (int j = 0; j < 3; ++j) {
                if (fabs(B[i][j]) > EPS) {
                    pivot_col = j;
                    break;
                }
            }
            if (pivot_col == -1) continue;

            if (!freeVarFound) {
                x[pivot_col] = 1; // ตั้งค่าสมมุติให้ตัวแปรอิสระ = 1
                freeVarFound = true;
            } else {
                // คำนวณค่าอื่น ๆ ตามลำดับ
                double sum = 0;
                for (int j = pivot_col + 1; j < 3; ++j)
                    sum += B[i][j] * x[j];
                x[pivot_col] = -sum;
            }
        }
        return x;
    }

    // หาค่า inverse ของเมทริกซ์ 3x3 โดยใช้เมทริกซ์ผกผันแบบ Gauss-Jordan
    vector<vector<double>> inverse(const vector<vector<double>>& M) {
        vector<vector<double>> A = M;
        vector<vector<double>> I = {{1,0,0}, {0,1,0}, {0,0,1}};

        for (int i = 0; i < 3; ++i) {
            int pivot = i;
            for (int j = i + 1; j < 3; ++j)
                if (fabs(A[j][i]) > fabs(A[pivot][i]))
                    pivot = j;
            if (fabs(A[pivot][i]) < EPS) return {};

            swap(A[i], A[pivot]);
            swap(I[i], I[pivot]);

            double div = A[i][i];
            for (int j = 0; j < 3; ++j) {
                A[i][j] /= div;
                I[i][j] /= div;
            }

            for (int j = 0; j < 3; ++j) {
                if (j != i) {
                    double factor = A[j][i];
                    for (int k = 0; k < 3; ++k) {
                        A[j][k] -= factor * A[i][k];
                        I[j][k] -= factor * I[i][k];
                    }
                }
            }
        }
        return I;
    }

    // คูณเมทริกซ์ A กับเมทริกซ์ B
    vector<vector<double>> multiply(const vector<vector<double>>& B) {
        vector<vector<double>> C(3, vector<double>(3, 0));
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                for (int k = 0; k < 3; ++k)
                    C[i][j] += A[i][k] * B[k][j];
        return C;
    }

    // คำนวณและพิมพ์ผลลัพธ์ Diagonalization
    void computeDiagonalization() {
        auto lambdas = eigenvalues();
        if (lambdas.empty()) {
            cout << "No real eigenvalues.\n";
            return;
        }

        cout << "Eigenvalues:\n";
        for (size_t i = 0; i < lambdas.size(); ++i)
            cout << "Lambda_" << i + 1 << " = " << lambdas[i] << "\n";

        vector<vector<double>> P(3, vector<double>(3));
        cout << "\n";
        for (int i = 0; i < 3; ++i) {
            auto v = eigenvector(lambdas[i]);
            cout << "Eigenvector for Lambda = " << lambdas[i] << ":\n";
            printVector(v);
            for (int j = 0; j < 3; ++j)
                P[j][i] = v[j]; // จัดเรียงเวกเตอร์ในแต่ละคอลัมน์ของ P
        }

        auto Pinv = inverse(P);
        if (Pinv.empty()) {
            cout << "Matrix is not diagonalizable. ❌\n";
            return;
        }

        // คำนวณ D = P^-1 * A * P
        vector<vector<double>> temp(3, vector<double>(3));
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                for (int k = 0; k < 3; ++k)
                    temp[i][j] += Pinv[i][k] * A[k][j];

        vector<vector<double>> D(3, vector<double>(3));
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                for (int k = 0; k < 3; ++k)
                    D[i][j] += temp[i][k] * P[k][j];

        cout << "\nThe matrix is diagonalizable. ✅\nMatrix P:\n";
        printMatrix(P);
        cout << "\nDiagonal matrix D = P^-1 * A * P:\n";
        printMatrix(D);
    }
};

int main() {
    int n;
    cout << "Enter the size of the matrix (2 or 3): ";
    cin >> n;

    vector<vector<double>> mat(n, vector<double>(n));
    cout << "Enter the elements of the " << n << "x" << n << " matrix:\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> mat[i][j];

    cout << endl;
    if (n == 2) {
        Matrix2x2 m(mat);
        m.computeDiagonalization();
    } 
    else if (n == 3) {
        Matrix3x3 m(mat);
        m.computeDiagonalization();
    } 
    else {
        cout << "Only 2x2 and 3x3 matrices are supported.\n";
    }

    return 0;
}