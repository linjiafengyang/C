#include "stack.h"

char get_command() {
	char command;
	bool waiting = true;
	cout << "select command and press <Enter>:";
	while (waiting) {
		cin >> command;
		command = tolower(command);
		if (strchr('?=+-*/q', command) != NULL) {
			waiting = false;
		}
	}
	return command;
}

bool do_command(char command, Stack &numbers) {
	double p, q;
	switch (command) {
		case '?':
			cout << "Enter a real number:" <<  
	}
}
int main() {
	Stack stored_numbers;
	while ()
}