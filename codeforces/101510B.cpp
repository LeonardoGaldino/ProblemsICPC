// Complete Search solution
// DON'T JUDGE THIS CODE, THE TIME WAS RUNNING AND I WAS UNDER PRESSURE! HAHA

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int counting[9];
vector<pair<int,int>> hand;
int a,b;

bool is_2() {
	vector<pair<int,int>> cp = hand;
	sort(cp.begin(), cp.end());
	return ((cp[0].first == cp[1].first &&
		cp[1].first == cp[2].first &&
		cp[2].first == cp[3].first) ||
		(cp[1].first == cp[2].first &&
		cp[2].first == cp[3].first &&
		cp[3].first == cp[4].first));
}

bool is_3() {
	vector<pair<int,int>> cp = hand;
	sort(cp.begin(), cp.end());
	return ((cp[0].first == cp[1].first &&
		cp[1].first == cp[2].first &&
		cp[3].first == cp[4].first) ||
		(cp[1].first == cp[2].first &&
		cp[2].first == cp[3].first &&
		cp[0].first == cp[4].first) ||
		(cp[2].first == cp[3].first &&
		cp[3].first == cp[4].first &&
		cp[0].first == cp[1].first));
}

bool is_4() {
	return (hand[0].second == hand[1].second &&
		hand[1].second == hand[2].second &&
		hand[2].second == hand[3].second &&
		hand[3].second == hand[4].second);
}

bool is_5() {
	vector<pair<int,int>> cp = hand;
	sort(cp.begin(), cp.end());
	return (cp[0].first == cp[1].first-1 &&
		cp[1].first == cp[2].first-1 &&
		cp[2].first == cp[3].first-1 &&
		cp[3].first == cp[4].first-1);
}

bool is_6() {
	for(int i = 0 ; i < 5 ; ++i) {
		for(int j = i+1 ; j < 5 ; ++j) {
			for(int k = j+1 ; k < 5 ; ++k) {
				if(hand[i].first == hand[j].first && hand[j].first == hand[k].first)
					return true;	
			}

		}
	}
	return false;
}


bool is_7() {
	for(int i = 0 ; i < 5 ; ++i) {
		for(int j = i+1 ; j < 5 ; ++j) {
			if(hand[i].first == hand[j].first) {
				for(int k = 0 ; k < 5 ; ++k) {
					for(int l = k+1 ; l < 5 ; ++l) {
						if(hand[k].first == hand[l].first && k != i && k != j && l != i && l != j) {
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

bool is_8() {
	for(int i = 0 ; i < 5 ; ++i) {
		for(int j = i+1 ; j < 5 ; ++j) {
			if(hand[i].first == hand[j].first)
				return true;
		}
	}
	return false;
}

bool card_used(int r, int s) {
	for(int i = 0 ; i < hand.size() ; ++i) {
		if(hand[i].first == r && hand[i].second == s)
			return true;
	}
	return false;
}

bool is_1() {
	return (is_5() && is_4());
}

void choose_card() {
	if(hand.size() == 5) {
		if(is_1())
			++counting[0];
		else if(is_2())
			++counting[1];
		else if(is_3())
			++counting[2];
		else if(is_4())
			++counting[3];
		else if(is_5())
			++counting[4];
		else if(is_6())
			++counting[5];
		else if(is_7())
			++counting[6];
		else if(is_8())
			++counting[7];
		else
			++counting[8];
		return;

	}
	for(int i = 0 ; i < a ; ++i) {
		for(int j = 0 ; j < b ; ++j) {
			if(!card_used(i,j)) {
				hand.push_back({i,j});
				choose_card();
				hand.pop_back();
			}
		}
	}
}

int main() {
	scanf("%d %d", &a, &b);
	int a1,a2, b1,b2;
	scanf("%d %d %d %d", &a1, &b1, &a2, &b2);   
	hand.push_back({a1,b1});
	hand.push_back({a2,b2});
	choose_card();

	for(int i = 0 ; i < 9 ; ++i)
		printf("%d ", counting[i]/6);
	puts("");
	return 0;
}