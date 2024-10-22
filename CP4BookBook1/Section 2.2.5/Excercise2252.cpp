#include <iostream> 
#include <list> 
  
using namespace std; 

class Queue {
    private:
        list<int> v;
    public:
        void push(int value){
            v.push_back(value);
        }
        int pop(){
            if (v.size()<1) { 
                return -1; 
            } 
            int top = v.back(); 
            v.pop_front();
            return top; 
        }
        bool isEmpty() {
             return v.empty(); 
        } 
        int size(){
            return v.size();
        }
        int front() { 
            if (isEmpty()) { 
                return -1; 
            } 
            return v.front(); 
        } 
        int back(){
            if (isEmpty()) { 
                return -1; 
            } 
            return v.back(); 
        }
};