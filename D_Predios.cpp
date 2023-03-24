#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> edifice;
    int peaks, troughs;
    int N, input;
    int i;

    cin >> N;

    for (i = 0; i < N; i++)
    {
        cin >> input;
        edifice.push_back(input);
    }

    peaks = troughs = 0;

    for (i = 1; i < N - 1; i++)
    {
        cout << "analisando " << edifice[i] << "..." << endl; 
        if (edifice[i - 1] < edifice[i] && edifice[i] > edifice[i + 1])
        {
            cout << edifice[i] << " eh um pico" << endl;
            peaks++;
        }
        if (edifice[i - 1] > edifice[i] && edifice[i] < edifice[i + 1])
        {
            cout << edifice[i] << " eh uma depressao" << endl;
            troughs++;
        }
    }

    cout << peaks << " " << troughs << endl;

    return 0;
}