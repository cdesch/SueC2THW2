//
//  main.cpp
//  SueC2THW2
//



#include <iostream>
#include "string.h"

using namespace std;
class Node{
    
protected:
    string data;
    Node* next;
public:
    Node(string data){
        this->data = data;
        this->next = NULL;
    }
    
    void setData(string data){ this->data = data;}
    void setNext(Node* next){ this->next = next;}
    string getData(){return this->data;}
    Node* getNext(){return this->next;}
    
};

class List{
protected:
    Node* head;
    
public:
    
    List(){this->head = NULL;}
    List(Node* node){ this->head = node;}
    
    void setHead(Node* node ){ this->head = node;}
    Node* getHead(){return this->head;}
    
    void add(string s){
        this->addItem(s);
    }
    
    void addItem(string s){
        this->addItem(new Node(s));
    }
    
    void addItem(Node* node){
        if(!this->head){
            this->head = node;
        }else{
            Node* next = this->head;
            while(next->getNext()){
                next = next->getNext();
            }
            next->setNext(node);
        }
    }
    
    string findSub(string sub){
        Node* next = this->head;
        while(next){
            if (next->getData().find(sub) != string::npos){
                return next->getData();
            }
            next = next->getNext();
        }
        return "-1";
    }

};
    

void testAddItemToList(){
 
    List* myList = new List();
    myList->addItem("12345");
    myList->addItem("Seymore");
    myList->addItem("Peter Griffin");
    
    string result = myList->findSub("more");
    if(result != "-1"){
        cout << "Found: " << result << endl;
    }
    
    string result2 = myList->findSub("Peter");
    if(result2 != "-1"){
        cout << "Found: " << result2 << endl;
    }
    
    
    //failing test case
    string result3 = myList->findSub("abc");
    if(result3 != "-1"){
        cout << "Found: " << result3 << endl;
    }else{
        cout << "NOT FOUND" << endl;
    }
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    testAddItemToList();
    
    return 0;
}
