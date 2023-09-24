#include <iostream>
using namespace std;
void merge(int arr[],int low,int mid,int high){
   //创建一个临时数组
   int* temp=new int[high-low+1];
   int i=low,j=mid+1,k=0;
   //对比两个子集元素的大小
   while(i<=mid && j<=high){
      if(arr[i]<arr[j]){
         temp[k]=arr[i];
         i++;
      }
      else{
         temp[k]=arr[j];
         j++;
      }
      k++;
   }
   //将左边子集或者右边子集没有比完的直接复制到临时数组中
   while(i<=mid){
      temp[k]=arr[i];
      i++;
      k++;
   } 
   while(j<=high){
      temp[k]=arr[j];
      j++;
      k++;
   }
   //将临时数组拷贝到原数组中
   i=low;
   for(int tempk=0;tempk<k && i<=high;tempk++){
      arr[i]=temp[tempk];
      i++;
   }
   delete[] temp;
   temp=NULL;
}
//递归（自己调用自己）
void mergesort(int arr[],int low,int high){
     if(low<high){
        int mid=(low+high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
     }
}



int main(){
   int a[]={2,25,414,55,44,55,12,62,54,26};
   int len = sizeof(a)/sizeof(a[0]);
   mergesort(a,0,len-1);
   for(int i=0;i<len;i++){
      cout<<a[i]<<" ";
   }
   cout<<endl;

}