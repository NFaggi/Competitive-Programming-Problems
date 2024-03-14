#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    queue<string>q;
    set<string>v;
    q.push(s);
    if(s.size()==1)
    {
        cout << 1 << endl << s;
        return 0;
    }
    while(q.size())
    {
        char aux;
        s=q.front();
        aux=s[s.size()-2];
        s[s.size()-2]=s[s.size()-1];
        s[s.size()-1]=aux;
        q.pop();
        if(v.count(s)>0)
            continue;
            v.insert(s);
            q.push(s);
        
        for(int i=3; i<=s.size(); i++)
        {
            aux=s[s.size()-i];
            s[s.size()-i]=s[s.size()+1-i];
            s[s.size()+1-i]=aux;
            q.push(s);
        }
        }
    
    cout << v.size() << endl;
    for(auto i:v)
        cout << i << '\n';
    return 0;
}