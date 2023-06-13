#include <iostream>


using namespace std;


int main()
{
    const int n = 10;
    int A[n] = {10,2,-100,1,2, 300, -4, 1, 2, 3};
    int B[n];

    cout << "A: ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    const long long* a = (const long long*)A;
    long long* b = (long long*)B;
    for (int i = 0; i < (sizeof(A[n]) * n / sizeof(long long)); i++)
    {
        *(b++) = *(a++);
    }

    cout << "B: ";
    for (int i = 0; i < n; i++)
    {
        cout << B[i] << " ";
    }
    return 0;
}