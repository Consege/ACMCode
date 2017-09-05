#include <bits/stdc++.h>

using namespace std;

int nxt[200] ;
void getNext(string str)
{
     nxt[0]=0;
     for(int i=1,j=0,m=str.length();i<m;i++)
     {
         while(j&&str[i]!=str[j])j=nxt[j-1];
         if(str[i]==str[j])j++;
         nxt[i]=j;
    }
}

int kmp(string S,string T)
{
    int ans=0,sn=S.length(),tn=T.length();
    for(int i=0,j=0;i<sn;i++)
     {
         while(j&&S[i]!=T[j])j=nxt[j-1];
         if(S[i]==T[j])j++;
         if(j==tn)
             return 1;
     }
     return 0;
 }


int main()
{
    int n ;
    while(cin>>n){
        string str[600] ;
        for(int i=0;i<n;i++){
            cin>>str[i] ;
        }

        int m ;
        cin>>m;
        for(int i = 0;i<m;i++){
            string q ;
            int ans = 0;
            cin>>q ;
            getNext(q);
           // cout<<i<<"  "<<q<<endl;
            for(int j=0;j<n;j++){
                if(kmp(str[j],q)) ans++;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}


