#include <iostream>
using namespace std;
int main()
{
    int a[]={2,25,4104,55,44,55,12,62,54,26};
    int len=sizeof(a)/sizeof(a[0]);

    for(int i=0;i<len;i++){
        for(int j=0;j<len-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    for(int k=0;k<len;k++){
        cout<<a[k]<<" ";
    }
    cout<<endl;
    
}