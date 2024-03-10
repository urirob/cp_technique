// rehn dita
// #include <algorithm>
// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
// #include <math.h>
// #include <string>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 #define endl "\n";
 #define nline cout<<"\n";
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define all(x)            (x).begin(),(x).end()
#define all1(v) (v).begin()+1,(v).end()
#define pb push_back
#define INF 1e18
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define I insert
#define F first
#define S second
#define B begin()
//#define L length()
#define E end():tabnew 
#define lb lower_bound
#define ub upper_bound
#define umap unordered_map
#define uset unordered_set
#define rep(i,a,b)   for(ll i=a;i<b;i++)
#define per(i,n,b)   for(ll i=n;i>=b;i--)
#define pii pair<ll,ll>
#define NO           cout<<"NO"<<endl;
#define YES          cout<<"YES"<<endl;
#define pprt(v,n) for(ll i=0;i<n;i++) cout<<v[i].F<<" "<<v[i].S<<endl;
#define dbg(var) cerr<<#var<<"="<<var<<" "
#define sz(x) (ll)x.size()
#define mxe(v)  *max_element(v.begin(),v.end())     // find max element in vector
#define mne(v)  *min_element(v.begin(),v.end())     // find min element in vector
#define max3(a,b,c) max(max((a),(b)),(c))
#define max4(a,b,c,d) max(max((a),(b)),max((c),(d)))
#define min3(a,b,c) min(min((a),(b)),(c))
#define min4(a,b,c,d) min(min((a),(b)),min((c),(d)))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef vector<ll> VL;
typedef vector<double> VD;
typedef vector<vector<bool> > VVB;
typedef priority_queue<ll> PQ;
typedef priority_queue<ll,VL,greater<ll> > MPQ;
typedef vector<bool> VB;
typedef queue<ll> QU;
typedef stack<ll> ST;
typedef set<ll> SL;
typedef set<pair<ll,ll> > SPL;
typedef vector<char> VCH;
typedef vector<vector<ll> > VVL;
typedef vector<vector<char> > VVCH;
typedef vector<vector<pair<ll,ll> > > VVPL;
typedef vector<pair<ll,ll> > VPL;
//ll MOD=998244353;
ll mod=1e9+7;
//constexpr long long inf = 1e18;
const ll maxm=1e5+10;
ll maxn=5e5+1;
const ll N =1e6+10;
//const ll inf=9999999999999;
using namespace std;
double M_Pi=3.14159265358979323846;

void _print(ll t) {cerr << t;}
//void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]"<<endl;}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{cerr<<*it<<": ";_print(a); cerr << ", "; err(++it, args...);};
#ifndef ONLINE_JUDGE
#define debug(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cerr<<"\n";};
#else
#define debug(args...)
#endif

//-----------------LEGEND-H-----------------//

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}

ll expo(ll a, ll b, ll mod) {a %= mod;ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}

ll pwr(ll a, ll b, ll mod) {a %= mod; ll res = 1; while (b > 0) {if (b & 1) res = res * a % mod; a = a * a % mod; b >>= 1;} return res;}

void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3

ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b

ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}

ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}

vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}

ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}

ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}

ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m

ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))

ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}

ll Floor(ll a, ll b) {  ll val = a / b; while(val * b > a)  val--;  return val;}

ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}

VL spf(maxn,0);

void sieve()
{
    spf[1] = 1;
    for(ll i = 2 ; i<maxn ; ++i)
    {
        if(!spf[i])
        {
            spf[i] = i;
            for(ll j=i*i ; j<maxn ; j+=i)
            {   
                if(!spf[j]) spf[j] = i;
            }   
        }
    }
}
 
VL factorize(ll n){ VL ans; while (n > 1){ ll fact = spf[n]; while (n % fact == 0) { n /= fact; }ans.pb(fact); } return ans; }
/*
  primefactorizations and count of factor cut and paste for it

  map<ll,ll>mp;
        vector<pll>vec;
        for(i = 2;i*i<=n;i++)
        {
            if(n%i == 0)
            {
                ll cnt = 0;
                while(n%i == 0)
                {
                    n/=i;
                    cnt++;
                }
                mp[i]+=cnt;
            }
        }
        if(n > 1)mp[n] = 1;


when u wanna use copy it!
*/
vector<bool> isprime(N+1,true);
VL primes;
void is_prime(){

    rep(i,2,N+1)
    {
        if(isprime[i])
        {
            primes.pb(i);
            for(ll j = 2*i;j<=N;j+=i)
            {
                isprime[j] = false;
            }
        }
    }
    isprime[1]=false;
}


////////////////////I/O-START/////////////////////

template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }

template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }

template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }

template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD> > &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }

template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }

template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}

template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}


////////////////////I/O-END///////////////////////////

void _print(vector<int> v){
    cerr<<"[ ";
    for(auto i:v){
        cerr<<i<<" ";
    }
    cerr<<"]"<<endl;
}
 
/////////////////CUSTOM-HASH/////////////////////////

//umap<ll,ll,custom_hash> color like

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

////////////////CUSTOM-HASH///////////////////////////

//////////////////////DSU/////////////////////////////

class dsu {
 public:
  vector<int> p;
  int n;
 
  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }
 
  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }
 
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};

//////////////////////bit function//////////////////// 

//__builtin_clz(k) // for leading zero(total);
 
string tostring(ll x){
    return bitset<32>(x).to_string();
}

//////////////////////bit function//////////////////
void init_code(){
   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
////////////////NCR write init() in main////////////
const int32_t M=1e9+7;
#define PRIME   M
ll pw(ll a,ll p=M-2,ll mod=M){
    ll result = 1;
    while (p > 0) {
        if (p & 1)
            result = a * result % mod;
        a = a * a % mod;
        p >>= 1;
    }
    return result;
}

ll fact[N],invfact[N];

void init(){
    ll p=PRIME;
    fact[0]=1;
    ll i;
    for(i=1;i<N;i++){
        fact[i]=i*fact[i-1]%p;
    }
    i--;
    invfact[i]=pw(fact[i],p-2,p);
    for(i--;i>=0;i--){
        invfact[i]=invfact[i+1]*(i+1)%p;
    }
}
ll ncr(ll n,ll r){
    if(r > n || n < 0 || r < 0)return 0;
    return fact[n]*invfact[r]%PRIME*invfact[n-r]%PRIME;
}


/////////////////topo//////////////////////
/*                c&p
        while (!q.empty())
        { 
            ll curr_node = q.front();
            topo.pb(curr_node);
            q.pop();
            for (auto x : adj[curr_node])
            {
                indegree[x]--;
                if (indegree[x] == 0)
                {
                    q.push(x);
                }
            }
        }
*/
//////////////////////////////////////////


//---------------LEGEND-H----------------//


/*
KEYNOTES:
------------------------------------------
merge(X,identity_element) = X
------------------------------------------
------------------------------------------
identity_transformation.combine(X) = X
------------------------------------------
------------------------------------------
ALWAYS: older_update.combine(newer_update)
------------------------------------------
*/
 
 
 
// example: addition: identity element is 0
 
// a + 0 = a or 0 + a = a
 
// min(x,INF) = x
 
struct my_node
{
    ll mn = (1ll<<32)-1;

    // use more variables if you want more information
    // these default values should be identity_element
    my_node(){}
    my_node(int val){
        mn = val;
    }
    void merge(const my_node &l,const my_node &r){ // store the thing you wanna query
    
        mn=l.mn&r.mn;   
        // if we wanted the maximum, then we would do
        // like v = max(l.v,r.v)
    }

};
 
// example: add on a range: identity transformation = 0
// old += new
 
// if old is identity which is 0, then 0 + new which new
 
struct my_update
{
    ll v = 0; // 4
    // use more variables if you want more information
    // these default values should be identity_transformation
    my_update(){}
    my_update(ll val){
        v = val; // 5
    }
    // combine the current my_update with the other my_update (see keynotes)
    void combine(my_update &other,const ll &tl,const ll &tr){
        v = v|other.v; // 6
        // you can be sure that the "other" is newer than current
 
    }
    // store the correct information in the my_node x
    void apply(my_node &x,const ll &tl,const ll &tr){
 
        // no change in freq
        x.mn=x.mn|v;
    }
};
 
template<typename node,typename update>
struct segtree
{
    ll len;
    vector<node> t;
    vector<update> u;
    vector<bool> lazy;
    node identity_element;
    update identity_transformation;
    segtree(ll l){
        len = l;
        t.resize(4 * len);
        u.resize(4 * len);
        lazy.resize(4 * len);
        identity_element = node();
        identity_transformation = update();
    }
 
    void pushdown(const ll &v, const ll &tl, const ll &tr){
        if(!lazy[v]) return;
        ll tm = (tl + tr) >> 1;
        apply(v<<1,tl,tm,u[v]);
        apply(v<<1|1,tm+1,tr,u[v]);
        u[v] = identity_transformation;
        lazy[v] = 0;
    }
 
    void apply(const ll &v, const ll &tl, const ll &tr, update upd){
        if(tl != tr){
            lazy[v] = 1;
            u[v].combine(upd,tl,tr);
        }
        upd.apply(t[v],tl,tr);
    }
 
    template<typename T>
    void build(const T &arr,const ll &v, const ll &tl, const ll &tr){
        if(tl == tr){
            t[v] = arr[tl];
            return;
        }
        ll tm = (tl + tr) >> 1;
        build(arr,v<<1,tl,tm);
        build(arr,v<<1|1,tm+1,tr);
        t[v].merge(t[v<<1],t[v<<1|1]);
    }
 
    node query(const ll &v,const ll &tl,const ll &tr,const ll &l,const ll &r){
        if(l > tr || r < tl){
            return identity_element;
        }
        if(tl >= l && tr <= r){
            return t[v];
        }
        pushdown(v,tl,tr);
        ll tm = (tl + tr) >> 1;
        node a = query(v<<1,tl,tm,l,r),b = query(v<<1|1,tm+1,tr,l,r),ans;
        ans.merge(a,b);
        return ans;
    }
 
    // rupd = range update
    void rupd(const ll &v,const ll &tl,const ll &tr,const ll &l,const ll &r,const update &upd){
        if(l > tr || r < tl){
            return;
        }
        if(tl >= l && tr <= r){
            apply(v,tl,tr,upd);
            return;
        }
        pushdown(v,tl,tr);
        ll tm = (tl + tr) >> 1;
        rupd(v<<1,tl,tm,l,r,upd);
        rupd(v<<1|1,tm+1,tr,l,r,upd);
        t[v].merge(t[v<<1],t[v<<1|1]);
    }
 
    public:

    template<typename T>
    void build(const T &arr){
        build(arr,1,0,len-1);
    }
    node query(const ll &l,const ll &r){
        return query(1,0,len-1,l,r);
    }
    void rupd(const ll &l,const ll &r,const update &upd){
        rupd(1,0,len-1,l,r,upd);
    }
};

template<typename NODE,typename UPDATE>
struct segtree{
    bool built=false;
    bool lazy[4*500000];
    NODE zero=NODE(),t[4*500000];
    UPDATE noop=UPDATE(),upds[4*500000];
    ll tl[4*500000],tr[4*500000];
    inline void pushdown(ll v)
    {
        if(lazy[v]){
            apply(v*2,upds[v]);
            apply(v*2+1,upds[v]);
            lazy[v]=0;
            upds[v]=noop;
        }
    }
    inline void apply(ll v,UPDATE &val)
    {
        if(tl[v]!=tr[v]){
            lazy[v]=1;
            upds[v].combine(val,tl[v],tr[v]);
        }
        val.apply(t[v],tl[v],tr[v]);
    }
    template<typename T>
    void build(T &a, ll v, ll l, ll r) {
        tl[v]=l;
        tr[v]=r;
        if (l == r) {
            t[v]=a[l];
            //change in this position when required
            //e.g ->t[v].mni = t[v].mxi = l;
            return;
        } else {
            ll tm = (l + r) / 2;
            build(a, v*2, l, tm);
            build(a, v*2+1, tm+1, r);
            t[v].merge(t[v*2],t[v*2+1]);
        }
    }
    NODE query(ll v, ll l, ll r) {
        if (l > tr[v] || r < tl[v])
            return zero;
        if (l <= tl[v] && tr[v] <= r) {
            return t[v];
        }
        pushdown(v);
        NODE a,b,ans;
        a=query(v*2, l, r);
        b=query(v*2+1, l, r);
        ans.merge(a,b);
        return ans;
    }
    void rupd(ll v, ll l, ll r, UPDATE &val)
    {
        if(l > tr[v] || r < tl[v])
            return;
        if(l <= tl[v] && tr[v] <= r)
        {
            apply(v,val);
            return;
        }
        pushdown(v);
        rupd(v*2,l,r,val);
        rupd(v*2+1,l,r,val);
        t[v].merge(t[v*2],t[v*2+1]);
    }
    template<typename T>
    ll descent_right(ll l, T x, ll v, NODE &prev) {
        if (l > tr[v]) // node is completely out of range
            return len;
        if(l <= tl[v]){ // node is completely in range
            NODE cur;
            cur.merge(prev,t[v]);
            if (!cur.check(x)){ // go further right than this node
                swap(prev,cur); // merging this node's contribution
                return len;
            }
            if (tl[v]==tr[v]) {
                return tr[v];
            }
        }
        pushdown(v);
        ll ans=descent_right(l, x, v*2, prev); // trying to find in left child
        if(ans!=len)return ans; // found in left child
        return descent_right(l, x, v*2+1, prev); // finding in right child
    }
    template<typename T>
    ll descent_left(ll r, T x, ll v, NODE &prev) {
        if (r < tl[v]) // node is completely out of range
            return -1;
        if(r >= tr[v]){ // node is completely in range
            NODE cur;
            cur.merge(t[v],prev);
            if (!cur.check(x)){ // go further left than this node
                swap(cur,prev); // merging this node's contribution
                return -1;
            }
            if (tl[v]==tr[v]) {
                return tl[v];
            }
        }
        pushdown(v);
        ll ans=descent_left(r, x, v*2+1, prev); // trying to find in right child
        if(ans!=-1)return ans; // found in right child
        return descent_left(r, x, v*2, prev); // finding in left child
    }
    
    ll len=maxn;
    void clear(){
        fill(t,t+4*len,zero);
        fill(lazy,lazy+4*len,false);
        fill(upds,upds+4*len,noop);
        built = false;
    }
    template<typename T>
    void build(T &a){
        build(a,1,0,len-1);
        built=true;
    }
    template<typename T>
    ll descent_right(ll l, T x){ // minimum r such that [l...r].check(x) == true, returns segtree.len if not found
        NODE prev=zero;
        return descent_right(l,x,1,prev);
    }
    template<typename T>
    ll descent_left(ll r, T x){ // maximum l such that [l...r].check(x) == true, returns -1 if not found
        NODE prev=zero;
        return descent_left(r,x,1,prev);
    }
    NODE query(ll l,ll r){
        if(!built)build(t);
        return query(1,l,r);
    }
    void rupd(ll l,ll r,UPDATE val){
        if(!built)build(t);
        rupd(1,l,r,val);
    }
};
 
#define node node1
#define update update1
struct node{
    // ll mn=INF,mx=-INF;
    // ll mni=-1,mxi=-1;
    node(){}
    node(ll val){
        // mn=val;
        // mx=val;
    }
    void merge(node &l,node &r)
    {
        // if(l.mn<r.mn){
        //     mn=l.mn;
        //     mni=l.mni;
        // }
        // else{
        //     mn=r.mn;
        //     mni=r.mni;
        // }

        // if(l.mx>r.mx){
        //     mx=l.mx;
        //     mxi=l.mxi;
        // }
        // else{
        //     mx=r.mx;
        //     mxi=r.mxi;
        // }
    }
    bool check(pii x){
       // if(x.S==0){
       //  return mx>x.F;
       // }
       // return mn<x.F;
    }
};
struct update{

    update(){}
    update(ll val){
 
    }
    void combine(update &other,ll tl,ll tr){
        
    }
    void apply(node &x,ll tl,ll tr){
    
    }
};
segtree<node,update> t;
//in main
//t.len=n;
//t.clear();
//t.build(v);
#undef node
#undef update


struct sparseTable
{
    //sparseTable sp1;
    //sp1.init(n(size));
    //sp1.build(left(array));
    ll n,k;
    vector< vector<ll> > table;
    vector<ll> logs;
    
    void init1(ll x)
    {
            n=x;
            logs.resize(n+1);
            logs[1]=0;
            for(ll i=2;i<=n;i++)
                    logs[i]=logs[i/2]+1;
            k=*max_element(logs.begin(),logs.end());
            table.resize(k+1,vector<ll> (n+1,-1e9) );
    }
 
    ll operation(ll x,ll y)
    {
        return std::max(x,y);
    }
 
    void build(vector<ll> &arr)
    {
        for(ll i=0;i<n;i++)
                table[0][i]=arr[i];
 
        for(ll j=1;j<=k;j++)
        {
            for(ll i=0;i+(1<<j)<=n;i++)
                table[j][i]=operation(table[j-1][i],table[j-1][i+(1<<(j-1))]);
        }
    }
 
    ll query(ll l , ll r)
    {
        ll j = logs[r - l + 1];
        ll answer = operation(table[j][l], table[j][r-(1<<j)+1]);
        return answer;
    }
};




void dfs(ll current,ll p,VVL &adj,VL &parent,VL &d){
    parent[current]=p;
    if(p!=-1){
        d[current]=d[p]+1;
    }
    else{
        d[current]=0;
    }
    for(auto i: adj[current]){
        if(i!=p){
            dfs(i,current,adj,parent,d);
        }
    }
}

ll kthparent(ll x,ll k,VVL &parent){
    ll n=parent[0].size();
    for(ll i=0;i<=log2(n);i++){
        if(k&(1<<i)){
            x=parent[i][x];
            if(x==-1){
                break;
            }
        }
    }
    return x;
}

ll lca(ll a,ll b,vector<vector<ll> > &parents,vector<ll> &d){
    ll diff=abs(d[a]-d[b]);
    if(d[a]>d[b]){
        a=kthparent(a,diff,parents);
    }
    else{
        b=kthparent(b,diff,parents);
    }
   // cout<<a+1<<" "<<b+1<<endl;
    ll l=0,r=parents[0].size();
    if(a==b){
        return a+1;
    }
    while(l+1<r){
        ll mid=(l+r)/2;
        if(kthparent(a,mid,parents)==kthparent(b,mid,parents)){
            r=mid;
        }
        else{
            l=mid;
        }
    }
    return kthparent(a,r,parents)+1;
 
}

ll lca2(ll a,ll b,vector<vector<ll> > &parent,vector<ll> &d){
     ll diff=abs(d[a]-d[b]);
    if(d[a]>d[b]){
        a=kthparent(a,diff,parent);
    }
    else{
        b=kthparent(b,diff,parent);
    }
    ll n=d.size();
    if(a==b){
        return a;
    }
    per(i,log2(n)+1,0){
        ll x=parent[(i)][a];
        ll y=parent[(i)][b];
        if(x!=y){
            a=x;
            b=y;
        }
    
    }
    return parent[0][a];
}

void precompute(vector<vector<ll> > &parent,VL &d,VVL &adj){
    dfs(0,-1,adj,parent[0],d);
    ll n=adj.size();
    rep(k,1,log2(n)+1){
        rep(i,0,n){
           ll inter=parent[k-1][i];
           if(inter!=-1){
             parent[k][i]=parent[k-1][inter];
           }
           else{
             parent[k][i]=-1;
           }
      }
    }
    // cout<<kthparent(4,0,parent)<<endl;
    // ll x,y;
    // cin>>x>>y;
    // x--;
    // y--;
    // cout<<lca(x,y,parent,d)<<endl;
    // write precompute() and define d and parent in solve
    //  vector<vector<ll> > parent(n+2,VL(log2(n+2)));
    // parent[i][k]=2^k parent of i
    // VL d(n,0);
    // precompute(parent,d,adj);
}



ll timer=0;
void dfs(ll current,ll p,VVL &adj, vector<ll> &eut,vector<ll> &st,vector<ll> &end){
    st[current]=timer++;
    eut.pb(current);
    for(auto i: adj[current]){
        if(i!=p){
            dfs(i,current,adj,eut,st,end);
        }
    }
    end[current]=timer++;
    eut.pb(current);
}


class dsu{
    vector<ll> par,size,rank;
public:
    dsu(ll n){
        rep(i,0,n+1){
            par.pb(i);
            rank.pb(0);
            size.pb(1);
        }
    }

    ll find_par(ll node){
        if(par[node]==node){
            return node;
        }
        return par[node]=find_par(par[node]);
    }

    void union_size(ll u,ll v){
        ll pu=find_par(u);
        ll pv=find_par(v);
        if(pu==pv){
            return;
        }
        
        if(size[pu]<size[pv]){
            par[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
             par[pv]=pu;
            size[pu]+=size[pv];
        }
    }

    void union_rank(ll u,ll v){
        ll pu=find_par(u);
        ll pv=find_par(v);
        if(pu==pv){
            return;
        }
        if(rank[pu]<rank[pv]){
            par[pu]=pv;
        }
        else if(rank[pv]<rank[pu]){
            par[pv]=pu;
        }
        else{
            par[pu]=pv;
            rank[pv]++;
        }
    }

    void dsu_union(ll u,ll v){
        ll pu=find_par(u);
        ll pv=find_par(v);
        if(pu==pv){
            return;
        }
        if(pu<pv){
            swap(pu,pv);
        }
        par[pv]=pu;
    }

};


void Dijkstra(ll s, ll n, vector<ll> &dist, vector<ll> &parent,VVPL &adj) {
    dist.assign(n, INF);
    parent.assign(n, -1);
    dist[s] = 0;
    priority_queue <pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > q;
    q.push(mp(0, s));
    while (!q.empty()) {
        pair<ll, ll> here = q.top();
        q.pop();
        ll v = here.S;
        ll d_v = here.F;
        if (d_v != dist[v])
            continue;
        for (auto edge : adj[v]) {
            if (dist[v] + edge.S < dist[edge.F]) {
                dist[edge.F] = dist[v] + edge.S;
                parent[edge.F] = v;
                q.push(mp(dist[edge.F], edge.F));
            }
        }
    }
}

vector<pii> nextGreaterElement(vector<ll> &arr, ll n)
{
        stack<pair<ll,ll> > st;   
        vector<pii> ans;
        for(ll i=n-1;i>=0;i--){
            if(st.empty()){
                ans.push_back(mp(-1,-1));
                st.push(mp(arr[i],i));
                continue;
            }
            else{        
                while(!st.empty() && st.top().F<=arr[i]){
                    st.pop();
                }
               if(st.size()==0){
                   ans.push_back(mp(-1,-1));
               }
               else{
                   ans.push_back(st.top());
               }
                st.push(mp(arr[i],i));
            }
           
        }
        reverse(ans.begin(),ans.end());
        return ans;
}

vector<pii> nextSmallerElement(vector<ll> &arr, ll n)
{
        stack<pair<ll,ll> > st;   
        vector<pii> ans;
        for(ll i=n-1;i>=0;i--){
            if(st.empty()){
                ans.push_back(mp(-1,-1));
                st.push(mp(arr[i],i));
                continue;
            }
            else{        
                while(!st.empty() && st.top().F>=arr[i]){
                    st.pop();
                }
               if(st.size()==0){
                   ans.push_back(mp(-1,-1));
               }
               else{
                   ans.push_back(st.top());
               }
                st.push(mp(arr[i],i));
            }
           
        }
        reverse(ans.begin(),ans.end());
        return ans;
}

vector<pii> prevGreaterElement(vector<ll> &arr, ll n)
{
        stack<pair<ll,ll> > st;   
        vector<pii> ans;
        for(ll i=0;i<n;i++){
            if(st.empty()){
                ans.push_back(mp(-1,-1));
                st.push(mp(arr[i],i));
                continue;
            }
            else{        
                while(!st.empty() && st.top().F<=arr[i]){
                    st.pop();
                }
               if(st.size()==0){
                   ans.push_back(mp(-1,-1));
               }
               else{
                   ans.push_back(st.top());
               }
                st.push(mp(arr[i],i));
            }
           
        }
        return ans;
}

vector<pii> prevSmallerElement(vector<ll> &arr, ll n)
{
        stack<pair<ll,ll> > st;   
        vector<pii> ans;
        for(ll i=0;i<n;i++){
            if(st.empty()){
                ans.push_back(mp(-1,-1));
                st.push(mp(arr[i],i));
                continue;
            }
            else{        
                while(!st.empty() && st.top().F>=arr[i]){
                    st.pop();
                }
               if(st.size()==0){
                   ans.push_back(mp(-1,-1));
               }
               else{
                   ans.push_back(st.top());
               }
                st.push(mp(arr[i],i));
            }
           
        }
        return ans;
}

class FenwickTree{
    public:
        ll n;
        vector<ll> bit;

        FenwickTree(vector<ll> &a): n(a.size()),bit(n+1){
            rep(i,0,n){
                upd(i,a[i]);
            }
        }

        void upd(ll i,ll x){
            for(i++;i<=n;i+=(i&-i)) bit[i]+=x; 
        }

        ll sum(ll i){
            ll s=0;
            for(i++;i>0;i-=i&-i){
                s+=bit[i];
            }
            return s;
        }

        ll query(ll l,ll r){
            return sum(r)-sum(l-1);
        }

};


struct Node{
    Node* arr[26];
    bool flag=false;

    bool contains(char c){
        return arr[c-'a']!=NULL;
    }

    void put(char c,Node* newNode){
        arr[c-'a']=newNode;
    }

    Node* getNext(char c){
        return arr[c-'a'];
    }

    void setFlag(){
        flag=true;
    }

};

Node* root=new Node();

void insert(string word){
    Node* temp=root;
    for(ll i=0;i<word.size();i++){
        if(!temp->contains(word[i])){
            Node* newNode=new Node();
            temp->put(word[i],newNode);

        }
       temp=temp->getNext(word[i]);
    }
    temp->setFlag();
}

bool search(string word){
    Node* temp=root;
    for(ll i=0;i<word.size();i++){
        if(temp->contains(word[i])){
            temp=temp->getNext(word[i]);
        }
        else{
            return false;
        }
    }
    if(temp->flag==true){
        return true;
    }
    else{
        return false;
    }
}

bool startsWith(string word){
    Node* temp=root;
    for(ll i=0;i<word.size();i++){
        if(temp->contains(word[i])){
            temp=temp->getNext(word[i]);
        }
        else{
            return false;
        }
    } 
    return true;
    
}


struct Node{
    Node* arr[26];
    ll cntWordEnd=0;
    ll cntPrefixs=0;

    bool contains(char c){
        return arr[c-'a']!=NULL;
    }

    void put(char c,Node* newNode){
        arr[c-'a']=newNode;
    }

    Node* getNext(char c){
        return  arr[c-'a'];
    }

    void increaseWordEndWith(){
        cntWordEnd++;
    }
    
    void increaseWordPrefixs(){
        cntPrefixs++;
    }

    void decreaseWordEndWith(){
        cntWordEnd--;
    }

    void decreaseWordPrefixs(){
        cntPrefixs--;
    }

    ll getCountWordEnd(){
        return cntWordEnd;
    }

    ll getCountWordPrefixs(){
        return cntPrefixs;
    }

};

Node* root=new Node();

void insert(string word){
    Node* temp=root;
    for(ll i=0;i<word.size();i++){
        if(!temp->contains(word[i])){
            Node* newNode=new Node();
            temp->put(word[i],newNode);

        }
        temp->increaseWordPrefixs();
       temp=temp->getNext(word[i]);
    }
    temp->increaseWordEndWith();
}

ll countWordsEqualTo(string word){
    Node* temp=root;
    for(ll i=0;i<word.size();i++){
        if(temp->contains(word[i])){
            temp=temp->getNext(word[i]);
        }
        else{
            return false;
        }
    }
    return temp->getCountWordEnd();
}

ll startsWith(string word){
    Node* temp=root;
    for(ll i=0;i<word.size();i++){
        if(temp->contains(word[i])){
            temp=temp->getNext(word[i]);
        }
        else{
            return 0;
        }
    } 
    return temp->getCountWordPrefixs();
    
}

void erase(string word){
    Node* temp=root;
    if(countWordsEqualTo(word)==0){
        return;
    }
    for(ll i=0;i<word.size();i++){
        temp->decreaseWordPrefixs();
        temp->getNext(word[i]);
    }
    temp->decreaseWordEndWith();
}




void solve()
{   
    

   
}     

int main(){

    #ifndef ONLINE_JUDGE
       freopen("error.txt","w",stderr);
    #endif

    IOS

    ll t = 1;
    init_code();
    //sieve();

   //  init();
    // is_prime();
    cin>>t;
   
    // cout<<setprecision(10);
    // coun<<fixed;

    for(ll i=0;i<t;i++){
     //   cout<<"Case #"<<i+1<<": ";
        solve();
    }

}
