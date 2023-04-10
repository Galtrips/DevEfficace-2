#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
	string name;
	bool state = true;
	Node* parent = nullptr;
	vector<Node*> childs;
};

class TreeList
{
private:
	Node* root;
	Node* current;
public:
	TreeList();
	TreeList(Node*);
	~TreeList();

	Node* getRoot() const { return this->root; }

	friend ostream& operator<<(ostream& os, TreeList& dt);

	void addChild(string);
	void editName(string);
	void changeStatus();
	int memory(Node* n);
	int countLeaves(Node* n);
	int countNodes(Node* n);

	void resetCurrentPos();
	bool moveToParent();
	bool moveToChild(int);
	int getHeight(Node*);

	void remove(Node*);
	void removeAllChildren();
	void removeChild(int);
	void removeChild(string);

	string printNode(Node* n, int l) const;
};