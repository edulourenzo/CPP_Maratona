#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<map>

using namespace std;

char T9[] ={
                    '2', '2', '2',  '3', '3', '3',
'4', '4', '4',      '5', '5', '5',  '6', '6', '6',
'7', '7', '7', '7', '8', '8', '8',  '9', '9', '9', '9'};

char CtoT9(char c)
{
    int idx;
    idx = c - 'a';
    return T9[idx];
}

string convert(string word)
{
    string result;
    int i;

    for(i = 0; i < word.size(); i++)
        result += CtoT9(word[i]);
    
    return result;
}


int main()
{
    map<string, vector<string> > dict;
    map<string, vector<string> >::iterator it;
    string input, number, ans;
    int N, qtt;
    int i, aux;
    bool multiple;

    cin >> N;

    for(i = 0; i < N; i++)
    {
        cin >> input;
        number = convert(input);
        dict[number].push_back(input);
    }

    multiple = false;
    qtt = 1;


    while(cin >> input)
    {   
        it = dict.find(input);
        if(it != dict.end())
        {
            qtt *= it->second.size();

            if(it->second.size() > 1)
                multiple = true;
            else if(!multiple)
            {
                if(ans.size() > 0)
                    ans += " ";
                ans += it->second.front();
            }
        }
        else
        {
            cout << "not a valid text" << endl;
            return 0;
        }
    }

    if(multiple)
        cout << "there are " << qtt << " possible messages" << endl;
    else
        cout << ans << endl;

    return 0;
}