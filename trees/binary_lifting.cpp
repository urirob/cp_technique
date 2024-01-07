//Jai shree ram
 
//Be Consistent,Be Extraordinary

//watashi wa shinu ka seiko suru ka no dochira ka desu ga 、 akirame mase nichi
 
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
#define eb emplace_back
#define pb push_back
#define YES          cout<<"YES"<<endl;
#define NO           cout<<"NO"<<endl;
#define sz(x)   (ll)x.size()
#define all(x)  (x).begin(),(x).end()
 
#define mxe(v)  *max_element(v.begin(),v.end())     // find max element in vector
#define mne(v)  *min_element(v.begin(),v.end())     // find min element in vector

#define set_bits(x)	__builtin_popcountll(x)


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
typedef vector<string> VS;
typedef vector<vector<string> > VVS;
 
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
 
ll expo(ll a, ll b, ll mod=MOD) {a %= mod;ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
 
ll pwr(ll a, ll b, ll mod=MOD) {a %= mod; ll res = 1; while (b > 0) {if (b & 1) res = res * a % mod; a = a * a % mod; b >>= 1;} return res;}
 
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
 
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
 
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
 
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
 
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
 
ll mod_add(ll a, ll b, ll m=MOD) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
 
ll mod_mul(ll a, ll b, ll m=MOD) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
 
ll mod_sub(ll a, ll b, ll m=MOD) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
 
ll mod_div(ll a, ll b, ll m=MOD) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
 
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
 
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
 
ll floor_div(ll a, ll b) {  ll val = a / b; while(val * b > a)  val--;  return val;}
 
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
//__builtin_popcountll(x) //for leading ones 
 
 
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
 
 
//kth ancestor of given node 


//node are given in query (q<=1e5), need to find the kth ancestor of node given in each of the query 

void dfs(int current_node,int parent,VVL&adj,VL&first_parent_of_each_node){
	first_parent_of_each_node[current_node]=parent;
	
	for(int neighbour:adj[current_node]){
		if(neighbour!=parent){
			dfs(neighbour,current_node,adj,first_parent_of_each_node);
		}
	}
}



//find the kth parent of node 'x'
int kth_parent(int x,int k,VVL&parents){
	
	//iterate on all the bits of number 'k'
	int n=parents[0].size();
	
	for(int i=0;i<=log2(n);i++){
		//if the ith bit in 'k' is set 
		if(k&(1<<i)){
			x=parents[i][x];
			
			if(x==-1){		//if we go outside the tree, then we can just break
				break;
			}
		}
		
	}
	
	//k=84 -> 64+16+4
	//x-4th parent-> y-16th parent-> z-64th parent-> w
	return x;
	
	//15->1111
	//15&8=8--> third bit is set in 15
	/*
	1<<i=2^i
	
	0101010100111
		AND
	0000010000000
	-------------
	0000010000000
	
	
	bit is set at ith position 
	
	*/
}





void solve(){
   
	int n;
	cin>>n;
	VVL adj(n);
	rep(i,0,n-1){
		int u,v;
		cin>>u>>v;
		u--,v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
 	
 	dfs(0,-1,adj);

	VL first_parent_of_each_node(n,0); 
  
  	//each array represents-> first_parent_of_each_node,second_parent_of_each_node,fourth_parent_of_each_node,eight_parent_of_each_node,...,(log2(n))th parent_of_each_node
  	VVL parents(log2(n)+1,VL(n));
  	//parents[(log2(n))+1][n]
  	
  	//parents[0]=(2^0)th parent of each node(its the first parent of each node)
  	dfs(0,-1,adj,parents[0]);
  	
  	for(int k=1;k<=log2(n);k++){
  		//find out 2^kth parent of every node
  		//parents[k][i]=2^kth parent of node i
  		//parents[k][i]=2^(k-1)th parent node of [2^(k-1)th parent of node 'i']
  		
  		
  		
  		//i->intermediate->goal
  		//goal=2^kth parent of i
  		//goal=2^(k-1)th parent of intermediate
  		//intermediate=2^(k-1)th parent of i
  		for(int i=0;i<n;i++){
  			//parents[k-1][i]=intermediate
  			int intermediate=parents[k-1][i];
  			//parents[k][i]=parents[k-1][intermediate]
  			if(intermediate!=-1){
  				parents[k][i]=parents[k-1][intermediate];
  			}
  			
  			else{
  				parents[k][i]=-1;
  			}
  			
  		}
  	}
  
  
  
  
  
  
}
 
 
 
signed main(){
  JAI_SHREE_RAM;		//disable this in interactive problem, and use endl instead of "\n"
 
   // ll tc; cin>>tc;	while(tc--)
        solve();
     
 
return 0;
}
