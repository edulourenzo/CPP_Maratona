#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string input;
    vector<int> accum(26, 0);
    int i;
    bool isPair;

    cin >> input;

    for (i = 0; i < input.size(); i++)
        accum[input[i] - 'a']++;

    isPair = true;
    for (i = 0; i < 26; i++)
    {
        if (accum[i] && accum[i] != 2)
        {
            isPair = false;
            break;
        }
    }

    if (isPair)
        cout << input << " --- pair isograms" << endl;
    else
        cout << input << " --- not pair isograms" << endl;

    return 0;
}