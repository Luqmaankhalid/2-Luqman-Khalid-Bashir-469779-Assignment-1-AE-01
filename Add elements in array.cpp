#include<iostream>
using namespace std;

int main()
{int size;
int a[5]={1,2,3,4,5};
cout<<"How many elements you want to enter:";
cin>>size;
int b[size+5];
for(int i=0;i<5;i++){
	b[i]=a[i];
}
cout<<"Enter elements:";
for(int j=5;j<size+5;j++){
	cin>>b[j];
}
cout<<"The new array is: ";
for(int k=0;k<size+5;k++){
	cout<<b[k]<<" ";
}
    
    return 0;
}