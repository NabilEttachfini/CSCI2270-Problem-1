#include <iostream>
#include <cstdlib>
#include "Lab8StarterCode.hpp"

int main(){
    int size=10, element, ch, hash_val;
    HashTab hash(10);
    while(1)
    {
        cout<<"1.Insert element into the table"<<endl;
        cout<<"2.Search an element"<<endl;
        cout<<"3.Delete element"<<endl;
        cout<<"4.Display HashTable"<<endl;
        cout<<"5.Exit"<<endl;
        cout<<"Enter your choice:";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"Enter element to be inserted:";
                cin>>element;
                hash.Insert(element);
                break;
            case 2:
                cout<<"Enter the element to be searched:";
                cin>>element;
                hash_val=hash.HashFunc(element);
                if(hash.Find(element)==-1)
                    cout<<"No element found at key"<<element<<endl;
                else{
                    cout<<"Element found at index"<<hash_val<<":";
                    cout<<"position"<<hash.Find(element)<<endl;
                }
                break;
            case 3:
                cout<<"Enter the element to be deleted:";
                cin>>element;
                if(hash.Find(element)==-1)
                    cout<<"key"<<element <<"is empty, nothing to delete"<<endl;
                else{
                    hash.Delete(element);
                    cout<<"Entry Deleted"<<endl;
                }
                break;
            case 4:
                hash.display();
                break;
            case 5:
                exit(1);
            default:
                cout<<"\nEnter correct option\n";
                
        }
    }
    return 0;
    
}
