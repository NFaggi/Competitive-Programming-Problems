#include "encoder.h"
#include "encoderlib.h"
#include <bits/stdc++.h>
using namespace std;
void encode(int N, int M[])
{
    int i, j, pot, part,num;
    for(i=0; i<N; i++)
    {
        num=0;
        pot=1;
        if(M[i]==255)
        {
            num=i;
            num=num<<2;
            num+=0;
            send(num);
            send(num);
            send(num);
            send(num);
            continue;
        }
        else if(M[i]==254)
        {
            num=i;
            num=num<<2;
            num+=1;
            send(num);
            send(num);
            send(num);
            send(num);
            continue;
        }
        else if(M[i]==251)
        {
            num=i;
            num=num<<2;
            num+=2;
            send(num);
            send(num);
            send(num);
            send(num);
            continue;
        }
        else if(M[i]==239)
        {
            num=i;
            num=num<<2;
            num+=3;
            send(num);
            send(num);
            send(num);
            send(num);
            continue;
        }
        else if(M[i]==191)
        {
            num=i;
            num=num<<2;
            num+=0;
            send(num);
            send(num);
            send(num);
            send(num);
            send(num);
            continue;
        }
        else if(M[i]==250)
        {
            num=i;
            num=num<<2;
            num+=1;
            send(num);
            send(num);
            send(num);
            send(num);
            send(num);
            continue;
        }
        else if(M[i]==190)
        {
            num=i;
            num=num<<2;
            num+=2;
            send(num);
            send(num);
            send(num);
            send(num);
            send(num);
            continue;
        }
        else if(M[i]==238)
        {
            num=i;
            num=num<<2;
            num+=3;
            send(num);
            send(num);
            send(num);
            send(num);
            send(num);
            continue;
        }
        else if(M[i]==175)
        {
            num=i;
            num=num<<2;
            num+=0;
            send(num);
            send(num);
            send(num);
            send(num);
            send(num);
            send(num);
            continue;
        }
        else if(M[i]==187)
        {
            num=i;
            num=num<<2;
            num+=1;
            send(num);
            send(num);
            send(num);
            send(num);
            send(num);
            send(num);
            continue;
        }
        else if(M[i]==235)
        {
            num=i;
            num=num<<2;
            num+=2;
            send(num);
            send(num);
            send(num);
            send(num);
            send(num);
            send(num);
            continue;
        }
        else if(M[i]==127)
        {
            num=i;
            num=num<<2;
            num+=3;
            send(num);
            send(num);
            send(num);
            send(num);
            send(num);
            send(num);
            continue;
        }
        else if(M[i]==223)
        {
            num=i;
            num=num<<2;
            num+=0;
            send(num);
            send(num);
            send(num);
            send(num);
            send(num);
            send(num);
            send(num);
            continue;
        }
        else if(M[i]==247)
        {
            num=i;
            num=num<<2;
            num+=1;
            send(num);
            send(num);
            send(num);
            send(num);
            send(num);
            send(num);
            send(num);
            continue;
        }
        else if(M[i]==253)
        {
            num=i;
            num=num<<2;
            num+=2;
            send(num);
            send(num);
            send(num);
            send(num);
            send(num);
            send(num);
            send(num);
            continue;
        }
        for(j=0; j<4; j++)
        {
            num=i;
            num=num<<2;
            num+=j;
            if((M[i]&pot)>0&&(M[i]&(pot*2))>0)
            {
                send(num);
                send(num);
                send(num);
            }
            else if((M[i]&pot)>0)
            {
                send(num);
            }
            else if((M[i]&(pot*2))>0)
            {
                send(num);
                send(num);
            }
            pot*=2;
            pot*=2;
        }
    }
}
