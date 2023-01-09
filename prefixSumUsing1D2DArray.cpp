//जय श्री राम
/*
Given array a of N integers. Given Q queries and in each
query given L and R print sum of array elements from index
L to R (L,R included)

Constraints
1<=N<=10^5
1<=a[i]<=10^9
1<=Q<=10^5
1<=L, R<=N
*/
#include <bits/stdc++.h>
#define endl "\n";

using namespace std;
const int N = 1e5+10;
int a[N];
int pf[N];
/*
IMPORTANT 

FOR PREFIX SUM PROBLEMS->
DECLARE ARRAY STARTING FROM INDEX 1 TO AVOID CONFUSIONS 


*/

/*
T.C.1->
6
3 6 2 8 9 2
4
2 3	
4 6 
1 5 
3 6 

expected output
2 3 -> print sum of index 2 to 3 -> 2+8
4 6 -> print sum of index 4 to 6 -> 8+9+2
1 5 -> print sum of index 1 to 5 -> 6+2+8+9+2
3 6 -> print sum of index 3 to 6 -> 2+8+9+2
*/

int main()
{
   /* unoptimised approach->
   [Execution for test case #1 has finished in 141ms]*/
   
   /*
   int n; cin>>n;
   for(int i=1; i<=n; ++i){
   	cin>>a[i];
   }
   
   int q; cin>>q;
   while(q--){
   	int l,r;
   	cin>>l>>r;
   	long long sum=0;
   	for(int i=l; i<=r; ++i){
   		sum+=a[i];
   	}
   	cout<<sum<<endl;
   }
	*/
	
	/*
	first loop for taking array input -> 0(n)
	
	second loop for queries -> 0(q)
	and inside it worst case will be for l=1, r=n(last element)
	its complexity -> 0(n)
	
	overall -> 0(n) + 0(q*n) -> 0(n^2)
	*/
	
/*--------------------------------------------------------------------*/
    
	/*optimised->
	[Execution for test case #1 has finished in 54ms]
	*/
	
	// creating a prefix array
	
	int n; cin>>n;
   	for(int i=1; i<=n; ++i){
   		cin>>a[i];
   		pf[i] = pf[i-1] + a[i];
   }
   
   int q; cin>>q;
   while(q--){
   	int l,r;
   	cin>>l>>r;
   	cout<< pf[r] - pf [l-1]<< endl;
   }
   
   /*
	first loop for taking array input and 
	creating prefix array -> 0(n) + 0(n) ~ 2*(0(n)) 
	
	second loop for queries -> 0(q)
	
	
	overall -> 0(n) + 0(q) ~ 2*(0(n))
	*/
   
	
}