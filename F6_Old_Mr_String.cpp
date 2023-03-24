#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string oneStr, twoStr;
    vector<int> oneNum(26, 0), twoNum(26, 0);
    int i;

    cin >> oneStr;
    cin >> twoStr;

    for (i = 0; i < oneStr.size(); i++)
        oneNum[oneStr[i] - 'a']++;

    for (i = 0; i < twoStr.size(); i++)
        twoNum[twoStr[i] - 'a']++;

    for (i = 25; i >= 0; i--)
    {
        if (oneNum[i] != twoNum[i])
            break;
    }

    if (i < 0)
        cout << "The two strings are the same age" << endl;
    else if (oneNum[i] > twoNum[i])
        cout << "First string is older" << endl;
    else
        cout << "First string is younger" << endl;

    return 0;
}