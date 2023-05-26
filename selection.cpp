#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }

        if (min_index != i)
        {
            swap(arr[min_index], arr[i]);
        }
    }

    cout << "\nSortedArray: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int n;
    vector<int> numbers;
    cout << "Enter total number of values : ";
    cin >> n;
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Number " << i + 1 << ": ";
        cin >> num;
        numbers.push_back(num);
    }

    selectionSort(numbers, n);
}