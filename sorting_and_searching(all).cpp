
#include<iostream>
using namespace std;

void insertion_sort(int arr[], int n)
{
    for(int i=1; i<5; i++)
    {
        int key= arr[i];
        int j=i-1;

        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }

        arr[j+1]=key;
    }
}

void selection_sort(int arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        int min_idx=i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[min_idx]> arr[j])
            {
                min_idx=j;
            }
        }
        int temp=arr[min_idx];
        arr[min_idx]=arr[i];
        arr[i]=temp;
    }
}

void bubble_sort(int arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j]> arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int linear_search(int arr[], int n, int key)
{
    for(int i=0; i<n ; i++)
    {
        if(arr[i]==key)
        {
            return i;
        }
    }

    return -1;
}

int Binary_search(int arr[], int n , int key)
{
    int l=0;
    int h=n-1;
    int mid;

    while(l<=h)
    {
        mid=(l+h)/2;

        if(arr[mid]==key)
        {
            return mid;
        }

        else if(arr[mid]>key)
        {
            h=mid-1;
        }

        else{
            l=mid+1;
        }
    }

    return -1;
}

int main()
{
    int arr[]= {5,1,3,2,4};

    //insertion_sort(arr, 5);

    //selection_sort(arr, 5);

    //bubble_sort(arr, 5);
    int key=6;
    //cout<<linear_search(arr,5,key)<<endl;
    cout<<Binary_search(arr,5,key)<<endl;


//    for(int i=0; i<5; i++)
//    {
//        cout<<arr[i]<<" ";
//    }
}
