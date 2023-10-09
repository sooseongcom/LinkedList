#ifndef STACK
#define STACK

#include "Chain.h"

template <class T>
class Stack {
public:
	Stack();
	~Stack();
	void push(T data);
	void pop();
	T top();
	bool empty();
private:
	Chain<T>* chain;
};

template <class T>
Stack<T>::Stack() {
	chain = new Chain<T>;
}

template <class T>
Stack<T>::~Stack() {
	delete chain;
}

template <class T>
void Stack<T>::push(T data) {
	chain->Insert(0, data);
}

template <class T>
void Stack<T>::pop() {
	chain->Delete(0);
}

template <class T>
T Stack<T>::top() {
	return chain->Get(0);
}

template <class T>
bool Stack<T>::empty() {
	return chain->IsEmpty();
}

#endif