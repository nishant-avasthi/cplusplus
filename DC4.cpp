#include<bits/stdc++.h>

struct Node{
    int key;
    int value;
    Node *next;
    Node *prev;
    Node(int key,int value):key(key),value(value),next(nullptr),prev(nullptr){};
};

class cache{
    protected:
        std::map<int,Node*> m;
        int cap;
        Node *next;
        Node *prev;
        virtual int get(int key)=0;
        virtual void set(int key, int value)=0;

    
};

class LRUCache :  cache{
    public:
        LRUCache(size_t cap){


        }
        int get(int key) override {

            if(m.find(key)==m.end())return -1;
            else{

                return m[key]->value;

            }


        }
        void set(int key, int value) override {
            

        }

};
