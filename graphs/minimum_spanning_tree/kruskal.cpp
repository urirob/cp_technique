#include <bits/stdc++.h>

using namespace std;


#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

typedef long long ll;
#define int long long

vector<int> pa;
vector<int> sz;
int get(int x)
{
    return ((pa[x] == x) ? x : (pa[x] = get(pa[x])));
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


/*
kruskal - greedy algorithm - finally ek tree hi banta 

time complexity - 0(nlog(n))

choti edge weight ko add krte jao tree construct krne mein jaab taak tree mein loop nahi banta

cycle agar bna rha hai usko check krne ke liye DSU ke use krenge issmein, DSU mein almmost 0(1) mein check krloge ke agar dono connected hai ke nahi

cycle taab banega agar dono nodes already ek component ka part hai


agar edge add karne ke loop ban rha hai toh uss edge ko mat add kro, else uss edge ko add krdo



*/

/*
6 9
5 4 9
1 4 1
5 1 4
4 3 5
4 2 3
1 2 2
3 2 3
3 6 8
2 6 7
*/
inline void divine()
{

    int n,m;
    cin>>n>>m;

    /*
    intialising DSU
    */

//    for(int i=1;i<=n;i++){
//     pa.push_back(i);
//     sz.push_back(1);
//    }

    for(int i=1;i<=n;i++){
        pa.push_back(i);
    }

    for(int i=1;i<=n;i++){
        sz.push_back(1);
    }

    //need to sort according to edge weight
    
    //edge_weight,{start_node,end_node}-> for each node


    vector<pair<int,pair<int,int> > >edges;
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        // u--,v--;    //1 based indexing
        edges.push_back({wt,{u,v}});
    }

    sort(edges.begin(),edges.end());

    int total_cost=0;
   for(auto i:edges){
        int weight=i.first;
        int u=i.second.first;
        int v=i.second.second;

        //u aur v ko join krne se cycle toh nahi banega, or check they are in same component or check whether they are having same parent or not

        if(get(u)==get(v)){
             continue;
        }     
        else{
            unite(u,v);

            total_cost+=weight;

            //printing the edges
            cout<<u<<" "<<v<<"\n";
        }

   }

    cout<<total_cost<<"\n";
    

}

signed main()
{
    FASTIO; // disable this in interactive problem, and use endl instead of "\n"

    // init();
    // sieve();

    //    ll tc; cin>>tc;	while(tc--)

    // cout<<fixed<<setprecision(10)<<ans;
    divine();

    return 0;
}
