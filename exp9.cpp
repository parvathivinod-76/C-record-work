#include <iostream>
using namespace std;

class Matrix {
    int row, col;
    int mat[10][10];   // limit 10x10 for convenience

public:
    Matrix(int r = 0, int c = 0) {
        row = r;
        col = c;
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                mat[i][j] = 0;
    }

    void input() {
        cout << "Enter elements for a " << row << "x" << col << " matrix:\n";
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                cin >> mat[i][j];
            }
        }
    }

    void show() const {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j)
                cout << mat[i][j] << "\t";
            cout << endl;
        }
    }

    Matrix operator+(const Matrix& m) {
        Matrix temp(row, col);
        if (row != m.row || col != m.col) {
            cout << "Matrix sizes are not the same.\n";
            return temp;
        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j)
                temp.mat[i][j] = mat[i][j] + m.mat[i][j];
        }
        return temp;
    }
};

int main() {
    int r, c;
    cout << "Enter rows and columns: ";
    cin >> r >> c;

    Matrix A(r, c), B(r, c);

    cout << "Enter elements for first matrix:\n";
    A.input();

    cout << "Enter elements for second matrix:\n";
    B.input();

    cout << "\nFirst Matrix:\n";
    A.show();

    cout << "\nSecond Matrix:\n";
    B.show();

    Matrix C = A + B;

    cout << "\nSum of the given matrices:\n";
    C.show();

    return 0;
}