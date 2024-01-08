#include <iostream>

using namespace std;

float Sum(int n){
    int sum=0;
    if (n==0){
        return n;
    }

    else
    if(n>0 ) {
        return   sum=n+Sum(n-2);

    }
    else{
        sum=sum+0;
    }
}

int main()
{
    int n;
    int sum;
    cout<<"введіть число:";
    cin>>n;
    n=2*n-1;
    cout<<Sum(n)<<endl;
    cout<<n;

    return 0;
}

