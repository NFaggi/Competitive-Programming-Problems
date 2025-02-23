//Link: https://jutge.org/problems/P35586_en/statement
#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define forn(i,n) for(i=0; i<n; i++)
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second
using namespace std;

const int MAXN=1e5+100;
const int S=317;

vector<pair<ll,pair<ll,ll>>> qs[S+1];

ll gauss[MAXN], cants[MAXN], v[MAXN], sGauss[MAXN], ans[MAXN];

void preCalc()
{
    for(ll i=1; i<MAXN; i++)
    {
        gauss[i]=gauss[i-1]+i;
        sGauss[i]=gauss[i]+sGauss[i-1];
    }
}

bool comp(const pair<ll,pair<ll,ll>> & a, const pair<ll,pair<ll,ll>> & b)
{
    return a.se.fr < b.se.fr;
}

void MO()
{
    ll i, igs=0, l=-1, r=-1, j, L, R, k, tam, difs, res=0, pref=0;
    for(i=0; i<=S; i++)
    {
        for(j=0; j<sz(qs[i]); j++)
        {
            L=qs[i][j].fr;
            R=qs[i][j].se.fr;
            if((R-L)+1<3)
            {
                ans[qs[i][j].se.se]=0;
                continue;
            }
            if(r<L||R<l)
            {
                igs=0;
                pref=0;
                if(l!=-1)
                    for(k=l; k<=r; k++)
                    {
                        cants[v[k]]--;
                    }
                l=L;
                r=L;
                cants[v[l]]++;
            }
            if(l<L)
            {
                for(l; l<L; l++)
                {
                    tam=(r-l)+1;
                    difs=tam-cants[v[l]];
                    pref-=gauss[cants[v[l]]-1];
                    igs-=pref;
                    if(cants[v[l]]>=2)
                    {
                        igs-=sGauss[cants[v[l]]-2];
                    }
                    cants[v[l]]--;
                    if(cants[v[l]]>=2)
                    {
                        igs+=sGauss[cants[v[l]]-2];
                    }
                    igs-=cants[v[l]]*difs;
                    if(cants[v[l]]>0)
                        pref+=gauss[cants[v[l]]-1];
                }
                l=L;
            }
            else if(l>L)
            {
                l--;
                for(l; l>=L; l--)
                {
                    tam=(r-l);
                    difs=tam-cants[v[l]];
                    if(cants[v[l]]>0)
                        pref-=gauss[cants[v[l]]-1];
                    igs+=pref;
                    igs+=cants[v[l]]*difs;
                    if(cants[v[l]]>=2)
                    {
                        igs-=sGauss[cants[v[l]]-2];
                    }
                    cants[v[l]]++;
                    if(cants[v[l]]>=2)
                    {
                        igs+=sGauss[cants[v[l]]-2];
                    }
                    pref+=gauss[cants[v[l]]-1];
                }
                l=L;
            }

            if(r>R)
            {
                for(r; r>R; r--)
                {
                    tam=(r-l)+1;
                    difs=tam-cants[v[r]];
                    pref-=gauss[cants[v[r]]-1];
                    igs-=pref;
                    if(cants[v[r]]>=2)
                    {
                        igs-=sGauss[cants[v[r]]-2];
                    }
                    cants[v[r]]--;
                    if(cants[v[r]]>=2)
                    {
                        igs+=sGauss[cants[v[r]]-2];
                    }
                    igs-=cants[v[r]]*difs;
                    if(cants[v[r]]>0)
                    pref+=gauss[cants[v[r]]-1];
                }
                r=R;
            }
            else if(r<R)
            {
                r++;
                for(r; r<=R; r++)
                {
                    tam=(r-l);
                    difs=tam-cants[v[r]];
                    if(cants[v[r]]>0)
                        pref-=gauss[cants[v[r]]-1];
                    igs+=pref;
                    igs+=cants[v[r]]*difs;
                    if(cants[v[r]]>=2)
                    {
                        igs-=sGauss[cants[v[r]]-2];
                    }
                    cants[v[r]]++;
                    if(cants[v[r]]>=2)
                    {
                        igs+=sGauss[cants[v[r]]-2];
                    }
                    pref+=gauss[cants[v[r]]-1];
                }
                r=R;
            }
            tam=(r-l)+1;
            ans[qs[i][j].se.se]=sGauss[tam-2]-igs;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i, x, num=1, a, b;
    preCalc();

    while(cin >> n)
    {
        num=1;
        for(i=0; i<=S; i++)
            qs[i].resize(0);
        vector<pair<ll,pair<ll,ll>>>qrs;
        map<ll,ll>m;
        for(i=0; i<n; i++)
        {
            cin >> x;
            if(m.find(x)==m.end()){
                m[x] = num++;
            }
            v[i]=m[x];
        }
        for(i=0; i<n; i++)
        {
            cin >> a >> b;
            qrs.pb({a,{b,i}});
        }
        sort(all(qrs));
        for(i=0; i<n; i++)
            qs[qrs[i].fr/S].pb({qrs[i].fr,{qrs[i].se.fr,qrs[i].se.se}});
        for(i=0; i<=S; i++)
        {
            if(sz(qs[i])==0)
                continue;
            sort(all(qs[i]),comp);
        }
        MO();
        for(i=0; i<n; i++)
        {
            cout << ans[i] << '\n';
            ans[i]=0;
            cants[v[i]]=0;
            v[i]=0;
        }
        cout << "----\n";
    }
    return 0;
}
