#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

int main()
{
    int n, k;
    int i;
    
    cin >> n >> k;

    string zeros(n-k, '0');
    string ones(k, '1');

    ones += zeros;
    
    do
    {
        cout << ones << endl;
    } while(prev_permutation(ones.begin(), ones.end()));

    return 0;
}



/*int main()
{
    int n, k;
    int head, tail, split, pivot;
    int i, j, l;

    cin >> n >> k;

    string pattern;
    string zero(n, '0');
    string one(k, '1');

    cout << pattern << endl;

    tail = n - 1;
    for (head = 0; head <= n - k; head++)
    {
        //movendo blocos de 1's
        pattern = zero;
        pattern.replace(head, k, one);
        cout << "H:" << head << " P:" << head << " T:" << tail << "\t";
        cout << pattern << endl;

        //seleciona o ultimo 1
        for (split = head + k - 1; split >= head; split--)
        {
            //move o ultimo 1 para o final dos 0's
            for (pivot = split; pivot < tail; pivot++)
            {
                swap(pattern[pivot], pattern[pivot + 1]);
                cout << "H:" << head << " P:" << pivot << " T:" << tail << "\t";
                cout << pattern << endl;
            }
            tail--;
        }
    }

    return 0;
}*/