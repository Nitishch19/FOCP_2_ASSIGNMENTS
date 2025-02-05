//Array Operations
#include <iostream>
#include <algorithm>  // For std::sort()
using namespace std;

void revarray(int n ,int nums[]);
void second_l_s(int n, int nums[]);

int main(){
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int nums[n];

    //inputs for array
    for (int i=0;i<n;i++){
        cout << "Enter integer at index " << i << ": ";
        cin >> nums[i];
    }

    // Displaying original array
    cout << "\nOriginal array: { ";
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << "}" << endl;

    revarray(n,nums);
    second_l_s(n,nums);

return 0;
}

void revarray(int n ,int nums[]){

    cout << "\nReversed array: { ";
    for (int i = n-1 ; i >= 0; i--) {
        cout << nums[i] << " ";
    }
    cout << "}\n" << endl;
 }

void second_l_s(int n, int nums[]){

    sort(nums, nums + n);
    cout << "Second largest number in the array: " << nums[n - 2] << endl;
    cout << "Second Smallest number in the array: " << nums[1] << endl;
    //for reference
    // cout << "Sorted array: ";
    // for (int i = 0; i < n; i++) {
    //     cout << nums[i] << " ";
    // }
    // cout << endl;
    
}