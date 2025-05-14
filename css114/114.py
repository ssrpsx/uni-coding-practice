from sympy import Matrix

def get_matrix_input():
    while True:
        try:
            size = int(input("Enter the size of the matrix (2 or 3): "))
            if size not in [2, 3]:
                raise ValueError("Size must be 2 or 3 only.")

            print(f"Enter the elements of the {size}x{size} matrix:")
            matrix = []
            for _ in range(size):
                row = list(map(int, input().split()))
                if len(row) != size:
                    raise ValueError(f"Each row must contain exactly {size} integers.")
                matrix.append(row)

            return Matrix(matrix)
        except ValueError as e:
            print(f"Error: {e}")
            print("Please try again.\n")

def print_matrix_labelled(mat, label):
    print(f"{label} :")
    for row in mat.tolist():
        row_str = ' '.join(f"{int(x):>2}" for x in row)
        print(f"[ {row_str} ]")

def analyze_matrix_sympy(A):
    print("\n=== Matrix Analysis ===")
    print_matrix_labelled(A, "Matrix A")

    eigen_data = A.eigenvects()

    print("\nEigenvalues:")
    eigenvectors = []
    count = 1
    for val, mult, vects in eigen_data:
        print(f"Lambda_{count} = {val}")
        for v in vects:
            vec_list = [int(x) if x.is_Integer else x for x in list(v)]
            print(f"Eigenvector for Lambda_{count}: {vec_list}\n")
            eigenvectors.append(v)
        count += 1

    if len(eigenvectors) == A.shape[0]:
        print("The matrix is diagonalizable.")
        P = Matrix.hstack(*eigenvectors)
        print_matrix_labelled(P, "Matrix P")
    else:
        print("The matrix is not diagonalizable.")

A = get_matrix_input()
analyze_matrix_sympy(A)