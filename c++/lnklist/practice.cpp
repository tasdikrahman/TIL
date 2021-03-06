// code for all the operations in a linked list 

#include <iostream>
using namespace std;  

struct node{
	int data  ; 
	node *next ; 
} *head ; 

class Lnklist{
public : 
	Lnklist() ; 		// initializes the head pointer to NULL at first 

	node *node_create(int) ;
	void print() ; 
	void print_with_arg(node *) ; 

	// insert operations 

	void insert_at_head(int) ; 
	void insert_at_last(int) ; 
	void insert_at_pos( int , int ) ; 

	//  now the delete operations 

	void delete_at_head() ; 
	void delete_at_last() ; 
	void delete_at_pos(int) ; 

	// reversing the linked list 

	node* reverse_iteratively(node *) ; 
	node* recursively(node *) ;
};

Lnklist::Lnklist(){
	head = NULL ;
}

node* Lnklist::node_create( int num ){

	// this allocates m/y and stores the data "num" there

	node *temp = new node() ; 
	temp->data = num ; 
	temp->next = NULL ; 
	return temp ; 
}

void Lnklist::print(){
	cout << "\nElements : " ; 
	node *temp = head ; 
	while(temp != NULL){
		cout << temp->data << " "; 
		temp = temp->next ; 
	}
	cout << endl ; 
}
void Lnklist::insert_at_head( int num ){

	node *temp = node_create(num) ; 

	temp->next = head ; 
	head = temp ;
	// inserted 
	print() ; 
}


void Lnklist::insert_at_last( int num ){
	node *temp = node_create(num) ; 

	// now I need to traverse till the end of the linked list !!

	node *traverse = head ; 
	while(traverse->next != NULL){
		traverse = traverse->next ; 
	}

	traverse->next = temp ; 

	// inserted at last

	print() ; 
}

void Lnklist::insert_at_pos(int pos , int num){

	node *temp = node_create(num) ; 

	cout << "\nInserting " << num << " at " << pos << "nd position " << endl; 

	node *traverse = head ;  

	for (int i = 1; i < pos-1; ++i){
		traverse = traverse->next ;
	}

	node *nth_node = traverse->next ; 
	temp->next = nth_node ; 
	traverse->next = temp ;  

	cout << "After insertion  : " ; 
	print() ; 
}

void Lnklist::delete_at_head(){
	cout << "Before deletion : " ; 

	print() ;

	node *temp = head ; 
	head = temp->next ; 
	delete temp ; 

	cout << "\nafter deletion : " ;
	print() ;
}

void Lnklist::delete_at_last(){
	cout << "\nBefore deletion : " ; 
	print() ; 

	node *traverse = head ; 	

	while(traverse->next->next != NULL) {
		traverse = traverse->next ;
	}
	traverse->next = NULL ; 

	cout << "\nAfter deletion : " ; 
	print() ; 
}


void Lnklist::delete_at_pos(int pos){
	cout << "\nBefore Deletion  : " ; 
	print() ; 

	node *traverse = head; 
	for (int i = 1 ; i < pos - 1; ++i){
		traverse = traverse->next  ; 
	}

	node *to_be_deleted = traverse->next  ; 
	traverse->next = to_be_deleted->next  ; 
	delete to_be_deleted ; 

	cout << "\nAfter Deletion at position " << pos << " : " ; 
	print() ; 
}

node* Lnklist::reverse_iteratively(node *head){
	node *current, *next_node, *previous ; 
	current = head ; 
	previous = NULL ; 
	
	while(current != NULL){
		next_node = current->next ;
		current->next = previous ; 

		// now I need to update my variables 
		previous = current ; 
		current = next_node ; 
	}
	head = previous ; 
	return head ; 
}

void Lnklist::print_with_arg(node *temp){
	head = temp ; 
	print() ; 
}

node* Lnklist::recursively(node *head){
	cout << "\nREcursively reversing the elements of the Linked list : "  ;
}
int main(){
	cout << "\n" ;

	Lnklist obj ; 
	obj.insert_at_head(1) ;
	obj.insert_at_head(2) ;

	cout << endl << "Inserting at last  : " << endl ; 

	obj.insert_at_last(4) ; 
	obj.insert_at_last(5) ; 

	/*
	cout << "\nInserting at a particular position : " << endl  ;

	obj.insert_at_pos(2, 10) ; 

	cout << "\nDeleting : " << "\n" 
		 << "\nDeleting at the head : \n " ; 
	obj.delete_at_head() ; 

	cout << "\nDeleting at the end : \n" ; 
	obj.delete_at_last() ; 

	cout << "\nDeleting at a position : " << 2; 

	obj.delete_at_pos(2) ; 
	*/
	cout << "\nReversing the linked list recursively  : " ; 

	node *temp = obj.reverse_iteratively(head) ; 
	obj.print_with_arg(temp) ; 
	cout << "\n" ;
}