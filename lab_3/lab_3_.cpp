#include "lab_3_.h"


using namespace std;


class Complex {
private:
    double num_c;
    double num_o;
public:
    Complex(double c = 0, double o = 0)
    {
        num_c = c;
        num_o = o;
    }

    Complex(const Complex& other) : num_c(other.num_c), num_o(other.num_o)
    {
    }

    Complex operator=(const Complex& other) // Оператор присваивания копированием
    {
        num_c = other.num_c;
        num_o = other.num_o;
        return *this;
    }

    ~Complex() // Деструктор
    {
    }


    Complex operator+=(const Complex& other) // оператор +=
    {
        num_c += other.num_c;
        num_o += other.num_o;
        return *this;
    }


    friend Complex operator+(Complex c1, const Complex& c2) // оператор +
    {
        return c1 += c2;
    }


    Complex operator*=(const Complex& other) // оператор *=
    {
        double r = num_c * other.num_c - num_o * other.num_o;
        double i = num_c * other.num_o + num_o * other.num_c;
        num_c = r;
        num_o = i;
        return *this;
    }


    friend Complex operator*(Complex num_1, const Complex& num_2) // оператор *
    {
        return num_1 *= num_2;
    }


    Complex& operator++() // префиксный оператор ++
    {
        ++num_c;
        return *this;
    }


    Complex operator++(int) // постфиксный оператор ++
    {
        Complex temp(*this);
        ++(*this);
        return temp;
    }


    friend std::istream& operator>>(std::istream& in, Complex& other) // оператор ввода
    {
        in >> other.num_c;
        in >> other.num_o;
        return in;
    }


    friend std::ostream& operator<<(std::ostream& out, const Complex& other) // оператор вывода
    {
        if (other.num_o >= 0)
        {
            out << other.num_c << " + " << other.num_o << "i";
            return out;
        }
        else
        {
            out << other.num_c << " - " << abs(other.num_o) << "i";
            return out;
        }
    }
};

int main()
{
    Complex a(2, 3);
    Complex b(4, 5);
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    Complex c = a + b;
    std::cout << c << std::endl;
    std::cout << a * b << std::endl;

    a += b;
    std::cout << a << std::endl;
    a *= b;
    std::cout << a << std::endl;

    std::cout << ++a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    Complex e;
    std::cin >> e;
    std::cout << e << std::endl;

    return 0;
}
