#include <bits/stdc++.h>
using namespace std;

class LRU_Cache{

    int max_size;
    list<int> dll;
    unordered_map<int,list<int>::iterator> mp;

    public:
        LRU_Cache(int msize){
            max_size = msize;
            dll.clear();
            mp.clear();
        }
    
    void query(int key){

        if(mp.find(key)==mp.end()){
            if(mp.size()==max_size){
                mp.erase(dll.back());
                dll.pop_back();
            }
        }
        else{
            dll.erase(mp[key]);
        }
        dll.push_front(key);
        mp[key] = dll.begin();
    }

    void display(){
        for(auto it : dll){
            cout<<it<<" ";
        }
        cout<<endl;
    }    
};

int main(){
    int msize,n,key;
    cout<<"Enter the size of Cache: ";
    cin>>msize;
    LRU_Cache cache(msize);

    cout<<"Enter the number of Queries: ";
    cin>>n;

    cout<<"Enter Queries: ";
    for(int i=0;i<n;i++){
        cin>>key;
        cache.query(key);
    }

    cout<<"Final Cache: ";
    cache.display();

    return 0;
}