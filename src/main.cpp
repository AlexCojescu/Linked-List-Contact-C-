#include<iostream>

using namespace std;


struct node{                //basic block of linked list
    string contact_name;    
    string contact_phone;   //fields to store variables
    node* next;             

};

node* head = NULL; //Declares Pointer: initailly list is empty so there are no nodes 

//function to create and insert a new contact
void insertAtEnd(string name, string phone){

    node* newNode = new node;
    newNode -> contact_name = name;
    newNode -> contact_phone = phone;
    newNode -> next = NULL;
    

//If the list is empty than the head pointer will point to newly created node 
//otherwise we have to consider second case

    if(head == NULL){
        head == newNode;   //checks if list is empty
}
else {                     //if list is empty than add node to existing list
    node* temp = head;
    while(temp -> next != NULL) {   //iterates through list until temp points to node whose next pointer is NULL
        temp = temp -> next;  
    }
    temp -> next = newNode;   //links old node to new contact node, making it new last node

}
cout <<"\nNew contact added successfully!";

}

void displayContact(){             //if null is empty it prints a message saying there are no contacts
    if (head == NULL){
        cout<<"\nNo contacts to display.";
    }
    else{
        cout<<"\n--Contact List--\n";
        node* temp = head;                                          //
        while(temp != NULL){                                        //iterates through every node starting from head
            cout<<"Contact Name: "<<temp -> contact_name<<"\n";
            cout<<"Phone Number: "<<temp -> contact_phone<<"\n";
            cout<<"---------\n";
            temp = temp -> next;                                    //moves pointer to next node in ssequence until it reaches NULL (end of list)
        }
        cout<<endl;
    }

}






int main(){

return 0;
}