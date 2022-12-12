#include<iostream>
#include<cstring>
using namespace std;

string xorFunc(string a,string b){
    int n=b.length();
    
    string result="";
    for(int i=1;i<n;i++){
        if(a[i]==b[i]){
            result+="0";
        }
        else{
            result+="1";
        }
    }
    return result;
}

string modulo2_division(string message,string poly){
    int len=poly.length();
    int n=message.length();
    // cout<<"hi"<<endl;
    string temp=message.substr(0,len);
    while(len<n){
        if(temp[0]=='1'){
            temp=xorFunc(poly,temp)+message[len];
        }
        else{
            temp=xorFunc(string(len,'0'),temp)+message[len];
        }
        len++;
    }
    if(temp[0]=='1'){
        temp=xorFunc(poly,temp);
    }
    else{
        temp=xorFunc(string(len,'0'),temp);
    }
    
    return temp;
}

int main(){
    
    cout<<"Enter the generator polynomial:";
    string poly;
    cin>>poly;
    
    cout<<"Enter the message you want to send:";
    string message;
    cin>>message;
    
    int len1=poly.length(),steps=1;
    
    for(int i=0;i<len1;i++){
        if(poly[i]=='1'){
            break;
        }
        steps++;
    }
    
    int degree=len1-steps;
    string appended_message=message;
    while(degree>0){
        appended_message.append("0");
        degree--;
    }
    // cout<<appended_message<<endl;
    string message_to_be_send=modulo2_division(appended_message,poly);
    
    cout<<"Message to be send is:"<<message.append(message_to_be_send)<<endl;
    
    
    string receive_for_check=modulo2_division(message,poly);
    
    int len2=receive_for_check.length();
    
    for(int i=0;i<len2;i++){
        if(receive_for_check[i]=='1'){
            cout<<"Error found in receiving "<<endl;
            break;
        }
        else if(i==len2-1){
            cout<<"No error found in receive"<<endl;
        }
    }
    
    return 0;
}
