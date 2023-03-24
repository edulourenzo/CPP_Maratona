#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

//Fazer o triângulo de Pascal
//Fazer o Crivo de Eratóstenes
//Fatorar a ultima linha do Triangulo com o Crivo
//Montar o binomio


int main()
{
    int T, N, R, P, E, i, j, k, max_in, max_pasc;
    vector<int> my_input, crivo;
    pair<int, int> my_pair;

    string poly;


    cin >> T;

    max_in = 0;
    for(i = 0; i < T; i++)
    {
        cin >> N;
        my_input.push_back(N);
        if(N > max_in)
            max_in = N;
    }


    max_in++;

    //	###	TRIANGULO DE PASCAL	###
    vector<vector<int> >pascal(max_in, vector<int>(max_in));
    for(i = 0; i < max_in; i++)
    {
        pascal[i][i] = 1;
        pascal[i][0] = 1;
    }

    for(i = 2; i < max_in; i++)
    {
        for(j = 1; j < i; j++)
        {
            pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
        }
    }

    /*IMPRESSAO
    for(i = 0; i < max_in; i++)
    {
        for(j = 0; j <= i; j++)
        {
            cout << pascal[i][j] << " ";
        }
        cout << endl;
    }
	*/


    //	###	Crivo de Erastostenes	###
    max_pasc = pascal[max_in - 1][(max_in/2)];
    vector<bool> prime(max_pasc + 1);

    for(i = 0; i <= max_pasc; i++)
        prime[i] = true;

    for(i = 2; i <= max_pasc; i++)
    {
        if(prime[i])
        {
            crivo.push_back(i);
            for(j = i+i; j <= max_pasc; j+=i)
                prime[j] = false;
        }
    }

    /* IMPRESSAO
    for(i = 0; i < crivo.size(); i++)
        cout << crivo[i] << " ";
     cout << endl;
     */

     //	###	FATORACAO	###
     vector<vector<pair<int, int> > >fator(max_pasc + 1);
     for(i = 1; i < max_in; i++)
    {
        for(j = 1; j < i; j++)
        {
			N = pascal[i][j];
			if(fator[N].empty())
			{
				cout << "FATORES DE " << N << endl;
                R = N;
				for(k = 0; crivo[k] <= N; k++)
				{
					P = crivo[k];
					E = 0;
					while(R % P == 0 && R >= P)
					{
						R /= P;
						E++;
					}
					if(E > 0)
                    {
					    fator[N].push_back(make_pair(P, E));
                        cout << "(" << P << "," << E << ") ";
                    }
				}
                cout << "\n\n";
                //for(int l = 0; l < fator[N].size(); l++)
                    //cout << "(" << fator[N][l].first << "," << fator[N][l].second << ") ";
                cout << endl;
			}
        }
    }

    /*
	for(i = 0; i < T; i++)
	{
		N = my_input[i];
		if(N > 1)
		{
			poly = "";
			poly += "A^" +  to_string(N);
			for(j = 1; j < N; j++)
			{
			}
			poly += "+B^" + to_string(N);
			cout << poly << endl;
		}
		else if(N == 1)
			cout << "A+B" << endl;
		else
			cout << "1" << endl;
	}
    */

    return 0;
}
