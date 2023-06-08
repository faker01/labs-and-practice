#include <iostream>


template<typename VCTR>
class Vector
{
private:
    VCTR* v;
    int s = 0;
public:
    Vector()
    {
        VCTR* v = new VCTR[s];
    }
    ~Vector()
    {
        delete[] v;
    }
    VCTR push_back(bool inp)
    {
        return v[s++] = inp;
    }
    bool& operator[](int ind)
    {
        return v[ind];
    }
    int size()
    {
        return s;
    }
    VCTR insert(bool inp, int ind)
    {
        int k = s;
        VCTR* v1 = v;
        while (s > 0)
        {
            v[s--];
        }
        for (int i = 0; i < k - 1; i++)
        {
            if (i == ind)
            {
                v[s++] = inp;
            }
            v[s++] = v1[i];

        }
        return v;
    }
    VCTR erase(int s_i, int c=1)
    {
        int k = s + 1;
        VCTR* v1 = v;
        while (s > 0)
        {
            v[s--];
        }
        for (int i = 0; i < k; i++)
        {
            if (i < s_i or i > s_i + c - 1)
            {
                v[s++] = v1[i];
            }
        }
        return v;
    }
};


int main() {
    Vector<bool> vec;
    vec.push_back(1);
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(1);
    std::cout << vec[0] << std::endl;
    std::cout << vec[1] << std::endl;
    std::cout << vec[2] << std::endl;
    std::cout << vec[3] << std::endl;
    std::cout << vec.size() << std::endl;
    vec.erase(1, 2);
    std::cout << vec[0] << std::endl;
    std::cout << vec[1] << std::endl;
    std::cout << vec.size() << std::endl;
    vec.insert(0, 1);
    std::cout << vec[1] << std::endl;
    vec[1] = 1;
    std::cout << vec[1] << std::endl;
    std::cout << vec.size() << std::endl;
    return 0;
}
