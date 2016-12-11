#include <iostream>
#include <string>

#include "HW3-Todo-QueueArray.hpp"

using namespace std;

int main()
{
	TodoQueueArray queue;
	
	bool isDone = false;
	while (!isDone)
	{
		int choice; string input;
		cout << "1. isEmpty; 2. isFull; 3. enqueue; 4. dequeue; 5. peek; 6. exit" << endl << "Choice: ";
		cin >> choice;
		switch (choice)
		{
			case 1:
				cout << "Queue " << (queue.isEmpty() ? "is" : "isn't") << " empty.";
				break;
			case 2:
				cout << "Queue " << (queue.isFull() ? "is" : "isn't") << " full.";
				break;
			case 3:
				cout << "Type item to queue: ";
				cin.ignore();
				getline(cin, input);
				queue.enqueue(input);
				cout << "Queued \"" << input << "\".";
				break;
			case 4:
				input = (queue.peek() ? queue.peek()->todo : "NULL");
				queue.dequeue();
				cout << "Dequeued \"" << input << "\".";
				break;
			case 5:
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
