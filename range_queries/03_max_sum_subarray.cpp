#include<bits/stdc++.h>

using namespace std;

struct node
{
	int msum,lsum,rsum,totsum;

	node(int a=(int)(-1e9),int b=0,int c=0,int d=0){
		msum=a;
		lsum=b;
		rsum=c;
		totsum=d;
	}
};

node merge(node a,node b){
	node ans;
	ans.msum=max({a.msum,b.msum,a.rsum+b.lsum});
	ans.lsum=max({a.lsum,a.totsum+b.lsum});
	ans.rsum=max({b.rsum,b.totsum+a.rsum});
	ans.totsum=a.totsum+b.totsum;

	return ans;
}

int n,q;
int arr[200200];
node t[800800];

void build(int id,int l,int r){
	if(l==r){
		t[id]=node(arr[l],arr[l],arr[l],arr[l]);
		return;
	}
	int mid=(l+r)/2;
	build(2*id,l,mid);
	build(2*id+1,mid+1,r);

	t[id]=merge(t[2*id],t[2*id+1]);
}


void update(int id,int l,int r,int pos,int val){
	if(pos<l || pos>r) return;
	if(l==r){
		arr[l]=val;
		t[id]=node(arr[l],arr[l],arr[l],arr[l]);
		return;
	}
	int mid=(l+r)/2;
	update(2*id,l,mid,pos,val);
	update(2*id+1,mid+1,r,pos,val);

	t[id]=merge(t[2*id],t[2*id+1]);
}


node query(int id,int l,int r,int lq,int rq){
	if(rq<l || r<lq) return node();
	if(lq<=l && r<=rq){
		return t[id];
	}
	int mid=(l+r)/2;
	return merge(query(2*id,l,mid,lq,rq),query(2*id+1,mid+1,r,lq,rq));
}

void solve(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	build(1,1,n);
	while(q--){
		int pos,val;cin>>pos>>val;
		update(1,1,n,pos,val);
		node x = query(1,1,n,1,n);
		cout<<max((long long)x.msum,0LL)<<endl;
	}
}    
 
  
     
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
    }
 
    return 0;
}
