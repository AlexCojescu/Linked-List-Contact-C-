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
        head = newNode;    //checks if list is empty
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


//function to search contact

void searchContact(){
    string name;
    bool found = false;    //assuming contact is not found, if contact is found, it is set to true

    cout<<"\nEnter the name that you want to search: ";     //user enters name they are looking for by storing input in variable
    cin>>name;

    if (head == NULL){                                      //if the head pointer is NULL, the list is empty so theres nothing to search
        cout<<"\nContact list is empty!";
}
else {
    node* temp = head;
    while(temp != NULL){                                    //iterates through every contact node in list
        if(name == temp -> contact_name){                   //compares the name the user entered with the name stored in current node
            cout<<"\nContact Found!";                            //if theres a match
            cout<<"\nContact Name:"<<temp -> contact_name;
            cout<<"\nContact Phone:"<<temp -> contact_phone;    
            found = true;
            break;

        }
        temp = temp -> next;
    }
    if (found == false){                                    //if theres no match
        cout<<"\nContact Not Found!";
    }
}
cout<<endl;

}


//function to delete a contact

void deleteContact(){
    if(head == NULL){
        cout<<"\nContact List is Empty";
        return;

}
    string name;

    node* temp = head;
    node* prev = NULL;

    cout<<"\nEnter the contact name that you want to delete";
    cin>>name;

    //Case 1: if node we are looking for is the first node. If we want to delete the first node in the list

    if (temp != NULL && temp -> contact_name == name){  
        head = temp -> next;
        delete head;
        cout<<"\nCnotact deleted succesfully!";
        return;
    }


    //Case 2: if it is any othe rnode in list

    bool found = false;
    while (temp != NULL){
        if (temp -> contact_name == name){
            found = true;
            prev -> next = temp -> next;
            delete temp;
            cout<<"\nContact deleted succesfully!";
            break;
        }
        prev = temp;
        temp = temp -> next;
    }

    if (found == false){
        cout<<"\nContact Not Found!";

    }

    cout<<endl;
}

int main(){
    string name, phone;
    int choice;

    do {
        cout<<"\n--MAIN MENU--";
        cout<<"\n1. Add a new contact";
        cout<<"\n2. Display all Contacts";
        cout<<"\n3. Search a Contact";
        cout<<"\n4. Delete a Contact";
        cout<<"\n5. Exit";
        cout<<"\nEnter your choice:";
        cin>>choice;

        switch(choice){
            case 1: cout<<"\nEnter the Contact Name: ";
                    cin>>name;
                    cout<<"\nEnter the Phone Number: ";
                    cin>>phone;
                    insertAtEnd(name, phone);
                    break;
            case 2: displayContact();
                    break;
            case 3: searchContact();
                    break;
            case 4: deleteContact();
                    break;
            case 5: cout<<"\nExiting the program...";
                    exit(0);
            default: cout<<"\nInvalid Choice... Please Try Again";
        }

    } while (choice != 5);

return 0;
}