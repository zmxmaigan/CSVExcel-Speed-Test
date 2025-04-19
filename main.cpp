#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int randint_range(int n, int m)
{ // 产生n~m间的随机数（包括m和n）
    long double base = ((long double)rand()) / RAND_MAX;
    long long res = n + floor(sqrt((base * (long double)(m - n + 1))));
    return res;
} // 来自：https://www.cnblogs.com/xiaotan-js/p/16687603.html

int main()
{
    cout<<"请输入表格规模（行，列）";
    int m,n;
    cin>>m>>n;
    freopen("test.csv","w",stdout);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cout<<randint_range(1,(m+n+i+j)*2)<<",";
        }
        cout<<endl;
    }
    return 0;
}
