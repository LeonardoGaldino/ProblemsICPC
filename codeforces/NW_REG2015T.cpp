#include <iostream>

#define LLI long long int

using namespace std;

LLI stringToLLI(string inp) {
	LLI acumul = 1;
	LLI res = 0;
	for(int i = inp.length()-1 ; i >= 0 ; --i) {
		if(i == 0 && inp[i] == '-')
			return -res;
		else if(i==0 && inp[i] == '+')
			return res;
		LLI digit = inp[i]-'0';
		res += digit*acumul;
		acumul *= 10;
	}
	return res;
}

bool canUseI(LLI i, string nums[], char op) {
	string num1 = nums[0];
	string num2 = nums[1];
	string num3 = nums[2];
	for(LLI j = 0 ; j < num1.length() ; ++j)
		num1[j] = (num1[j] == '?' ? (i+'0') : num1[j]);
	for(LLI j = 0 ; j < num2.length() ; ++j)
		num2[j] = (num2[j] == '?' ? (i+'0') : num2[j]);
	for(LLI j = 0 ; j < num3.length() ; ++j)
		num3[j] = (num3[j] == '?' ? (i+'0') : num3[j]);
	LLI n1 = stringToLLI(num1);
	LLI n2 = stringToLLI(num2);
	LLI n3 = stringToLLI(num3);
	
	if(op == '+')
		return (n1+n2 == n3);
	else if(op == '-')
		return (n1-n2 == n3);
	return (n1*n2 == n3); 
}

bool containsI(const string& inp, int i) {
	char seek = '0'+i;
	for(char c : inp) {
		if(c == seek)
			return true;
	}
	return false;
}

int main() {
	LLI t;
	scanf("%lld", &t);
	while(t--) {
		string inp;	
		cin >> inp;
		char op;
		LLI opIdx, equalsIdx;
		for(LLI	i = 1; i < inp.length() ; ++i) {
			if(inp[i] == '+' || inp[i] == '-' || inp[i] == '*') {
				op = inp[i];
				opIdx = i;
				break;
			}
		}
		for(LLI	i = opIdx+1; i < inp.length() ; ++i) {
			if(inp[i] == '=') {
				equalsIdx = i;
				break;
			}
		}
		string nums[3];
		nums[0] = inp.substr(0, opIdx);
		nums[1] = inp.substr(opIdx+1, equalsIdx-opIdx-1);
		nums[2] = inp.substr(equalsIdx+1);

		bool ok0 = false;
		for(LLI i = 0 ; i < 3 ; ++i) {
			if( (nums[i][0] == '-' && nums[i][1] == '?') || (nums[i][0] == '+' && nums[i][1] == '?'))
				ok0 = true;
			if(nums[i][0] == '?' && nums[i].length() > 1)
				ok0 = true;
		}
		LLI res = -1;
		for(LLI i = ok0 ; i <= 9 ; ++i) {
			if(canUseI(i, nums, op) && !containsI(inp, i)) {
				res = i;
				break;
			}
		}
		cout << res << endl;
	}
	return 0;
}
