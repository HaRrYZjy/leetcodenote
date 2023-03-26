#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldb;
typedef pair<ll, ll> pii;

class Solution {

private:
    bool vaild=true;
    vector<vector<int>> edges;
    vector<int> vis;
public:

    void dfs(int u){
        vis[u]=1;
        for(int x:edges[u]){
            if(vis[x]==0){
                dfs(x);
                if(!vaild) return;
            }
            else if(vis[x]==1){
                vaild=false;
                return;
            }
        }
        vis[u]=2;


    }

    bool canFinish(int n, vector<vector<int>>& p) {
        edges.resize(n);
        vis.resize(n);
        for (const auto& x: p) {
            edges[x[1]].push_back(x[0]);
        }
        for(int i=0;i<n&&vaild;++i){
            if(vis[i]==0){
                dfs(i);
            }
        }
    return vaild;

    }
};

int main(){

	int n;
	vector<vector<int>> p;
	n=2;
	p={{1,0},{0,1}};
	Solution s;
	if(s.canFinish(n,p)){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	
}
