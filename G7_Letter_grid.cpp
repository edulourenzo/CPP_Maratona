#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef unsigned long long int ulli;
typedef vector<vector<char> > D2C;
typedef vector<char> D1C;

int X[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int Y[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

int mod(int a, int b)
{
   return (b + (a%b)) % b;
}

ulli recusive(int l, int c, int s, D2C grid, int H, int W, D1C word, int L)
{
    bool next;
    ulli sum;
    int i, indX, indY;

    sum = 0;
    if(s == L)
        return 1;
    else //if(s < L)
    {
        sum = 0; 
        if(grid[l][c] == word[s])
        {
            sum++;
            for(i = 0; i < 9; i++)
            {
                indX = mod(l + X[i], H);
                indY = mod(c + Y[i], W);
                if(grid[indX][indY] == word[s+1])
                {
                    sum += recusive(indX, indY, s+1, grid, H, W, word, L);
                }
            }

        }
        return sum;
    }   
}

int main()
{
    //Weight and Width of grid; Length of the word;
    int H, W, L;
    ulli ans;
    char auxC;
    int i, j;

    //Leitura dos parametros;
    scanf("%d %d %d\n", &H, &W, &L);

    D2C myGrid(H, D1C(W));
    D1C myWord(L);

    //Leitura da Tabela
    for(i = 0; i < H; i++)
    {
        for(j = 0; j < W; j++)
        {
            scanf("%c", &auxC);
            myGrid[i][j] = auxC;
        }
        scanf("%c", &auxC);
    }

    //Leitura da palavra;
    for(i = 0; i < L; i++)
    {
        scanf("%c", &auxC);
        myWord[i] = auxC;
    }
    scanf("%c", &auxC);

    //Recursao;
    ans = 0;
    for(i = 0; i < H; i++)
    {
        for(j = 0; j < W; j++)
        {
            if(myGrid[i][j] == myWord[0])
                ans += recusive(i, j, 0, myGrid, H, W, myWord, L);
        }
    }

    cout << "Recursao: " << ans << endl;

    return 0;
}