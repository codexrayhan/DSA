
#include<stdio.h>
int linear_search(int arr[], int n, int key)
{
    for(int i=0; i<n; i++)
    {
        if(arr[i] == key)
        {
            return i;
        }
    }

    return -1;
}

int binary_search_(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    while(low<=high)
    {
        int mid = (low + high)/2;
        if(arr[mid] == key)
        {
            return mid;
        }
        else if(key>arr[mid])
        {
            low = mid + 1;
        }
        else /// key < arr[mid]
        {
            high = mid - 1;
        }
    }


    return -1;
}
int main()
{
    int n = 6;
    int arr[6] = {9, 8, 6, 7, 1, 2};
    int key = 6;
    int index = linear_search(arr, n, key);

    if(index==-1)
    {
        printf("Not Found\n");
    }
    else
    {
        printf("Found at index %d\n", index);
    }

    return 0;
}
