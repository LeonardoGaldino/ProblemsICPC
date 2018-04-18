// Bitmask PD solution
#include <iostream>
#include <vector>

#include <climits>
#include <math.h>

#define EPS 1e-8
#define fr(it, ini,end,k) for(int it = ini; it < end ; it +=k)

using namespace std;

class Point {
public:
	int x;
	int y;
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

double memo[(1<<16)+1];

double dist(Point p1, Point p2) {
	double diffX = double(p1.x)-double(p2.x);
	double diffY = double(p1.y)-double(p2.y);
	return sqrt(diffX*diffX + diffY*diffY);
}

double minSumDists(const vector<Point>& points, int bitmask) {

	if(bitmask == ( (1 << points.size())-1) )
		return 0;

	if(memo[bitmask] > -0.5) {
		return memo[bitmask];
	}

	double best = 1e10;

	fr(i,0,points.size(),1) {
		if((bitmask&(1<<i)) == 0) {
			bitmask |= (1<<i);

			fr(j,0,points.size(),1) {
				if((bitmask&(1<<j)) == 0) {
					double d = dist(points[i], points[j]);
					double subProb = minSumDists(points, (bitmask | (1<<j)) );
					best = min(best, subProb+d);			
				}
			}

			bitmask &= (~(1<<i));
		}
	}

	return (memo[bitmask] = best);
}

int main() {
	int n;
	int testNum = 1;
	while(scanf("%d", &n), n) {
		fr(i, 0, (1<<16)+1, 1)  { memo[i] = -1; }
		vector<Point> points;
		string name;
		fr(i, 0, (n<<1), 1) {
			cin >> name;
			int x, y;
			scanf("%d %d", &x, &y);
			points.push_back(Point(x,y));			
		}
		
		printf("Case %d: %.2lf\n", testNum++, minSumDists(points, 0));
		
	}
	return 0;
}

