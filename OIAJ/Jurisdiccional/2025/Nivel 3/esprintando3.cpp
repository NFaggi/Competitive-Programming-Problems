//Link: https://juez.oia.unsam.edu.ar/task/180
//Score: 90/100
#include <bits/stdc++.h>
#define ll long long
#define sz(x) int(x.size())
#define forn(i, n) for (i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fr first
#define se second
using namespace std;

double dist(double x, double y, double x2, double y2)
{
    double xd = (x - x2), yd = (y - y2);
    double dis = (xd * xd) + (yd * yd);
    dis = sqrt(dis);
    return dis;
}
vector<int> x, y;
vector<ll>dis,pref;
int k;
pair<int, int> fin(ll pos)
{
    ll K = k;
    ll xf = x[pos], yf = y[pos], ant = pos, sig, aK = K;
    K=K%pref.back();
    ll dis0=pref.back(), l=pos, r=sz(x)-1, piv, di, res=0;
    if(pos>0)
        dis0=dis0-pref[pos-1];
    if(K>dis0)
    {
        K=K-dis0;
        pos=0;
        xf=x[0];
        yf=y[0];
        r=l-1;
        l=0;
    }
    if(l>0)
        res=pref[l-1];
    while(l<=r)
    {
        piv=(l+r)/2;
        di=0;
        if(piv>0)
            di=pref[piv-1]-res;
        if(di<=K)
        {
            pos=piv;
            aK=K-di;
            l=piv+1;
        }
        else
            r=piv-1;
    }
    ant=pos;
    sig = (ant + 1) % sz(x);
    xf = x[ant];
    yf = y[ant];
    if (xf == x[sig])
    {
        if (y[sig] < yf)
            yf = yf - aK;
        else
            yf = yf + aK;
    }
    else
    {
        if (x[sig] < xf)
            xf = xf - aK;
        else
            xf = xf + aK;
    }
    return {xf, yf};
}

int N;
double k2;
double EPS=1e-12;
double ham(double x, double y, double x2, double y2)
{
    double dis=(x-x2)*(x-x2)+(y-y2)*(y-y2);
    dis=sqrt(dis);
    return dis;
}

void cal(int ind, int sig, double piv, double & gx, double & gy)
{
    if(x[ind]==x[sig])
    {
        if(y[ind]>y[sig])
            gy=gy-piv;
        else
            gy=gy+piv;
    }
    else
    {
        if(x[ind]>x[sig])
            gx=gx-piv;
        else
            gx=gx+piv;
    }
}

double calcDisGC(double piv, int ind)
{
    int sig=(ind+1)%sz(x);
    double falt=k2, sD, cx, cy, gx=x[ind], gy=y[ind];

    if(x[ind]==x[sig])
    {
        gy=piv;
        sD=abs(gy-y[sig]);
    }    
    else
    {
        gx=piv;
        sD=abs(gx-x[sig]);
    }    
    cx=gx;
    cy=gy;
    if(sD>=falt-EPS)
    {
        cal(ind,sig,falt,cx,cy);
        return ham(gx,gy,cx,cy);
    }
    falt=falt-sD;
    cx=x[sig];
    cy=y[sig];
    ind=sig;
    while(falt>EPS)
    {
        sig=(ind+1)%sz(x);
        sD=ham(x[ind],y[ind],x[sig],y[sig]);
        if(sD>=falt-EPS)
        {
            cx=x[ind];
            cy=y[ind];
            cal(ind,sig,falt,cx,cy);
            return ham(gx,gy,cx,cy);
        }
        falt=falt-sD;
        cx=x[sig];
        cy=y[sig];
        ind=sig;
    }
    return ham(gx,gy,cx,cy);
}

double distGC(int ind)
{
    int sig=(ind+1)%sz(x);
    double l, r, m1,m2, piv, d1, d2;
    if(x[ind]==x[sig])
    {
        l=min(y[ind],y[sig]);
        r=max(y[ind],y[sig]);
    }
    else
    {
        l=min(x[ind],x[sig]);
        r=max(x[ind],x[sig]);
    }
    for(int i=0; i<100; i++)
    {
        piv=(r-l)/3;
        m1=l+piv;
        m2=r-piv;
        d1=calcDisGC(m1,ind);
        d2=calcDisGC(m2,ind);
        if(d1<d2)
            r=m2;
        else
            l=m1;
    }
    return calcDisGC((l+r)/2,ind);
}

vector<double> esprintando(int K, vector<int> &X, vector<int> &Y) {

    k2=K;
    N=sz(X);
    x=X;
    y=Y;
    vector<double> ans(2);
    k = K;
    ll i, sig;
    dis.resize(sz(X));
    pref.resize(sz(X),0);
    for(i=0; i<sz(X); i++)
    {
        sig=(i+1)%sz(X);
        dis[i]=dist(X[i],Y[i],X[sig],Y[sig]);
        if(i>0)
            pref[i]=pref[i-1];
        pref[i]=pref[i]+dis[i];
    }
    pair<int, int> p2 = fin(0);
    ans[0] = ans[1] = dist(x[0], y[0], p2.fr, p2.se);
    for (i = 0; i < sz(X); i++)
    {
        p2 = fin(i);
        ans[0] = min(dist(x[i], y[i], p2.fr, p2.se), ans[0]);
        ans[1] = max(dist(x[i], y[i], p2.fr, p2.se), ans[1]);
    }
    if(N<=500||K<=2)
    {
    ans[0]=DBL_MAX;
    for(int i=0; i<N; i++)
        ans[0]=min(ans[0],distGC(i));
        }
    return ans;
}


