#include<iostream>
#include<random>
#include<chrono>
#include<iomanip>
#include<fstream>
using namespace std;
using namespace std ::chrono;
int arr[10000000], arr_sortate[10000000], arr_invers[10000000], arr_plat[10000000];
void selectionSort(int arr2[],int n)
{
    fstream file("selection_sort.csv",ios::app);
    auto start = high_resolution_clock::now();
    int* arr = new int [n];
    for(int i = 0; i < n; i++)
        arr[i] = arr2[i];
    for (int i = 0; i < n - 1; ++i)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(arr[i], arr[min_idx]);
    }
    auto stop = high_resolution_clock::now();
    duration<double> durata = stop - start;
cout <<fixed<<setprecision(9);
cout <<"selection sort: "<<durata.count()<<"s"<<"\n";
for(int i = 0; i < n; i++)
    file << arr[i]<<", ";
file << endl;
file.close();
}
void bubbleSort(int arr2[], int n)
{
    fstream file("bubble_sort.csv",ios::app);
    auto start = high_resolution_clock::now();
    int* arr = new int [n];
    for(int i = 0; i < n; i++)
        arr[i] = arr2[i];
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
auto stop = high_resolution_clock::now();
    duration<double> durata = stop - start;
cout <<fixed<<setprecision(9);
cout <<"bubble sort: "<<durata.count()<<"s"<<"\n";
for(int i = 0; i < n; i++)
    file << arr[i]<<", ";
file << endl;
file.close();
}
void insertionSort(int arr2[], int n)
{
    fstream file("insert_sort.csv",ios::app);
    auto start = high_resolution_clock::now();
    int* arr = new int [n];
    for(int i = 0; i < n; i++)
        arr[i] = arr2[i];
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
auto stop = high_resolution_clock::now();
    duration<double> durata = stop - start;
cout <<fixed<<setprecision(9);
cout <<"inser sort: "<<durata.count()<<"s"<<"\n";
for(int i = 0; i < n; i++)
    file << arr[i]<<", ";
file << endl;
file.close();
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
void radixsort(int arr2[], int n)
{
    fstream file("radix_sort.csv",ios::app);
    auto start = high_resolution_clock::now();
    int* arr = new int [n];
    for(int i = 0; i < n; i++)
        arr[i] = arr2[i];
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
    auto stop = high_resolution_clock::now();
    duration<double> durata = stop - start;
cout <<fixed<<setprecision(9);
cout <<"radix sort: "<<durata.count()<<"s"<<"\n";
for(int i = 0; i < n; i++)
    file << arr[i]<<", ";
file << endl;
file.close();
}
void print_funct(int arr[],int n) //in fisier
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
    int n;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0,1000);
    cout <<"Nr de elemente de sortat\n";
    cin >>n;
    for(int i = 0; i < n; i++)
        arr[i] = distr(gen);

    mt19937 gen2(rd());
    uniform_int_distribution<> distr2(0, 1000);
    int nr = distr2(gen2);
    for (int i = 0; i < n; i++)
        arr_sortate[i] = nr + i ;

    for(int i = 0; i <n; i++)
        arr_invers[i] = arr_sortate[n-i-1];
    mt19937 gen3(rd());
    uniform_int_distribution<> distr3(0, n);
    for(int i = 0; i< n; i++)
    {
        if(distr3(gen3) % 10 == i)
            arr_plat[i] = nr+i;
        else
            arr_plat[i] = nr;
    }
    cout <<"Lista de elemente aleatoare\n";
        selectionSort(arr,n);
        bubbleSort(arr,n);
        insertionSort(arr,n);
        radixsort(arr,n);
        cout <<"\n";
    cout <<"\nLista de elemente sortate\n";
        selectionSort(arr_sortate,n);
        bubbleSort(arr_sortate,n);
        insertionSort(arr_sortate,n);
        radixsort(arr_sortate,n);
        cout <<"\n";
    cout <<"\nLista de elemente sortate invers\n";
        selectionSort(arr_invers,n);
        bubbleSort(arr_invers,n);
        insertionSort(arr_invers,n);
        radixsort(arr_invers,n);
        cout <<"\n";
    cout <<"\nLista de elemente plate\n";
        selectionSort(arr_plat,n);
        bubbleSort(arr_plat,n);
        insertionSort(arr_plat,n);
        radixsort(arr_plat,n);
        cout <<"\n";
    //print_funct(arr,n);
    return 0;
}