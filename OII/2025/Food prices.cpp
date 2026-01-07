//Score: 100/100
#include <bits/stdc++.h>
#define ll int
#define sz(x) int(x.size())
#define forn(i, n) for (i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second
using namespace std;

const int MAXN = 2e5 + 1;
const int LOG = 18;
const int MOD = 1e9 + 7;
const ll p[2] = {200003, 200009};

vector<ll> comp[MAXN], grafo[MAXN];
pair<ll, ll> rang[MAXN], seg[MAXN * 2], segINV[MAXN * 2];
ll pots[2][MAXN], potsINV[2][MAXN], id[MAXN], n, tot = 1, invs[MAXN], up[MAXN][LOG], depth[MAXN], tams[MAXN];
ll tp[MAXN], idH[MAXN], act;
void conv(pair<ll, ll> &a, pair<ll, ll> &b, pair<ll, ll> &c)
{
    a.fr = (b.fr + c.fr) % MOD;
    a.se = (b.se + c.se) % MOD;
}

void update(ll nod, ll x, ll i)
{
    seg[nod].fr = (1ll*x * pots[0][i]) % MOD;
    seg[nod].se = (1ll*x * pots[1][i]) % MOD;
    nod /= 2;
    while (nod > 0)
    {
        conv(seg[nod], seg[nod * 2], seg[nod * 2 + 1]);
        nod /= 2;
    }
}

void updateINV(ll nod, ll x, ll i)
{
    ll k = n - i + 1;
    segINV[nod].fr = (1ll*x * pots[0][k]) % MOD;
    segINV[nod].se = (1ll*x * pots[1][k]) % MOD;
    nod /= 2;
    while (nod > 0)
    {
        conv(segINV[nod], segINV[nod * 2], segINV[nod * 2 + 1]);
        nod /= 2;
    }
}

ll binpow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (1ll*ans * a) % MOD;
        a = (1ll*a * a) % MOD;
        b >>= 1;
    }
    return ans;
}

ll inv(ll a)
{
    return binpow(a, MOD - 2);
}

ll tam(ll x)
{
    return ((rang[x].se - rang[x].fr + 1) % MOD);
}

void unir(ll a, ll b)
{
    ll x = id[a], y = id[b];
    if (x == y)
        return;
    if (sz(comp[x]) < sz(comp[y]))
        swap(x, y);
    for (auto &k : comp[y])
    {
        id[k] = x;
        comp[x].pb(k);
        update(idH[k] + n, x + 1, depth[k]-depth[tp[k]]+1);
        updateINV(idH[k] + n, x + 1, depth[k]-depth[tp[k]]+1);
    }
    tot = (1ll*tot * inv((1ll*tam(x) * tam(y)) % MOD)) % MOD;
    rang[x].fr = max(rang[x].fr, rang[y].fr);
    rang[x].se = min(rang[x].se, rang[y].se);
    if (rang[x].fr > rang[x].se)
    {
        tot = 0;
        return;
    }
    tot = (1ll*tot * tam(x)) % MOD;
}

void dfs(ll nod)
{
    for(ll j=1; j<LOG; j++)
        up[nod][j]=up[up[nod][j-1]][j-1];
    tams[nod]=1;
    for(auto k:grafo[nod])
    {
        depth[k]=depth[nod]+1;
        up[k][0]=nod;
        dfs(k);
        tams[nod]+=tams[k];
    }
}

void dfsHLD(ll nod, ll pad, ll top, ll prof)
{
    tp[nod]=top;
    idH[nod]=act;
    seg[act+n].fr=(1ll*(nod+1)*pots[0][prof])%MOD;
    seg[act+n].se=(1ll*(nod+1)*pots[1][prof])%MOD;
    segINV[act+n].fr=(1ll*(nod+1)*pots[0][(n-prof)+1])%MOD;
    segINV[act+n].se=(1ll*(nod+1)*pots[1][(n-prof)+1])%MOD;
    act++;
    ll ma=0, mk=0;
    for(auto k:grafo[nod])
    {
        if(k==pad)
            continue;
        if(tams[k]>ma)
        {
            ma=tams[k];
            mk=k;
        }
    }
    if(ma==0)
        return;
    dfsHLD(mk,nod,top,prof+1);
    for(auto k:grafo[nod])
    {
        if(k==pad||k==mk)
            continue;
        dfsHLD(k,nod,k,1);
    }
}

ll k_ans(ll a, ll x)
{
    for(ll i=0; i<LOG; i++)
        if((1<<i)&x)
            a=up[a][i];
    return a;
}

ll lca(ll a, ll b)
{
    if(a==b)
        return a;
    if(depth[a]<depth[b])
        swap(a,b);
    a=k_ans(a,depth[a]-depth[b]);
    if(a==b)
        return a;
    for(ll i=LOG-1; i>=0; i--)
    {
        if(up[a][i]!=up[b][i])
        {
            a=up[a][i];
            b=up[b][i];
        }
    }
    return up[a][0];
}

pair<ll,ll> cal(ll l, ll r, ll t)
{
    pair<ll,ll> L={0,0}, R={0,0};
    while(l<=r)
    {
        if(l==r)
        {
            if(t==0)
                conv(L,L,seg[l]);
            else
                conv(L,L,segINV[l]);
            break;
        }
        if(l%2!=0)
        {
            if(t==0)
                conv(L,L,seg[l++]);
            else
                conv(L,L,segINV[l++]);
        }
        if(r%2==0)
        {
            if(t==0)
                conv(R,R,seg[r--]);
            else
                conv(R,R,segINV[r--]);
        }
            
        l/=2;
        r/=2;
    }
    conv(L,L,R);
    return L;
}
void format(pair<ll,ll>&act, ll x, ll aIn)
{
    if(x==aIn)
        return;
    if(x>aIn)
    {
        act.fr=(1ll*act.fr*pots[0][x-aIn])%MOD;
        act.se=(1ll*act.se*pots[1][x-aIn])%MOD;
    }
    else
    {
        act.fr=(1ll*act.fr*potsINV[0][aIn-x])%MOD;
        act.se=(1ll*act.se*potsINV[1][aIn-x])%MOD;
    }
}
pair<ll,ll> calcUP(ll a, ll b)
{
    pair<ll,ll> sum={0,0}, act;
    ll in=1, dis;
    while(true)
    {
        if(tp[a]!=tp[b])
        {
            act=cal(idH[tp[a]]+n,idH[a]+n,1);
            format(act,in,n-(depth[a]-depth[tp[a]]));
            in+=depth[a]-depth[tp[a]]+1;
            conv(sum,sum,act);
            a=up[tp[a]][0];
        }
        else
        {
            act=cal(idH[b]+n,idH[a]+n,1);
            format(act,in,n-(depth[a]-depth[tp[a]]));
            in+=depth[a]-depth[b]+1;
            conv(sum,sum,act);
            break;
        }
    }
    return sum;
}

pair<ll,ll> calcDOWN(ll a, ll b, ll in)
{
    pair<ll,ll> sum={0,0}, act;
    ll dis;
    while(true)
    {
        if(tp[a]!=tp[b])
        {
            act=cal(idH[tp[a]]+n,idH[a]+n,0);
            format(act,depth[tp[a]]-depth[b]+in,1);
            conv(sum,sum,act);
            a=up[tp[a]][0];
        }
        else
        {
            act=cal(idH[b]+n,idH[a]+n,0);
            format(act,in,depth[b]-depth[tp[a]]+1);
            conv(sum,sum,act);
            break;
        }
    }
    sum.fr=(1ll*sum.fr*potsINV[0][in])%MOD;
    sum.se=(1ll*sum.se*potsINV[1][in])%MOD;
    sum.fr=(sum.fr-(id[b]+1)+MOD)%MOD;
    sum.se=(sum.se-(id[b]+1)+MOD)%MOD;
    sum.fr=(1ll*sum.fr*pots[0][in])%MOD;
    sum.se=(1ll*sum.se*pots[1][in])%MOD;
    return sum;
}


pair<ll,ll> sig(ll a, ll b, ll lab, ll x)
{
    ll inX=x;
    if(x>depth[a]-depth[lab])
    {
        x-=(depth[a]-depth[lab]);
        x=(depth[b]-depth[lab])-x;
        pair<ll,ll>cU=calcUP(a,lab),cD=calcDOWN(k_ans(b,x),lab,(depth[a]-depth[lab])+1);
        conv(cU,cU,cD);
        return cU;
    }
    return calcUP(a,k_ans(a,x));
}

ll nodSig(ll a, ll b, ll lab, ll x)
{
    ll inX=x;
    if(x>depth[a]-depth[lab])
    {
        x-=(depth[a]-depth[lab]);
        x=(depth[b]-depth[lab])-x;
        return k_ans(b,x);
    }
    return k_ans(a,x);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll i, j, m;
    // input
    cin >> n;
    for (i = 0; i < n - 1; i++)
    {
        cin >> j;
        j--;
        grafo[j].pb(i+1);
    }

    for (i = 0; i < n; i++)
        cin >> rang[i].fr >> rang[i].se;

    cin >> m;
    // end input

    // Init
    for (i = 0; i < n; i++)
    {
        id[i] = i;
        comp[i] = {i};
        tot = (1ll*tot * tam(i)) % MOD;
    }
    pots[0][0] = pots[1][0] = 1;
    potsINV[0][0] = potsINV[1][0] = inv(1);
    for (i = 1; i <= n; i++)
        for (j = 0; j < 2; j++)
        {
            pots[j][i] = (1ll*pots[j][i - 1] * p[j]) % MOD;
            potsINV[j][i] = inv(pots[j][i]);
        }
    // end init

    // init HLD

    dfs(0);
    dfsHLD(0,0,0,1);
    // fin init HLD

    // init segtree

    for (i = n - 1; i > 0; i--)
    {
        conv(seg[i], seg[i * 2], seg[i * 2 + 1]);
        conv(segINV[i], segINV[i * 2], segINV[i * 2 + 1]);
    }
    // end init segtree

    // queries
    pair<ll,ll>sa,sc;
    ll a, b, c, d, l, r, piv, pos, lab, lcd, ta;
    for (i = 0; i < m; i++)
    {
        cin >> a >> b >> c >> d;
        if (tot == 0)
        {
            cout << 0 << '\n';
            continue;
        }
        a--;
        b--;
        c--;
        d--;
        lab=lca(a,b);
        lcd=lca(c,d);
        l = 0;
        ta=(depth[a]-depth[lab])+(depth[b]-depth[lab]);
        
        while (l <= ta && sig(a,b,lab,ta)!=sig(c,d,lcd,ta))
        {
            r = ta;
            pos = r;
            while (l <= r)
            {
                piv = (l + r) / 2;
                if (sig(a,b,lab,piv)!=sig(c,d,lcd,piv))
                {
                    pos = piv;
                    r = piv - 1;
                }
                else
                    l = piv + 1;
            }
            unir(nodSig(a,b,lab,pos), nodSig(c,d,lcd,pos));
            if (tot == 0)
                break;
            l = pos + 1;
        }
        cout << tot << '\n';
    }
    // end queries
    return 0;
}
