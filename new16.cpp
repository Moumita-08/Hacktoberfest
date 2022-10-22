//function overload
#include<iostream>
using namespace std;
//sum of 2 integers 
int sum(int a , float b){
    return (a+b);
}
//sum of 3 integers 
float sum(int a , float b, int c){
    return (a+b+c);
}
//volume of cube
int vol(int a){
    return (a*a*a);
}
//volume of cuboid
int vol(int a,int b,int c){
    return (a*b*c);
}
//volume of cylinder
int vol(double a,int b){
    return (3.14*a*a*b);
}


int main()
{
    cout<<"the sumof the numbers 4,5.213 is  "<<sum(4,5.213)<<endl;
    cout<<"the sumof the numbers 4,6.2165 & 5 is  "<<sum(4,6.2165,5)<<endl;
    cout<<"the volume of cube with side 4 is "<<vol(4)<<endl;
    cout<<"the volume of cuboid with lenght 4 breadth is 5 and height  6 is "<<vol(4,5,6)<<endl;
    cout<<"the volume of cylinder with radius 4 and height 5 is "<<vol(4,5)<<endl;
    return 0;
}