#include <iostream>
#include "Chain.h"
#include "Stack.h"
#include "Queue.h"
//#include <utility>

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

	chain.Delete(3);
	chain.Print();

	chain.Delete(0);
	chain.Print();

	chain.Delete(4);

	if (chain.Delete(4) == 0) {
		cout << "Index error" << endl << endl;
	}

	cout << "--- Test: Stack ---" << endl;
	/*Stack<pair<int, char>> sp;

	for (int i = 0; i < 4; i++) {
		sp.push(make_pair(i, 'a' + i));
	}

	while (!sp.empty()) {
		cout << "Stack top <first, second>: <"
			<< sp.top().first << ","
			<< sp.top().second << ">" << endl;
		sp.pop();
	}*/
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