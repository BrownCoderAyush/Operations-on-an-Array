#include <stdio.h>
#include <iostream>
#include <stdlib.h>

struct array
{
    int *A;
    int size;
    int length;
};

using namespace std;

void Display(struct array arr)
{
    printf("Elements Are:");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}

void append(struct array *arr, int x)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length] = x;
        arr->length++;
    }
}

void insert(struct array *arr, int index, int x)
{
    if (arr->size > arr->length)
    {
        if (index >= 0 && index <= arr->length)
        {
            for (int i = arr->length; i > index; i--)
            {
                arr->A[i] = arr->A[i - 1];
            }
        }
    }

    arr->A[index] = x;
    arr->length++;
}

void Delete(struct array *arr, int index)
{
    if (index >= 0 && index <= arr->length - 1)
    {
        for (int i = index; i <= arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
    }
    arr->length--;
}
int linearSearch(struct array *arr, int Key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == Key)
        {
            return i;
        }
    }
    return -1;
}
void swap(int *ptr, int *p)
{

    int t = *ptr;
    *ptr = *p;
    *p = t;
}
int TransposeSearch(struct array *arr, int key)
{

    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == key && i != 0)
        {
            swap(&arr->A[i], &arr->A[i - 1]);
            return i - 1;
        }
    }
    return -1;
}
// iterative approach
int BiSearch(struct array *arr, int l, int h, int key)
{
    int mid;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr->A[mid])
        {
            return mid;
        }
        else if (key > arr->A[mid])
        {
            l = mid + 1;
        }
        else if (key < arr->A[mid])
        {
            h = mid - 1;
        }
    }
    return -1;
}
// recursive approach for binary search
int RBinSrch(struct array *arr, int l, int h, int key)
{
    int mid;
    if (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr->A[mid])
        {
            return mid;
        }
        else if (key < arr->A[mid])
        {
            return RBinSrch(arr, l, mid - 1, key);
        }
        else if (key > arr->A[mid])
        {
            return RBinSrch(arr, mid + 1, h, key);
        }
    }

    return -1;
}

// Sum using itetative approach
int sum(int length, struct array arr)
{
    int total = 0;
    for (int i = 0; i < length; i++)
    {
        total = total + arr.A[i];
    }
    return total;
}

// Sum using recursive approach
// n = length - 1
int rsum(int n, struct array arr)
{
    if (n == 0)
    {
        return arr.A[0];
    }
    else
    {
        return rsum(n - 1, arr) + arr.A[n];
    }
}

// maximum function
int maxi(struct array arr)
{
    int max = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }
    return max;
}
// minimum function
int mini(struct array arr)
{
    int min = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
        {
            min = arr.A[i];
        }
    }
    return min;
}

// Reverse Function
void AuxiReverse(struct array *arr)
{
    int *B;
    B = (int *)malloc(arr->length * sizeof(int));
    for (int i = 0, j = arr->length - 1; arr->length - 1 >= i; i++, j--)
    {
        B[j] = arr->A[i];
    }
    for (int i = 0; i < arr->length; i++)
    {
        arr->A[i] = B[i];
    }
    free(B);
}

// Reverse Function without auxilary array
void Reverse(struct array *arr)
{
    for (int i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        int temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
        // arr->A[i]= arr->A[j];
    }
}
// InsertSorted is function which inserts in a sorted array
void InsertSorted(struct array *arr, int x)
{
    int i = arr->length - 1;
    if (arr->length < arr->size)
    {
        while ((i >= 0) && (arr->A[i] > x))
        {
            arr->A[i + 1] = arr->A[i];
            i--;
        }
        arr->A[i+1]= x;
        arr->length++;
    }
}

// check If an array is sorted or not
bool checkSorted(struct array *arr)
{
    for (int i = 0; i < arr->length - 1; i++)
    {
        if (arr->A[i] > arr->A[i + 1])
        {
            return false;
        }
    }
    return true;
}
// rearranging +ve and -ve integers 
void Rearrange(struct array * arr){
    int i = 0;
    int j = arr->length - 1;
    printf("rearranging started \n");
    while (i<j)
    {
        while (arr->A[i]<0)
        {
            i++;
        }
        while (arr->A[j]>=0)
        {
            j--;
        }
        if (i<j)
        {
            int temp = arr->A[i];
            arr->A[i] = arr->A[j];
            arr->A[j] = temp;
        }    
    }
    printf("rearranging ended \n");
}
int main(int argc, char const *argv[])
{
    int n;
    struct array arr;
    int summ;
    int min;
    int max;

    printf("Please enter the size of array");
    cin >> arr.size;
    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0;

    printf("Enter the number of numbers");
    cin >> n;
    printf("Number of elements are %d\n", n);

    printf("Enter All Elements");
    for (int i = 0; i < n; i++)
    {
        // cin>>arr.A[i];
        scanf("%d", &arr.A[i]);
    }
    arr.length = n;
    // insert(&arr,2,100);
    // append(&arr,10);
    // append(&arr,11);
    // Delete(&arr, 5);
    // append(&arr, 100);
    // int result = linearSearch(&arr,1);
    // printf("%d \n",result);
    // int result1 = TransposeSearch(&arr,1);
    // printf("%d \n",result1);
    // int result2 = linearSearch(&arr,1);
    // printf("%d \n",result2);
    // printf("%d \n",RBinSrch(&arr,0, arr.length-1,4));
    // summ = rsum(arr.length-1,arr);
    // printf("the total sum is - %d \n", summ);
    // min = mini(arr);
    // max = maxi(arr);
    // printf("the minimum is - %d \n the maximum is - %d \n", min, max);
    // bool Value = checkSorted(&arr);
    // printf("the array is  - %d \n", Value);
    // InsertSorted(&arr,5);
    // Rearrange(&arr);
    Display(arr);
    return 0;
}
