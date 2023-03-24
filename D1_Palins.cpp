#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

int main()
{
    map<string, bool> isFirst;
    vector<string> myPalindrome;
    string word, subword;
    int endsubword;
    int i, j, k, l;
    bool isPalindrome;

    cin >> word;

    //i = tamanho;
    //j = posicao;
    //k = iterador normal;
    //l = iterador reverso;
    for(i = 1; i <= word.size(); i++)
    {
        for(j = 0; j < word.size(); j++)
        {
            for(k = j, l = i + j - 1; k < l && word[k] == word[l]; k++, l--)
            {
                /*...*/
            }

            if(k >= l)
            {
                subword = word.substr(j, i);
                if(isFirst.find(subword) == isFirst.end())
                {
                    isFirst[subword] = false;
                    myPalindrome.push_back(subword);
                }
            }
        }
    }

    cout << myPalindrome.size() << " -";
    for(i = 0; i < myPalindrome.size(); i++)
        cout << " \"" << myPalindrome[i] << "\"";
    cout << endl;

    return 0;
}