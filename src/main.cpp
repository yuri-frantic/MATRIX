#include <iostream>
#include <vector>
#include <stdexcept>

class Matrix {
private:
    std::vector<std::vector<int>> data;
    size_t rows, cols;

public:
    // Конструктор для инициализации матрицы
    Matrix(size_t r, size_t c) : rows(r), cols(c) {
        data.resize(rows, std::vector<int>(cols, 0));
    }

    // Перегрузка оператора ввода
    friend std::istream& operator>>(std::istream& is, Matrix& m) {
        for (size_t i = 0; i < m.rows; ++i) {
            for (size_t j = 0; j < m.cols; ++j) {
                is >> m.data[i][j];
            }
        }
        return is;
    }

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const Matrix& m) {
        for (size_t i = 0; i < m.rows; ++i) {
            for (size_t j = 0; j < m.cols; ++j) {
                os << m.data[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }

    // Перегрузка оператора += (сложение матриц с присваиванием)
    Matrix& operator+=(const Matrix& other) {
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Matrices dimensions must match for addition.");
        }
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                data[i][j] += other.data[i][j];
            }
        }
        return *this;
    }

    // Перегрузка оператора -= (вычитание матриц с присваиванием)
    Matrix& operator-=(const Matrix& other) {
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Matrices dimensions must match for subtraction.");
        }
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                data[i][j] -= other.data[i][j];
            }
        }
        return *this;
    }

    // Перегрузка оператора *= (умножение матрицы на число с присваиванием)
    Matrix& operator*=(int scalar) {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                data[i][j] *= scalar;
            }
        }
        return *this;
    }

    // Перегрузка оператора + для сложения матриц
    friend Matrix operator+(Matrix lhs, const Matrix& rhs) {
        lhs += rhs;
        return lhs;
    }

    // Перегрузка оператора - для вычитания матриц
    friend Matrix operator-(Matrix lhs, const Matrix& rhs) {
        lhs -= rhs;
        return lhs;
    }

    // Перегрузка оператора * для умножения матрицы на число
    friend Matrix operator*(Matrix m, int scalar) {
        m *= scalar;
        return m;
    }
};

int main() {
    size_t rows, cols;

    std::cout << "Введите количество строк и столбцов матриц: ";
    std::cin >> rows >> cols;

    Matrix A(rows, cols);
    std::cout << "Введите элементы матрицы A:" << std::endl;
    std::cin >> A;

    Matrix B(rows, cols);
    std::cout << "Введите элементы матрицы B:" << std::endl;
    std::cin >> B;

    Matrix C = A + B;
    std::cout << "A + B:" << std::endl << C;

    Matrix D = A - B;
    std::cout << "A - B:" << std::endl << D;

    int scalar;
    std::cout << "Введите число для умножения матрицы A: ";
    std::cin >> scalar;

    A *= scalar;
    std::cout << "Результат умножения матрицы A на " << scalar << ":" << std::endl << A;

    A += B;
    std::cout << "A += B: " << std::endl << "Выводим A:" << std::endl << A;

    //std::cout << "Результат умножения матрицы A на " << scalar << ":" << std::endl << A;

    return 0;
}

