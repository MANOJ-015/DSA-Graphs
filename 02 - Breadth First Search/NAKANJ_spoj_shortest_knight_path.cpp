// https://www.spoj.com/problems/NAKANJ/
// find the shortest dist from a point to other point in a matrix

#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

bool vis[9][9];
int level[9][9];

vector<pair<int,int>> movements = {
	{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}	
};

void reset(){
	for(int i=0 ; i<9 ; ++i){
		for(int j=0 ; j<9 ; ++j){
			vis[i][j] = false;
			level[i][j] = 0;
		}
	}
}

int getX(string s){
	return (s[0] - 'a') + 1;
}

int getY(string s){
	return (s[1] - '0');
}

bool isValid(int x,int y){
	return x>=1 && x<=8 && y>=1 && y<=8;
}

void bfs(int srcX,int srcY,int destX,int destY){
	queue<pair<int,int> > q;
	
	q.push({srcX,srcY});
	vis[srcX][srcY] = true;
	
	
	while(!q.empty()){
		pair<int,int> p = q.front();
		q.pop();
		
		int parX = p.first;
		int parY = p.second;
		
		for(auto movement : movements){
			int x = movement.first + parX;
			int y = movement.second + parY;
			
			if(vis[x][y])continue;
			if(!isValid(x,y))continue;
			
			q.push({x,y});
			vis[x][y] = true;
			level[x][y] = level[parX][parY] + 1;

		}
	}
	
	cout << level[destX][destY] << "\n";
}

int main()
{
	int test;
	cin >> test;
	
	while(test--){
		reset();
		string s1,s2;
		cin >> s1 >> s2;
		
		int srcX,srcY,destX,destY;
		srcX = getX(s1);
		srcY = getY(s1);
		destX = getX(s2);
		destY = getY(s2);
		
		bfs(srcX,srcY,destX,destY);
	}
	return 0;
}
