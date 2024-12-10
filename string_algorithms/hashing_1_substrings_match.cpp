#include<bits/stdc++.h>
using namespace std;

struct hasher{
    int n, _k, _p;
    vector<int> powk,base;
 
    void init(string s,int k,int p){
        _k = k, _p = p;
        n = s.length();
        powk.resize(n+1);
        base.resize(n+1);
        // precompute
        base[0] = 0;
        powk[0] = 1;
        for(int i=0;i<n;i++){
            int num = (s[i]-'a'+1 )%p;
            base[i+1] = (1LL *base[i] * k + num)%p;
            powk[i+1] = (1LL* k * powk[i]) %p;
        }
    }  
    int gethash(int l,int r){ // 0 index
        int ans = (base[r+1] - 1LL *base[l]*powk[(r-l+1)])%_p;
        return (ans+_p)%_p;
    }
};

int n;
 
void solve(){
    string s;
    cin>>s;
    hasher hasha,hashb;
    //two different hasher for single string to reduce the probability collision of having same value for two different substrings
    hasha.init(s,37,1000000021);
    hashb.init(s,39,1000000009);
    
    set<pair<int,int>> st;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            st.insert({hasha.gethash(i,j),hashb.gethash(i,j)});
        }
    }


    for(auto i:st){
      cout<<i.first<<" "<<i.second<<"\n";
    }
}
 
int main()
{
    solve();
    return 0;
}
