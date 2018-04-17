// LIS solution (used n² LIS)
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

vector<pair<double, double>> vec;
int n;

bool gt(pair<double, double> p1, pair<double, double> p2) {
	return (p1.first > p2.first && p1.second < p2.second);
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		vec.clear();
		for(int i = 0 ; i < n ; ++i) {
			double a,b;
			cin >> a >> b;
			vec.push_back({a,b});
		}
		if(n == 0) {
			cout << 0 << endl;
			continue;
		}
		vector<int> lis;
		lis.push_back(1);
		int res = 1;
		for(int i = 1 ; i < vec.size() ; ++i) {
			int best = 0;
			for(int j = 0 ; j < i ; ++j) {
				if(gt(vec[i], vec[j]))
					best = max(best, lis[j]);
			}
			lis.push_back(best+1);
			res = max(res, lis.back());
		}
		cout << res << endl;
	}
	return 0;
}
