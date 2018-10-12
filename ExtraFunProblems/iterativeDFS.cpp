#include<iostream>
#include<stack>

class node{
	public:
		int val;
		node* left;
		node* right;
		node(int newVal, node* newLeft = nullptr, node* newRight = nullptr) : val(newVal), left(newLeft), right(newRight){}
};

/**
 *	Cannot do inputs that want to insert the same value.
 *	For example, cannot do: [ 1 , 1 , 2 ]
 *	Time Complexity : O(n), If inserted in ascending/descending order
 *	Can be fixed with AVL tree (balancing)
 */
void generateBinarySearchTree(node *root, int k){
	if(k < root->val){
		if(root->left)
			generateBinarySearchTree(root->left, k);
		else
			root->left = new node(k);
	} else { 
		if(root->right)
			generateBinarySearchTree(root->right, k);
		else
			root->right = new node(k);
	}
}

node* generateTree(){
	// Change this to what you want to add to the tree :
	int arr[] = {4,2,8,1,3,6,7,9};
	// -------------------------------------------------
	
	node* root = new node(arr[0]);
	for(int i = 1; i < sizeof(arr)/sizeof(arr[0]); ++i){
		generateBinarySearchTree(root, arr[i]);
	}
	return root;
}

void deleteTree(node* root){
	if(root->left)
		deleteTree(root->left);
	if(root->right)
		deleteTree(root->right);
	delete root;
}

/**
 * This is a post order search. So it traverses the longest 
 * path and then checks the nodes value coming back up the tree.
 */
bool find(node* root, int n){
	
	struct visitNode{
		node* Node;
		bool left;
		bool right;
		visitNode(node* newNode, bool newLeft = false, bool newRight = false) : Node(newNode), left(newLeft), right(newRight){}
	};

	std::stack<visitNode*> s;
	s.push(new visitNode(root));

	while(!s.empty()){
		if(s.top()->Node->left && s.top()->left == false){
			s.top()->left = true;
			s.push(new visitNode(s.top()->Node->left));
		}else if(s.top()->Node->right && s.top()->right == false){
			s.top()->right = true;
			s.push(new visitNode(s.top()->Node->right));
		}else{
			std::cout << s.top()->Node->val << std::endl;
			if(s.top()->Node->val == n){
				while(!s.empty()){
					delete s.top();
					s.pop();
				}
				return true;
			}
			delete s.top();
			s.pop();
		}
	}
	return false;
}

int main(){
	int n = 4;
	node* root = generateTree();
	if(root){
		find(root, n) == false ? std::cout << "False" << std::endl : std::cout << "True" << std::endl;
		deleteTree(root);
	} else 
		std::cout << "False" << std::endl;
	
	return 0;
}
