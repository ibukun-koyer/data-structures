#include "stack.cpp"
using namespace std;
int main(){
	stack<int> stacks;
	cout<<"Is the stack empty? "<< stacks.empty() <<endl;
	stacks.push(1);
	stacks.push(3);
	stacks.push(4);
	stacks.push(2);
	stacks.push(7);
	stacks.push(25);
	stacks.print();
	cout<<endl;
	cout << "Value at the head of the stack ==>"<<stacks.peek()<<endl;
	cout << "The size of the stack is "<< stacks.getSize()<<endl;
	stacks.pop();
	stacks.print();
	cout<<endl;
	cout << "Value at the head of the stack ==>"<<stacks.peek()<<endl;
	stacks.pop();
	stacks.print();
	cout<<endl;
	cout << "Value at the head of the stack ==>"<<stacks.peek()<<endl;
	stacks.pop();
	stacks.print();
	cout<<endl;
	cout << "Value at the head of the stack ==>"<<stacks.peek()<<endl;
	return 0;
}
