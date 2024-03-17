#include <bits/stdc++.h>
using namespace std;
int main(){
	multiset<int> nums;
	int n; cin>>n;
	n--;
	int aux; cin>>aux;
	nums.insert(aux);
	while (n--){
		cin>>aux;
		auto it=nums.upper_bound(aux);
		if (it!=nums.end()){
			nums.insert(aux);
			nums.erase(it);
		}
		else {
			nums.insert(aux);
		}
	}
	int total=0;
	cout<<nums.size();
}
