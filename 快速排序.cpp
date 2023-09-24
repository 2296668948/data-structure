#include <iostream>
using namespace std;

void  quick(int a[],int low,int high){
    if(low<high){
      int i=low,j=high;
      int x=a[low];
      while(i<j){
        //从右向左找到小于基准的数
        while(a[j]>x&&j>i){
            j--;
        }
        //while循环结束表示，找到了小于基准的数，就将找到的数与前面的i所在的位置的数进行交换，并将i往右移动
        if(i<j){
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i++;
        }
        //当在右边找到小于基准的数后，就从左找大于基准的数
        while(a[i]<x && i<j){
            i++;
        }
        //上个while结束表示找到了大于基准的数，并将找到的数与j所在位置的数进行交换
        if(i<j){
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
      }
      a[i]=x;
      quick(a,low,i-1);
      quick(a,i+1,high);
    }
}
int main(){
   int a[]={2,25,414,55,44,55,12,62,54,26};
   int len = sizeof(a)/sizeof(a[0]);
   quick(a,0,len-1);
   for(int i=0;i<len;i++){
    cout<<a[i]<<" ";
   }
   cout<<endl;

}