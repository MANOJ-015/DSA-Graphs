#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 1e3+7;
int val[N][N];
bool vis[N][N];
int lev[N][N];
int n,m;

vector<pair<int,int> > movements = {
	{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}	
};

void reset(){
	for(int i=0 ; i<n ; ++i){
		for(int j=0 ; j<m ; ++j){
			val[i][j] = 0;
			lev[i][j] = 0;
			vis[i][j] = false;
		}
	}
}

bool isValid(int i,int j){
	return i>=0 && i<n && j>=0 && j<m;
}

int bfs(){
	int mx = val[0][0],ans = 0;
	
	for(int i=0 ; i<n ; ++i){
		for(int j=0 ; j<m ; ++j){
			mx = max(mx,val[i][j]);
		}
	}
	
	queue<pair<int,int> > q;
	
	for(int i=0 ; i<n ; ++i){
		for(int j=0 ; j<m ; ++j){
			if(val[i][j] == mx){
				q.push({i,j});
				lev[i][j] = 0;
				vis[i][j] = true;
			}
		}
	}
	
	while(!q.empty()){
		auto vertex = q.front();
		int x = vertex.first;
		int y = vertex.second;
		q.pop();
		
		for(auto movement : movements){
			int child_x = movement.first + x;
			int child_y = movement.second + y;
			
			if(vis[child_x][child_y]) continue;
			if(!isValid(child_x,child_y)) continue;
			
			q.push({child_x,child_y});
			vis[child_x][child_y] = true;
			lev[child_x][child_y] =lev[x][y] + 1;
			ans = max(ans,lev[child_x][child_y]);
			
		}
	}
	
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	

	int test;
	cin >> test;
	
	while(test--){
		
		reset();
		cin >> n >> m;
		
		for(int i=0 ; i<n ; ++i){
			for(int j=0 ; j<m ; ++j){
				cin >> val[i][j];
			}
		}
		
		cout << bfs() << "\n";
	}
	return 0;
}
