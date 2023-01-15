//जय श्री राम
//29-01-2021 3:15pm
/* YOU ARE NOT DOING IT FOR SOMEONE ELSE OR TO PROVE SOMEONE YOU ARE DOING IT TO RAISE YOUR STANDARD
AND GET OUT THIS HELL 		NO ONE CARES */

// Take examples for small test cases on pen paper if not understanding algorithm
// DEBUG YOUR CODE YOURSELF, GOOGLE IS YOUR BEST FRIEND FOR DEBUGGING
/*
RANGES OF DATA TYPES
int 						 n<=10^9				
long long int				 n~10^18	
unsigned long long int		 0<n<10^19
*/


#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <unordered_map>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n";
#define nline cout<<"\n";
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define all(x)            (x).begin(),(x).end()
#define pb push_back
#define INF 1e18
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
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define per(i,n,b) for(ll i=n;i>=b;i--)
#define pii   pair<ll,ll>
#define prtno cout<<"NO"<<endl;
#define prtyes cout<<"YES"<<endl;
#define pprt(v,n) for(ll i=0;i<n;i++) cout<<v[i].F<<" "<<v[i].S<<endl;
#define dbg(var) cout<<#var<<"="<<var<<" "
#define sz(x) (ll)x.size()
#define mxe(v)  *max_element(v.begin(),v.end())     // find max element in vector
#define mne(v)  *min_element(v.begin(),v.end())     // find min element in vector
#define max3(a,b,c) max(max((a),(b)),(c))
#define max4(a,b,c,d) max(max((a),(b)),max((c),(d)))
#define min3(a,b,c) min(min((a),(b)),(c))
#define min4(a,b,c,d) min(min((a),(b)),min((c),(d)))
using namespace std;
typedef long long ll;
typedef vector<ll> VL;
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
ll MOD=998244353;
ll mod=1e9+7;
//constexpr long long inf = 1e18;
const int maxm=1e5+10;
ll maxn=3e5+1;
ll N = 100005;
using namespace std;
 
//-----------------URIROB-----------------//
 
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
 
ll Floor(ll a, ll b) {	ll val = a / b;	while(val * b > a)	val--;	return val;}
 
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
 
string isPalindrome(string S)
{
    // Iterate over the range [0, N/2]
    for (int i = 0; i < S.length() / 2; i++) {
 
        // If S[i] is not equal to
        // the S[N-i-1]
        if (S[i] != S[S.length() - i - 1]) {
            // Return No
            return "No";
        }
    }
    // Return "Yes"
    return "Yes";
}
/*
 *
when u wanna use copy it!
 
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
}
*/
 
////////////////////I/O-START/////////////////////
 
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
 
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
 
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
 
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD> > &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
 
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
 
////////////////////I/O-END///////////////////////////
 
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
 
///////////////////////////////////////////////////////
 
//---------------somtimes use-------------// 
/*
 
__builtin_clz(k) // for leading zero(total);
 
ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}
 
ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
 
ll mod_add(ll a, ll b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}
 
ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);}
 
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
 
ll pwr(ll a, ll b) {a %= mod; ll res = 1; while (b > 0) {if (b & 1) res = res * a % mod; a = a * a % mod; b >>= 1;} return res;}
 
// change this N as required
VL fact(N + 1, 1);
VL ifact(N + 1, 1);
ll C(ll n, ll r)
{
    if (r > n)return 0;
    ll ans = fact[n];
    ans = mod_mul(ans, ifact[r],mod);
    ans = mod_mul(ans, ifact[n - r],mod);
    return ans;
 
    // cut this part from here and paste inside the main function and outside while(t--)
 
}
*/