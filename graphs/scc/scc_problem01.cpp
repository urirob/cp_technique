// https://cses.fi/problemset/task/1682

//Jai shree ram

//Implementing Strongly Connnected Components

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define int ll
#define sz(x) (ll)(x.size())
#define JAI_SHREE_RAM ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define MOD (ll)(1e9+7)
#define pb push_back
#define all(x)	(x.begin(),x.end())

//<------------------------------------------------------------------------>

/*


(output will be according to 1-based indexing)

			   ___________
			   |		 |
			   V		 |
0<---2--->3--->4--->7	 |
|	^		   |    ^	 |
|	|		   |    |	 |
v	|		   v    |	 |
1___| 	       5--->6____| 



8 10
3 1
1 2
2 3
4 5
5 8
5 6
6 7
7 8
7 5
3 4




*/




stack<int>st;
vector<int>temp;
vector<vector<int>>scc;

int visited[100005];

void dfs(int node,vector<int>adj[]){
	visited[node]=1;
	
	for(auto it:adj[node]){
		if(visited[it]==0){
			dfs(it,adj);
		}
	}
	
	st.push(node);
	
	
}


//dfs on reverse ordered graph
void dfs2(int node,vector<int>tadj[]){
	visited[node]=1;
	temp.push_back(node);
	for(auto it:tadj[node]){
		if(visited[it]==0){
			dfs2(it,tadj);
		}
	}
	
	
}

//if there is 1 scc, print yes, else two diffrent scc members i.e. their components as well



void solve(){
	int n,m;
	cin>>n>>m;
	
	vector<int>adj[n+1],tadj[n+1];
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		tadj[v].push_back(u);
	}
	memset(visited,0,sizeof(visited));

	
	for(int i=1;i<=n;i++){
		if(visited[i]==0){
			dfs(i,adj);
		}
	}
	
	memset(visited,0,sizeof(visited));
	while(st.empty()==false){
		int node=st.top();
		st.pop();
		
		if(visited[node]==0){
			dfs2(node,tadj);
			
			//entering nodes of one scc component which is stored in temp, into vector<vector<int>>scc
			scc.push_back(temp);
			temp.clear();
		}
	}
	
	

	
	if(scc.size()<2){
		cout<<"YES\n";
	}
	
	/*
			   ___________
			   |		 |
			   V		 |
0<---2--->3--->4--->7	 |
|	^		   |    ^	 |
|	|		   |    |	 |
v	|		   v    |	 |
1___| 	       5--->6____| 


	node 2 se node 3 jaana possible hai despite being different scc components
	isliye pehle dusre component ke pehle element ko aur uske pehle component ke pehle element ko print karaya hai, (eg ke liye node 3 se node 2 jaana possible nahi hoga), toh scc[1][0] to scc[0][0] will be a valid answer	
	*/
	else{
		cout<<"NO\n";
		cout<<scc[1][0]<<" "<<scc[0][0]<<"\n";
	}
	
	
	
	
	
}


signed main(){
	JAI_SHREE_RAM;
	
	// ll tc;	cin>>tc;	while(tc--)
		solve();
}
