//Score: 100/100
#include <bits/stdc++.h>

using namespace std;
vector<vector<int>>grafo;
vector<int>cantHijos;
vector<int>cNec;
int DFS(int nod, int pad)
{
  if(int(grafo[nod].size())==0)
    return 1;
  int sum=0, i=0;
  vector<int>cH(cantHijos[nod]);
  for(auto k:grafo[nod])
  {
    if(k!=pad)
    {
      cH[i]=DFS(k,nod);
      i++;
    }
  }
  sort(cH.begin(),cH.end());
  for(i=0; i<cNec[nod]; i++)
  {
    sum+=cH[i];
  }
  return sum;
}
int petitorios(int T, vector<int> &jefes)
{
  int n=int(jefes.size()), i;
  double t=double(T);
  t=t/100;
  cantHijos.resize(n+1,0);
  grafo.resize(n+1);
  cNec.resize(n+1,0);
  for(i=0; i<n; i++)
  {
    grafo[jefes[i]].push_back(i+1);
    cantHijos[jefes[i]]++;
  }
  for(i=0; i<=n; i++)
  {
    double res = ceil(double(cantHijos[i])*t);
    cNec[i]=res;
  }
  return DFS(0, -1);
}
