#include <iostream>
#include<map>
#include <list> 
#include <algorithm>
using namespace std;
struct Node {
    int value, key;
    Node (int k,int v):value(v),key(k){};
};
class Cache{
    protected :
    list <Node> l;
    map<int, list<Node>::iterator> mp;
    int cp;
    virtual void set(int,int)=0;
    virtual int get(int)=0;
    
};
class LRUCache:public Cache{

    void removeBack(){
        auto tail = l.end();
        mp.erase(tail->key);
        l.pop_back();
    }
     void addNodeFront(int k, int v) {
         Node *node = new Node(k,v);
         
         if (mp.size() == cp)
            removeBack();
                        
         //l.push_front({k,v});
         l.push_front(*node);
         mp[k] = l.begin();//head
     }  
     void moveToHead(list<Node>::iterator  arg, int new_val){
        (*arg).value = new_val;

        l.splice(l.begin(),l, arg);
        mp[arg->key]= l.begin();
     }
public:
    LRUCache(int &cap){
        cp = cap;
    }
     void set(int k,int v){
         if (mp.find(k)!=mp.end()){
            if (mp.size()>1)
                moveToHead(mp[k],v);
            else {
                l.begin()->value = v;
            }
         }
         else 
            addNodeFront(k,v);
     }
     
     int get (int k){
         if (mp.find(k)!=mp.end()){
         moveToHead(mp[k], mp[k]->value);
            return mp[k]->value;
         }
        return -1;
     }
};

int main()
{
    int n, capacity,i;
    cin>> n>> capacity;
    LRUCache l(capacity);
    for (i =0;i< n;i++){
        string command;
        cin>> command;
        if (command == "get"){
            int key;
            cin >> key;
            cout<< l.get(key)<< endl;
        }
        else if(command == "set"){
            int key,value;
            cin>> key>>value;
            l.set(key,value);
        }
    }
    return 0;
}

