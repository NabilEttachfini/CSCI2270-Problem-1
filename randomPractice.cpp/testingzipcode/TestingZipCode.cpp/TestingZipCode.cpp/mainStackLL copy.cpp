#include <iostream>
#include <string>

#include "HW3-Todo-StackLinkedList.hpp"

using namespace std;

int main()
{
	TodoStackLinkedList stack;
	
	bool isDone = false;
	while (!isDone)
	{
		int choice; string input;
		cout << "1. isEmpty; 2. push; 3. pop; 4. peek; 5. exit" << endl << "Choice: ";
		cin >> choice;
		switch (choice)
		{
			case 1:
				cout << "Stack " << (stack.isEmpty() ? "is" : "isn't") << " empty.";
				break;
			case 2:
				cout << "Type item to push: ";
				cin.ignore();
				getline(cin, input);
				stack.push(input);
				cout << "Pushed \"" << input << "\" into list.";
				break;
			case 3:
				input = (stack.peek() ? stack.peek()->todo : "NULL");
				stack.pop();
				cout << "Popped \"" << input << "\" out of list.";
				break;
			case 4:
				input = (stack.peek() ? stack.peek()->todo : "NULL");
				cout << "Top list item is \"" << input << "\".";
				break;
			default:
				isDone = true;
		}
		cout << endl;
	}
	
	return 0;
}
