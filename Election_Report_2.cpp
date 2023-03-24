#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long int ullint;
typedef unsigned short int usint;

int main()
{
    ullint Takahashi, Aoki, quotient;
    usint N, T, A, i;

    cin >> N;

    Takahashi = Aoki = 1;

    for (i = 0; i < N; i++)
    {
        cin >> T >> A;

        quotient = max(ceil(Takahashi / (float)T), ceil(Aoki / (float)A));

        Takahashi = T * quotient;
        Aoki = A * quotient;
    }

    cout << Takahashi + Aoki << endl;

    return 0;
}