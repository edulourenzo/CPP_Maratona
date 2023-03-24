#include <iostream>

using namespace std;

int mod(int a, int b)
{
   return (b + (a%b)) % b;
}

int main()
{
    int i;
    cout << "MOD 3" << endl;

    for(i = -5; i <= 5; i++)
    {
        cout << i << " : " << i%3 << endl;
    }

    cout << endl;

    for(i = -6; i <= 6; i++)
    {
        cout << i << " : " << mod(i, 3) << endl;
    }

    return 0;
}