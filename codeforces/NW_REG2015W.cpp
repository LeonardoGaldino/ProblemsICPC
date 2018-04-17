// Floyd-Warshall solution
#include <iostream>
#include <map>
#include <vector>
#include <math.h>
#include <string.h>

typedef long long int LLI;

using namespace std;

double dists[62][62];
LLI p,w,q;

class Point {
public:
	LLI x;
	LLI y;
	LLI z;
	Point(LLI a, LLI b, LLI c) {
		this->x = a;
		this->y = b;
		this->z = c;
	}
};

map<string, LLI> nameToIdx;
map<LLI, string> idxToName;
LLI idx = 1;

vector<Point> coords;

double dist(Point p1, Point p2) {
	double diffX = double(p1.x)-double(p2.x);
	double diffY = double(p1.y)-double(p2.y);
	double diffZ = double(p1.z)-double(p2.z);
	double tmp = diffX*diffX + diffY*diffY + diffZ*diffZ; 
	return (sqrt(tmp));
}

void init() {
	memset(dists, 0, sizeof dists);
	coords.clear();
	nameToIdx.clear();
	idxToName.clear();
	idx = 1;
}

void computeDists() {
	for(LLI i = 0 ; i < coords.size() ; ++i) {
		for(LLI j = i+1 ; j < coords.size() ; ++j) {
			double distBetween = dist(coords[i], coords[j]);
			dists[i][j] = dists[j][i] = distBetween;
		}
	}
}

void floyd() {
	for(LLI i = 0 ; i < p ; ++i) dists[i][i] = 0;
	for(LLI k = 0 ; k < p ; ++k) {
		for(LLI i = 0 ; i < p ; ++i) {
			for(LLI j = 0 ; j < p ; ++j) {
				dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
			}
		}
	}

}

int main() {
	LLI t, _case = 1;
	cin >> t;
	
	while(t--) {
		cout << "Case " << _case++ << ":" << endl;
		init();
		cin >> p;
		for(LLI i = 0 ; i < p ; ++i) {
			string name;
			cin >> name;
			if(!nameToIdx[name]) {
				nameToIdx[name] = idx;
				idxToName[idx] = name;
				++idx;
			}
			LLI x,y,z;
			cin >> x >> y >> z;
			Point temp = Point(x,y,z);
			coords.push_back(temp);
		}
		computeDists();
		cin >> w;
		for(LLI i = 0 ; i < w ; ++i) {
			string from, to;
			cin >> from >> to;
			LLI idxFrom = nameToIdx[from];
			LLI idxTo = nameToIdx[to];
			dists[idxFrom-1][idxTo-1] = 0;
		}
		floyd();
		cin >> q;
		for(LLI i = 0 ; i < q ; ++i) {
			string p1, p2;
			cin >> p1 >> p2;
			LLI idx1 = nameToIdx[p1];
			LLI idx2 = nameToIdx[p2];
			cout << "The distance from " << p1 << " to " << p2 << " is " << (LLI)round(dists[idx1-1][idx2-1]) << " parsecs." << endl;
		}
		
	}
	
	return 0;
}
