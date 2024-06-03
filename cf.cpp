// Jai shree ram
// 一切荣耀归于拉玛勋爵
//  Вся слава Господу Раме
//  ラーマ卿に栄光あれ

// Why you started? Make it a reason for keep it going

// Mehnat aur dimaag tu khud aapna jyotish hai

#include <bits/stdc++.h>

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; // find_by_order, order_of_key

//<--------------------TEMPLATE BEGINS-------------------->

#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define nline '\n'
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define repn(i, a, b) for (ll i = a; i <= b; i++)
#define per(i, a, b) for (ll i = a; i >= b; i--)

#define mp make_pair
typedef long double lld;
#define F first
#define S second
#define I insert
#define eb emplace_back
#define pb push_back
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define sz(x) (ll) x.size()
#define all(x) (x).begin(), (x).end()
#define all1(v) (v).begin() + 1, (v).end()

#define mxe(v) *max_element(v.begin(), v.end()) // find max element in vector
#define mne(v) *min_element(v.begin(), v.end()) // find min element in vector

#define set_bits(x) __builtin_popcountll(x)

// __builtin_clzll(x): the number of zeros at the beginning of the number
// __builtin_ctzll(x): the number of zeros at the end of the number
// __builtin_popcountll(x): the number of ones in the number
// __builtin_parityll(x): the parity (even or odd) of the number of ones

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> VL;
typedef vector<vector<ll>> VVL;
typedef pair<ll, ll> pii;
typedef vector<double> VD;
typedef vector<bool> VB;
typedef vector<vector<bool>> VVB;
typedef priority_queue<ll> PQ;
typedef priority_queue<ll, VL, greater<ll>> MPQ; // min priority queue
typedef set<ll> SL;
typedef set<pair<ll, ll>> SPL;
typedef vector<char> VCH;
typedef vector<vector<char>> VVCH;
typedef vector<vector<pair<ll, ll>>> VVPL;
typedef vector<pair<ll, ll>> VPL;
typedef vector<string> VS;
typedef vector<vector<string>> VVS;
typedef queue<ll> QU;
typedef stack<ll> ST;

const ll mod = 998244353;
const ll MOD = 1e9 + 7;
const ll inf = 1e18;
const ld eps = 1e-12;
const ll N = 3e6 + 20;
const ld pie = 2 * acos(0.0);

#define int ll
#define double ld

//<------------------------------------------------------------------------------------>

// finding divisors in O(sqrt(n));

ll maxn = 5e5 + 1;

VL spf(maxn, 0);

void sieve()
{
    spf[1] = 1;
    for (ll i = 2; i < maxn; ++i)
    {
        if (!spf[i])
        {
            spf[i] = i;
            for (ll j = i * i; j < maxn; j += i)
            {
                if (!spf[j])
                    spf[j] = i;
            }
        }
    }
}

VL factorize(ll n)
{
    VL ans;
    while (n > 1)
    {
        ll fact = spf[n];
        while (n % fact == 0)
        {
            n /= fact;
        }
        ans.pb(fact);
    }
    return ans;
}
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
vector<bool> isprime(N + 1, true);
VL primes;
void is_prime()
{

    rep(i, 2, N + 1)
    {
        if (isprime[i])
        {
            primes.pb(i);
            for (ll j = 2 * i; j <= N; j += i)
            {
                isprime[j] = false;
            }
        }
    }
    isprime[1] = false;
}

//<------------------------------------------------------------------------------------>

// exploring adjacent cells while grid exploration using graph traversals
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// solving straight lines type problems using gcd
// https://codeforces.com/contest/514/submission/214319537

ll gcd(ll a, ll b)
{
    if (b > a)
    {
        return gcd(b, a);
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }

ll expo(ll a, ll b, ll mod = MOD)
{
    a %= mod;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}

ll pwr(ll a, ll b, ll mod = MOD)
{
    a %= mod;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void extendgcd(ll a, ll b, ll *v)
{
    if (b == 0)
    {
        v[0] = 1;
        v[1] = 0;
        v[2] = a;
        return;
    }
    extendgcd(b, a % b, v);
    ll x = v[1];
    v[1] = v[0] - v[1] * (a / b);
    v[0] = x;
    return;
} // pass an arry of size1 3

ll mminv(ll a, ll b)
{
    ll arr[3];
    extendgcd(a, b, arr);
    return arr[0];
} // for non prime b

ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
bool revsort(ll a, ll b) { return a > b; }

ll combination(ll n, ll r, ll m, ll *fact, ll *ifact)
{
    ll val1 = fact[n];
    ll val2 = ifact[n - r];
    ll val3 = ifact[r];
    return (((val1 * val2) % m) * val3) % m;
}

vector<ll> sieve(int n)
{
    int *arr = new int[n + 1]();
    vector<ll> vect;
    for (int i = 2; i <= n; i++)
        if (arr[i] == 0)
        {
            vect.push_back(i);
            for (int j = 2 * i; j <= n; j += i)
                arr[j] = 1;
        }
    return vect;
}

ll mod_add(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}

ll mod_mul(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}

ll mod_sub(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}

ll mod_div(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (mod_mul(a, mminvprime(b, m), m) + m) % m;
} // only for prime m

ll phin(ll n)
{
    ll number = n;
    if (n % 2 == 0)
    {
        number /= 2;
        while (n % 2 == 0)
            n /= 2;
    }
    for (ll i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            number = (number / i * (i - 1));
        }
    }
    if (n > 1)
        number = (number / n * (n - 1));
    return number;
} // O(sqrt(N))

ll ceil_div(ll a, ll b) { return a % b == 0 ? a / b : a / b + 1; }

ll floor_div(ll a, ll b)
{
    ll val = a / b;
    while (val * b > a)
        val--;
    return val;
}

ll inv(ll i)
{
    if (i == 1)
        return 1;
    return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;
}

// look for the longest (shortest) segment with some property. Both options are solved using the two pointer method.

/*
chicken mcnugget theorem-> if there exists two prime numbers, m and n, then the largest number which can't be represented in the form (m*a + n*b), is (m*n-m-n)

https://codeforces.com/contest/1526/submission/226416574
*/

template <typename typC, typename typD>
istream &operator>>(istream &cin, pair<typC, typD> &a) { return cin >> a.first >> a.second; }

template <typename typC>
istream &operator>>(istream &cin, vector<typC> &a)
{
    for (auto &x : a)
        cin >> x;
    return cin;
}

template <typename typC, typename typD>
ostream &operator<<(ostream &cout, const pair<typC, typD> &a) { return cout << a.first << ' ' << a.second; }

template <typename typC, typename typD>
ostream &operator<<(ostream &cout, const vector<pair<typC, typD>> &a)
{
    for (auto &x : a)
        cout << x << '\n';
    return cout;
}

template <typename typC>
ostream &operator<<(ostream &cout, const vector<typC> &a)
{
    int n = a.size();
    if (!n)
        return cout;
    cout << a[0];
    for (int i = 1; i < n; i++)
        cout << ' ' << a[i];
    return cout;
}

template <typename T, typename T1>
T amax(T &a, T1 b)
{
    if (b > a)
        a = b;
    return a;
}

template <typename T, typename T1>
T amin(T &a, T1 b)
{
    if (b < a)
        a = b;
    return a;
}

//<--------------------CUSTOM HASH-------------------->

// umap<ll,ll,custom_hash> color like

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

//<---------------NCR write init() in main--------------->

const int32_t M = 998244353;
#define PRIME M
ll pw(ll a, ll p = M - 2, ll mod = M)
{
    ll result = 1;
    while (p > 0)
    {
        if (p & 1)
            result = a * result % mod;
        a = a * a % mod;
        p >>= 1;
    }
    return result;
}

ll fact[N], invfact[N];

void init()
{
    ll p = PRIME;
    fact[0] = 1;
    ll i;
    for (i = 1; i < N; i++)
    {
        fact[i] = i * fact[i - 1] % p;
    }
    i--;
    invfact[i] = pw(fact[i], p - 2, p);
    for (i--; i >= 0; i--)
    {
        invfact[i] = invfact[i + 1] * (i + 1) % p;
    }
}

ll ncr(ll n, ll r)
{
    if (r > n || n < 0 || r < 0)
        return 0;
    return fact[n] * invfact[r] % PRIME * invfact[n - r] % PRIME;
}

//<---------------------------DSU-------------------------------->

class dsu
{
    vector<ll> par, size, rank;

public:
    dsu(ll n)
    {
        rep(i, 0, n + 1)
        {
            par.pb(i);
            rank.pb(0);
            size.pb(1);
        }
    }

    ll find_par(ll node)
    {
        if (par[node] == node)
        {
            return node;
        }
        return par[node] = find_par(par[node]);
    }

    void union_size(ll u, ll v)
    {
        ll pu = find_par(u);
        ll pv = find_par(v);
        if (pu == pv)
        {
            return;
        }

        if (size[pu] < size[pv])
        {
            par[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            par[pv] = pu;
            size[pu] += size[pv];
        }
    }

    void union_rank(ll u, ll v)
    {
        ll pu = find_par(u);
        ll pv = find_par(v);
        if (pu == pv)
        {
            return;
        }
        if (rank[pu] < rank[pv])
        {
            par[pu] = pv;
        }
        else if (rank[pv] < rank[pu])
        {
            par[pv] = pu;
        }
        else
        {
            par[pu] = pv;
            rank[pv]++;
        }
    }

    void dsu_union(ll u, ll v)
    {
        ll pu = find_par(u);
        ll pv = find_par(v);
        if (pu == pv)
        {
            return;
        }
        if (pu < pv)
        {
            swap(pu, pv);
        }
        par[pv] = pu;
    }
};


//-----------DEBUG TEMPLATE-----------
void _print(ll t) {cerr << t;}
//void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
// void _print(lld t) {cerr << t;}
// void _print(double t) {cerr << t;}
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


//<------------------------------TEMPLATE ENDS------------------------------->

vector<int> pa;
vector<int> sz;
int get(int x)
{
    return ((pa[x] == x) ? x : (pa[x] == get(pa[x])));
}

void unite(int a, int b)
{
    a = get(a);
    b = get(b);

    if (a == b)
    {
        return;
    }

    if (sz[a] > sz[b])
    {
        swap(a, b);
    }
    pa[a] = b;

    sz[b] += sz[a];

    return;
}

bool isconnected(int a, int b)
{
    return (get(a) == get(b));
}

void precompute(){


 
}

inline void divine()
{

}

signed main()
{
    FASTIO; // disable this in interactive problem, and use endl instead of "\n"

    // init();
    // sieve();
  
    ll tc; cin>>tc;	while(tc--)

    // cout<<fixed<<setprecision(10)<<ans;

    precompute();
    divine();

    return 0;
}
