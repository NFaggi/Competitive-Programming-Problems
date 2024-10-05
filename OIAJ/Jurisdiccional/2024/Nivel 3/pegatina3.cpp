//Score: 100/100
#include <bits/stdc++.h>

using namespace std;

string pegatina(int N, int K)
{
  int num=K;
  string s="";
  while(num<=N)
  {
    s+=to_string(num);
    num+=K;
  }
  return s;
}
