#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<int> q;

	q.push(23);
	q.push(3);
	q.push(41);
	q.push(55);


	cout << q.front() << " ";
	cout << q.back() << " ";
	q.pop();

	cout << q.front() << " ";
	cout << q.back() << " ";
	q.pop();

	cout << q.front() << " ";
	cout << q.back() << " ";
	q.pop();

	cout << endl;
	return 0;
}
