#include <iostream>
#include <vector>
#include <queue> 

using namespace std;

int main(){

	int test_num;
	cin >> test_num;
	while(test_num--){
		int n, m;
		cin >> n >> m;
		vector<vector<int> > gra;
		gra.resize(n+1,vector<int>());
		for(int i = 0; i < m; i++){
			int x, y;
			cin >> x >> y;
			gra[x].push_back(y);
		}
		int seen[n+1] = {0};
		queue<int> edge;
		for(int i = 1; i <= n; i++){
			if(seen[i] == 1 || seen[i] == -1) continue;
			seen[i] == 1;
			for(int j = 0; j < gra[i].size(); j++){
				edge.push(gra[i][j]);
			}
			while(!edge.empty()){
				int cur = edge.front();
				edge.pop();
				seen[cur] = seen[i]*(-1);
				for(int j = 0; j < gra[i].size(); j++){
					edge.push(gra[cur][j]);
				}
			}
		}
	}

	return 0;
}
