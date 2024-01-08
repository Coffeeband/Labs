#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void number1() {
    int n;
    int a=0;
    cout << "vvedit rozmir masivy: ";
    cin>>n;
    int arr[n];
    int firstparne=arr[0];
    for (int i = 0; i < n; i++)
    {
        cout << "vvedit chislo: " ;
        cin>>arr[i];
        if(arr[i]%2==0){
            a++;
        }

    }
    for (int i = n; i >= 0; i=i-1){

        if( arr[i]%2==0){
            firstparne = arr[i];
        }
    }
    int *parr= new int[a];
    cout<<"Розмір маисву: "<<a<<endl;

    int j=0;

    for (int i = 0; i < n  ; i++  ){

        if(arr[i]%2==0){

            parr[j]=arr[i]+firstparne;
            j++;
        }
    }
    for (int i = 0; i < a; i++){
        if(a>0){
            cout<<parr[i]<<" ";
        }
        else{
            cout<<"парних чисел нема";
        }
    }

    delete[] parr;
}

void number2()
{
    int n;
    int m;
    int a=0;
    cout << "vvedit k-st stovpciv: ";
    cin>>n;
    cout << "vvedit ryadkiv stovpciv: ";
    cin>>m;
    int arr[n][m];

    int b=0;
    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<m;j++){
            cout << "vvedit chislo: " ;
            cin>>arr[i][j];
            if(arr[i][j]>0){
                a++;
            }
        }
    }
    int *parr= new int[a];

    for(int i=0; i < n;i++){

        for(int j=0;j<m;j++){
            if(arr[i][j]>0){
                parr[b]=arr[i][j];
                b++;
            }
        }

    }
    for(int i=0;i<a;i++){
        cout<<parr[i]<<"  ";
    }

    delete[] parr;
}

int main()
{
    cout << "1): " << endl;
    number1();
    cout << endl;
    cout << "2): " << endl;
    number2();

    return 0;
}

