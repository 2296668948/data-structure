#include <iostream>
using namespace std;
int main(){
    int a[]={26,25,414,55,44,55,12,62,54,26};
    int len=sizeof(a)/sizeof(a[0]);
    //定义间隔
    int h=1;
    while(h<len/3){
        h=h*3+1;
    }
    while(h>=1){
    for(int i=h;i<len;i++){
        for(int j=i;j>=h&&a[j]<a[j-h];j=j-h){
            swap(a[j],a[j-h]);
        }
    }
    h=h/3;
    }
    for(int k=0;k<len;k++){
        cout<<a[k]<<" ";
    }
    cout<<endl;
}