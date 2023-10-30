#include <iostream>
#include "Chain.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main(void)
{
	Chain<int> chain;

	cout << "--- Test: Chain ---" << endl;
	chain.Insert(0, 1);
	chain.Insert(1, 2);
	chain.Insert(2, 3);
	chain.Insert(2, 4);
	chain.Insert(2, 5);
	cout << "chain[4]==" << chain.Get(4) << endl;
	chain.Print();
	cout << "chain size: " << chain.GetSize() << endl;

	chain.Delete(3);
	chain.Print();
	cout << "chain size: " << chain.GetSize() << endl;

	chain.Delete(0);
	chain.Print();
	cout << "chain size: " << chain.GetSize() << endl;

	chain.Delete(4);

	if (chain.Delete(4) == 0) {
		cout << "Index error" << endl << endl;
	}

	cout << "--- Test: Stack ---" << endl;
	Stack<double> sp;

	for (int i = 0; i < 4; i++) {
		sp.push(1.1 + 0.1 * i);
	}

	while (!sp.empty()) {
		cout << "Stack top: " << sp.top() << endl;
		sp.pop();
	}

	cout << "--- Test: Queue ---" << endl;
	Queue<double> q;

	for (double i = 0; i < 4; i++) {
		q.push(1.1 + 0.1 * i);
	}

	while (!q.empty()) {
		cout << "Queue front: " << q.front() << endl;
		q.pop();
	}

	return 0;
}