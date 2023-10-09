#ifndef QUEUE
#define QUEUE

#include "Chain.h"

template <class T>
class Queue {
public:
	Queue();
	~Queue();
	void push(T data);
	void pop();
	T front();
	T back();
	bool empty();
	int size();
private:
	Chain<T>* chain;
};

template <class T>
Queue<T>::Queue() {
	chain = new Chain<T>;
}

template <class T>
Queue<T>::~Queue() {
	delete chain;
}

template <class T>
void Queue<T>::push(T data) {
	int i = 0;
	for (i = 0; chain->GetIter(i) != 0; i++);
	chain->Insert(i, data);
}

template <class T>
void Queue<T>::pop() {
	chain->Delete(0);
}

template <class T>
T Queue<T>::front() {
	return chain->Get(0);
}

template <class T>
T Queue<T>::back() {
	int i = 0;
	T result;

	for (i = 0; chain->GetIter(i) != 0; i++) {
		result = chain->Get(i);
	}

	return result;
}

template <class T>
int Queue<T>::size() {
	int i = 0;
	T result;

	for (i = 0; chain->GetIter(i) != 0; i++);

	return i;
}

template <class T>
bool Queue<T>::empty() {
	return chain->IsEmpty();
}

#endif

/*

**개선해야 할 점**
Doubly-linked List를 사용하면 push()와 back()의 시간 복잡도를 줄일 수 있을 것으로 보임.

*/