// 2-sets solution (no classic algorithm or technique)
#include <iostream>
#include <vector>
#include <set>

using namespace std;

string v1[1000003];
string v2[1000003];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		string tmp;
		for(int i = 0 ; i < n ; ++i) {
			cin >> tmp;
			v1[i] = tmp;
		}
		for(int i = 0 ; i < n ; ++i) {
			cin >> tmp;
			v2[i] = tmp;
		}
		bool first = true;
		int count = 0;
		int idx = -1;
		set<string> s1;
		set<string> s2;
		for(int i = 0 ; i < n ; ++i) {
			if(v1[i] != v2[i]) {
				if(s1.find(v2[i]) != s1.end())
					--count;
				else
					++count;
				if(s2.find(v1[i]) != s2.end())
					--count;
				else
					++count;
				s1.insert(v1[i]);
				s2.insert(v2[i]);
			}
			if(count == 0) {
				printf("%s%d ", (first?"":" "), (i-idx));
				idx = i;
			}
		}
		puts("");
	}

	return 0;
}
