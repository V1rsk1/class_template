#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;

template<class T>
class Matrix {
    T** ar;
    size_t row;
    size_t col;

public:
    Matrix(size_t row, size_t col) : row(row), col(col) {
        ar = new T * [row];
        for (size_t i = 0; i < row; i++) {
            ar[i] = new T[col];
        }
    }

    T* operator[](size_t index) {
        return ar[index];
    }

    const T* operator[](size_t index) const {
        return ar[index];
    }

    void add() {
        for (size_t i = 0; i < row; i++) {
            for (size_t j = 0; j < col; j++) {
                ar[i][j] = 1 + rand() % 50;
            }
        }
    }

    void addin() {
        cout << "Введіть елементи матриці (" << row * col << " числа): " << endl;
        for (size_t i = 0; i < row; i++) {
            for (size_t j = 0; j < col; j++) {
                cin >> ar[i][j];
            }
        }
    }

    void print() const {
        cout << endl;
        for (size_t i = 0; i < row; i++) {
            for (size_t j = 0; j < col; j++) {
                cout << ar[i][j] << " ";
            }
            cout << endl;
        }
    }

    void MaxandMin() const {
        T max = ar[0][0], min = ar[0][0];
        for (size_t i = 0; i < row; i++) {
            for (size_t j = 0; j < col; j++) {
                if (ar[i][j] > max) max = ar[i][j];
                if (ar[i][j] < min) min = ar[i][j];
            }
        }
        cout << endl << "Max: " << max << "\nMin: " << min << endl;
    }

    ~Matrix() {
        for (size_t i = 0; i < row; i++) {
            delete[] ar[i];
        }
        delete[] ar;
    }

    friend const Matrix operator+(const Matrix& m1, const Matrix& m2) {
        if (m1.row == m2.row && m1.col == m2.col) {
            Matrix<T> result(m1.row, m1.col);
            for (size_t i = 0; i < m1.row; i++) {
                for (size_t j = 0; j < m1.col; j++) {
                    result[i][j] = m1[i][j] + m2[i][j];
                }
            }
            return result;
        }
        else {
            cout << "Матриці різних розмірів!" << endl;
            exit(1);
        }
    }

    friend const Matrix operator-(const Matrix& m1, const Matrix& m2) {
        if (m1.row == m2.row && m1.col == m2.col) {
            Matrix<T> result(m1.row, m1.col);
            for (size_t i = 0; i < m1.row; i++) {
                for (size_t j = 0; j < m1.col; j++) {
                    result[i][j] = m1[i][j] - m2[i][j];
                }
            }
            return result;
        }
        else {
            cout << "Матриці різних розмірів!" << endl;
            exit(1);
        }
    }

    friend const Matrix operator*(const Matrix& m1, const Matrix& m2) {
        if (m1.row == m2.row && m1.col == m2.col) {
            Matrix<T> result(m1.row, m1.col);
            for (size_t i = 0; i < m1.row; i++) {
                for (size_t j = 0; j < m1.col; j++) {
                    result[i][j] = m1[i][j] * m2[i][j];
                }
            }
            return result;
        }
        else {
            cout << "Матриці різних розмірів!" << endl;
            exit(1);
        }
    }

    friend const Matrix<double> operator/(const Matrix& m1, const Matrix& m2) {
        if (m1.row == m2.row && m1.col == m2.col) {
            Matrix<double> result(m1.row, m1.col);
            for (size_t i = 0; i < m1.row; i++) {
                for (size_t j = 0; j < m1.col; j++) {
                    if (m2[i][j] != 0) {
                        result[i][j] = double(m1[i][j]) / double(m2[i][j]);
                    }
                    else {
                        result[i][j] = 0;
                    }
                }
            }
            return result;
        }
        else {
            cout << "Матриці різних розмірів!" << endl;
            exit(1);
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(time(0));

    Matrix<int> m1(3, 3);
    m1.add();
    m1.print();
    m1.MaxandMin();

    Matrix<int> m2(3, 3);
    m2.addin();
    m2.print();
    m2.MaxandMin();

    Matrix<int> m3 = m1 + m2;
    cout << endl << "Сума матриць: " << endl;
    m3.print();

    Matrix<int> m4 = m1 - m2;
    cout << endl << "Різниця матриць: " << endl;
    m4.print();

    Matrix<int> m5 = m1 * m2;
    cout << endl << "Множення матриць: " << endl;
    m5.print();

    Matrix<double> m6 = m1 / m2;
    cout << endl << "Ділення матриць: " << endl;
    m6.print();

    return 0;
}
