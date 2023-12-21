#include <iostream>  
using namespace std;  
int main()  
{  
char sent1[30],sent2[30];
int count,counter=0;
cout<<"Enter first string: ";
cin>>sent1;
cout<<"Enter second string: ";
cin>>sent2;
for(int i=0;sent1[i]!='\0'||sent2[i]!='\0';i++)
{  counter++;
 	if(sent1[i]!=sent2[i]){++count;}
}
  if (count==0){

  cout<<"Strings are equal."<<endl;
  cout<<"Inverted string is:";
   for(int i=counter;i>=0;i--){
	cout<<sent1[i];}}
	
else cout<<"Strings are not equal.";

return 0;} 