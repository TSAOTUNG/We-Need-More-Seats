//
//  function.cpp
//  HW05
//
//  Created by 曹心瞳 on 2022/5/18.
//

#include <iostream>
#include <cstdlib>
#include <stddef.h>
#include <vector>
#include <algorithm>

using namespace std;

template < class T >
void mySort(T arr[], int l, int r)
{
    long long int pivot=arr[l];
    int left=l;
    int right=r+1;
    if(l<r)
    {
        do
        {
            do
            {
                left++;
            }while (arr[left]<pivot);
            do
            {
                right--;
            }while (arr[right]>pivot);
            if(left<right)
            {
                long long int temp;
                temp=arr[left];
                arr[left]=arr[right];
                arr[right]=temp;
            }
        }while(left<right);
        
        long long int temp;
        temp=arr[l];
        arr[l]=arr[right];
        arr[right]=temp;
        
        mySort(arr,l,right-1);
        mySort(arr,right+1,r);
    }
}


void solve()
{
    int group_num;
    cin >> group_num;
    
    long long int Ai_sort[group_num];
    vector<long long int> Timeline;
    string Si_sort[group_num];
    long long int max_Li=0;
    
    for(int i=0;i<group_num;i++)
    {
        long long int Pi,Li;
        cin >> Pi >> Ai_sort[i] >> Li >> Si_sort[i];
        if(max_Li<Li)
        {
            max_Li=Li;
            Timeline.resize(max_Li,0);
        }
        //cout << Si_sort[i];
        //cout << Pi << Ai << Li << Si << endl;
        for(long long int cur=Ai_sort[i];cur<Li;cur++)
        {
            //cout << cur << Pi << endl;
            
            Timeline[cur]=Timeline[cur]+Pi;
            //cout << Timeline[cur] << endl;
        }
        
        //Data.insert(Data.end(),Node(Pi,Ai,Li,Si));
    }
    //cout << max_Li << endl;
    /*for(int i=0;i<max_Li;i++)
    {
        cout << Timeline[i] << " " ;
    }
    cout << endl;
    for(int i=0;i<group_num;i++)
    {
        cout << Ai_sort[i] << " " ;
    }*/
    
    mySort(Ai_sort, 0 , group_num-1);

    /*for(int i=0;i<group_num;i++)
    {
        cout << Ai_sort[i] << " " ;
    }*/
    int queries;
    cin >> queries;
    
    for(int i=0;i<queries;i++)
    {
        string command;
        cin >> command;
        if(command=="TIME_ARRIVE")
        {
            int group;
            cin >> group;
            if(group<=group_num)
            {
                cout << Ai_sort[group-1] << endl;
            }
        }
        if(command=="TRAFFIC_AT")
        {
            /*for(int i=0;i<=max_Li;i++)
            {
                cout << Timeline[i] << endl;
            }*/
            int a;
            cin >> a;
            if(a<max_Li)
            {
                cout << Timeline[a] << endl;
            }
            else
            {
                cout << "0" << endl;
            }
        }
        if(command=="MAX_TRAFFIC")
        {
            vector<long long int>::iterator max_tra=max_element(Timeline.begin(),Timeline.end());
            cout << distance(Timeline.begin(), max_tra) << " " << *max_tra << endl;
        }
        if(command=="STORE_LIST")
        {
            for(int i=0;i<group_num-1;i++)
            {
                for(int j=0;j<group_num-1-i;j++)
                {
                    if(Si_sort[j]>Si_sort[j+1])
                    {
                        string temp=Si_sort[j];
                        Si_sort[j]=Si_sort[j+1];
                        Si_sort[j+1]=temp;
                    }
                }
            }
            for(int i=0;i<group_num;i++)
            {
                if(Si_sort[i]!=Si_sort[i+1] && Si_sort[i]!=Si_sort[group_num-1])
                {
                    cout << Si_sort[i] << " " ;
                }
                else if(Si_sort[i]!=Si_sort[i+1] && Si_sort[i]==Si_sort[group_num-1])
                {
                    cout << Si_sort[i];
                }
            }
            cout << endl;
        }
        
    }
}
