//Jai shree ram
 
//Be Consistent,Be Extraordinary
 
#include <bits/stdc++.h>
 
using namespace std;
 
//<--------------------TEMPLATE BEGINS-------------------->
 
#define JAI_SHREE_RAM ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define F first
#define S second

typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define int ll


 
/*
subsets of array of size n exists including empty set=2^n

memory used=n*(2^n)

store the subsets in 2D vector
*/ 
 
 

   
	/*
	given a list of points on a 2d plane, rearrange these points in any way such that in the final permutation of points, the sum of distances of adjacent elements is minimised
	
	constraints:(N<=15),[-1e9<=Xi,Yi<=1e9]
	
	Points:[{0,0},{5,6},{1,2}]
	
	Best permutation-> [{0,0},{1,2},{5,6}]
	
	Ans=Dist(P1,P3)+Dist(P3,P2)
	*/
	
	
	
	/*

//<------------------------------------------------------------------------>	
	identification of overlapping subproblem
	
	lets say the possible scenarios are possible
	
	
			 current element	
				 |
				 v
	P1 P2 P3 P4 (Pi .....)
	P3 P1 P2 P4 (Pi .....)
	P2 P1 P4 P4 (Pi .....)
	
	before the current element Pi, there are so many past configuration which are already decided points which are now not changing our suffix (Pi,...), hence these all are overlapping subproblem and there is implementation of dp in it
	
//<------------------------------------------------------------------------>	
	let dp[last][bitmask]=minimum sum of distance among the points that are not in bitmask, such that last point choosen was 'last'
	
//<------------------------------------------------------------------------>	
	to check arr[3] is present in the array
	index = 0  1  2  3  4  5
	
	check 2^3 is set with the bitmask or not(resultant should give 1)
				
//<------------------------------------------------------------------------>	


			
												
					new bitmask will contain ith point also, so add it to our bitmask by doing OR
											|
(....., last , ith element 	)				|
					|						|
					v						|
		between ith and last point			v					
	distance(point[i],point[last]) + dp[i][bitmask OR (1<<i)]
					^					^
					|					|
	between ith and last point		last point is now going to ith point itself
	

//<------------------------------------------------------------------------>

		
	dp[last][bitmask]=min(distance(point[i],point[last])+dp[i][bitmask OR (1<<i)])
	
	*/
 
 
/*
function for returning answer for a particular dp state


*/

vector<pair<double,double> >points(100);

double dist(pair<double,double>&a,pair<double,double>&b){
	double x_dist=a.F-b.F;
	double y_dist=a.S-b.S;
	
	return sqrt(x_dist*x_dist + y_dist*y_dist);
}


double f(int last,int bitmask,int n,vector<vector<double> >&dp){
	/*
	base case=already chosen all the points there is no transition possible,since all the array is exhausted
	*/
	
	//base case= all the points already be chosen so return 0
	if(bitmask==(1<<n)-1){
		return 0;
	}
	
	if(dp[last][bitmask]!=-1){
		return dp[last][bitmask];
	}
	
	
	dp[last][bitmask]=1e18;
	for(int i=0;i<n;i++){
		if((bitmask&&(1<<i))>0){	//the element is present then continue, and then go forward to the array
			continue;
		}
		
		//if you want to consider the point then need to find the distance
		
		int new_last=i;
		int new_bitmask=(bitmask|(1<<i));
		double ans_here=dist(points[i],points[last]) + 
		f(new_last,new_bitmask,n,dp);
		
		dp[last][bitmask]=min(dp[last][bitmask],ans_here);
	}
	
	return dp[last][bitmask];
}


 
void solve(){ 
 	int n;
 	cin>>n;
 

 
 	rep(i,0,n){
 		cin>>points[i].F>>points[i].S;
 	}
  	
  	/*
  	to store in dp state
  	
  	the last point we've chosen,
  	*/
  
  	vector<vector<double>>dp(n,vector<int>(1<<n,-1));
  	/*
  	intialising with -1, means that the state we have found is not calculated
  	*/
  	
  	//dp[last][bitmask]=minimum sum of distances among the points, that have not be choosen so far considering that last point chosen so far was 'last'
  	
  	/*
  	final subproblem=first point can be anything,iterating over all the points to chose them as a first point
  	*/
  	
  	double ans=1e18;
  	
  	for(int i=0;i<n;i++){
  		ans=min(ans,f(i,1<<i,n,dp));
  	}
  
  	cout<<ans<<"\n";
  	
  	
  	//time complexity=(number of states)*(transition_time)
  	
  	//number_of_states=n*(2^n) states
  	//transition_time_of_one_state=n
  	
  	//overall_complexity=n^2*(2^n)
  	
  	//space_complexity=number_of_states
  	//0(n*(2^n))
  	
}
 
 
 
signed main(){
  JAI_SHREE_RAM;		
 
 
        solve();
     
 
return 0;
}
