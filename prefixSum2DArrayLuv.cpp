//जय श्री राम

/*
RANGES OF DATA TYPES
int 						 n<=10^9				
long long int				 n~10^18	
unsigned long long int		 0<n<10^19
*/

// https://youtu.be/nZe7P674xZo  (10:56) for optimised approach

/*--------------------------------------------------------------------*/
/*
Given a 2D array a of N*N integers. Given Q queries and in
each query given a,b,c and d, print sum of square represented
by (a,b) as top left point and (c,d) as bottom right point

Constraints
1<=N<=10^3
1<=a[i][j]<=10^9
1<=Q<=10^5
1<=a,b,c,d<=N
*/
/*--------------------------------------------------------------------*/


/*
explaination->
let's say for order 4 square matrix, need to calculate
sum from coordinate (a,b) to (c,d), then need to create a rectangle
from coordinate (a,b) to (c,d) and find the sum of elements in that
rectangle


___		___		__		__

__		___		__		__
		(a,b)	X		X
__		___		__		___
		X		X		(c,d)
__		___		__		___

__		___		__		__

for this 4X4 matrix find elements in rectangle 



*/
#include <bits/stdc++.h>
#define endl "\n";

using namespace std;
const int N= 1e3+10;
int arr[N][N];
long long pf[N][N];

/*
IMPORTANT 

FOR PREFIX SUM PROBLEMS->
DECLARE ARRAY STARTING FROM INDEX 1 TO AVOID CONFUSIONS 
*/


/*
T.C.1->

3
3 6 2
8 9 2
3 4 1 
2
1 1 2 2 
1 2 3 3 

expected output ->
26
24

matrix->
3 6 2 
8 9 2
3 4 1 

query->2 , for coordinate (1,1) to (2,2)
		   for coordinate (1,2) to (3,3)
*/
int main()
{
    
   /*unoptimised approach
   [Execution for test case #1 has finished in 47ms]
   */
   /*
   int n; cin>>n;
   for(int i=1; i<=n; ++i){
   	for(int j=1; j<=n; ++j){
   		cin>>arr[i][j];
   	}
   }
   int q; cin>>q;
   while(q--){
   	int a,b,c,d;
   	cin>>a>>b>>c>>d;
   	long long sum =0;
   	
   // create a loop from coordinate (a,b) to (c,d)
   // and calculate its sum in that rectangle 
   	for(int i=a; i<=c; ++i){
   		for(int j=b; j<=d; ++j){
   			sum += arr[i][j];
   		}
   	}
   	cout<<sum<<endl;
   }
   */
   
   /*
   taking 2d array as input -> 0(n^2)
   
   taking query loop inside of which matrix sum found 
   element by element -> 0(q*(n^2))
   
   overall complexity 0(n^2) + 0(q*(n^2)) ~ 0(q*(n^2)) = (10^5 * 10^6 = 10^11)
   
   */
   
   
/*--------------------------------------------------------------------*/   
	/*optimised approach
	[Execution for test case #1 has finished in 89ms]
	
	calculating prefix sum outside query loop and
	directly calling prefix 2D array for giving value
	
	*/

   int n; cin>>n;
   for(int i=1; i<=n; ++i){
   	for(int j=1; j<=n; ++j){
   		cin>>arr[i][j];
   		pf[i][j] = arr[i][j] + pf[i-1][j]+ pf[i][j-1]- pf[i-1][j-1];
   	}
   	}
   	
   	int q; cin>>q;
   while(q--){
   	int a,b,c,d;
   	cin>>a>>b>>c>>d;
   	cout<<pf[c][d] -pf[a-1][d] -pf[c][b-1] +pf[a-1][b-1]<<endl;
   }
   
   /*
   taking input from the user for 2D square array -> 0(n^2)
   
   running a loop for taking query from the user -> 0(q)
   
   overall complexity -> 0(n^2) + 0(q) ~ 0(n^2) ~ 
   */
   
}