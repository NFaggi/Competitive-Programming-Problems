//Link: https://oj.uz/problem/view/IOI17_coins
//Score: 100/100
#include <bits/stdc++.h>
using namespace std;
std::vector<int> coin_flips(std::vector<int> b, int c)
{
    bool v[7][64],un,x,mal[7],igu=0,mal2[7];
    vector<int>flip(0);
    memset(v,0,sizeof(v));
    memset(mal,0,sizeof(mal));
    memset(mal2,0,sizeof(mal2));
    int i, j,ca,pos=0, bitMal=-1;
    for(i=1; i<64; i*=2)
    {
        ca=0;
        un=1;
        x=0;
        for(j=i; j<=64; j++)
        {
            if(ca==i)
            {
                un=!un;
                ca=0;
            }
            v[pos][j-1]=un;
            if(un)
                x^=b[j-1];
            ca++;
        }
        mal[pos]=x;
        pos++;
    }
    for(i=0; i<64; i++)
    {
        igu=1;
        for(j=0; j<6; j++)
        {
            if(v[j][i]!=mal[j])
            {
                igu=0;
                break;
            }
        }
        if(igu)
        {
            bitMal=i;
            break;
        }
    }
    if(c==63)
    {
        if(bitMal!=-1)
            flip.push_back(bitMal);

    }
    else if(bitMal==-1)
        flip.push_back(c);
    else if(bitMal!=c)
    {
        for(i=0; i<6; i++)
            if(v[i][c]!=mal[i])
                mal2[i]=1;
        for(i=0; i<64; i++)
        {
            igu=1;
            for(j=0; j<6; j++)
                if(v[j][i]!=mal2[j])
                {
                    igu=0;
                    break;
                }
            if(igu)
            {
                flip.push_back(i);
                break;
            }
        }
    }
    else
        flip.push_back(63);
    return flip;
}

int find_coin(std::vector<int> b)
{
    bool v[7][64],un,x,mal[7],igu=0,mal2[7];
    memset(v,0,sizeof(v));
    memset(mal,0,sizeof(mal));
    memset(mal2,0,sizeof(mal2));
    int i, j,ca,pos=0, bitMal=-1;
    for(i=1; i<64; i*=2)
    {
        ca=0;
        un=1;
        x=0;
        for(j=i; j<=64; j++)
        {
            if(ca==i)
            {
                un=!un;
                ca=0;
            }
            v[pos][j-1]=un;
            if(un)
                x^=b[j-1];
            ca++;
        }
        mal[pos]=x;
        pos++;
    }
    for(i=0; i<64; i++)
    {
        igu=1;
        for(j=0; j<6; j++)
            if(v[j][i]!=mal[j])
            {
                igu=0;
                break;
            }
        if(igu)
        {
            bitMal=i;
            break;
        }
    }
    if(bitMal==-1)
        return 63;
    else
        return bitMal;
}
