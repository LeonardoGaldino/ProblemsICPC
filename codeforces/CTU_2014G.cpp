// Linear pass on input
#include <iostream>

using namespace std;

int main() {
	string line;
	while(cin >> line) {
		bool pos = true;
		for(int i = line.length()-1 ; i >= 0 ; --i, pos = !pos) {
			if(pos && line[i] == '0') {
				line[i] = '1';
				cout << line << endl;
				break;
			}
			else if(pos && line[i] == '1') {
				line[i] = '0';
				if(!i) {
					cout << ("11"+line) << endl;
				}
			} else if(!pos && line[i] == '1') {
				line[i] = '0';
				if(!i) {
					while(i < line.length() && line[i] == '0') ++i;
					if(i == line.length())
						cout << "0" << endl;
					else
						cout << line.substr(i) << endl;
					break;
				}
				cout << line << endl;
				break;
			} else if(!pos && line[i] == '0') {
				line[i] = '1';
				if(!i) {
					cout << ("1" + line) << endl;
					break;
				}
			}
		}
	}
	return 0;
}
