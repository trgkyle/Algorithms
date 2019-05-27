    
#include <iostream>
#include <algorithm>
using namespace std;
int BinarySearch(int a[], int left, int right, int x)
{ 
	if (left+1 == right)
    {
        if(a[left]!=x and a[right]!=x)
        {
            cout<<"left va right cach nhau 1 don vi la : "<<left<<" "<<right<<endl;
            return left;
        }
    }

	int mid = (left + right) / 2;

	if (x == a[mid]) 
		return mid;

	if (x < a[mid]) 
		return BinarySearch(a,left,mid-1,x);

	if (x > a[mid]) 
		return BinarySearch(a,mid+1,right,x);
    //return vi tri;
}