// PD solution
#include <iostream>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

//PD table
int memo[1001][51][51];

int _minCutCost(int l, int h, int lc, int hc, const vector<int>& cuts) {
	if(lc > hc)
		return 0;
	int currentCost = h-l+1;
	if(~memo[currentCost][lc][hc])
		return memo[currentCost][lc][hc];
	int minCutCostPartial = INT_MAX;
	for(int i = lc ; i <= hc ; ++i) {
		int leftSubCost = _minCutCost(l, cuts[i], lc, i-1, cuts);
		int rightSubCost = _minCutCost(cuts[i]+1, h, i+1, hc, cuts);
		minCutCostPartial = min(minCutCostPartial, leftSubCost+rightSubCost);
	}

	return (memo[currentCost][lc][hc] = currentCost+minCutCostPartial);
}

int minCutCost(int length, const vector<int>& cuts) {
	return _minCutCost(1, length, 0, cuts.size()-1, cuts);
}

int main() {
	int l;

	while(scanf("%d", &l), l) {
		memset(memo, -1, sizeof memo);

		int cutsNumber;
		scanf("%d", &cutsNumber);
		vector<int> cuts(cutsNumber);

		for(int i = 0 ; i < cutsNumber ; ++i) {
			int temp;
			scanf("%d", &temp);
			cuts[i] = temp;
		}

		int answer = minCutCost(l, cuts);
		cout << "The minimum cutting is " << answer << "." << endl;  
	}

	return 0;
}

