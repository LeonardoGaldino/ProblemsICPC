// 2 DP's solution. Just follow commands and remember states
#include <iostream>
#include <map>
#include <utility>

using namespace std;

int h, w, n;
char mat[101][101];
char cmds[11];
int dirs[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
int turnLeft[4] = {3, 2, 0, 1};
int turnRight[4] = {2, 3, 1, 0};
map<pair<pair<int,int>, pair<int,int>>, int> solved;
int num = 0;

bool validPos(int r, int c) {
	return (r >= 0 && r < h && c >= 0 && c < w && mat[r][c] != 'X');
}

bool _scapes(int curRow, int curCol, map<pair<pair<int,int>, pair<int,int>>, bool>& vis, int dir, int cmd) {
	pair<pair<int,int>, pair<int,int>> state = {{curRow, curCol}, {cmd, dir}};
	if(solved[state] != 0) {
		return (solved[state] == 1 ? true : false);
	}
	if(mat[curRow][curCol] == 'E') {
		return true;
	}
	if(vis[state]) {
		return false;
	}
	vis[state] = true;
	int newDir;
	if(cmds[cmd] == 'S') {
		int newRow = curRow+dirs[dir][0];
		int newCol = curCol+dirs[dir][1];
		if(validPos(newRow, newCol)) {
			solved[state] = (_scapes(newRow, newCol, vis, dir, (cmd+1)%n) ? 1 : 2);
			return (solved[state] == 1 ? true : false); 
		}
		solved[state] = (_scapes(curRow, curCol, vis, dir, (cmd+1)%n) ? 1 : 2);
		return (solved[state] == 1 ? true : false);
	} else if(cmds[cmd] == 'L') {
		newDir = turnLeft[dir];
	} else if(cmds[cmd] == 'R') {
		newDir = turnRight[dir];
	}
	solved[state] = (_scapes(curRow, curCol, vis, newDir, (cmd+1)%n) ? 1 : 2);
	return (solved[state] == 1 ? true : false); 
}

int main() {
	while(scanf("%d %d", &h, &w) == 2) {
		solved.clear();
		int valids = 0;
		for(int i = 0 ; i < h ; ++i) {
			for(int j = 0 ; j < w ; ++j) {
				scanf(" %c", &mat[i][j]);
				valids += (mat[i][j] != 'X');
			}
		}

		scanf("%d", &n);
		for(int i = 0 ; i < n ; ++i) scanf(" %c", &cmds[i]);

		int succ = 0;
		map<pair<pair<int,int>, pair<int,int>>, bool> visiteds;
		for(int i = 0 ; i < h ; ++i) {
			for(int j = 0 ; j < w ; ++j) {
				if(mat[i][j] != 'X') {
					visiteds.clear();
					succ += _scapes(i,j, visiteds, 3, 0);
				}
			}
		}

		if(succ == valids)
			puts("OK");
		else
			printf("%d\n", succ);		
	}


 	return 0;
}
