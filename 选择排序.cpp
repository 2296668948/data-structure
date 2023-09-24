#include <iostream>
using namespace std;
    int main(){
    int a[]={2,25,414,55,44,55,12,62,54,26};
    int len=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
            if(a[j]<a[i]){
                swap(a[j],a[i]);
            }
        }
    }
    for(int k=0;k<len;k++){
        cout<<a[k]<<" ";
        }
    cout<<endl;
}
