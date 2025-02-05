//Number manipulation and prime numbers
#include <iostream>
using namespace std;
void ifnotprime(int n);
void ifprime(int n);

int main(){
    int n;
    cout << "Program checks if number entered is prime or not\nif prime,next greater prime is displayed\nif not all factors of the number\n";
    cout<<"Enter the number : ";
    cin >> n;
    //prime check

    int temp=0;
    for(int i=2;i<=n/2;i++){
    if(n%i==0){temp++;}}

    if(temp ==0 && n !=1){
        cout << n << " is a Prime Number."<<std::endl;
        ifprime(n);
    }
    else{
        cout << n << " is not a Prime Number."<<std::endl;
        ifnotprime(n);
    }
    
    return 0;
}

void ifnotprime(int n){
    cout <<"So , It's factors : \n";
    for(int i=1;i<=n;i++){
        if(n%i==0){
            cout<< i <<endl;
        }
        else{continue;}
    }

}
void ifprime(int n){
    cout << "So, the next greatest prime number is: ";
    int next = n+1;
    while (true) {
        int temp = 0;

        for (int i = 2; i <= next / 2; i++) {
            if (next % i == 0) {
                temp++; 
                break;  
            }
        }

        if (temp == 0 && next != 1) {
            cout << next << endl;
            return;
        }

        next++; 
    }
}