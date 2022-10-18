#include<stdio.h>

//recursive function to find the factorial of a number
int fact(int n){
    if(n<=1)return 1;
    else return n*fact(n-1);
}

//return sum of factorial of digits of a number
int sumOfFactorialOfDigits(int n){
    int sum=0;
    while(n>0){
        sum+=fact(n%10);
        n/=10;
    }
    return sum;
}

//return sum of cubes of digits
int sumOfCubesOfDigits(int n){
    int sum=0;
    while(n>0){
        sum+=(n%10)*(n%10)*(n%10);
        n/=10;
    }
    return sum;
}

//return reverse of a number
int reverse(int n){
    int rev=0;
    while(n>0){
        rev=rev*10+n%10;
        n/=10;
    }
    return rev;
}

//checks is n is Krishnamurthy
int isKrishnamurthy(int n){
    if(n==sumOfFactorialOfDigits(n))return 1;
    else return 0;
}

//checks is n is Armstrong
int isArmstrong(int n){
    if(n==sumOfCubesOfDigits(n))return 1;
    else return 0;
}

//checks is n is Palindrome
int isPalindrome(int n){
    if(n==reverse(n))return 1;
    else return 0;
}

int main(){
    int n=0;
    printf("Enter a number: ");
    scanf("%d",&n);
    if(isKrishnamurthy(n))printf("%d is a Krishnamurthy number\n",n);
    else printf("%d is not a Krishnamurthy number\n",n);
    if(isArmstrong(n))printf("%d is an Armstrong number\n",n);
    else printf("%d is not an Armstrong number\n",n);
    if(isPalindrome(n))printf("%d is a Palindrome number\n ",n);
    else printf("%d is not a Palindrome number\n",n);
}