// Solves using binary search (on set)
#include <bits/stdc++.h>

#define fr(i,st,nd,q) for(int i = st ; i < nd ; i += q)

using namespace std;

int n;
vector<pair<int,int>> v;
vector<pair<int,int>> v2;
set<int> v3;

map<int,int> opens;
map<int,int> closes;

map<int,int> mark;

int main() {
	scanf("%d", &n);
	fr(i,0,n,1) { 
		int a,b;
		scanf("%d %d", &a, &b);
		v.push_back({a,b});
		v2.push_back({b,i});
	}
	fr(i,0,n,1) {
		int idx2 = i+1;
		int a = v[i].first;
		int b = v[i].second;
		if(opens[a]) {
			int idx1 = opens[a];
			if(v[idx1-1].second < b)
				printf("%d %d\n", idx1, idx2);
			else
				printf("%d %d\n", idx2, idx1);
			return 0;		
		}
		if(closes[b]) {
			int idx1 = closes[b];
			if(v[idx1-1].first > a)
				printf("%d %d\n", idx1, idx2);
			else
				printf("%d %d\n", idx2, idx1);
			return 0;
		}
		opens[a] = closes[b] = (i+1);
	}

	sort(v2.begin(), v2.end());

	fr(i,0,v2.size(),1)
		mark[v[i].first] = i;

	fr(i,0,v2.size(),1) {
		int idx = v2[i].second;
		auto k = v3.lower_bound(v[idx].first);
		if(k != v3.end()) {
			int idx2 = mark[*k];
			printf("%d %d\n", idx2+1, idx+1);
			return 0;
		}
		v3.insert(v[idx].first);
	}
	puts("-1 -1");
	return 0;
}


