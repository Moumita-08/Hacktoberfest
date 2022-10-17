#include <stdio.h>
#define MAX 100
 
void merge(int arr1[], int arr2[], int n1, int n2);
void bubbleSort(int arr[], int n);
 
int main()
{
    int arr1[MAX], arr2[MAX], n1, n2, i;
 
    printf("Enter size of array 1: ");
    scanf("%d", &n1);
 
    printf("Enter %d elements of array 1: ", n1);
    for(i=0; i<n1; i++)
        scanf("%d", &arr1[i]);
 
    printf("Enter size of array 2: ");
    scanf("%d", &n2);
 
    printf("Enter %d elements of array 2: ", n2);
    for(i=0; i<n2; i++)
        scanf("%d", &arr2[i]);
 
    merge(arr1, arr2, n1, n2);
 
    printf("\nArray after merging: ");
    for(i=0; i<n1+n2; i++)
        printf("%d ", arr1[i]);
 
    printf("\n");
 
    return 0;
}
 
/* Merges two user defined arrays with user defined elements */
void merge(int arr1[], int arr2[], int n1, int n2)
{
    int i, j, k;
 
    /* Initialize i, j and k */
    i = 0;
    j = 0;
    k = 0;
 
    if(n1 == 0)
    {
        while(j < n2)
        {
            arr1[k] = arr2[j];
            j++;
            k++;
        }
 
        return;
    }
 
    if(n2 == 0)
    {
        while(i < n1)
        {
            arr1[k] = arr1[i];
            i++;
            k++;
        }
 
        return;
    }
 
    /* Merge the temp arrays back into arr1[] */
    while(i<n1 && j<n2)
    {
        if(arr1[i] <= arr2[j])
        {
            arr1[k] = arr1[i];
            i++;
        }
        else
        {
            arr1[k] = arr2[j];
            j++;
        }
 
        k++;
    }
 
    /* Copy the remaining elements of arr1[], if there are any */
    while(i < n1)
    {
        arr1[k] = arr1[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of arr2[], if there are any */
    while(j < n2)
    {
        arr1[k] = arr2[j];
        j++;
        k++;
    }
}
 
/* Bubble Sort in ascending order */
void bubbleSort(int arr[], int n)
{
    int i, j, temp;
 
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}