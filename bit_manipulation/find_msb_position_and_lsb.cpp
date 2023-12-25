#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	
	//lsb is last bit from right, finding it doing bitwise &
	int lsb=(n&1);
	
	
	//msb is last bit from left,finding the leftmost setbit 
	
	int msb_position=0;
	
	while(n>0){
	    n=n>>1; //right shift by 1 to move to the next bit
	    msb_position+=1;
	}
	
	
	cout<<msb_position-1<<" "<<lsb<<"\n";  //msb_position-1 because of 0 based indexing of it

}
