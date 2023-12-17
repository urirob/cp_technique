//Jai shree ram
 
//Be Consistent,Be Extraordinary

/*
generating subset of given array

and then subsets of a particular subset
*/
 
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
typedef vector<vector<ll> > matrix;
 
const ll mod=998244353;
const ll MOD=1e9+7;
const ll inf=1e18;
const ld eps=1e-9;
const ll N =3e6+20; 
const ld pie=2*acos(0.0);
 
 
#define int ll

 
//<------------------------------TEMPLATE ENDS------------------------------->

/*
both & , && have different meaning 
similarly for |, ||
*/ 
 
void solve(){
   int n;
   cin>>n;
   
   /*
   if ith bit is set in the mask this means the element is present in the subset
   */
	
	vector<int>arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	for(int mask=0;mask<(1<<n);mask++){			//0(2^n)
		cout<<"subset: ";
		for(int i=0;i<n;i++){
			if(mask&(1<<i)){	//ith element is present in the mask, then print the ith value
				// continue;
				cout<<arr[i]<<" ";
			}
		}
		
		cout<<"\n";

//<---------------------------------------------------------------------------------------------------------------->
	
		//x is done till x>0 because  if we try to get into printing empty set as well then we have to do x=0, this will done into infinite loop
		
		
		//0(2^setbits in mask)
		for(int x=mask;x>0;x=(x-1)&mask){		//this will iterate over all subsets of our current subset
			cout<<"subset of subset: ";
			for(int i=0;i<n;i++){
				if(x&(1<<i)){					//x is subset of our current subset that we have here, ith element is present if the condition is true
					cout<<arr[i]<<" ";
				}
			}
			
			cout<<"\n";
		}
		
		
	}
	

  
  
}
 
 
 
signed main(){
  JAI_SHREE_RAM;		//disable this in interactive problem, and use endl instead of "\n"
 
   // ll tc; cin>>tc;	while(tc--)
        solve();
     
 
return 0;
}



/*
input
4 
1 2 3 4


output

subset: 
subset: 1 
subset of subset: 1 
subset: 2 
subset of subset: 2 
subset: 1 2 
subset of subset: 1 2 
subset of subset: 2 
subset of subset: 1 
subset: 3 
subset of subset: 3 
subset: 1 3 
subset of subset: 1 3 
subset of subset: 3 
subset of subset: 1 
subset: 2 3 
subset of subset: 2 3 
subset of subset: 3 
subset of subset: 2 
subset: 1 2 3 
subset of subset: 1 2 3 
subset of subset: 2 3 
subset of subset: 1 3 
subset of subset: 3 
subset of subset: 1 2 
subset of subset: 2 
subset of subset: 1 
subset: 4 
subset of subset: 4 
subset: 1 4 
subset of subset: 1 4 
subset of subset: 4 
subset of subset: 1 
subset: 2 4 
subset of subset: 2 4 
subset of subset: 4 
subset of subset: 2 
subset: 1 2 4 
subset of subset: 1 2 4 
subset of subset: 2 4 
subset of subset: 1 4 
subset of subset: 4 
subset of subset: 1 2 
subset of subset: 2 
subset of subset: 1 
subset: 3 4 
subset of subset: 3 4 
subset of subset: 4 
subset of subset: 3 
subset: 1 3 4 
subset of subset: 1 3 4 
subset of subset: 3 4 
subset of subset: 1 4 
subset of subset: 4 
subset of subset: 1 3 
subset of subset: 3 
subset of subset: 1 
subset: 2 3 4 
subset of subset: 2 3 4 
subset of subset: 3 4 
subset of subset: 2 4 
subset of subset: 4 
subset of subset: 2 3 
subset of subset: 3 
subset of subset: 2 
subset: 1 2 3 4 
subset of subset: 1 2 3 4 
subset of subset: 2 3 4 
subset of subset: 1 3 4 
subset of subset: 3 4 
subset of subset: 1 2 4 
subset of subset: 2 4 
subset of subset: 1 4 
subset of subset: 4 
subset of subset: 1 2 3 
subset of subset: 2 3 
subset of subset: 1 3 
subset of subset: 3 
subset of subset: 1 2 
subset of subset: 2 
subset of subset: 1 


*/
