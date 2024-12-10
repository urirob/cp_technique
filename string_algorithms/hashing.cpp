//choose p to be some prime numbers like 29,31,37...
//and chose mod value to non-standard like (int)(1e9)+9, (int)(1e9)+21 to avoid any collision for hidden test cases

ll mod_mul(ll a,ll b,ll mod){
  a%=mod;
  b%=mod;
  ll res=a*b;
  res+=mod;
  res%=mod;
  return res;
}


//finding hash value for entire string
ll quick_hash(string s,ll p,ll mod){
  ll ans=s[0]-'a'+1;
  for(int i=1;i<s.length();i++){
    ans=(ans*p + (s[i]-'a'+1))%mod;
  }
  return ans;
}

//hashing value for some substring after preprocessing in init function
struct hasher{
  int sz;
  ll mod,p;
  vector<ll>f_hash; //forward-hash or prefix-hash
  vector<ll>pwr_p;  //creating power of p array to avoid use of binpow function (0(logn)) to make the substring hash values in 0(1)

  vector<int>rev_hash; 


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
      for(int i=s.length()-1;i>=0;i--){
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
    if(r==sz-1) return rev_hash[l]; if(l>r) return 0;
    return ((rev_hash[l]-rev_hash[r+1]*pwr_p[r-l+1])%mod+mod)%mod;
  }

};


//31,37,999'999'937,999'999'929

struct double_hash{  //create double hash for single string for length=1e5 to avoid collisions due to same hash value for two different substrings
  hasher h1,h2;
  void init(string &s,int _b1=31,int _b2=37,int _m1=999'999'937,int _m2=999'999'929){
    h1.init(s,_b1,_m1); h2.init(s,_b2,_m2);
  }

  pair<int,int> get_front_hash(int l,int r){
    return make_pair(h1.get_f_hash(l,r),h2.get_f_hash(l,r));
  }

  pair<int,int> get_reverse_hash(int l,int r){
    return make_pair(h1.get_rev_hash(l,r),h2.get_rev_hash(l,r));
  }
};
