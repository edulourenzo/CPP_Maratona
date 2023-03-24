#include <iostream>
#include <vector>

#define CAT -1

using namespace std;

int main()
{
    int R, C, K;
    int i, j, x, y, up, left;

    cin >> R >> C;

    //Matriz com bordas;
    R += 2;
    C += 2;
    vector<vector<int> > grid(R, vector<int>(C, 0));

    //Inicializando Bordas;
    R--;
    C--;
    for(i = 0; i <= R; i++)
        grid[i][0] = grid[i][C] = CAT;
    
    for(i = 0; i <= C; i++)
        grid[0][i] = grid[R][i] = CAT;
    
    cin >> K;

    //Inserindo "K" gatos;
    for(i = 0; i < K; i++)
    {
        cin >> x >> y;
        grid[x][y] = CAT;
    }

    
    //Calculando os caminhos;
    R--;
    C--;
    grid[1][1] = 1;
    for(i = 1; i <= R; i++)
    {
        for(j = 1; j <= C; j++)
        {
            if(grid[i][j] != CAT)
            {
                up = grid[i-1][j];
                left = grid[i][j-1];
                
                if(up != CAT)
                    grid[i][j] += up;
                if(left != CAT)
                    grid[i][j] += left;
            }
        }
    }

    //Resposta;
    cout << grid[R][C] << endl;

    return 0;
}