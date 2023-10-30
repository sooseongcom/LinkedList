#ifndef CHAIN
#define CHAIN

#include <iostream>
using namespace std;

template <class T>
class Chain;

template <class T>
class ChainNode {
	template <class U> friend class Chain;

public:
	ChainNode(const T data, ChainNode<T>* link = NULL);

private:
	T data;
	ChainNode<T>* link;
};

template <class T>
class Chain {
public:
	Chain(void);
	virtual ~Chain();
	bool IsEmpty(void);
	void Print(void);
	T Get(int index);
	ChainNode<T>* GetIter(int index);
	ChainNode<T>* Insert(int index, T data);
	int GetSize();
	int Delete(int index);

private:
	ChainNode<T>* first;
};

//definition

template <class T>
ChainNode<T>::ChainNode(const T data, ChainNode<T>* link) {
	this->data = data;
	this->link = link;
}

template <class T>
Chain<T>::Chain(void) {
	first = NULL;
}

template <class T>
Chain<T>::~Chain() {
	ChainNode<T>* next = NULL;

	while (first != NULL) {
		next = first->link;
		delete first;
		first = next;
	}
}

template <class T>
bool Chain<T>::IsEmpty(void) {
	return first == NULL;
}

template <class T>
void Chain<T>::Print(void) {
	ChainNode<T>* currNode = first;

	cout << "Print: ";
	while (currNode != NULL) {
		cout << currNode->data << ' ';
		currNode = currNode->link;
	}
	cout << endl;
}

template <class T>
T Chain<T>::Get(int index) {
	int currIndex = 0;
	ChainNode<T>* currNode = first;

	for (currIndex = 0; currIndex < index; currIndex++) {
		currNode = currNode->link;
	}

	if (currNode) {
		return currNode->data;	//Now, currNode is the desired node.
	}

	//else
	//return 0;	//Need Exception Handling
}

template <class T>
ChainNode<T>* Chain<T>::GetIter(int index) {
	int currIndex = 0;
	ChainNode<T>* currNode = first;

	for (currIndex = 0; currIndex < index; currIndex++) {
		currNode = currNode->link;
	}

	if (currNode) {
		return currNode;	//Now, currNode is the desired node.
	}

	//else
	return 0;
}

template <class T>
ChainNode<T>* Chain<T>::Insert(int index, T data) {
	int currIndex = 0;
	ChainNode<T>* currNode = first, * newNode = 0;

	for (currIndex = 0; currNode && currIndex < index - 1; currIndex++) {
		currNode = currNode->link;
	}
	if (index > 0 && currNode == NULL) return NULL;

	if (index == 0) {
		newNode = new ChainNode<T>(data, first);
		first = newNode;
	}
	else {
		newNode = new ChainNode<T>(data, currNode->link);
		currNode->link = newNode;
	}

	return newNode;
}

template <class T>
int Chain<T>::GetSize() {
	int currIndex = 0;
	ChainNode<T>* currNode = first;

	for (currIndex = 0; currNode != NULL; currIndex++) {
		currNode = currNode->link;
	}

	return currIndex;
}

template <class T>
int Chain<T>::Delete(int index) {
	int currIndex = 0;
	ChainNode<T>* prevNode = 0, * currNode = first;

	for (currIndex = 0; currNode && currIndex < index; currIndex++) {
		prevNode = currNode;
		currNode = currNode->link;
	}

	if (currNode) {
		if (prevNode) {
			prevNode->link = currNode->link;
			delete currNode;
		}
		else {
			first = currNode->link;
			delete currNode;
		}
		return currIndex;
	}

	//else
	return 0;
}

#endif