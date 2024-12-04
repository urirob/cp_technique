//choose p to be some prime numbers like 29,31,37...
//and chose mod value to standard (int)(1e9)+7

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

};
