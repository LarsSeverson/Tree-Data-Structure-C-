/*
 Lars Severson
 * 4/25/2022
 * Assignment Trees
 Implement functions provided in assignment notes.
 */
#include <iostream>
using namespace std;
#include <stack>
#include <iomanip>

class Node {
public:
	int data;
	Node* pLeftChild;
	Node* pRightChild;
	Node() {
		data = 0;
		pLeftChild = NULL;
		pRightChild = NULL;
	}
	void displayNode() {
		cout  << "{" << data << "}";
	}
}; // end class Node
class Tree {
private:
	Node* pRoot;
public:
	Tree() {
		pRoot = NULL;
	}
	Node* find(int key) { // find node with given key
		Node* pCurrent = pRoot;
		while (pCurrent->data != key) {
			if (key < pCurrent->data) { // if go left
				pCurrent = pCurrent->pLeftChild;
			}
			else { // else go right
				pCurrent = pCurrent->pRightChild;
			}
			if (pCurrent == NULL) { // not found
				return NULL;
			}
		}
		return pCurrent; // found and return the node
	}
	void insert(int newData) {
		Node* newNode = new Node; // new node
		newNode->data = newData;  // set data

		if (pRoot == NULL) {      // if no node
			pRoot = newNode;
		}

		else {
			Node* pCurrent = pRoot; // navigation
			Node* pParent;
			while (true) {
				pParent = pCurrent; // loops back and defines each frame of while loop
				if (newData < pCurrent->data) { // less than is left
					pCurrent = pCurrent->pLeftChild;
					if (pCurrent == NULL) { // end of line
						pParent->pLeftChild = newNode; // set value
						return; // end while
					}
				}
				else { // else go right
					pCurrent = pCurrent->pRightChild;
					if (pCurrent == NULL) {
						pParent->pRightChild = newNode;
						return; // end while
					}	
				}	
			}
		}
	}
	void traverse(int type) {
		if (type == 1) {
			inOrder(pRoot);
		}
		if (type == 2) {
			preOrder(pRoot);
		}
		if (type == 3) {
			postORder(pRoot);
		}
	}
	void inOrder(Node* pLocalRoot) {
		if (pLocalRoot != NULL) {
			inOrder(pLocalRoot->pLeftChild);  // left
			cout << pLocalRoot->data << " ";  // display
			inOrder(pLocalRoot->pRightChild); // right
		}
	}
	void preOrder(Node* pLocalRoot) {
		if (pLocalRoot != NULL) {
			cout << pLocalRoot->data << " ";  // display
			inOrder(pLocalRoot->pLeftChild);  // left
			inOrder(pLocalRoot->pRightChild); // right
		}
	}
	void postORder(Node* pLocalRoot) {
		if (pLocalRoot != NULL) {
			inOrder(pLocalRoot->pLeftChild);  // left
			inOrder(pLocalRoot->pRightChild); // right
			cout << pLocalRoot->data << " ";  // display
		}
	}
	void minimum() {
		Node* pCurrent;
		pCurrent = pRoot;
		while (pCurrent->pLeftChild != NULL) {
			pCurrent = pCurrent->pLeftChild; // left
		}
		cout << pCurrent->data << endl; // display
	}
	void maximum() {
		Node* pCurrent;
		pCurrent = pRoot;
		while (pCurrent->pRightChild != NULL) {
			pCurrent = pCurrent->pRightChild; // right
		}
		cout << pCurrent->data << endl; // display
	}
	
	void displayTree() { // typed from lecture and doenst work, no clue how to do this function
		/*stack <Node*> globalStack;
		globalStack.push(pRoot);
		int nBlanks = 32;
		bool isRowEmpty = false;
		cout << "......................................";
		cout << endl;
		while (isRowEmpty == false) {
			stack<Node*> localStack;
			for (int j = 0; j < nBlanks; j++) {
				cout << ' ';
			}
			while (globalStack.empty() == false) {
				Node* temp = globalStack.top();
				globalStack.pop();
				if (temp != NULL) {
					cout << temp->data;
					localStack.push(temp->pLeftChild);
					localStack.push(temp->pRightChild);
					if (temp->pLeftChild != NULL || temp->pRightChild != NULL) {
						isRowEmpty = false;
					}
				}
				else {
					cout << "--";
					localStack.push(NULL);
					localStack.push(NULL);
				}
				for (int j = 0; j < nBlanks * 2 - 2; j++) {
					cout << " ";
				}
				cout << endl;
				nBlanks /= 2;
				while (localStack.empty() == false) {
					globalStack.push(localStack.top());
					localStack.pop();
				}
			}
		}
		cout << "......................................";
		cout << endl;*/
	}
};
int main() {
	Tree theTree;
	theTree.insert(6);
	theTree.insert(1);
	theTree.insert(3);
	theTree.insert(9);
	theTree.insert(8);

	Node* found = theTree.find(3);
	if (found != NULL) {
		cout << "Found the node with key 3" << endl;
	}
	else {
		cout << "Could not find the node with key 3" << endl;
	}
	cout << "tree inOrder(): ";
	theTree.traverse(1);
	cout << endl;
	cout << "tree preOrder(): ";
	theTree.traverse(2);
	cout << endl;
	cout << "tree postOrder(): ";
	theTree.traverse(3);
	cout << endl;
	theTree.displayTree();
	cout << "smallest: ";
	theTree.minimum();
	cout << "largest: ";
	theTree.maximum();
}
//Found the node with key 3
//tree inOrder() : 1 3 6 8 9
//tree preOrder() : 6 1 3 8 9
//tree postOrder() : 1 3 8 9 6
//smallest : 1
//largest : 9