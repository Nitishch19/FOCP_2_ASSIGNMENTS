#include <iostream>
#include <string>
using namespace std;

void palindrome(string str);
void frequency_count(string str);
void vowelchange(string str);

int main(){
    string str;
    cout <<"Enter the string : ";
    getline(cin >> ws , str);

    palindrome(str);
    frequency_count(str);
    vowelchange(str);

    return 0;
}


void palindrome(string str) {
    int start = 0, end = str.length() - 1;

    while (start < end) {
        if (str[start] != str[end]) {
            cout << "The string is not a palindrome.\n";
            return;
        }
        start++;
        end--;
    }

    cout << "The string is a palindrome.\n";
}

void frequency_count(std::string str) {
    int freq[256] = {0}; 

    // Count occurrences
    for (int i = 0; i < str.length(); i++) {
        freq[str[i]]++;
    }

    // Display frequencies
    std::cout << "Character frequencies :\n";
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            std::cout << "'" << (char)i << "' appears " << freq[i] << " times\n";
        }
    }
}

void vowelchange(string str){
    int length=str.length();
    for(int i=0;i<length;i++){
        if(str[i]=='A' || str[i]=='a'||str[i]=='E'||str[i]=='e'||str[i]=='I' || str[i]=='i'||str[i]=='O'||str[i]=='o'||str[i]=='u'||str[i]=='U'){
            str[i]='*';
        }
    }
    cout<<"Modified string : " << str;
}