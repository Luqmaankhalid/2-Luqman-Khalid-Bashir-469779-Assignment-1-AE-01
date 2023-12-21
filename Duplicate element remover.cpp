#include <iostream>  
#include<cctype>
using namespace std;  
int main()  
{int p=0;
string str;
cout<<"Enter string:";
cin>>str;
for(int i=0;i<str.length();i++){
	str[i]=tolower(str[i]);
	for(int j=0;j<str.length();j++){
		if(str[i]==str[j] && i!=j)
		{for(int k=0;k<str.length();k++){
			str[j]='\0';}
		}
	}
}
cout<<"String after removing duplicate charcaters:"<<endl;
for(int i=0;i<str.length();i++){
	if(str[i]=='\0'){
        continue;}
    str[i]=str[p];
    p++;
    }
    for(int i=0;i<str.length();i++){cout<<str[i];}
return 0;	
 } 