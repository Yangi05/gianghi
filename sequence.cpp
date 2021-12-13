#include <bits/stdc++.h>
using namespace std;
const int nmax= 3e4+10;
int n;
int a[nmax];
int p[nmax];
int f[nmax];
int maxa=0;
void prime()
{
    p[0]=true;
    p[1]=true;
    for(int i=2;i<maxa;i++)
        if(!p[i])
    {
        for(int j=i*i;j<=maxa;j+=i)
            p[i]=true;
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            maxa=max(a[i],maxa);
        }
    prime();
    for(int i=2;i<=n;i++)
        {
            if(!p[a[i]+a[i-1]])
                if(f[i]<f[i-1]+1)
                {
                    f[i]=f[i-1]+1;
                }
            else
            f[i]=f[i-1];
        }
    maxa=0;
    for(int i=1;i<=n;i++)
        maxa=max(f[i],maxa);
    cout<<maxa;
    return 0;
}
