#include <iostream>
using namespace std;

struct ListNode{
	int key_value;
	ListNode *next;
	
	ListNode(int v): key_value(v), next(nullptr)
		{}	
};

class List{	
	public:
		List();
		void append(int key);
		void traverse();
		void reverse_sublist(int start, int finish);
	
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
		tail->next = newnode;
		tail = newnode;
	}
	return;
}

void List::traverse(){
	ListNode *current;
	current = head;
	cout << "\n";
	while(current != tail){
		cout << current->key_value << ", ";
		current = current->next;
	}
	cout << current->key_value << ".";
	return;
}

void List::reverse_sublist(int start, int finish){
	ListNode *current = head;
	ListNode *conn_node, *end_node, *pivot, *prev_node;
	int count = 1;
	while(count <= finish){
		if(count == start - 1){
			conn_node = current;
			end_node = current->next;
			pivot = end_node;
		}
		if(count > start){
			prev_node = current;
			current = current->next;
			prev_node->next = pivot;
			pivot = prev_node;
		}
		else
			current = current->next;
		count++;
	}
	end_node->next = current;
	conn_node->next = pivot;
	return;
}

int main(){
	try{ 
		List l1;
		l1.append(1);
		l1.append(2);
		l1.append(3);
		l1.append(4);
		l1.append(5);
		l1.append(6);
		l1.traverse();
		l1.reverse_sublist(2, 5);
		l1.traverse();
	} 
    catch (exception const& ex) { 
        cerr << "Exception: " << ex.what() <<endl; 
        return -1;
    } 
}