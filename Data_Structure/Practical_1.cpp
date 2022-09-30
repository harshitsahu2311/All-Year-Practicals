#include <iostream>
using namespace std;


void linearsearch(int arr[], int value, int size){
     for(int i=0; i< size ; i++){
            if (arr[i] == value)
                cout<<"Found at index "<< i ;
        }
}

void binarysearch(int arr[], int value, int size){
    int l=0;
    int u=size-1;
        
    while (l<= u){
        int m= (l+u)/2;
            
        if(value == arr[m]){
            cout<<"Found at index "<< m ;
            break;
        }
        else if ( value<m)
        {
            u=m-1;
        }
        else{
            l=m+1;
        }
    }
        
    if (l>u){
        cout<<"not found";
    }
        

}

int main() {
    cout<<"Enter 1 for linear search \nEnter 2 for binary search  \n";
    cout<<"Enter your choice : ";
    int ch;
    cin>>ch;
    
    int size=0;
    cout<<"Enter the size of the array : ";
    cin>>size;
    
    int arr[size];
    // this is for input
    for(int i=0;i<size ; i++){
        cout<<"Enter the "<< i+1 <<" element : ";
        cin>> arr[i];
    }
    
    // this is for printing
    cout<< "\n[ " ;
    for(int i=0;i<size ; i++){
        if ( i!= size-1)
            cout<<" "<< arr[i]<< " ,";
        else 
            cout<<" "<< arr[i];

    }
    cout<<" ]";
   
    int value=0;
    cout<<"\nEnter the number you want to find: ";
    cin>>value;

    
    
    if ( ch == 1){
        linearsearch(arr,value,size);
    }
    
    else if (ch == 2) {
        binarysearch(arr,value,size);
    }

    else{
        cout<<"Wrong input";
    }
    
    

    return 0;
}
