#include <iostream>
#include <string>

#include "HW3-Todo-StackArray.hpp"

using namespace std;

int main()
{
	TodoStackArray stack;
	
	bool isDone = false;
	while (!isDone)
	{
		int choice; string input;
		cout << "1. isEmpty; 2. isFull; 3. push; 4. pop; 5. peek; 6. exit" << endl << "Choice: ";
		cin >> choice;
		switch (choice)
		{
			case 1:
				cout << "Stack " << (stack.isEmpty() ? "is" : "isn't") << " empty.";
				break;
			case 2:
				cout << "Stack " << (stack.isFull() ? "is" : "isn't") << " full.";
				break;
			case 3:
				cout << "Type item to push: ";
				cin.ignore();
				getline(cin, input);
				stack.push(input);
				cout << "Pushed \"" << input << "\" into list.";
				break;
			case 4:
				input = (stack.peek() ? stack.peek()->todo : "NULL");
				stack.pop();
				cout << "Popped \"" << input << "\" out of list.";
				break;
			case 5:
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
