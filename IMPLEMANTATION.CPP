#include<bits/stdc++.h> 
using namespace std; 

template <typename T> class vectorClass {
     T* arr; 
     int capacity; 
     int current; 
     
     public : 
        
        vectorClass() {      // constructor 
            arr = new T[1];
            capacity = 1; 
            current = 0; 
        }
        
        ~vectorClass() {    // destructor 
            delete [] arr; 
        }
    
    void push(T data) {
        
        if(current == capacity) {
            T* temp = new T[capacity*2]; 
        
        for(int i =0; i<capacity; i++) {
            temp[i] = arr[i]; 
        }
        
        delete [] arr; 
        arr = temp; 
        capacity *=2;     
        
    }
        arr[current] = data; 
        current++; 
    }
    
    
    void push(T data, int index) {
        if(index == capacity) {
            push(data); 
        } else 
         arr[index] = data; 
    }
    
    
    T get(int index) {
        if(index < current) return arr[index]; 
    }
    
    void pop()  {
        current--; 
    }
    
    int size() {
        return current; 
    }
    
    int getcapacity() {
        return capacity; 
    }
    
    void print() {
        for(int i =0; i<current; i++) {
            cout<< arr[i] << "  "; 
        }
        cout<< endl; 
    }
    
    
}; 


/////////////////////  QUEUE implemantation ///////////////////////////////

#include<bits/stdc++.h> 
using namespace std; 

#define SIZE 1000 

template <typename T> class Queue{
      T *arr; 
      int capacity; 
      int front; 
      int rear; 
      int curr_size; 
      
      public : 
        Queue() {
            arr = new int[SIZE]; 
            capacity = SIZE; 
            front = 0; 
            rear = -1; 
            curr_size = 0; 
        }
        
        ~Queue() {
            delete[] arr; 
        }
        
        
        T dequue() {
            if(isEmpty()) {
                cout<<"Underflow/n Program Terminated"; 
                exit(EXIT_FAILURE);
            }    
            
            T x = arr[front]; 
            cout<< "Removing " << x <<endl; 
            
            front = (front +1) %capacity; 
            curr_size--; 
            return x; 
        }
        
        void enqueue(T data) {
            
            if(isFull()) {
                cout<<"Overflow\n Program Terminated " ; 
                exit(EXIT_FAILURE); 
            }
            
            rear = (rear+1) % capacity; 
            
          arr[rear] = data; 
          curr_size++; 
        }
    
    T peek() {
        if(isEmpty()) {
            cout<< "Underflow\n Program Terminated"; 
            exit(EXIT_FAILURE); 
        }
        
        return arr[curr_size];
    }
    
    int size() {
        return curr_size;
    }
    
    bool isEmpty() {
        return (size() ==0); 
    }
    
    bool isFull() {
        return size() == capacity; 
    }
    
    
    
}; 

/////////////////////////////////////////////////  STATCK implemantation //////////////////////////

#include<bits/stdc++.h> 
using namespace std; 

#define SIZE  10; 

class Stack {
   int *arr; 
   int top; 
   int capacity; 
   
 public : 
    Stack() {
        arr = new int[SIZE]; 
        capacity = size; 
        top = -1; 
    }
    
    ~Stack() {
        delete[] arr; 
    }
    
    void push(int data) {
        
        if(isFull()) {
            cout<<"Stack Overflow\n Program terminated " ; 
            exit(EXIT_FAILURE); 
        }
        
        arr[++top] = data; 
        
    }
    
    int pop() {
        
        if(isEmpty()) {
            cout<<"StackUnderflow\n Program Terminated \n " ; 
            exit(EXIT_FAILURE); 
        }
        
       return arr[top--]; 
        
    }
   
   int peek() {
       
       if(!isEmpty()) {
           return arr[top]; 
       } else {
           exit(EXIT_FAILURE); 
       }
       
   }
   
   int size() {
       return top +1; 
   }
   
   bool isEmpty() {
       return top == -1; 
   }
   
   bool isFull() {
       return top == capacity-1; 
   }
   
}; 


/////////////////////////////// bst insetion  deletion , diplay, search ////////
#include<bits/stdc++.h> 
using namespace std; 

class Node{
    int key; 
    Node* left; 
    Node* right; 
    
    Node(int value) {
        key(value);
        left(NULL); 
        right(NULL); 
    }
}; 

Node* newNode(int value) {
    Node* new_node = new Node(value); 
    return new_node; 
}

// inorder traversal 

void inorder(Node* root) {
    if(!root) return; 
    inorder(root->left); 
    cout<<root->key<<"  "; 
    inorder(root->right); 
}

// insert node 

Node* insert(Node* root, int value) {
    if(!root) return newNode(value) ; 
    
    if(value < root->key) 
       root->left = insert(root->left, value); 
     else 
        root->right = insert(root->right, value); 
        
    return root; 
}

Node* minValueNode(Node* root) {
    node* curr = node; 
    
    while(curr && curr->left) {
          curr = curr->left; 
    }
    return curr; 
}

Node* deletNode(Node* root, int value) {
    
    if(!root) return root; 
    
    if(key < root->key) 
        root->left = deletNode(root->left, value); 
   else if(key > root->key) {
       root->right = deletNode(root->right, value); 
   } else {
       if(root->left ==NULL && root->right ==NULL) {
           return NULL; 
       } 
       else if(root->left == NULL) {
           Node* temp = root->right; 
           free(root); 
           return temp; 
       } else if(root->right == NULL) {
           Node* temp = root->left; 
           free(root); 
           return temp; 
       }
       
       Node* temp = minValueNode(root->right); 
       root->key = temp->key; 
       
       root->right = deletNode(root->right, temp->key); 
   }
   return root; 
}

////////////////////////////////////////////////////////////////////////



