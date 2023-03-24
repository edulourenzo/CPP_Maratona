#include <iostream>

using namespace std;

int main()
{
    int soma = 0;
    int total = 0;
    for(int i=1; i < 9; i++){
        cout << 840/i << endl;
        total+=840/i;
    }
    cout << "840: " << total << endl;

    double c = 0.368;
    for(int i=1; i < 9; i++){
        cout << c/i << endl;
    }
    
    cout << endl;

    for(int i=1; i < 9; i++)
    {
        cout << 210/i << endl;
        soma += 210/i;
    }

    cout << (double)soma/210.0F << endl;

    return 0;
}