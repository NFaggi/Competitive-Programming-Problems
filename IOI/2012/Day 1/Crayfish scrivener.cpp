//Link: https://oj.uz/problem/view/IOI12_scrivener
//Score: 100/100
#include <iostream>
#include <vector>

using namespace std;

const int MAXN=1e6+1;
const int LOG=22;

int ti[MAXN][LOG], let[MAXN];

pair<int,int>times[MAXN];

int tim=1, lets=0,ant=0,act, ta=0;

char txt[MAXN];

void Init()
{

}

void update(int tim)
{
    for(int i=1; i<LOG; i++)
    {
        ti[tim][i]=ti[ti[tim][i-1]][i-1];
    }
}

int Undo(int v, int k) {
    for (int i = 0; i < LOG; ++i) {
        if (k & (1 << i)) {
            v = ti[v][i];
            if (v == -1) break;
        }
    }
    return v;
}

vector<int>ord={0}, tam={0};

void TypeLetter(char L)
{
    ti[tim][0]=ant;
    update(tim);
    ant=tim;
    txt[lets]=L;
    let[tim]=lets;
    lets++;
    ord.push_back(tim);
    tam.push_back(ta+1);
    ta++;
    tim++;
}
void UndoCommands(int U)
{
    act=ord[int(ord.size())-(U+1)];
    ant=act;
    ta=tam[int(tam.size())-(U+1)];
    ord.push_back(act);
    tam.push_back(ta);
}

char GetLetter(int P)
{
    P++;
    int sub=tam[int(tam.size())-1]-P;
    int pos=Undo(ant, sub);
    return txt[let[pos]];
}
