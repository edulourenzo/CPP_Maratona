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
    if(i.second < j.second)
        return true;
    
    else if(i.second == j.second)
    {
        if(i.first.size() < j.first.size())
            return true;
        else
            return false;
    }
    
    else
        return false;
}

bool comp_trio(trio i, trio j)
{
    return get<1>(i) < get<1>(j);
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
    vector<trio>::iterator maxTrio; 
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

        if (split.size())
        {
            vector<pair<string, int> > DP(split.size());
            vector<pair<string, int> >::iterator maxDP;
            for (j = 0; j < split.size(); j++)
            {
                sufixStr = prefixStr.substr(get<2>(split[j]));
                sufixInt = codexValue(codex, sufixStr);

                if (sufixInt)
                {
                    DP[j].second = get<1>(split[j]) + sufixInt;
                    DP[j].first = sufixStr;
                }
                else
                    DP[j].second = 0;
            }

            maxDP = max_element(DP.begin(), DP.end(), comp_pair);
            if (prefixInt >= maxDP->second)
            {
                split.push_back(make_tuple(prefixStr, prefixInt, prefixStr.size()));
            }
            else if (maxDP->second)
            {
                k = distance(DP.begin(), maxDP);
                word = get<0>(split[k]) + " " + maxDP->first;
                value = maxDP->second;
                original_size = get<2>(split[k]) + maxDP->first.size();
                
                split.push_back(make_tuple(word, value, original_size));
            }
        }
        else if (prefixInt)
        {
            split.push_back(make_tuple(prefixStr, prefixInt, prefixStr.size()));
        }
    }

    maxTrio = max_element(split.begin(), split.end(), comp_trio);
    cout << get<1>(*maxTrio) << endl;
    cout << get<0>(*maxTrio) << endl;
    
    return 0;
}