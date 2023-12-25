#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	//flip msb and lsb and print the decimal equivalent of that number
	
	n=n^1;
	
	int pos=0;
	int n1=n;
	while(n1!=0){
	    n1=n1/2;
	    pos++;
	}
	
	pos--;          //because of 0 based indexing in bitwise representation
	
	n=n^(1<<pos);
	
	
	cout<<n<<"\n";
	
	

}
