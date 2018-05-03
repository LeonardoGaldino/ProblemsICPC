// Linear pass solution
#include <bits/stdc++.h>

#define fr(i,st,nd,q) for(int i = st ; i < nd ; i += q)
#define PII pair<int,int>
#define VI vector<int>
#define INF 0x3f3f3f3f
#define EPS 1e-10

using namespace std;

int main() {
	string inp;
	int n;
	cin >> n >> inp;
	if(inp == "0")
		cout << "0" << endl;
	else {
		string out = "1";
		for(int i = 1 ; i < n ; ++i){
			if(inp[i] == '0')
				out.push_back('0');
		}
		cout << out << endl;
	}
	return 0;
}


