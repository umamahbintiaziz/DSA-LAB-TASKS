#include <iostream>
using namespace std;
int binarySearch(int arr[],int size,int key)
{
    int low=0;
    int high=size-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==key)
            return mid;
        if(key>arr[mid])
            low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}
int main()
{
    int arr[10],choice,key;
    cout<<"Enter 10 integers: ";
    for(int i=0;i<10;i++)
    {
        cin>>arr[i];
    }
    do
    {
    	cout<<"MENU"<<endl;
        cout<<"1. Selection Sort"<<endl;
        cout<<"2. Bubble Sort"<<endl;
        cout<<"3. Insertion Sort"<<endl;
        cout<<"4. Binary Search"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter choice: "<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                for(int i=0;i<9;i++)
                {
                    int minIndex=i;
                    for(int j=i+1;j<10;j++)
                    {
                        if(arr[j]<arr[minIndex])
                            minIndex=j;
                    }
                    int temp=arr[i];
                    arr[i]=arr[minIndex];
                    arr[minIndex]=temp;
                }
                cout<<"Sorted Array: ";
                for(int i=0;i<10;i++)
                    cout<<arr[i]<<" ";
                    cout<<"\n";
                break;
            }
            case 2:
            {
                for(int i=0;i<9;i++)
                {
                    for(int j=0;j<9-i;j++)
                    {
                        if(arr[j]>arr[j+1])
                        {
                            int temp=arr[j];
                            arr[j]=arr[j+1];
                            arr[j+1]=temp;
                        }
                    }
                }
                cout<<"Sorted Array: ";
                for(int i=0;i<10;i++)
                    cout<<arr[i]<<" ";
                    cout<<"\n";
                break;
            }
            case 3:
            {
                for(int i=1;i<10;i++)
                {
                    int key=arr[i];
                    int j=i-1;
                    while(j>=0 && arr[j]>key)
                    {
                        arr[j+1]=arr[j];
                        j--;
                    }
                    arr[j+1]=key;
                }
                cout<<"Sorted Array: ";
                for(int i=0;i<10;i++)
                    cout<<arr[i]<<" ";
                    cout<<"\n";
                break;
            }
            case 4:
            {
                for(int i=0;i<9;i++)
                {
                    for(int j=0;j<9-i;j++)
                    {
                        if(arr[j]>arr[j+1])
                        {
                            int temp=arr[j];
                            arr[j]=arr[j+1];
                            arr[j+1]=temp;
                        }
                    }
                }
                cout<<"Enter value to search: ";
                cin>>key;
                int result=binarySearch(arr,10,key);
                if(result!=-1)
                    cout<<"Element found at index "<<result;
                else
                    cout<<"Element not found";
                    cout<<"\n";
                break;
            }
            case 5:
            {
                cout<<"Exit";
                break;
            }
            default:
            {
                cout<<"Invalid choice";
            }
        }
    }
    while(choice!=5);
    return 0;
}