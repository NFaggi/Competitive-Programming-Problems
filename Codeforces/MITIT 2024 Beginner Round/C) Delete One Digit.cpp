//Link: https://codeforces.com/gym/104936/problem/C
//Score: 100/100
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    bool un=0, dos=0;
    long long sum=0,i;
    string s;
    cin >> s;
    for(i=0; i<int(s.size()); i++)
    {
        sum+=(s[i]-'0');
        if(s[i]=='1')
            un=1;
        else
            dos=1;
    }
    if(un==0)
    {
        cout << s << ' ' << 2 << '\n';
        return;
    }
    else if(dos==0)
    {
        if(int(s.size())%2!=0)
            s.pop_back();
        cout << s << ' ';
        for(i=0; i<int(s.size())-1; i++)
        {
            if(i%2==0)
                cout << 1;
            else
                cout << 0;
        }
        cout << '\n';
        return;
    }
    if(sum%9==0)
    {
        cout << s << ' ' << 9 << '\n';
        return;
    }
    if(sum%3==0)
    {
        cout << s << ' ' << 3 << '\n';
        return;
    }
    if(un)
    {
        sum--;
        if(sum%9==0)
        {
            for(i=0; i<int(s.size()); i++)
            {
                if(s[i]=='1')
                {
                    s.erase(s.begin()+i);
                    break;
                }
            }
            cout << s << ' ' << 9 << '\n';
            return;
        }
        if(sum%3==0)
        {
            for(i=0; i<int(s.size()); i++)
            {
                if(s[i]=='1')
                {
                    s.erase(s.begin()+i);
                    break;
                }
            }
            cout << s << ' ' << 3 << '\n';
            return;
        }
        sum++;
    }
    if(dos)
    {
        sum--;
        sum--;
        if(sum%9==0)
        {
            for(i=0; i<int(s.size()); i++)
            {
                if(s[i]=='2')
                {
                    s.erase(s.begin()+i);
                    break;
                }
            }
            cout << s << ' ' << 9 << '\n';
            return;
        }
        if(sum%3==0)
        {
            for(i=0; i<int(s.size()); i++)
            {
                if(s[i]=='2')
                {
                    s.erase(s.begin()+i);
                    break;
                }
            }
            cout << s << ' ' << 3 << '\n';
            return;
        }
        sum++;
        sum++;
    }

}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
