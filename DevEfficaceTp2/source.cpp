#include <iostream>

#include "treelist.h"

using namespace std;

//LAPIERRE Yohan G2

int main(int argc, char const* argv[]) {

	TreeList* tree = new TreeList;
	tree->addChild("Php");
	tree->addChild("Tmp");
	tree->addChild("Users");
	tree->addChild("Programmes");

	tree->moveToChild(2);
	tree->addChild("Etu Lyon 1");
	tree->addChild("Public");

	tree->moveToChild(0);
	tree->addChild("Documents");
	tree->addChild("Videos");
	tree->addChild("Desktop");

	tree->moveToParent();
	tree->moveToChild(1);
	tree->addChild("Documents");
	tree->addChild("Videos");

	tree->changeStatus();
	tree->editName("Etu Lyon 2");
	tree->moveToParent();
	//tree->remove(nullptr);

	cout << *tree << endl;
	cout << "La memoire de l'arbre est de " << tree->memory(tree->getRoot()) << " Octets." << endl;
	cout << "L'arbre possede " << tree->countLeaves(tree->getRoot()) << " feuilles." << endl;
	cout << "L'arbre possede " << tree->countNodes(tree->getRoot()) << " noeuds." << endl;

	return EXIT_SUCCESS;
}