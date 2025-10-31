#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <stdexcept>

using namespace std;

/**
 * Strassen Matrix Multiplication Algorithm
 * ----------------------------------------
 * Strassen's algorithm is a divide-and-conquer algorithm for matrix multiplication
 * that reduces the number of recursive multiplications from 8 to 7.
 * 
 * Time Complexity: O(n^log₂7) ≈ O(n^2.807)
 * Space Complexity: O(log n) for recursion + O(n²) for temporary matrices
 */

using Matrix = vector<vector<int>>;

const int THRESHOLD = 64;

// --- Helper Function Declarations ---
Matrix standardMultiply(const Matrix& A, const Matrix& B);
Matrix add(const Matrix& A, const Matrix& B);
Matrix subtract(const Matrix& A, const Matrix& B);
Matrix getSubMatrix(const Matrix& matrix, int row, int col, int size);
Matrix combineMatrices(const Matrix& C11, const Matrix& C12, const Matrix& C21, const Matrix& C22);
Matrix padMatrix(const Matrix& matrix, int newSize);
Matrix extractMatrix(const Matrix& matrix, int rows, int cols);
bool isValidForMultiplication(const Matrix& A, const Matrix& B);
int nextPowerOfTwo(int n);

// --- Strassen Recursive Implementation ---
Matrix strassenRecursive(const Matrix& A, const Matrix& B) {
    int n = A.size();

    if (n <= THRESHOLD)
        return standardMultiply(A, B);

    int half = n / 2;

    Matrix A11 = getSubMatrix(A, 0, 0, half);
    Matrix A12 = getSubMatrix(A, 0, half, half);
    Matrix A21 = getSubMatrix(A, half, 0, half);
    Matrix A22 = getSubMatrix(A, half, half, half);

    Matrix B11 = getSubMatrix(B, 0, 0, half);
    Matrix B12 = getSubMatrix(B, 0, half, half);
    Matrix B21 = getSubMatrix(B, half, 0, half);
    Matrix B22 = getSubMatrix(B, half, half, half);

    Matrix M1 = strassenRecursive(add(A11, A22), add(B11, B22));
    Matrix M2 = strassenRecursive(add(A21, A22), B11);
    Matrix M3 = strassenRecursive(A11, subtract(B12, B22));
    Matrix M4 = strassenRecursive(A22, subtract(B21, B11));
    Matrix M5 = strassenRecursive(add(A11, A12), B22);
    Matrix M6 = strassenRecursive(subtract(A21, A11), add(B11, B12));
    Matrix M7 = strassenRecursive(subtract(A12, A22), add(B21, B22));

    Matrix C11 = add(subtract(add(M1, M4), M5), M7);
    Matrix C12 = add(M3, M5);
    Matrix C21 = add(M2, M4);
    Matrix C22 = add(subtract(add(M1, M3), M2), M6);

    return combineMatrices(C11, C12, C21, C22);
}

// --- Public API ---
Matrix strassenMultiply(const Matrix& A, const Matrix& B) {
    if (!isValidForMultiplication(A, B))
        throw invalid_argument("Invalid matrices: columns of A must equal rows of B.");

    int aRows = A.size(), aCols = A[0].size();
    int bRows = B.size(), bCols = B[0].size();

    int maxDim = max({aRows, aCols, bRows, bCols});
    int paddedSize = nextPowerOfTwo(maxDim);

    Matrix paddedA = padMatrix(A, paddedSize);
    Matrix paddedB = padMatrix(B, paddedSize);

    Matrix result = strassenRecursive(paddedA, paddedB);
    return extractMatrix(result, aRows, bCols);
}

// --- Helper Implementations ---
Matrix standardMultiply(const Matrix& A, const Matrix& B) {
    int rows = A.size(), cols = B[0].size(), common = B.size();
    Matrix result(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            for (int k = 0; k < common; k++)
                result[i][j] += A[i][k] * B[k][j];

    return result;
}

Matrix add(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix result(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = A[i][j] + B[i][j];
    return result;
}

Matrix subtract(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix result(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = A[i][j] - B[i][j];
    return result;
}

Matrix getSubMatrix(const Matrix& matrix, int row, int col, int size) {
    Matrix sub(size, vector<int>(size));
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            sub[i][j] = matrix[row + i][col + j];
    return sub;
}

Matrix combineMatrices(const Matrix& C11, const Matrix& C12, const Matrix& C21, const Matrix& C22) {
    int half = C11.size();
    int n = 2 * half;
    Matrix result(n, vector<int>(n));

    for (int i = 0; i < half; i++) {
        copy(C11[i].begin(), C11[i].end(), result[i].begin());
        copy(C12[i].begin(), C12[i].end(), result[i].begin() + half);
        copy(C21[i].begin(), C21[i].end(), result[i + half].begin());
        copy(C22[i].begin(), C22[i].end(), result[i + half].begin() + half);
    }

    return result;
}

Matrix padMatrix(const Matrix& matrix, int newSize) {
    int rows = matrix.size(), cols = matrix[0].size();
    Matrix padded(newSize, vector<int>(newSize, 0));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            padded[i][j] = matrix[i][j];
    return padded;
}

Matrix extractMatrix(const Matrix& matrix, int rows, int cols) {
    Matrix result(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = matrix[i][j];
    return result;
}

bool isValidForMultiplication(const Matrix& A, const Matrix& B) {
    return !A.empty() && !B.empty() && A[0].size() == B.size();
}

int nextPowerOfTwo(int n) {
    if (n <= 1) return 1;
    int power = 1;
    while (power < n) power <<= 1;
    return power;
}

// --- Utility & Demonstration ---
void printMatrix(const Matrix& matrix, const string& name) {
    cout << "\n" << name << ":\n";
    for (const auto& row : matrix) {
        for (int val : row)
            cout << setw(6) << val << " ";
        cout << endl;
    }
}

Matrix generateRandomMatrix(int rows, int cols, int maxValue) {
    Matrix matrix(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = (rand() % (2 * maxValue + 1)) - maxValue;
    return matrix;
}

void handleManualInput() {
    int r1, c1, r2, c2;
    cout << "Enter rows & cols of first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter rows & cols of second matrix: ";
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << "Error: Columns of A must equal rows of B.\n";
        return;
    }

    Matrix A(r1, vector<int>(c1)), B(r2, vector<int>(c2));

    cout << "Enter elements of first matrix:\n";
    for (auto& row : A)
        for (int& x : row) cin >> x;

    cout << "Enter elements of second matrix:\n";
    for (auto& row : B)
        for (int& x : row) cin >> x;

    clock_t start = clock();
    Matrix result = strassenMultiply(A, B);
    double time = (clock() - start) * 1000.0 / CLOCKS_PER_SEC;

    printMatrix(result, "Result (A x B)");
    cout << "\nTime: " << time << " ms\n";
}

void handleRandomMatrices() {
    int n, maxVal;
    cout << "Enter matrix size (n x n): ";
    cin >> n;
    cout << "Enter max random value: ";
    cin >> maxVal;

    Matrix A = generateRandomMatrix(n, n, maxVal);
    Matrix B = generateRandomMatrix(n, n, maxVal);

    clock_t start = clock();
    Matrix result = strassenMultiply(A, B);
    double time = (clock() - start) * 1000.0 / CLOCKS_PER_SEC;

    if (n <= 10) {
        printMatrix(A, "Matrix A");
        printMatrix(B, "Matrix B");
        printMatrix(result, "Result (A x B)");
    }

    cout << "\nTime taken: " << time << " ms\n";
}

int main() {
    srand(time(0));
    cout << "=== Strassen Matrix Multiplication ===\n";
    cout << "1. Manual Input\n2. Random Matrices\nChoose: ";

    int choice;
    cin >> choice;

    try {
        if (choice == 1) handleManualInput();
        else if (choice == 2) handleRandomMatrices();
        else cout << "Invalid choice!\n";
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
