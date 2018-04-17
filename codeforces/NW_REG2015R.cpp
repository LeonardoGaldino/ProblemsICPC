// PD solution
#include <iostream>
#include <map>

#define LLI long long int

using namespace std;

map<pair<LLI,LLI>, LLI> ht;

bool isRamp(string n) {
	if(n.empty())
		return true;
	LLI mini = n[0]-'0';
	for(LLI i = 1 ; i < n.length() ; ++i) {
		if((n[i]-'0') < mini)
			return false;
		mini = max(mini, (LLI)(n[i]-'0'));
	}
	return true;
}

LLI getWays(LLI mini, LLI num) {
	if(ht[{mini,num}])
		return ht[{mini, num}];
	LLI ways = 0;
	for(LLI i = 9 ; i >= mini ; --i)
		ways += getWays(i, num-1);
	return (ht[{mini,num}] = ways);
}

int main() {
	LLI t;
	scanf("%lld", &t);
	for(LLI i = 0 ; i < 10 ; ++i)
		ht[{i,0}] = 1;
	while(t--) {
		string inp;
		cin >> inp;
		if(!isRamp(inp)) {
			cout << -1 << endl;
			continue;
		}
		LLI originalLength = inp.length();
		string currentString = inp;
		LLI res = 0;
		while(currentString.length() >= 1) {
			if(currentString.length() == 1) {
				if(currentString[0] == '0')
					break;
				currentString[0] = (currentString[0]-1);
				res += getWays(currentString[0]-'0', originalLength-1);
				continue;
			}
			LLI lastIdx = currentString.length()-1;
			if(currentString[lastIdx] > currentString[lastIdx-1]) {
				currentString[lastIdx] = (currentString[lastIdx]-1);
				res += getWays(currentString[lastIdx]-'0', originalLength-currentString.length());
			} else {
				currentString.pop_back();
			}
		}
		cout << res << endl;
	}

	return 0;
}
