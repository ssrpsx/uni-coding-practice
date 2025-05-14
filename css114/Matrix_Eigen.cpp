#include <bits/stdc++.h>
#include "eigen/Eigen/Dense"
// ต้องโคลน lib มาก่อนถึงจะใช้ได้
// "git clone https://gitlab.com/libeigen/eigen.git" พิมพ์คำสั่งนี้ลงในTerminal(ต้องอยู่ใน Pathเดียวกับไฟล์ Matrix.cpp)

using namespace std;
using namespace Eigen;

// ช่วยปัดเลขเล็กๆ ให้เป็น 0
double clean(double value, double epsilon = 1e-10) {
    if (abs(value) < epsilon) {
        return 0.0;
    } 
    else {
        return value;
    }
}

// ปริ้นเมทริกซ์ให้คลีน
void printCleanMatrix(const MatrixXd& mat) {
    for (int i = 0; i < mat.rows(); ++i) {
        for (int j = 0; j < mat.cols(); ++j) {
            cout << setw(10) << clean(mat(i, j)) << " ";
        }
        cout << endl;
    }
}

// เรียง eigenvalues และ eigenvectors (ตามลำดับค่าจริง)
void sortEigenPairs(VectorXd& eigenvalues, MatrixXd& eigenvectors) {
    int n = eigenvalues.size();
    vector<pair<double, VectorXd>> pairs;

    for (int i = 0; i < n; ++i) {
        pairs.push_back(make_pair(eigenvalues(i), eigenvectors.col(i)));
    }

    sort(pairs.begin(), pairs.end(), [](const pair<double, VectorXd>& a, const pair<double, VectorXd>& b) {
        if (a.first < b.first) {
            return true;
        } 
        else {
            return false;
        }
    });

    for (int i = 0; i < n; ++i) {
        eigenvalues(i) = pairs[i].first;
        eigenvectors.col(i) = pairs[i].second;
    }
}

// ตรวจสอบว่าเมทริกซ์แปลงเป็นเมทริกซ์ทแยงมุมได้ไหม
bool isDiagonalizable(const MatrixXd& A) {
    EigenSolver<MatrixXd> solver(A);
    if (solver.info() == Success) {
        MatrixXd V = solver.eigenvectors().real();
        FullPivLU<MatrixXd> lu(V);
        if (lu.rank() == A.rows()) {
            return true;
        } 
        else {
            return false;
        }
    } 
    else {
        return false;
    }
}

// แสดง eigenvalues และ eigenvectors
void showEigenData(const MatrixXd& A, VectorXd& eigenvalues, MatrixXd& eigenvectors) {
    EigenSolver<MatrixXd> solver(A);
    if (solver.info() != Success) {
        cout << "การหาค่าเจาะจงล้มเหลว\n";
    } 
    else {
        eigenvalues = solver.eigenvalues().real();
        eigenvectors = solver.eigenvectors().real();
        sortEigenPairs(eigenvalues, eigenvectors);

        cout << "\n1. ค่าเจาะจง (Eigenvalues):\n";
        for (int i = 0; i < eigenvalues.size(); ++i) {
            cout << "Lambda_" << (i + 1) << " = " << clean(eigenvalues(i)) << endl;
        }

        cout << "\n2. เวกเตอร์เจาะจง (Eigenvectors):\n";
        for (int i = 0; i < eigenvectors.cols(); ++i) {
            cout << "Eigenvector for Lambda_" << (i + 1) << ":\n[";
            for (int j = 0; j < eigenvectors.rows(); ++j) {
                cout << clean(eigenvectors(j, i));
                if (j != eigenvectors.rows() - 1) {
                    cout << ", ";
                }
            }
            cout << "]\n";
        }
    }
}

// คำนวณเมทริกซ์ P และ D แล้วแสดง
void calculatePAndD(const MatrixXd& A, const VectorXd& eigenvalues, const MatrixXd& eigenvectors) {
    MatrixXd P = eigenvectors;
    MatrixXd D = P.inverse() * A * P;

    cout << "\n4. เมทริกซ์ P (เวกเตอร์เจาะจงเป็นคอลัมน์):\n";
    printCleanMatrix(P);

    cout << "\nเมทริกซ์ D = P⁻¹AP (Diagonal Matrix):\n";
    printCleanMatrix(D);
}

int main() {
    int size;
    cout << "กรุณากรอกขนาดของเมทริกซ์ (2 สำหรับ 2x2, 3 สำหรับ 3x3): ";
    cin >> size;

    if (size != 2 && size != 3) {
        cout << "รองรับเฉพาะเมทริกซ์ 2x2 หรือ 3x3 เท่านั้น\n";
        return 1;
    }

    MatrixXd A(size, size);
    cout << "กรุณากรอกสมาชิกของเมทริกซ์ " << size << "x" << size << ":\n";
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cin >> A(i, j);
        }
    }

    cout << "\nMatrix A:\n";
    printCleanMatrix(A);

    VectorXd eigenvalues;
    MatrixXd eigenvectors;
    showEigenData(A, eigenvalues, eigenvectors);

    if (isDiagonalizable(A)) {
        cout << "\n3. เมทริกซ์นี้สามารถแปลงเป็นเมทริกซ์ทแยงมุมได้ ✅\n";
        calculatePAndD(A, eigenvalues, eigenvectors);
    } 
    else {
        cout << "\n3. เมทริกซ์นี้ไม่สามารถแปลงเป็นเมทริกซ์ทแยงมุมได้ ❌\n";
    }

    return 0;
}