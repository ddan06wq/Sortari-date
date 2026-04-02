#include<iostream>
#include<random>
using namespace std;
void selectionSort(int arr[],int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(arr[i], arr[min_idx]);
    }
}
void bubbleSort(int arr[], int n)
{
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
    if (!swapped)
        break;
}
}
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i) 
    {
        int key = arr[i];
        int j = i - 1;
    while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
void countSort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = { 0 };
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
void radixsort(int arr[], int n)
{
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
void print_funct(int arr[],int n)
{
    for(int i= 0; i < n ;i++)
        {
            cout << arr[i]<<" ";
            if(i % 10 == 0 && i != 0)
                cout <<"\n";
        }
}
int main()
{
    int arr[1000000],n,m;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0,1000);
    cout <<"Nr de elemente de sortat\n";
    cin >>n;
    for(int i = 0; i < n; i++)
        arr[i] = distr(gen);
    cout <<"Algoritm de sortare:\n1. Selection Sort\n2. Bubble Sort\n3. Insertion Sort\n4. Radix Sort\n";
    cin >>m;
    switch (m)
    {
        case 1:
            selectionSort(arr,n);
            break;
        case 2:
            bubbleSort(arr,n);
            break;
        case 3:
            insertionSort(arr,n);
            break;
        case 4:
            radixsort(arr,n);
            break;
    }
    print_funct(arr,n);
    return 0;
}