#include<iostream>
void spiral(int n);

int main(){
    int n ;
    std::cout<<"Enter the number : ";
    std::cin >> n;
    spiral(n);
}
void spiral(int n){
    int arr[n][n];
    for(int r=0;r<n;r++){
        for(int c=0;c<n;c++){
            std::cout<<"enter value in row "<<r<<"column "<<c<<" : ";
            std::cin>>arr[r][c];
        }
    }
    std::cout << "\nThe matrix is:\n";
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            std::cout << arr[r][c] << " ";
        }
        std::cout << '\n';
    }
}