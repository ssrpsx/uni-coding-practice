from sympy import Matrix

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
                    print(f"Each row must have {size} elements.")
                    break

                row = []
                for element in row_elements:
                    row.append(int(element))
                matrix.append(row)
            
            if len(matrix) == size:
                return Matrix(matrix)

        except ValueError:
            print("Invalid input. Please enter integers only.")

def print_matrix_labelled(mat, label):
    print(f"{label} :")
    for row in mat.tolist():
        line = "[ "
        for element in row:
            line += f"{int(element):>3} "
        line += "]"
        print(line)

def analyze_matrix_sympy(A):
    print("\n=== Matrix Analysis ===")
    print_matrix_labelled(A, "Matrix A")

    eigen_data = A.eigenvects()
    eigenvectors = []

    print("\nEigenvalues:")
    lambda_index = 1

    for eigenvalue, multiplicity, vectors in eigen_data:
        print(f"Lambda_{lambda_index} = {eigenvalue}")
        for v in vectors:
            formatted_vector = []
            for element in list(v):
                if element.is_Integer:
                    formatted_vector.append(int(element))
                else:
                    formatted_vector.append(element)
            print(f"Eigenvector for Lambda_{lambda_index}: {formatted_vector}\n")
            eigenvectors.append(v)
        lambda_index += 1

    if len(eigenvectors) == A.shape[0]:
        print("The matrix is diagonalizable.")

        # Build matrix P from eigenvectors
        P_columns = []
        for v in eigenvectors:
            P_columns.append(v)

        P = Matrix.hstack(*P_columns)
        print_matrix_labelled(P, "Matrix P")
    else:
        print("The matrix is not diagonalizable.")

A = get_matrix_input()
analyze_matrix_sympy(A)