#include <cassert>
#include <iostream>
#include <memory>
#include <stack>

using std::cout;
using std::endl;
using std::make_unique;
using std::unique_ptr;

template <typename T>
struct BinaryTreeNode {
	T data;
	unique_ptr<BinaryTreeNode<T>> left, right;
};

class btree
{
    public:
        btree();
        ~btree();

        void insert(int key);
        //node *search(int key);
        void destroy_tree();
		void inorder_traversal();
		//void test_traversal();
		void preorder_traversal();
		void postorder_traversal();
		void read_node_inputs();
		//int find_height(node *treenode, int height, int left_height, int right_height);
		//void check_height_balanced();

    private:
        void destroy_tree(const unique_ptr<BinaryTreeNode<int>>&);
        void insert(int key, const unique_ptr<BinaryTreeNode<int>>&);
        <BinaryTreeNode<int>> *search(int key, const unique_ptr<BinaryTreeNode<int>>&);
        unique_ptr<BinaryTreeNode<int>> root;
};

btree::btree()
{
  root=nullptr;
}

btree::~btree()
{
  destroy_tree();
}

void btree::destroy_tree(const unique_ptr<BinaryTreeNode<int>>& leaf)
{
  if(leaf!=nullptr)
  {
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}

void btree::insert(int key, const unique_ptr<BinaryTreeNode<int>>& leaf)
{
  if(key < leaf->data)
  {
    if(leaf->left!=nullptr)
     insert(key, leaf->left);
    else
    {
      leaf->left = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{key, nullptr, nullptr});
  //Sets the right child of the child node to null
    }  
  }
  else if(key >= leaf->data)
  {
    if(leaf->right!=nullptr)
      insert(key, leaf->right);
    else
    {
      leaf->right= make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{key, nullptr, nullptr});
    }
  }
}

<BinaryTreeNode<int>> *btree::search(int key, const unique_ptr<BinaryTreeNode<int>>& leaf)
{
  if(leaf!=nullptr)
  {
    if(key==leaf->data)
      return leaf;
    if(key<leaf->data)
      return search(key, leaf->left);
    else
      return search(key, leaf->right);
  }
  else return nullptr;
}

void btree::insert(int key)
{
  if(root!=nullptr)
    insert(key, root);
  else
  {
    root = make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{key, nullptr, nullptr});
  }
}

<BinaryTreeNode<int>> *btree::search(int key)
{
  return search(key, root);
}

void btree::destroy_tree()
{
  destroy_tree(root);
}

void btree::test_traversal(){
	cout << "Entered test_traversal...";
	unique_ptr<BinaryTreeNode<int>> current;
	unique_ptr<BinaryTreeNode<int>> display_node;
	current = root;
	//stack<node*> nodeStack;
	while(current->left!=nullptr){
		cout << current->data << ", ";
		current = current->left;
	}
	cout << current->data << ", ";
}

void btree::inorder_traversal(){
	cout << "Entered inorder_traversal...\n";
	unique_ptr<BinaryTreeNode<int>> current;
	unique_ptr<BinaryTreeNode<int>> display_node;
	current = root;
	stack<<BinaryTreeNode<int>>*> nodeStack;
	int current_null = 0;
	do{
		if(current_null != 1){
			nodeStack.push(current);
			//cout << current->key_value << " pushed on stack...\n";
			if(current->left != nullptr)
				current = current->left;
			else current_null = 1;
		}
		else{
			display_node = nodeStack.top();
			//cout << "top of stack: " << display_node->key_value << "\n";
 			nodeStack.pop();
			cout << display_node->data << ", ";
			current = display_node->right;
			if(display_node->right != nullptr){
				current = display_node->right;
				current_null = 0;
			}
		}
		//cout << "current_null value: " << current_null << "\n";
	} while(!(nodeStack.empty() && current_null == 1));
	cout << "exited inorder_traversal...\n";
	return;
}

/*void btree::preorder_traversal(){
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
}*/

void btree::read_node_inputs(){
	int data = 0;
	cout << "Enter first key value to be inserted:";
	cin >> data;
	insert(data);
	cout << "Enter key value to be inserted: (-ve to stop)";
	cin >> data;
	while(data >=0){
		insert(data, root);
		cout << "Enter key value to be inserted: (-ve to stop)";
		cin >> data;
	}
	return;
}

/*int btree::find_height(node *treenode, int height, int left_height, int right_height){
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
}*/

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