#include<iostream>
using namespace std;

int subsetsum(int arr[],int n,int sum)
{
    if(sum == 0){
        return true;
    }
    if(n == 0){
        return false;
    }
    if(arr[n-1] > sum)
        return subsetsum(arr,n-1,sum);

    return subsetsum(arr,n-1,sum) || subsetsum(arr,n-1,sum-arr[n-1]);

}

int main(){

int arr[] = {3,34,4,12,5,2};
int n = 6;
int target = 9;

if(subsetsum(arr,n,target))
cout<< "found";
else
cout<<"not found";

return 0;
}
