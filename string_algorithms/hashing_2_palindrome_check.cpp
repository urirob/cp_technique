//reverse hashing for palindrome check

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

ll mod_mul(ll a,ll b,ll mod){
  a%=mod;
  b%=mod;
  ll res=a*b;
  res+=mod;
  res%=mod;
  return res;
}

ll quick_hash(string s,ll p,ll mod){
  ll ans=s[0]-'a'+1;
  for(int i=1;i<s.length();i++){
    ans=(ans*p + (s[i]-'a'+1))%mod;
  }
  return ans;
}

struct hasher{
  int sz;
  ll mod,p;
  vector<ll>f_hash; //forward-hash or prefix-hash
  vector<ll>pwr_p;  //creating power of p array to avoid use of binpow function (0(logn)) to make the substring hash values in 0(1)
    vector<ll>rev_hash;

  //preprocessing
  void init(string s,ll _p,ll _mod){
    mod=_mod;
    p=_p;

    sz=s.length();
    f_hash.resize(sz);

    f_hash[0]=(s[0]-'a'+1);

    pwr_p.assign(sz,0);
    pwr_p[0]=1;
    for(int i=1;i<s.length();i++){
      pwr_p[i]=(pwr_p[i-1]*p)%mod;
      f_hash[i]=(f_hash[i-1]*p + (s[i]-'a'+1))%mod;
    }

    rev_hash.resize(sz);
    rev_hash[sz-1]=(s[0]-'a'+1);
    for(int i=s.length()-2;i>=0;i--){
        rev_hash[i]=(rev_hash[i+1]*p + (s[i]-'a'+1))%mod;
    }

  }

  //finding substring hash from prefix hash in 0(1)
  ll get_f_hash(int l,int r){
    //finding hash value of s[l...r]
    if(l==0) return f_hash[r];
    ll ans=f_hash[r]-(f_hash[l-1]*pwr_p[r-l+1]);
    ans%=mod;
    ans+=mod;
    ans%=mod;
    return ans;
  }

  ll get_rev_hash(int l,int r){
    if(l==0) return rev_hash[r];
    ll ans=rev_hash[l]-(rev_hash[r+1]*pwr_p[r-l+1]);
    ans%=mod;
    ans+=mod;
    ans%=mod;
    return ans;
  }



};

void solve();

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tc=1;
  //cin>>tc;
  while(tc--){
    solve();
  }
}



string s;
int n;

void solve(){
    s="abcbdabad";
    n=s.length();

    hasher s_hash;
    s_hash.init(s,37,999'999'929);

    if(s_hash.get_f_hash(1,3)==s_hash.get_rev_hash(1,3)){
        cout<<"palindrome found\n";
    }
    else{
        cout<<"palindrome not found\n";
    }

}
