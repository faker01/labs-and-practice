#include <iostream>
#include <cstring>


class String {
private:
    size_t size;
    char* str;

public:
    String(): size(0), str(nullptr) {}

    ~String()
    {
        delete[] str;
    }

    String(const String& other)
    {
        if (other.str == nullptr)
        {
            str = nullptr;
            size = 0;
        }
        else
        {
            size = other.size;
            str = new char[size + 1];
            strcpy_s(str, size + 1, other.str);
        }
    }

    String& operator=(const String& other)
    {
        size = other.size;
        str = new char[size + 1];
        strcpy_s(str, size + 1, other.str);
        return *this;
    }

    String operator+(const String& other) const
    {
        String res;
        res.size = size + other.size;
        res.str = new char[res.size + 1];
        strcpy_s(res.str, res.size + 1, str);
        strcat_s(res.str, res.size + 1, other.str);
        return res;
    }

    String& operator +=(const String& other)
    {
        char* res = new char[size + other.size + 1];
        strcpy_s(res, size + other.size + 1, str);
        strcat_s(res, size + other.size + 1, other.str);
        delete[] str;
        str = res;
        size = size + other.size;
        return *this;
    }

    char& operator[](size_t i)
    {
        return str[i];
    }

    bool operator < (const String& other)
    {
        return std::strcmp(str, other.str) < 0;
    }

    bool operator > (const String& other)
    {
        return std::strcmp(str, other.str) > 0;
    }

    bool operator == (const String& other)
    {
        return std::strcmp(str, other.str) == 0;
    }

    friend std::ostream& operator<<(std::ostream& os, const String& s)
    {
        os << s.str;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, String& s)
    {
        const int m_s = 256;
        char buffer[m_s];
        if (is.getline(buffer, m_s)) {
            s.size = std::strlen(buffer);
            s.str = new char[s.size + 1];
            strcpy_s(s.str, s.size + 1, buffer);
        }
        return is;
    }


    int find(char a)
    {
        for (int i = 0; i < size; i++)
        {
            if (str[i] == a)
                return i;
        }
        return -1;
    }
    size_t length() const
    {
        return size;
    }

    char* c_str() const
    {
        return str;
    }

    char& at(int i)
    {
        if ((i >= 0) && (i < size))
        {
            return str[i];
        }
        return str[0];
    }
};


int main() {
    String s1;
    String s2;
    return 0;
}
