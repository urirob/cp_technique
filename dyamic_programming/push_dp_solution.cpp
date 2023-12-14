// Problem: C. Chef Monocarp
// Contest: Codeforces - Educational Codeforces Round 97 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1437/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//Jai shree ram
 
//Be Consistent,Be Extraordinary

//push-dp solution 
 
 
#include <bits/stdc++.h>
 
using namespace std;
 
//<--------------------TEMPLATE BEGINS-------------------->
 
#define JAI_SHREE_RAM ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
// #define endl '\n'
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repn(i,a,b) for(ll i=a;i<=b;i++)
#define per(i,a,b)	for(ll i=a;i>b;i--)
 
#define mp make_pair
#define F first
#define S second
#define I insert
#define pb push_back
#define eb emplace_back
#define YES          cout<<"YES"<<endl;
#define NO           cout<<"NO"<<endl;
#define sz(x)   (ll)x.size()
#define all(x)  (x).begin(),(x).end()
 
#define mxe(v)  *max_element(v.begin(),v.end())     // find max element in vector
#define mne(v)  *min_element(v.begin(),v.end())     // find min element in vector
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> VL;
typedef vector<vector<ll> > VVL;
typedef pair<ll,ll> pii;
typedef vector<double> VD;
typedef vector<bool> VB;
typedef vector<vector<bool> > VVB;
typedef priority_queue<ll> PQ;
typedef priority_queue<ll,VL,greater<ll> > MPQ;  //min priority queue
typedef set<pair<ll,ll> > SPL;
typedef vector<char> VCH;
typedef vector<vector<char> > VVCH;
typedef vector<vector<pair<ll,ll> > > VVPL;
typedef vector<pair<ll,ll> > VPL;
 
const ll mod=998244353;
const ll MOD=1e9+7;
const ll inf=1e18;
const ld eps=1e-9;
const ll N =3e6+20; 
const ld pie=2*acos(0.0);
 
 
#define int ll

//solving straight lines type problems using gcd
//https://codeforces.com/contest/514/submission/214319537 
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
 
// look for the longest (shortest) segment with some property. Both options are solved using the two pointer method.  
 
 
/*
chicken mcnugget theorem-> if there exists two prime numbers, m and n, then the largest number which can't be represented in the form (m*a + n*b), is (m*n-m-n)
 
https://codeforces.com/contest/1526/submission/226416574
*/
 
 
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
 
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
 
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
 
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD> > &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
 
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
 
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
 
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
 
 
//__builtin_clz(k) // for leading zero(total);
 
 
 
//<---------------NCR write init() in main--------------->
 
const int32_t M=998244353;
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
 
//<------------------------------TEMPLATE ENDS------------------------------->
 
 
 
 
void solve(){
   
	int n;
	cin>>n;
	
	vector<int>arr(n+1,0);
	rep(i,1,n+1){
		cin>>arr[i];
	}
	sort(arr.begin()+1,arr.begin()+n+1);
	/*
	ith dish cooking time=t[i]
	
	at any +ve integer T, chef can't take more than one dish out of the oven, if the ith dish is taken out of oven, at some time T, its unplesant value if abs(T-t[i])
	
	need to put out the all the dishes out of the oven
	
	 
	total minimum pleasant value for all the 'n' dishes
	*/
 
 
 
 	/*
 	observations
 	1) we will remove dishes in the increasing order of t[i], if t[i]<t[j],remove the t[i] before t[j](explaintion in iterative dp lecture)
 	
 	2) upper bound on time taken=2*n
 	
 	since all t[i]<n
 	
 	let dp[i][j]=min cost to remove first 'i' dishes, and in j amount of time
 	
 	final answer=dp[n][2*n]
 	
 	-->transitions(in push_dp fashion)
 	
 	dp[i][j](taken i items with j amount of time taken)=(dp[i+1][j+1](taken i+1 items and j+1 amount of time taken),
 	
 	dp[i][j+1](did not choose next item, and overall amount of time is then j+1))
 	
 						
 	
 	dp[i][j+1]=min(dp[i][j+1],dp[i][j])
 	dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+t[i+1]-(j+1))	//extra time taken to take out the (i+1)th time
 
 	-->base case
 	
 	dp[0][0]=0		//time taken to remove the 0 items in 0 amount of time overall will be 0 minutes
 	
 	rest of dp table can be initialised with infinity
 
 	*/
 
  
  	vector<vector<int> >dp(n+5,vector<int>((2*n)+5,inf));
  	
  	dp[0][0]=0;
  	
  	for(int i=0;i<=n;i++){
  		for(int j=0;j<=2*n;j++){
  			dp[i][j+1]=min(dp[i][j+1],dp[i][j]);
  			
  			dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+abs(arr[i+1]-(j+1)));
  		}
  	}
  
  
  
  
  	cout<<dp[n][2*n]<<"\n";
  
}
 
 
 
signed main(){
  JAI_SHREE_RAM;		//disable this in interactive problem, and use endl instead of "\n"
 
   ll tc; cin>>tc;	while(tc--)
        solve();
     
 
return 0;
}
