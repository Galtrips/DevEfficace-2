#include "treelist.h"

using namespace std;

TreeList::TreeList() {
	this->root = new Node;
	this->root->name = "Root";

	this->current = this->root;
}

TreeList::TreeList(Node* node) {
	this->root = node;
	this->current = this->root;
}

TreeList::~TreeList() {
	//Destruction de tous les enfants des noeuds
	//La destruction doit commencer par la fin de list

}

void TreeList::addChild(string name) {

	Node* child = new Node;
	child->name = name;
	child->parent = this->current;

	this->current->childs.push_back(child);
}

void TreeList::resetCurrentPos() {
	this->current = this->root;
}

bool TreeList::moveToChild(int index) {
    try {
		if (this->current->childs[index] != nullptr) {
			this->current = this->current->childs[index];
			return true;
		}
		return false;
    }
    catch (const exception& e) {
        return false;
    }
}

bool TreeList::moveToParent() {
	try {
		if (this->current->parent != nullptr) {
			this->current = this->current->parent;
			return true;
		}
		return false;
	}
	catch (const exception& e) {
		return false;
	}
}

string TreeList::printNode(Node* n, int l) const {
	string value = "";

	for (int i = 0; i < l; i++) {
		value += "	";
	}

	if (n == this->current) {
		value += "X " + n->name + " " + (n->state == true ? "(Open)" : "(Close)") + "\n";
	}
	else {
		value += "0 " + n->name + " " + (n->state == true ? "(Open)" : "(Close)") + "\n";
	}
	
	if (n->state == true) {
		for (Node* child : n->childs) {
			value += printNode(child, l + 1);
		}
	}

	return value;
}

int TreeList ::getHeight(Node* root) {
	if (root == NULL) {
		return 0;
	}

	int maxHeight = 0;
	for (auto child : root->childs) {
		maxHeight = max(maxHeight, getHeight(child));
	}
	return maxHeight + 1;
}

void TreeList::editName(string name) {
	this->current->name = name;
}

void TreeList::changeStatus() {
	if (this->current->state == true) {
		this->current->state = false;
		return;
	}
	this->current->state = true;
}

int TreeList::memory(Node* n) {
	int value = 0;

	value = sizeof(*n);

	if (n->state == true) {
		for (auto child : n->childs) {
			value += memory(child);
		}
	}

	return value;
}

int TreeList::countLeaves(Node* n) {
	int count = 0;
	
	if (n == nullptr) {
		return 0;
	}

	if (n->childs.empty()) {
		return 1;
	}
	else {
		for (auto child : n->childs) {
			count += countLeaves(child);
		}
		
	};
	return count;
}

int TreeList::countNodes(Node* n) {
	int count = 0;

	++count;
	for (auto child : n->childs) {
		count += countNodes(child);
	}

	return count;
}

void TreeList::remove(Node* n) {

	if (n == nullptr) {
		n = current;
	}

	Node* parent = n->parent;
	if (parent) {
		for (auto it = parent->childs.begin(); it != parent->childs.end(); it++) {
			if (*it == n) {
				parent->childs.erase(it);
				break;
			}
		}
	}
	else {
		root = nullptr;
	}
	for (auto enfant : n->childs) {
		remove(enfant);
	}
	if (n == current) current = root;
	delete n;
}

void TreeList::removeAllChildren() {

}

void TreeList::removeChild(int index) {

}

void TreeList::removeChild(string name) {

}

ostream& operator<<(ostream& os, TreeList& dt) {
	
	os << dt.printNode(dt.root, 0) << endl;

	return os;
}