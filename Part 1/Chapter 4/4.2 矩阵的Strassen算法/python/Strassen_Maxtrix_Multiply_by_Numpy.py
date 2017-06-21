import numpy as np
import math

print "Input a number"
n = eval(raw_input())
while not math.log(n, 2).is_integer():
    print "error input,try again"
    n = eval(raw_input())
A = np.mat(np.random.randint(10, size=(n, n)))
B = np.mat(np.random.randint(10, size=(n, n)))
print A
print B


def Strassen(X, Y, sizex):
    if sizex == 1:
        return X * Y
    else:
        half = sizex / 2
        A11 = X[:half, :half]
        A21 = X[half:, :half]
        A12 = X[:half, half:]
        A22 = X[half:, half:]
        B11 = Y[:half, :half]
        B21 = Y[half:, :half]
        B12 = Y[:half, half:]
        B22 = Y[half:, half:]
        S1 = B12 - B22
        S2 = A11 + A12
        S3 = A21 + A22
        S4 = B21 - B11
        S5 = A11 + A22
        S6 = B11 + B22
        S7 = A12 - A22
        S8 = B21 + B22
        S9 = A11 - A21
        S10 = B11 + B12

        M1 = Strassen(A11, S1, half)
        M2 = Strassen(S2, B22, half)
        M3 = Strassen(S3, B11, half)
        M4 = Strassen(A22, S4, half)
        M5 = Strassen(S5, S6, half)
        M6 = Strassen(S7, S8, half)
        M7 = Strassen(S9, S10, half)

        C11 = M5 + M4 - M2 + M6
        C12 = M1 + M2
        C21 = M3 + M4
        C22 = M5 + M1 - M3 - M7

        C1 = np.column_stack((C11, C12))
        C2 = np.column_stack((C21, C22))
        C = np.row_stack((C1, C2))
        return C


# print Strassen(A, B, n)
# print A * B
