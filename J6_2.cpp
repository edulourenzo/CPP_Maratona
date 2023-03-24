#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

typedef map<string, int> dict;          // <Key, value>
typedef tuple<string, int, int> trio;    // <split, value, original_size>

bool comp_pair(pair<string, int> i, pair<string, int> j)
{
    return i.second < j.second;
}

int codexValue(dict &codex, string key)
{
    dict::iterator it;

    it = codex.find(key);

    if (it != codex.end())
        return it->second;
    else
        return 0;
}

int main()
{
    dict codex;
    vector<trio> split; //division
    string inscription, word, prefixStr, sufixStr, answer;
    int num_pairs, value, num_char, prefixInt, sufixInt, original_size;
    int i, j, k;

    cin >> inscription;

    cin >> num_pairs;
    for (i = 0; i < num_pairs; i++)
    {
        cin >> word >> value;
        codex[word] = value;
    }

    num_char = inscription.size();
    for (i = 0; i < num_char; i++)
    {
        prefixStr = inscription.substr(0, i + 1);
        prefixInt = codexValue(codex, prefixStr);
        cout << "\nPrefixo: " << prefixStr << " = " << prefixInt << endl;

        if (split.size())
        {
            vector<pair<string, int> > DP(split.size());
            vector<pair<string, int> >::iterator maxDP;
            for (j = 0; j < split.size(); j++)
            {
                sufixStr = prefixStr.substr(get<2>(split[j]));
                sufixInt = codexValue(codex, sufixStr);

                cout << get<0>(split[j]) << " | " << sufixStr << endl;
                cout << get<1>(split[j]) << " | " << sufixInt << endl;

                if (sufixInt)
                {
                    DP[j].second = get<1>(split[j]) + sufixInt;
                    DP[j].first = sufixStr;
                }
                else
                    DP[j].second = 0;
            }
            maxDP = max_element(DP.begin(), DP.end(), comp_pair);

            cout << "Max DP: " << maxDP->second << endl;
            if (prefixInt > maxDP->second)
            {
                cout << "Prefixo > DP: " << prefixInt << endl;
                split.push_back(make_tuple(prefixStr, prefixInt, prefixStr.size()));
            }
            else if (maxDP->second)
            {
                cout << "DP > Prefixo: " << maxDP->first << endl;
                k = distance(DP.begin(), maxDP);
                word = get<0>(split[k]) + " " + maxDP->first;
                value = maxDP->second;
                original_size = get<2>(split[k]) + maxDP->first.size();
                
                split.push_back(make_tuple(word, value, original_size));
            }
        }
        else if (prefixInt)
        {
            cout << "Sem DP e com Prefixo: " << prefixInt << endl;
            split.push_back(make_tuple(prefixStr, prefixInt, prefixStr.size()));
        }
        else
        {
            cout << "Sem DP e sem Prefixo" << endl;
        }
    }

    cout << "SAIDA: " << get<0>(split.back()) << " = " << get<1>(split.back()) << endl;

    return 0;
}