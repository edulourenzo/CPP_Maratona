#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

#define MIN 0xBFFFFFFF

using namespace std;

int main()
{
    int M;
    int i, j, aux;
    vector<int>::iterator maxDP;

    cin >> M;

    vector<vector<int> > triangle(M + 1);

    triangle[0].push_back(MIN);
    triangle[0].push_back(MIN);
    for(i = 1; i <= M; i++)
    {
        triangle[i].push_back(MIN);
        for(j = 1; j <= i; j++)
        {
            cin >> aux;
            triangle[i].push_back(aux);
        }
        triangle[i].push_back(MIN);
    }

    for(i = 2; i <= M; i++)
        for(j = 1; j <= i; j++)
            triangle[i][j] += max(triangle[i-1][j], triangle[i-1][j-1]);


    maxDP = max_element(triangle[M].begin(), triangle[M].end());
    
    cout << *maxDP << endl; 

    return 0;
}