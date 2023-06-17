#include <iostream>
#include <cmath>
#include <map>

using namespace std;

class Encryption
{
private:
    int key = 0;
    int len = 0;
    int num_len(int n)
    {
        int l = 0;
        while (n != 0)
        {
            n /= 10;
            l++;
        }
        return l;
    }
    int take_fib(int n)
    {
        int num = 0;
        int fib_series = 12;
        for (int i = 0; i < n - 2; i++)
        {
            num = (fib_series % 10) + ((fib_series / 10) % 10);
            fib_series = fib_series * int(pow(10, num_len(num))) + num;
        }

        return fib_series;
    }
    int take_len(int k)
    {
        int l = 0;
        while (k != 0)
        {
            k /= 10;
            l++;
        }
        return l;
    }
    string take_word_by_index(string text, int ind)
    {
        int n = 0;
        string ans = "";
        for (int i = 0; i < text.size(); i++)
        {

            if (n > ind)
            {
                break;
            }
            if (n == ind)
            {
                ans += text[i];
            }
            if (text[i] == ' ')
            {
                n++;
            }

        }
        return ans;
    }
public:
    Encryption(int k)
    {
        key = k;
        len = take_len(k);
    }
    ~Encryption()
    {
    }
    string encode(string s)
    {
        int f_s = take_fib(len);
        string encoded_string = "";
        map<int, string> str;
        for (int i = 0; i < len; i++)
        {
            str[f_s / int(pow(10, len - i - 1))] = take_word_by_index(s, i);
            f_s = f_s % int(pow(10, len - i - 1));

        }
        for (int i = 0; i < len; i++)
        {
            encoded_string += str[(key / int(pow(10, len - i - 1))) % 10];
        }
        return encoded_string;
    }
    string decode(string s)
    {
        int f_s = take_fib(len);
        string decoded_string = "";
        map<int, string> str;
        for (int i = 0; i < len; i++)
        {
            str[key / int(pow(10, len - i - 1)) % 10] = take_word_by_index(s, i);
        }
        for (int i = 0; i < len; i++)
        {
            decoded_string += str[f_s / int(pow(10, len - i - 1)) % 10];
        }
        return decoded_string;
    }
    int show_key()
    {
        return key;
    }
    int import_new_key(int k)
    {
        key = k;
        len = take_len(k);
    }
};


int main(int argc, char** argv)
{
    string  inp = "Hello, my name is Ivan. ";
    Encryption encrypt_class = 28513;
    /*cout << encrypt_class.show_key()<<endl;*/
    inp = encrypt_class.encode(inp);
    cout << inp << endl;
    inp = encrypt_class.decode(inp);
    cout << inp<<endl;
    return 0;
}
