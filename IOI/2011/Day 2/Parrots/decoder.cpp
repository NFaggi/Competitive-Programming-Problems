#include "decoder.h"
#include "decoderlib.h"
#include <bits/stdc++.h>
using namespace std;
void decode(int N, int L, int X[])
{
    int i,j,a,b,pos,par,num;
    vector<vector<int>>v(N,vector<int>(4,0));
    for(i=0; i<L; i++)
    {
        pos=X[i];
        pos=pos>>2;
        par=(X[i]^(pos<<2));
        v[pos][par]++;
    }
    for(i=0; i<N; i++)
    {
        num=0;
        if(v[i][0]==4)
        {
            output(255);
            continue;
        }
        else if(v[i][1]==4)
        {
            output(254);
            continue;
        }
        else if(v[i][2]==4)
        {
            output(251);
            continue;
        }
        else if(v[i][3]==4)
        {
            output(239);
            continue;
        }
        else if(v[i][0]==5)
        {
            output(191);
            continue;
        }
        for(j=3; j>=0; j--)
        {
            if(v[i][j]==3)
            {
                num=num<<1;
                num++;
                num=num<<1;
                num++;
            }
            else if(v[i][j]==1)
            {
                num=num<<2;
                num++;
            }
            else if(v[i][j]==2)
            {
                num=num<<1;
                num++;
                num=num<<1;
            }
            else
            {
                num=num<<2;
            }
        }
        output(num);
    }
}
