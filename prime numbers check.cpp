#include<iostream>
using namespace std;
int main()
{
int n,count=0;
cout<<"Enter number= ";
cin>>n;
int k,i=1;
while(i<=n){
	count=0;
	int j=1;
	while(j<=i){
		if(i%j==0){count++;}
	j++;}
if(count==2){ k=i;}
i++;}
cout<<"The largest prime number equal or less than given number is "<<k;
	return 0;
}