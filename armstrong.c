#include<iostream>
using namespace std;

int main()
{
    int num,remainder,cube,result=0,temp;
    cout<<"Enter the number: ";
    cin>>num;
    temp=num;

    while(num>0)
    {
        remainder=num%10;
        cube=remainder*remainder*remainder;
        result=result+cube;
        num/=10;
    }

    if(result==temp)
    {
        cout << "The number is an armstrong number";
    }
    else
    {
        cout << "The number is not an armstrong number";
    }

}
