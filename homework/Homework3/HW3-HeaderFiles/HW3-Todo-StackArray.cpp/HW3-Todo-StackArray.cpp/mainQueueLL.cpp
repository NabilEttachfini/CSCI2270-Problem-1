#include <iostream>
#include <string>

#include "HW3-Todo-QueueLinkedList.hpp"

using namespace std;

int main()
{
	TodoQueueLinkedList queue;
	
	bool isDone = false;
	while (!isDone)
	{
		int choice; string input;
		cout << "1. isEmpty; 2. enqueue; 3. dequeue; 4. peek; 5. exit" << endl << "Choice: ";
		cin >> choice;
		switch (choice)
		{
			case 1:
				cout << "Queue " << (queue.isEmpty() ? "is" : "isn't") << " empty.";
				break;
			case 2:
				cout << "Type item to queue: ";
				cin.ignore();
				getline(cin, input);
				queue.enqueue(input);
				cout << "Queued \"" << input << "\".";
				break;
			case 3:
				input = (queue.peek() ? queue.peek()->todo : "NULL");
				queue.dequeue();
				cout << "Dequeued \"" << input << "\".";
				break;
			case 4:
				input = (queue.peek() ? queue.peek()->todo : "NULL");
				cout << "Front item is \"" << input << "\".";
				break;
			default:
				isDone = true;
		}
		cout << endl;
	}
	
	return 0;
}
