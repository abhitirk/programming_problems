#include <iostream>
#include <stack>
using namespace std;

struct node
{
  int key_value;
  node *left;
  node *right;
};

class btree
{
    public:
        btree();
        ~btree();

        void insert(int key);
        node *search(int key);
        void destroy_tree();
		void inorder_traversal();
		void test_traversal();
		void preorder_traversal();
		void postorder_traversal();
		void read_node_inputs();
		int find_height(node *treenode, int height, int left_height, int right_height);
		void check_height_balanced();

    private:
        void destroy_tree(node *leaf);
        void insert(int key, node *leaf);
        node *search(int key, node *leaf);
        node *root;
};

btree::btree()
{
  root=NULL;
}

btree::~btree()
{
  destroy_tree();
}

void btree::destroy_tree(node *leaf)
{
  if(leaf!=NULL)
  {
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}

void btree::insert(int key, node *leaf)
{
  if(key< leaf->key_value)
  {
    if(leaf->left!=NULL)
     insert(key, leaf->left);
    else
    {
      leaf->left=new node;
      leaf->left->key_value=key;
      leaf->left->left=NULL;    //Sets the left child of the child node to null
      leaf->left->right=NULL;   //Sets the right child of the child node to null
    }  
  }
  else if(key>=leaf->key_value)
  {
    if(leaf->right!=NULL)
      insert(key, leaf->right);
    else
    {
      leaf->right=new node;
      leaf->right->key_value=key;
      leaf->right->left=NULL;  //Sets the left child of the child node to null
      leaf->right->right=NULL; //Sets the right child of the child node to null
    }
  }
}

node *btree::search(int key, node *leaf)
{
  if(leaf!=NULL)
  {
    if(key==leaf->key_value)
      return leaf;
    if(key<leaf->key_value)
      return search(key, leaf->left);
    else
      return search(key, leaf->right);
  }
  else return NULL;
}

void btree::insert(int key)
{
  if(root!=NULL)
    insert(key, root);
  else
  {
    root=new node;
    root->key_value=key;
    root->left=NULL;
    root->right=NULL;
  }
}

node *btree::search(int key)
{
  return search(key, root);
}

void btree::destroy_tree()
{
  destroy_tree(root);
}

void btree::test_traversal(){
	cout << "Entered test_traversal...";
	node *current;
	node *display_node;
	current = root;
	//stack<node*> nodeStack;
	while(current->left!=NULL){
		cout << current->key_value << ", ";
		current = current->left;
	}
	cout << current->key_value << ", ";
}

void btree::inorder_traversal(){
	cout << "Entered inorder_traversal...\n";
	node *current;
	node *display_node;
	current = root;
	stack<node*> nodeStack;
	int current_null = 0;
	do{
		if(current_null != 1){
			nodeStack.push(current);
			//cout << current->key_value << " pushed on stack...\n";
			if(current->left != NULL)
				current = current->left;
			else current_null = 1;
		}
		else{
			display_node = nodeStack.top();
			//cout << "top of stack: " << display_node->key_value << "\n";
 			nodeStack.pop();
			cout << display_node->key_value << ", ";
			current = display_node->right;
			if(display_node->right != NULL){
				current = display_node->right;
				current_null = 0;
			}
		}
		//cout << "current_null value: " << current_null << "\n";
	} while(!(nodeStack.empty() && current_null == 1));
	cout << "exited inorder_traversal...\n";
	return;
}

void btree::preorder_traversal(){
	cout << "Entered preorder_traversal...\n";
	node *current;
	current = root;
	stack<node*> nodeStack;
	while(true){
		cout << current->key_value << ", ";
		if (current->left != NULL){
			if(current->right != NULL)
				nodeStack.push(current);
			current = current->left;
		}
		else if(current->right != NULL){
			current = current->right;
		}
		else if(!nodeStack.empty()){
			if(nodeStack.top()->right != NULL){
				current = nodeStack.top()->right;
			}
			nodeStack.pop();
		}
		else break;
	}
	cout<<"Exiting preoder_traversal\n";
	return;
}

void btree::postorder_traversal(){
	cout << "Entered postorder_traversal...\n";
	stack<node*> nodeStack;
	stack<node*> preorderStack;
	node *current;
	current = root;
	while(true){
		preorderStack.push(current);
		if(current->right!=NULL){
			if(current->left!=NULL)
				nodeStack.push(current);
			current = current->right;
		}
		else if(current->left!=NULL){
			current = current->left;
		}
		else if(!nodeStack.empty()){
			if(nodeStack.top()->left!=NULL){
				current = nodeStack.top()->left;
				nodeStack.pop();
			}
		}
		else break;
	}
	
	while(!preorderStack.empty()){
		cout << preorderStack.top()->key_value << ", ";
		preorderStack.pop();
	}
	
	cout<<"Exiting postorder_traversal\n";
	return;
}

void btree::read_node_inputs(){
	int key_value = 0;
	cout << "Enter first key value to be inserted:";
	cin >> key_value;
	insert(key_value);
	cout << "Enter key value to be inserted: (-ve to stop)";
	cin >> key_value;
	while(key_value >=0){
		insert(key_value, root);
		cout << "Enter key value to be inserted: (-ve to stop)";
		cin >> key_value;
	}
	return;
}

int btree::find_height(node *treenode, int height, int left_height, int right_height){
	if (treenode == NULL)
		return height;
	else{
		height++;
		int temp_height;
		left_height = find_height(treenode->left, height, left_height, right_height);
		right_height = find_height(treenode->right, height, left_height, right_height);
		temp_height = left_height > right_height? left_height : right_height;
		height = temp_height > height ? temp_height: height;
		return height;
	}
}

void btree::check_height_balanced(){
	node *left_subtree = root->left;
	node *right_subtree = root->right;
	int left_height = 0, right_height = 0, diff;
	int height = 0;
	left_height = find_height(left_subtree, height, left_height, right_height);
	right_height = find_height(right_subtree, height, left_height, right_height);
	diff = left_height - right_height;
	cout << "Left height: " << left_height << "\n";
	cout << "Right height: " << right_height << "\n";
	if(diff >=-1 && diff <= 1)
		cout << "Tree is height balanced.";
	else
		cout << "Tree is not height balanced.";
	return;
}

int main(){
	try { 
			btree bt;
			bt.read_node_inputs();
			//bt.inorder_traversal();
			//bt.preorder_traversal();
			//bt.postorder_traversal();
			bt.check_height_balanced();
	    } 
	    catch (exception const& ex) { 
	        cerr << "Exception: " << ex.what() <<endl; 
	        return -1;
	    } 
}