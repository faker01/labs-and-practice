// lab_4.cpp: определяет точку входа для приложения.
//

#include "lab_4.h"


template<typename MTRX, int n, int k>
class Matrix
{
private:
    MTRX m[n][k];

public:
    Matrix()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                m[i][j] = MTRX();
            }
        }
    }

    Matrix(const Matrix& other)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                m[i][j] = other.m[i][j];
            }
        }
    }


    Matrix& operator=(const Matrix& other) // Оператор присваивания копированием
    {
        if (this != &other)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < k; j++)
                {
                    m[i][j] = other.m[i][j];
                }
            }
        }
        return *this;
    }


    friend std::ostream& operator<<(std::ostream& os, const Matrix& mt) // Оператор вывода
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                os << mt.m[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Matrix& matrix) // оператор ввода
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                is >> matrix.m[i][j];
            }
        }
        return is;
    }

    Matrix operator+(const Matrix& other) const // оператор +
    {
        Matrix res;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                res.m[i][j] = m[i][j] + other.m[i][j];
            }
        }
        return res;
    }

    Matrix& operator+=(const Matrix& other) // оператор +=
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                m[i][j] += other.m[i][j];
            }
        }
        return *this;
    }

    Matrix operator*(const Matrix& other) const // оператор *
    {
        Matrix result;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                MTRX sum = MTRX();
                for (int f = 0; f < k; f++)
                {
                    sum += m[i][k] * other.m[k][j];
                }
                result.m[i][j] = sum;
            }
        }
        return result;
    }

    Matrix& operator*=(const Matrix& other) // оператор *=
    {
        *this = *this * other;
        return *this;
    }

    Matrix operator++(int) // Оператор ++
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                m[i][j]++;
            }
        }
        return *this;
    }

    MTRX determinant() const // вычисление определителя
    {
        if (n != k)
        {
            return -1;
        }
        if (n > 3)
        {
            return -1;
        }
        if (n == 1)
        {
            return m[0][0];
        }
        if (n == 2)
        {
            return m[0][0] * m[1][1] - m[0][1] * m[1][0];
        }
        if (n == 3)
        {
            return m[0][0] * m[1][1] * m[2][2] +
                   m[0][1] * m[1][2] * m[2][0] +
                   m[0][2] * m[1][0] * m[2][1] -
                   m[0][2] * m[1][1] * m[2][0] -
                   m[0][0] * m[1][2] * m[2][1] -
                   m[0][1] * m[1][0] * m[2][2];
        }
    }

    MTRX& operator()(int i, int j) // оператор индекса
    {
        return m[i][j];
    }
};

int main()
{
    Matrix<int, 2, 2> matrix1;
    std::cin >> matrix1;
    std::cout << matrix1 << std::endl;

    Matrix<int, 2, 2> matrix2;
    matrix2 = matrix1;
    std::cout << matrix2 << std::endl;

    std::cout << matrix1 * matrix2 << std::endl;
    std::cout << matrix1 + matrix2 << std::endl;
    matrix2 += matrix1;
    std::cout << matrix2 << std::endl;
    matrix2 *= matrix1;
    std::cout << matrix2 << std::endl;
    matrix2++;
    std::cout << matrix2 << std::endl;

    std::cout << matrix2.determinant() << std::endl;

    std::cout << matrix2(1, 1) << std::endl;
    return 0;
}