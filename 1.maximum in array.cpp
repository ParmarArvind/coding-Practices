#include<iostream>
using namespace std;

class Maximum
{
public:
int arr[6]={1,5,4,-5,9,-4};
int MaxNum=INT_MIN;
int idx;
int ans[2];
public:

 int result(){
    for(int i=0;i<6; i++){
        if(arr[i] >MaxNum) {
            MaxNum=arr[i];
            idx=i;
            ans[0]=MaxNum;
            ans[1]=idx;

        }
        
    }
    return ans[2];
 }

 void display(){
   for(int i=0;i<6; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\nmaximum number :"<<MaxNum;
    cout<<"\nindex of element:"<<idx;
 }

};


int main(){
    
    Maximum m;
   
    m.result();
    m.display();

    return  0;
}