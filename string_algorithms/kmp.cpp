int kmp[1001000];
string s;
int n;

void kmp_(){
    memset(kmp,0,sizeof(kmp));
    int i=0;int j=-1;kmp[0]=-1;
    while(i<n){
        while(j!=-1 && s[i]!=s[j])  j=kmp[j];
        j++;i++;
        kmp[i]=j;
    }
}
