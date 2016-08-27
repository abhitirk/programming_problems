#include <iostream>
using namespace std;
    
struct ListNode{
	int key_value;
	ListNode *next;
};

class List{	
	public:
		List();
		void append(int key);

	private:
		ListNode *head;
		ListNode *tail;
};

List::List(){
	head = NULL;
	tail = head;
}

void List::append(int key){
	ListNode *newnode = new ListNode;
	newnode->key_value = key;
	newnode->next = NULL;

	if(head == NULL){
		head = newnode;
		tail = head;
	}
	else{
		tail->next = newnode;
		tail = newnode;
	}
	return;
}

int main(){
	try{ 
		List l1;
		l1.append(1);
		//l1.append(2);
		//l1.append(3);
		//l1.append(5);
	} 
    catch (exception const& ex) { 
        cerr << "Exception: " << ex.what() <<endl; 
        return -1;
    } 
}