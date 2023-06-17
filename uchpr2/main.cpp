#include <iostream>


using namespace std;

template <typename arr>
void Copy(arr* input, arr* output, int l)
{
    const long long* a = (const long long*)input;
    long long* b = (long long*)output;
    for (int i = 0; i < (sizeof(input[l]) * l / sizeof(long long)); i++)
    {
        *(b++) = *(a++);
    }
    char* a2 = (char*)a;
    char* b2 = (char*)b;
    for (int i = 0; i < (sizeof(input[l]) * l) % sizeof(long long); i++)
    {
        *(b2++) = *(a2++);
    }
}


int main()
{
    const int n = 4;
    short int A[n] = {2, -7, 3, 5};
    short int B[n];

    cout << "A: ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    Copy(A, B, n);

    cout << "B: ";
    for (int i = 0; i < n; i++)
    {
        cout << B[i] << " ";
    }
    return 0;
}
