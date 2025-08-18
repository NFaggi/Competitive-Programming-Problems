//Link: https://qoj.ac/problem/13648
//Score: 100/100
#include <bits/stdc++.h>
#define ll long long
#define fr first
#define se second
#define sz(x) int(x.size());
#define mp make_pair
#define pb push_back
using namespace std;

vector<int> a, b;
void initialize(std::vector<int> A, std::vector<int> B)
{
    a = A;
    b = B;
    return;
}

int answer_question(int i, int j)
{
    return a[i]+b[j];
}
