#include "queue.cpp"
using namespace std;
int main(){
	queue<int> que;
	cout<<"Is the queue empty? "<< que.empty() <<endl;
	que.enqueue(1);
	que.enqueue(3);
	que.enqueue(4);
	que.enqueue(2);
	que.enqueue(7);
	que.enqueue(25);
	que.print();
	cout<<endl;
	cout << "Value at the head of the queue ==>"<<que.peek()<<endl;
	cout << "The size of the queue is "<< que.getSize()<<endl;
	que.dequeue();
	que.print();
	cout<<endl;
	cout << "Value at the head of the queue ==>"<<que.peek()<<endl;
	que.dequeue();
	que.print();
	cout<<endl;
	cout << "Value at the head of the queue ==>"<<que.peek()<<endl;
	que.dequeue();
	que.print();
	cout<<endl;
	cout << "Value at the head of the queue ==>"<<que.peek()<<endl;
	return 0;
}
