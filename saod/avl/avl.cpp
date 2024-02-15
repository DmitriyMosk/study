#include <iostream>
#include <stdexcept>

class TreeAVL {
public:
	struct Node {
		int key;
		int height;
		bool deleted;
		Node* left;
		Node* right;

		Node(int key) : key(key), height(0), deleted(false), left(nullptr), right(nullptr) {}
	};

	Node* root = nullptr;

	void insert(int key) {
		root = insert(root, key);
	}

	Node* insert(Node* node, int key) {
		if (node == nullptr) {
			return new Node(key);
		}
		else if (node->key > key) {
			node->left = insert(node->left, key);
		}
		else if (node->key < key) {
			node->right = insert(node->right, key);
		}
		else {
			throw std::runtime_error("Duplicate Key!");
		}
		return rebalance(node);
	}

	Node* rebalance(Node* z) {
		updateHeight(z);
		int balance = getBalance(z);
		if (balance > 1) {
			if (height(z->right->right) > height(z->right->left)) {
				z = rotateLeft(z);
			}
			else {
				z->right = rotateRight(z->right);
				z = rotateLeft(z);
			}
		}
		else if (balance < -1) {
			if (height(z->left->left) > height(z->left->right)) {
				z = rotateRight(z);
			}
			else {
				z->left = rotateLeft(z->left);
				z = rotateRight(z);
			}
		}
		return z;
	}

	void updateHeight(Node* n) {
		n->height = 1 + std::max(height(n->left), height(n->right));
	}

	Node* deleteNode(Node* node, int key) {
		if (node == nullptr) {
			return node;
		}
		else if (node->key > key) {
			node->left = deleteNode(node->left, key);
		}
		else if (node->key < key) {
			node->right = deleteNode(node->right, key);
		}
		else {
			node->deleted = true;
		}
		return rebalance(node);
	}

	Node* find(int key) {
		return find(root, key);
	}

	Node* find(Node* node, int key) {
		if (node == nullptr) {
			return nullptr;
		}
		if (node->key == key && !node->deleted) {
			return node;
		}
		if (key < node->key) {
			return find(node->left, key);
		}
		else {
			return find(node->right, key);
		}
	}

	Node* rotateRight(Node* y) {
		Node* x = y->left;
		Node* z = x->right;
		x->right = y;
		y->left = z;
		updateHeight(y);
		updateHeight(x);
		return x;
	}

	Node* rotateLeft(Node* y) {
		Node* x = y->right;
		Node* z = x->left;
		x->left = y;
		y->right = z;
		updateHeight(y);
		updateHeight(x);
		return x;
	}

	int height(Node* n) {
		return n == nullptr ? -1 : n->height;
	}

	int getBalance(Node* n) {
		return (n == nullptr) ? 0 : height(n->right) - height(n->left);
	}

	int findMax() {
		if (root == nullptr) {
			throw std::runtime_error("Tree is empty");
		}
		Node* current = root;
		while (current->right != nullptr) {
			current = current->right;
		}
		return current->key;
	}

	int findMin() {
		if (root == nullptr) {
			throw std::runtime_error("Tree is empty");
		}
		Node* current = root;
		while (current->left != nullptr) {
			current = current->left;
		}
		return current->key;
	}

	void printTree() {
		printTree(root, 0);
	}

	void printTree(Node* node, int depth) {
		if (node != nullptr) {
			for (int i = 0; i < depth; i++) {
				std::cout << " ";
			}
			std::cout << node->key << std::endl;
			printTree(node->left, depth + 1);
			printTree(node->right, depth + 1);
		}
	}
};

int main() {
	TreeAVL treeAVL;
	for (int i = 0; i < 50000; i++) {
		treeAVL.insert(i);
	}

	std::cout << "Max height = " << treeAVL.root->height << std::endl;
	std::cout << "Value = " << treeAVL.root->key << std::endl;

	std::cout << treeAVL.find(6)->key << std::endl;

	return 0;
}