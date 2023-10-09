# Linked List
This is the code that I learned.

## 1\. Files
* Chain.h: classes for linked list
* Queue.h: class for queue
* Stack.h: class for stack
* Manager.cpp: main function for test

## 2\. Definition of Member Function is Not Seperated from Header File
```cpp
template <class T>
```

* reference: Litcoder. n. d. "C++ template 선언과 구현을 서로 다른 파일에 나눌 수 없다", Litcoder Blog. <https://www.litcoder.com/?p=3208>

## 3\. Debug Delete
```cpp
// Chain.h approximately Line 50
template <class T>
Chain<T>::~Chain() {
	ChainNode<T>* next = NULL;

	while (first != NULL) {
		next = first->link;
        cout << "Delete: " << first->data << endl;  //Debug
		delete first;  
		first = next;
	}
}
```

If you want to print when a node is deleted, alternate the destructer of Chain with the above code.

## 4\. To Do
* Doubly-linked List
* In Chain.h, T Chain<T>::Get(int index) Needs Exception Handling