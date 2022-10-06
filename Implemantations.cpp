#inclde<bits/stdc++.h> 
using namespace std; 


// stack implementatins Using linked list

class ListNode{
    public : 
        ListNode* next ; 
        int val ; 
        int size =0; 
        ListNode(int value) {
            val = value; 
            next = NULL;
        }
};

ListNode* head = NULL; 
ListNode*
void push(int value) {
    ListNode* new_node = new ListNode(value);
    if(head==NULL) {
        head = new_node
    }
}





int main() {
    
    cout<<"/n Stack implementatins Using LinkedList "; 
    while(1) {
        cout<<"1. push "<<endl; 
        cout<<"2. Pop()"<<endl; 
        cout<<"3. Top()"<<endl; 
        cout<<"4. size()"<<endl; 
        cout<<"5. exit()"<<endl; 
        int n ;
        cout<<"Enter opration no. "<<endl; 
        cin>> n;
        if(n==5) {
            cout<<"Thanks for Participant "<<endl; 
            break; 
        }
        switch(n) {
            case : 1 
                cout << "Enter Value for push" <<endl; 
                int a ; 
                cin>>a; 
                push(a); 
                break; 
        
        case 2 : 
             cout<<"Pop Element " ; 
                int a = pop(); 
                cout<<"Pop() Elemnt is " << a<<endl; 
                break; 
        case 3: 
            int a = top(); 
            cout<<"Top Element is  "<<a<<endl; 
            break; 
        case 4 : 
            int a = size();
            cout<<"Size of the stack " <<endl; 
            cout<<a<<endl; 
        default  : 
            cout<<"Please Enter valid No. " <<endl; 
        }
        
    }
    
    return 0; 
}








//  QUEUE implementatins

#include<bits/stdc++.h> 
using namespace std; 


class ListNode {
    public : 
        int val; 
        ListNode* next; 
        ListNode(int value) {
            val = value; 
            next = NULL; 
        }
}; 
int size = 0; 
ListNode* head= NULL; 
ListNode* last = NULL; 
void push(int value) {
    ListNode* new_node = new ListNode(value); 
    size++; 
    if(!head) 
    {
        head = new_node; 
        last = head; 
        break; 
    }
    
    last->next = new_node; 
    last = last->next; 
    
}


int pop(){
    if(!head) return -1; 
    size--; 
    int a = head->val; 
    head = head->next; 
    if(!head) last = head; 
    return a; 
}

int front() {
    if(!head) return -1; 
    return head->val; 
}

bool isEmpty() {
    return size==0; 
}


// stack Using Doubly LinkedList 

#include<bits/stdc++.h> 
using namespace std; 


class ListNode {
    public : 
        int val ;
        ListNode* next; 
        ListNode* prev; 
        
        ListNode(int value) { 
             int val = value; 
             next = NULL; 
             prev = NULL; 
        } 
        
}; 

ListNode* top = NULL; 

void push(int value) {
    ListNode* new_node = new ListNode(value); 
    size++; 
    if(!top) {
        top = new_node; 
    }
    
    top->next = new_node; 
    new_node->prev = top; 
    top = new_node; 
}

int pop() {
    if(!top)  return -1; 
    size--; 
    ListNode* temp = top;
    int t = top->val; 
    top = top->prev; 
    free(temp); 
}

int topElement() {
    if(!top) return -1; 
    return top->val; 
    
}

bool isEmpty() {
    return size==0; 
}

bool isFull() {
     ListNode* temp = new ListNode(1); 
     if(!temp) {
         return 1; 
     }
     
     free(temp); 
     return 0; 
}


//  STACK USING SINGLE LINKEDLIST; 

#include<bits/stdc++.h> 
using namespace std; 

class ListNode{  // ListNode //
   public : 
       int val; 
       ListNode* next; 
       ListNode(int value) {
           val = value; 
           next = NULL; 
       }
}; 


ListNode* top = NULL; 
int size  = 0; 
void Push(int value) {
    ListNode* newNode = new ListNode(value); 
    if(!top) {
        top = newNode; return; 
    }
    
    newNode->next = top; 
    top = newNode; 
}

int pop() {
    if(!head) return -1; 
    
    int t = head->val; 
    ListNode* temp = head; 
    head = head->next; 
    free(temp); 
    return t; 
}

int top() {
    if(!top) return -1;
    
    return top->val; 
}

bool isEmpty() {
    return top==NULL; 
}

bool isFull() {
    // if there is no space in heap memory then we say -> stack is full; 
    ListNode* temp = new ListNode(-1); 
    if(!temp) return 1; 
    free(temp); 
    return 0; 
}

void Display() {
    if(!top) {
        cout<<"StackUnderflow"; 
        return; 
    }
    
    ListNode* curr = top; 
    while(curr) {
        cout<<curr->val<<"  ";
        curr = curr->next; 
    }
    return; 
}



// out own vector Using templet 
#include<bits/stdc++.h> 
using namespace std; 

template<typename T> class vectorClass {
    
    T* arr; 
    
    int capacity; 
    int current; 
    
    public : 
        
        vectorClass() {
            arr = new T[1]; 
            capacity = 1; 
            current = 0; 
        }
        
        ~vectorClass() {
            delete [] arr; 
        }
        
        void push(T data) {
            
            
            if(capacity == current) {
                T* temp = new T[2 * capacity]; 
            
            for(int i =0; i<capacity ; i++) {
                temp[i]  = arr[i]; 
            }
            
            delete[] arr; 
            capacity *=2; 
            arr = temp; 
        }
        
        arr[current] = data; 
        current++; 
        
    }
  
  void push(T data, int index) {
      if(index== capacity) {
          push(data); 
      } else {
          arr[index] = data; 
      }
  }
  
  
  T get(int index) {
      if(index < current) 
      return arr[index]; 
  }
  
  void pop() {current--;}
  
  int size() { return current; }; 
  
  int getcapacity() { return capacity; } 
  
  void print() {
      for(int i =0; i<current; i++) {
          cout<<arr[i]<<"  "; 
      }
      cout<<endl; 
  }
};
