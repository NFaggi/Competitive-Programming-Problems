//Link: https://codeforces.com/contest/1927/problem/C
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long t, n, m, k, i;
    cin >> t;
    while(t--)
    {
        long long cV=0, cV2=0, a, igu=0;
        cin >> n >> m >> k;
        set<long long>s;
        set<long long>s2;
        for(i=0; i<n; i++)
        {
            cin >> a;
            s.insert(a);
        }
        for(i=0; i<m; i++)
        {
            cin >> a;
            s2.insert(a);
        }
        bool todos=true;
        for(i=1; i<=k; i++)
        {
            bool comp=false;
            std::set<long long>::iterator it;
            if(!s.empty()) it = s.begin();
            std::set<long long>::iterator it2;
            if(!s2.empty()) it2 = s2.begin();
            if(!s.empty()&&!s2.empty())
            {
                if(*it==i&&*it2==i)
                {
                    igu++;
                }
            }
            if(!s.empty())
            {
                if(*it==i)
                {
                    comp=true;
                    cV++;
                    s.erase(it);
                }
            }
            if(!s2.empty())
            {
                if(*it2==i)
                {
                    comp=true;
                    cV2++;
                    s2.erase(it2);
                }
            }
            if(comp==false)
                todos=false;
        }
        if(cV>=k/2&&cV2>=k/2&&todos)
        {
            if(cV-k/2<=igu&&cV2-k/2<=igu)
                cout << "YES";
            else
                cout << "NO";
        }
        else
            cout << "NO";
        cout << endl;

    }
    return 0;
}
