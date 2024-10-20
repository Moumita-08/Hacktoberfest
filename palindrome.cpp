//to find if given string is palindrome or not
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    //variables for comparing characters from start and end
    int start=0, end = s.length() -1;
    // converting everything to lower case for simplicity
    for (auto& x : s) { 
        x = tolower(x); 
    } 
    while(start<end){
        //ignore everything except alphanumeric characters
        if(!isalpha(s[start]) && !isdigit(s[start])){
            start++;
            continue;
        }
        if(!isalpha(s[end]) && !isdigit(s[end])){
            end--;
            continue;
        }
        if(s[start]!=s[end]){
            cout<<"Not a palindrome!"<<endl;
            return 0;
        }
        start++;
        end--;
    }
    cout<<"A palindrome"<<endl;
    return 0;
}
