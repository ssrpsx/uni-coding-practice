from sympy import Matrix  # นำเข้า Matrix จากไลบรารี SymPy สำหรับคำนวณเมทริกซ์

# ฟังก์ชันสำหรับรับอินพุตเมทริกซ์จากผู้ใช้
def get_matrix_input():
    while True:
        try:
            size = int(input("Enter matrix size (2 or 3): "))
            if size != 2 and size != 3:
                print("Only 2x2 or 3x3 matrices are supported.")
                continue

            print(f"Enter the elements of the {size}x{size} matrix row by row:")
            matrix = []

            for i in range(size):
                row_input = input(f"Row {i+1}: ")
                row_elements = row_input.strip().split()

                if len(row_elements) != size:
                    print(f"Each row must have {size} elements.")  # ต้องมีจำนวนสมาชิกในแถวให้ครบ
                    break

                row = []
                for element in row_elements:
                    row.append(int(element))  # แปลงสมาชิกแต่ละตัวเป็นจำนวนเต็ม
                matrix.append(row)

            if len(matrix) == size:
                return Matrix(matrix)  # แปลงเป็นเมทริกซ์ของ SymPy และส่งกลับ

        except ValueError:
            print("Invalid input. Please enter integers only.")

# ฟังก์ชันสำหรับแสดงเมทริกซ์พร้อมชื่อ
def print_matrix_labelled(mat, label):
    print(f"{label} :")
    for row in mat.tolist():  # แปลงเมทริกซ์เป็น list ปกติ
        line = "[ "
        for element in row:
            line += f"{int(element):>3} "
        line += "]"
        print(line)

# ฟังก์ชันสำหรับวิเคราะห์เมทริกซ์ หา eigenvalues และ eigenvectors
def analyze_matrix_sympy(A):
    print("\n=== Matrix Analysis ===")
    print_matrix_labelled(A, "Matrix A")

    eigen_data = A.eigenvects()  # หา eigenvalues และ eigenvectors
    eigenvectors = []

    print("\nEigenvalues:")
    lambda_index = 1

    for eigenvalue, multiplicity, vectors in eigen_data:  # วนลูปค่า eigen แต่ละตัว
        print(f"Lambda_{lambda_index} = {eigenvalue}")  # แสดงค่า eigenvalue

        for v in vectors:  # แสดงเวกเตอร์เฉพาะของ eigenvalue นั้น
            formatted_vector = []
            for element in list(v):
                if element.is_Integer:
                    formatted_vector.append(int(element))  # ถ้าเป็นจำนวนเต็ม ให้แปลงเป็น int
                else:
                    formatted_vector.append(element)

            print(f"Eigenvector for Lambda_{lambda_index}: {formatted_vector}\n")
            eigenvectors.append(v)  # เก็บเวกเตอร์ไว้ใช้ภายหลัง

        lambda_index += 1

    # ตรวจสอบว่าเมทริกซ์สามารถแปลงเป็นรูปทแยงมุมได้หรือไม่
    if len(eigenvectors) == A.shape[0]:  # ถ้าจำนวน eigenvectors เท่ากับขนาดเมทริกซ์
        print("The matrix is diagonalizable.")

        # สร้างเมทริกซ์ P จาก eigenvectors
        P_columns = []
        for v in eigenvectors:
            P_columns.append(v)

        P = Matrix.hstack(*P_columns)
        print_matrix_labelled(P, "Matrix P")  # แสดงเมทริกซ์ P
    else:
        print("The matrix is not diagonalizable.")  # ถ้าไม่สามารถแปลงเป็นรูปทแยงมุมได้

# เรียกใช้ฟังก์ชันรับอินพุตเมทริกซ์จากผู้ใช้
A = get_matrix_input()

# วิเคราะห์เมทริกซ์ที่ได้
analyze_matrix_sympy(A)