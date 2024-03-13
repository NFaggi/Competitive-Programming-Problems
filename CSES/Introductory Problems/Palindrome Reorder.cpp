#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string n;
  string s;
  int impar=0;
  vector <int> letras(26,0);
  cin >> n;
  for(int i=0; i<n.size(); i++)
  {
      int letra = int(n[i])-65;
      letras[letra]++;
      
  }
  for(int i=0;i<letras.size(); i++)
  {
      if(letras[i]%2!=0)
      {
          impar++;
          char l=i+65;
          s=l;
          letras[i]--;
      }
      
     
  }
 
  if (impar>1)
  {
      cout << "NO SOLUTION";
  }
  else if(impar==1)
  {
      for(int i=0; i<letras.size(); i++)
      {
          int cant = letras[i]/2;
          for(int j=0; j<cant; j++)
          {
              char l = i+65;
              s+=l;
          }
      }
      for(int i=s.size()-1; i>0; i--)
          cout << s[i];
      cout << s;
  }
  else
  {
      
      for(int i=0; i<letras.size(); i++)
      {
          int cant = letras[i]/2;
          for(int j=0; j<cant; j++)
          {
              char l = i+65;
              s+=l;
              
          }
      }
      for(int i=s.size()-1; i>=0; i--)
          cout << s[i];
      cout << s;
  }
  return 0;
}
