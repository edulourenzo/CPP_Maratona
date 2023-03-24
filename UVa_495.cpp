#include<cstdin>
#include<iostream>
#include<cstdio>
#include<stdlib>

using namespace std;

vector<uint8_t> adde(vector<uint8_t>, vector<uint8_t>);

int main()
{
    vector<uint8_t> primus, secundus, result;

    primus.push_back(0xff);
    secundus.push_back(0xff);

    result = adde(primus, secundus);

    for(int i = 0; i < result.size(); i++)
    {
        printf("%X\n", result[i]);
    }


    return 0;
}

vector<uint8_t> adde(vector<uint8_t> A, vector<uint8_t> B)
{
    vector<uint8_t> C;
    uint16_t r;
    uint8_t vai_um, i, p, s;
    
    
    p = A.size();
    s = B.size();
    vai_um = 0x0;

    for(i = 0; i < p; i++)
    {
        r = (uint16_t)A[i] + (uint16_t)B[i] + vai_um;
        
        if(r > 0x100)
        {
            C.push_back((uint8_t)(r - 0x100));
            vai_um = 0x1;
        }
        else
        {
            C.push_back((uint8_t)r);
            vai_um = 0x0;
        }         
    }
    if(vai_um)
            C.push_back(0x1);

    return C;
}