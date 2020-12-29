#include<bits/stdc++.h>
using namespace std;

/*whysoseriousss!!! let's put a smile on that face*/

int main()
{
    string s;
    cin>>s;
    int c=2;
    map<string,int> m;
    m["0"]=0;
    m["1"]=1;
    int iold=0;
    int inew=0;
    int l=s.length();
    while(inew!=l)
    {

        if(m.find(s.substr(iold,inew-iold+1))==m.end())
         {
             m[s.substr(iold,inew-iold+1)]=c++;
             printf("%d",m[s.substr(iold,inew-iold)]);
             iold=inew;
             inew--;

         }
         inew++;
    }

    if(m.find(s.substr(iold))!=m.end())
        printf("%d\n",m[s.substr(iold)]);
    else
        printf("%d\n",c);

}
