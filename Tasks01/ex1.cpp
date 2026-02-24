#include <iostream>

namespace MatrixNS {
    int** createMatrix(int rows, int cols) {
        int** matrix = new int* [rows];
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new int[cols];
        }
        return matrix;
    }

    void freeMatrix(int** matrix, int rows) {
        for (int i = 0; i < rows; i++)
        {
            delete[]matrix[i];
        }
        delete[] matrix;
    }

    void readMatrix(int** matrix, int rows, int cols) {
        if (!matrix) return;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                std::cin >> matrix[i][j];
            }
        }
    }

    int** transposeMatrix(int** matrix, int rows, int cols) {
        if (!matrix) return nullptr;
        int** transposedMatrix = createMatrix(cols, rows);
        
        for (int i = 0; i < cols; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                transposedMatrix[i][j] = matrix[j][i];
            }
        }

        return transposedMatrix;
    }

    void swapRows(int** matrix, int rowIdx1, int rowIdx2) {
        if (!matrix) return;

        int* temp = matrix[rowIdx1];
        matrix[rowIdx1] = matrix[rowIdx2];
        matrix[rowIdx2] = temp;
    }

    void printMatrix(int** matrix, int rows, int cols) {
        if (!matrix) return;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << '\n';
        }
    }

}

int main()
{
    using namespace MatrixNS;

    int rows, cols;
    std::cin >> rows >> cols;

    int** matrix = createMatrix(rows, cols);
    readMatrix(matrix, rows, cols);

    int** trMatrix = transposeMatrix(matrix, rows, cols);
    printMatrix(trMatrix,  cols, rows);

    freeMatrix(matrix, rows);
    freeMatrix(trMatrix, cols);
}

