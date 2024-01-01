//Jai shree ram

//toposort using bfs
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define int ll
#define sz(x) (ll)(x.size())
#define JAI_SHREE_RAM ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define MOD (ll)(1e9+7)
#define pb push_back
//<------------------------------------------------------------------------>


/*

5--->0<---4
|	   |
|	   |
v          |
2--->1<---3					queue:



iteration 1 --->	
			
    5	 0<---4
	      |		 
	      |
	      |
    2--->1<---3				    queue: 5


iteration 2 --->

    5	     0<---4
		  |
		  |
		  |
   2	    1<---3					queue: 5|2


iteration 3 --->

5	 0    4
		  
		  
		  
2	 1<---3					queue: 5|2|4|0


iteration 4 --->

5	 0    4
		  
		  
		  
2	 1	  3					queue: 5|2|4|0|3|1

*/
void toposort(int node,vector<int>&indegree,vector<int>&topo,vector<int>adj[],vector<int>&visited){
	queue<int>q;
	q.push(node);
	visited[node]=1;		//marking any node from where we start as 1
	
	while(q.empty()==false){
		int x=q.front();
		q.pop();
		topo.push_back(x);
		//iterating for all the connected node of node 'x'
		for(auto it:adj[x]){
			indegree[it]--;
			if(indegree[it]==0){
				q.push(it);
				visited[it]=1;
			}
		}
	}
}

void solve(){
	
	int n,m;
	cin>>n>>m;
	vector<int>adj[n+1];
	vector<int>indegree(n+1,0);
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		indegree[v]++;
	}
	
	vector<int>topo;
	vector<int>visited(n+1,0);
	for(int i=1;i<=n;i++){
		
		if(indegree[i]==0&&visited[i]==0){
			toposort(i,indegree,topo,adj,visited);
		}
		
		
	}
	
	for(auto it:topo){
		cout<<it<<" ";
	}
	
	
	
	
}


signed main(){
	JAI_SHREE_RAM;
	
	// ll tc;	cin>>tc;	while(tc--)
		solve();
}
