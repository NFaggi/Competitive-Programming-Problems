//Link: https://www.hackerrank.com/challenges/synchronous-shopping/problem
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

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'shop' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. STRING_ARRAY centers
 *  4. 2D_INTEGER_ARRAY roads
 */

vector<ll>stov(string &s)
{
    vector<ll>ans;
    ll act=0, i;
    for(i=0; i<sz(s); i++)
    {
        if(s[i]==' ')
        {
            ans.pb(act);
            act=0;
            continue;
        }
        act=(act*10)+(s[i]-'0');
    }
    ans.pb(act);
    return ans;
}

const int MAXN=1001;

vector<pair<ll,ll>>grafo[MAXN];

int shop(int n, int k, vector<string> centers, vector<vector<int>> roads) {
    vector<ll>c(n+1,0);
    vector<ll>v;
    ll i, j;
    for(i=1; i<=n; i++)
    {
        v=stov(centers[i-1]);
        for(j=1; j<sz(v); j++)
            c[i]=c[i]|(1<<(v[j]-1));
    }

    for(i=0; i<sz(roads); i++)
    {
        grafo[roads[i][0]].pb({roads[i][1],roads[i][2]});
        grafo[roads[i][1]].pb({roads[i][0],roads[i][2]});
    }

    vector<vector<ll>>dist(n+1,vector<ll>(1<<k,LLONG_MAX));
    vector<vector<bool>>proc(n+1,vector<bool>(1<<k,0));
    priority_queue<vector<ll>>pq;
    pq.push({0,1,c[1]});
    dist[1][c[1]]=0;
    while(sz(pq))
    {
        v=pq.top();
        pq.pop();
        v[0]=-v[0];
        if(proc[v[1]][v[2]])
            continue;
        proc[v[1]][v[2]]=1;
        for(auto k:grafo[v[1]])
        {
            ll cost=dist[v[1]][v[2]]+k.se;
            ll vec=v[2]|c[k.fr];
            if(dist[k.fr][vec]>cost)
            {
                dist[k.fr][vec]=cost;
                pq.push({-cost,k.fr,vec});
            }
        }
    }

    ll mask=(1<<k)-1, mi=INT_MAX;
    for(i=0; i<=mask; i++)
    {
        for(j=0; j<=mask; j++)
        {
            if((j|i)!=mask||dist[n][i]==LLONG_MAX||dist[n][j]==LLONG_MAX)
                continue;
            mi=min(mi,max(dist[n][i],dist[n][j]));
        }
    }
    return int(mi);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    int k = stoi(first_multiple_input[2]);

    vector<string> centers(n);

    for (int i = 0; i < n; i++) {
        string centers_item;
        getline(cin, centers_item);

        centers[i] = centers_item;
    }

    vector<vector<int>> roads(m);

    for (int i = 0; i < m; i++) {
        roads[i].resize(3);

        string roads_row_temp_temp;
        getline(cin, roads_row_temp_temp);

        vector<string> roads_row_temp = split(rtrim(roads_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int roads_row_item = stoi(roads_row_temp[j]);

            roads[i][j] = roads_row_item;
        }
    }

    int res = shop(n, k, centers, roads);

    fout << res << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
