#include <iostream>
#include <stack>


using namespace std;

stack <int>s;
typedef struct Element{
    int value;
    struct Element* next;
}Element;
Element* top=NULL;

Element* push(int value){
    Element* ptr=new Element;

    ptr->value=value;
    ptr->next=top;

    top=ptr;
    return ptr;
}
void pop(){
    if(top==NULL){return;}
    Element* ptr=top->next;
    delete top;
    top=ptr;
}
void show(){
    Element* v=top;
    while(v!=NULL){
        cout<<v->value<<" ";
        v=v->next;
    }
}
int main()
{
    int n;
    int a=0;
    cout << "vvedit rozmir masivy: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout << "vvedit число для масиву: ";
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        int value=arr[i];
        push(value);
    }

    show();
    return 0;
}

