#include <iostream> 
#include <vector> 
  
using namespace std; 

class Stack {
    private:
        vector<int> v;
    public:
        void push(int value){
            v.push_back(value);
        }
        int pop(){
            if (v.size()<1) { 
                return -1; 
            } 
            int top = v.back(); 
            v.pop_back(); 
            return top; 
        }
        bool isEmpty() {
             return v.empty(); 
        } 
        int top() { 
            if (isEmpty()) { 
                return -1; 
            } 
            return v.back(); 
        } 
};