#include <iostream>
using namespace std;
int main(){
    int a[]={26,25,414,55,44,55,12,62,54,26};
    int len=sizeof(a)/sizeof(a[0]);
    for(int i=1;i<len;i++){
        int key=a[i];
        int j=i-1;
        while(j>=0 && a[j]>key){
        a[j+1]=a[j];
        j--;
        }
        a[j+1]=key;
    }
    for(int k=0;k<len;k++){
        cout<<a[k]<<" ";
    }
    cout<<endl;
}