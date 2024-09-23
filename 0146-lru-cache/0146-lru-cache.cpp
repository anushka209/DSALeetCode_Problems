class LRUCache {
public:
 class Node{
    public:
        int k,v;
        Node *prev;
        Node* next;

        Node(int k1,int v1)
        {
            k=k1;
            v=v1;
        }
 };
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    int capc;
    unordered_map<int,Node*>mpp;
 
    LRUCache(int capacity) {
         capc=capacity;
        head->next=tail;
        tail->prev=head;
    }

      void addnode(Node* newNode)
    {
        Node* temp=head->next;
        newNode->next=temp;
        newNode->prev=head;
        head->next=newNode;
        temp->prev=newNode;
    }

    void deletenode(Node* delNode)
    {
        Node* delprev=delNode->prev;
        Node* delnext=delNode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    
    int get(int key) {
        if(mpp.find(key)!=mpp.end())
        {
            Node* resnode=mpp[key];
            int res=resnode->v;
            mpp.erase(key);
            deletenode(resnode);
            addnode(resnode);
            mpp[key]=head->next;
        return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
         if(mpp.find(key)!=mpp.end())
        {
            Node* exNode=mpp[key];
            mpp.erase(key);
            deletenode(exNode);
        }
        if(mpp.size()==capc)
        {
            mpp.erase(tail->prev->k);
            deletenode(tail->prev);
        }
        addnode(new Node(key,value));
        mpp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */