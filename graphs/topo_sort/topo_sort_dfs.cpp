//Jai shree ram

//toposort using dfs

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
// #define int ll
#define sz(x) (ll)(x.size())
#define JAI_SHREE_RAM ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define MOD (ll)(1e9+7)
#define pb push_back
//<------------------------------------------------------------------------>

/*

5--->4--->3--->2--->1
		  |			^
		  |			|
		  |____6____7
		  
		  
7 7
5 4
4 3 
3 2 
3 6
2 1 
6 7
7 1

stack possible


|5|
|4|
|3|
|6|
|7|
|2|
|1|
---

one of expected topo sort= 5 4 3 6 7 2 1




*/

void dfs(int node,vector<int>&visited,stack<int>&st,vector<int>adj[]){
	visited[node]=1;
	
	for(auto it:adj[node]){
		if(visited[it]==0){
			dfs(it,visited,st,adj);
		}
	}
	
	st.push(node);
	
}

void solve(){
	int n,m;
	cin>>n>>m;
	
	vector<int>adj[n+1];
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}
	
	vector<int>visited(n+1,0);
	stack<int>st;
	
	for(int i=1;i<=n;i++){
		if(visited[i]==0){
			dfs(i,visited,st,adj);
		}
	}
	
	
	while(st.empty()==false){
		cout<<st.top()<<" ";
		st.pop();
	}
	
	
	
	
}


signed main(){
	JAI_SHREE_RAM;
	
	// ll tc;	cin>>tc;	while(tc--)
		solve();
}
