#include <iostream>
using namespace std;

class ListNode{
	private:
		int keyvalue;
		ListNode *next;
		
	public:
		ListNode(int key){
			this->keyvalue = key;
			this->next = NULL;
		}
		ListNode(int key, ListNode *next){
			this->keyvalue = key;
			this->next = next;
		}
		int getKey(){
			return keyvalue;
		}
		void setKey(int key){
			this->keyvalue = key;
			return;
		}
		ListNode * getNext(){
			return next;
		}
		void setNext(ListNode *next){
			this->next = next;
			return;
		}
};

class List{	
	public:
		List();
		void append(int key);
		void traverse();
		void reverse_sublist(int start, int finish);
		void merge_even_odd();
	
	private:
		ListNode *head;
		ListNode *tail;
};

List::List(){
	head = NULL;
	tail = head;
}

void List::append(int key){
	ListNode *newnode = new ListNode(key);
	
	if(head == NULL){
		head = newnode;
		tail = head;
	}
	else{
		tail->setNext(newnode);
		tail = newnode;
	}
	return;
}

void List::traverse(){
	ListNode *current;
	current = head;
	cout << "\n";
	while(current != tail){
		cout << current->getKey() << ", ";
		current = current->getNext();
	}
	cout << current->getKey() << ".";
	return;
}

void List::reverse_sublist(int start, int finish){
	ListNode *current = head;
	ListNode *conn_node, *end_node, *pivot, *prev_node;
	int count = 1;
	while(count <= finish){
		if(count == start - 1){
			conn_node = current;
			end_node = current->getNext();
			pivot = end_node;
		}
		if(count > start){
			prev_node = current;
			current = current->getNext();
			prev_node->setNext(pivot);
			pivot = prev_node;
		}
		else
			current = current->getNext();
		count++;
	}
	end_node->setNext(current);
	conn_node->setNext(pivot);
	return;
}

void List::merge_even_odd(){
	ListNode *even_node = head;
	ListNode *odd_node_head = head->getNext();
	ListNode *odd_node = odd_node_head;
	
	while(odd_node->getNext()){
		even_node->setNext(odd_node->getNext());
		even_node = even_node->getNext();
		odd_node->setNext(even_node->getNext());
		if(odd_node->getNext())
			odd_node = odd_node->getNext();
	}
	tail = odd_node;
	even_node->setNext(odd_node_head);
	cout << "\nEven node: " << even_node->getKey();
	cout << "\nEven node next: " << even_node->getNext()->getKey();
	cout << "\nOdd node head: " << odd_node_head->getKey();
	cout << "\nOdd node: " << odd_node->getKey();
	//cout << "\nOdd node next: " << odd_node->getNext()->getKey();
	return;
}

int main(){
	try{ 
		List *l1 = new List();
		l1->append(0);
		l1->append(1);
		l1->append(2);
		l1->append(3);
		l1->append(4);
		l1->append(5);
		l1->append(6);
		l1->traverse();
		//l1->reverse_sublist(2, 5);
		l1->merge_even_odd();
		l1->traverse();
	} 
    catch (exception const& ex) { 
        cerr << "Exception: " << ex.what() <<endl; 
        return -1;
    } 
}