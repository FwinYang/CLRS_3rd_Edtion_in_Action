# -*-coding:utf8-*-
# Calculate multiply of maxtrixes by Strassen way
# It could just be used when A,B are square maxtrixes in the same size
# Theoretically, it could be used when A,B are normal maxtrixes,
# while it hasn't been achieved by now.


def Matrix_ADD(A, B):
    C = [];
    tmp = []
    lenth = len(A)
    for i in range(lenth):
        for j in range(lenth):
            tmp[j] = A[i][j] + B[i][j]
        C[i] = tmp
    return C


def Matrix_SUB(A, B):
    C = [];
    tmp = []
    lenth = len(A)
    for i in range(lenth):
        for j in range(lenth):
            tmp[j] = A[i][j] - B[i][j]
        C[i] = tmp
    return C


def Matrix_Divide(A, n):
    k = len(A)
    Ans=[0]
    Ans=Ans*k
    C=Ans*k
    print C
    half = k / 2
    print n,k,A[0][0]
    if n == 11:
        for i in range(half):
            for j in range(half):
                Ans[i][j] = A[i][j]
    if n == 12:
        for i in range(half):
            for j in range(half, k):
                Ans[i][j] = A[i][j]
    if n == 21:
        for i in range(half, k):
            for j in range(half):
                Ans[i][j] = A[i][j]
    if n == 22:
        for i in range(half, k):
            for j in range(half, k):
                Ans[i][j] = A[i][j]
    return Ans


def Matrix_Multiply(A, B):
    C = []
    tmp = []
    lenth = len(A)
    for i in range(lenth):
        for j in range(lenth):
            C[i][j] = 0
            for k in range(lenth):
                C[i][j] += A[i][k] * B[k][j]
    return C


def Strassen(A, B):
    lenth = len(A)
    half = lenth / 2
    C = []
    if lenth == 1:
        C[0][0] = A[0][0] * B[0][0]
        return C
    else:
        A11 = Matrix_Divide(A, 11)
        A12 = Matrix_Divide(A, 12)
        A21 = Matrix_Divide(A, 21)
        A22 = Matrix_Divide(A, 22)
        B11 = Matrix_Divide(B, 11)
        B12 = Matrix_Divide(B, 12)
        B21 = Matrix_Divide(B, 21)
        B22 = Matrix_Divide(B, 22)
        S1 = Matrix_SUB(B12, B22)
        S2 = Matrix_ADD(A11, A12)
        S3 = Matrix_ADD(A21, A22)
        S4 = Matrix_SUB(B21, B11)
        S5 = Matrix_ADD(A11, A22)
        S6 = Matrix_ADD(B11, B22)
        S7 = Matrix_SUB(A12, A22)
        S8 = Matrix_ADD(B21, B22)
        S9 = Matrix_SUB(A11, A21)
        S0 = Matrix_ADD(B11, B12)
        P1 = Strassen(A11, S1)
        P2 = Strassen(S2, B22)
        P3 = Strassen(S3, B11)
        P4 = Strassen(A22, S4)
        P5 = Strassen(S5, S6)
        P6 = Strassen(S7, S8)
        P7 = Strassen(S9, S0)
        C11 = Matrix_SUB(Matrix_ADD(P5, Matrix_ADD(P4, P6)), P2)
        C12 = Matrix_ADD(P1, P2)
        C21 = Matrix_SUB(P3, P4)
        C22 = Matrix_SUB(Matrix_SUB(Matrix_ADD(P5, P4), P3), P7)
        for i in range(lenth):
            for j in range(lenth):
                if i < half:
                    if j < half:
                        C[i][j] = C11[i][j]
                    else:
                        C[i][j] = C12[i][j - half]
                else:
                    k = i - half
                    if j < half:
                        C[i][j] = C21[k][j]
                    else:
                        C[i][j] = C22[k][j - half]
        return C

a = [[1, 3],[7, 5]]
b = [[6, 8], [4, 2]]
print Strassen(a,b)