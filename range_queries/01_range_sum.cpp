#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

int arr[200200];

struct node{
  int sum;
  node(){
    sum=0;
  }
};

node merge(node a,node b){
  node ans;
  ans.sum=a.sum+b.sum;
  return ans;
}

node t[4*(200200)];

void build(int id,int l,int r){
  if(l==r){
    //leaf node
    t[id].sum=0;
    return;
  }

  int mid=(l+r)/2;

  build(2*id,l,mid);
  build(2*id+1,mid+1,r);


  t[id]=merge(t[2*id],t[2*id+1]);

}

void update(int id,int l,int r,int pos,int val){
    if(pos<l || pos>r){
      return;
    }

    if(l==r){
      t[id].sum+=val;
      return;
    }

    int mid=(l+r)/2;
    update(2*id,l,mid,pos,val);
    update(2*id+1,mid+1,r,pos,val);
    t[id]=merge(t[2*id],t[2*id+1]);



}

node query(int id,int l,int r,int lq,int rq){
    if(lq>r && rq<l){
      return node();
    }
    if(lq<=l && rq>=r){
      return t[id];
    }

    int mid=(l+r)/2;
    return merge(query(2*id,l,mid,lq,rq),query(2*id+1,mid+1,r,lq,rq));


}

void solve(){
  int n,q;
  cin>>n>>q;

  for(int i=1;i<=n;i++){
    cin>>arr[i];
  }

  build(1,1,n);

  while(q--){
    int ch;
    cin>>ch;
    if(ch==1){
      int l,r,val;
      cin>>l>>r>>val;

      update(1,1,n,l,val);
      update(1,1,n,r+1,-val);
      // p[l]+=val;
      // p[r+1]-=val;

    }

    else{
      int pos;
      cin>>pos;

      node ans=query(1,1,n,1,pos);
      cout<<ans.sum+arr[pos]<<"\n";

    }
  }
    


}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tc=1;
  // cin>>tc;
  while(tc--){
    solve();
  }
}
