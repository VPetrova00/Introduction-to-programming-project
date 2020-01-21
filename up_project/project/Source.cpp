#include <iostream>

int length(char*);
char* lowercase(char[]);
void print(char*);
void print(int);
void remove(char*, char*);
void replace(char*, char*, char*);
char* uppercase(char*);
int search(char*, char*);

int main() {

	char userInput[1000] = "";
	char commandNumber = '0';
	std::cout << "Enter string: ";
	std::cin.getline(userInput, 1000);
	std::cout << "Select what would you like to do: \n1. Uppercase\n2.Lowercase\n3.Search\n4.Delete\n5.Replace\n";
	std::cout << "Enter command number!\n";
	std::cin >> commandNumber;
	bool getSecondComand = false;

	char secondCommand[1000] = "";
	char thirdCommand[1000] = "";

	if (commandNumber != '1' && commandNumber != '2' && (commandNumber < 1 || commandNumber > 5) && commandNumber != 'e') {
		std::cout << "Enter second command: ";
		std::cin >> secondCommand;
		if (commandNumber == '5') {
			std::cout << "Enter third command: ";
			std::cin >> thirdCommand;
			getSecondComand = true;
		}
		getSecondComand = true;
	}

	while (commandNumber != 'e') {
		switch (commandNumber)
		{
		case '1':
		{
			//work
			char* uppercaseInput = uppercase(userInput);
			print(uppercaseInput);
			break;
		}
		case '2':
		{
			//work
			char* lowercaseInput = lowercase(userInput);
			print(lowercaseInput);
			break;
		}
		case '3':
		{
			//work
			if (!getSecondComand) {
				std::cout << "Enter second command: ";
				std::cin >> secondCommand;
			}
			int searchStringIndex = search(userInput, secondCommand);
			if (searchStringIndex == -1) {
				std::cout << "There is no such a word!\n";
			}
			else {
				print(searchStringIndex);
			}
			getSecondComand = false;
			break;
		}
		case '4':
		{
			if (!getSecondComand) {
				std::cout << "Enter second command: ";
				std::cin >> secondCommand;
			}
			remove(userInput, secondCommand);
			std::cout << secondCommand << " removed!\n";
			std::cout << userInput << std::endl;
			getSecondComand = false;
			break;
		}
		case '5':
		{
			if (!getSecondComand) {
				std::cout << "Enter second command: ";
				std::cin >> secondCommand;
				std::cout << "Enter third command: ";
				std::cin >> thirdCommand;
			}

			replace(userInput, secondCommand, thirdCommand);
			print(userInput);
			getSecondComand = false;
			break;
		}
		default:
		{
			std::cout << "There is not a command like this! Try again! \n";
			break;
		}
		}

		std::cout << "Enter number command: ";
		std::cin >> commandNumber;
	}

	if (commandNumber == 'e') {
		std::cout << "See you again! :D" << std::endl;
	}
}

int length(char* arr) {
	if (arr == nullptr) {
		return -1;
	}

	int index = 0;
	while (arr[index] != '\0') {
		index++;
	}

	return index;
}

char* lowercase(char userInput[]) {
	int arrLength = length(userInput);

	for (int i = 0; i < arrLength; i++)
	{
		if ('A' <= userInput[i] && userInput[i] <= 'Z') {
			userInput[i] = userInput[i] + ('a' - 'A');
		}
	}

	return userInput;
}

char* uppercase(char* userInput) {
	int arrLength = length(userInput);

	for (int i = 0; i < arrLength; i++)
	{
		if ('a' <= userInput[i] && userInput[i] <= 'z') {
			userInput[i] = userInput[i] - ('a' - 'A');
		}
	}

	return userInput;
}

void replace(char* userInput, char* searchWord, char* replaceWord) {
	int position = search(userInput, searchWord);
	int len = length(searchWord);
	int replaceWordLen = length(replaceWord);
	int index = 0;
	while (position != -1)
	{
		for (int i = position; i < position + replaceWordLen; i++)
		{
			userInput[i] = replaceWord[index];
			index++;
		}
		index = 0;
		position = search(userInput, searchWord);
	}
}

int search(char* arr, char* stringToSearch) {
	int arr_length = length(arr);
	int word_len = length(stringToSearch);
	int count = 0;
	int k = 0;
	int hasWord = false;
	int foundAtPosition = -1;
	for (int i = 0; i < arr_length; i++)
	{
		if (arr[i] == stringToSearch[k]) {
			k++;
			count++;
			if (arr[i + 1] == stringToSearch[k]) {
				hasWord = true;
				foundAtPosition = i - count + 1;
			}
			else {
				if (arr[i] == stringToSearch[k - 1] && count == word_len) {
					hasWord = true;
					foundAtPosition = i - count + 1;
					break;
				}
				hasWord = false;
				k = 0;
				count = 0;
				foundAtPosition = -1;
			}
		}
	}

	return foundAtPosition;
}

void remove(char* userInput, char* stringToRemove) {
	int position = search(userInput, stringToRemove);
	int len = length(stringToRemove);
	int userInputLen = length(userInput);
	while (position != -1)
	{
		for (int i = position; i < userInputLen; i++)
		{
			userInput[i] = userInput[i + len];
		}
		position = search(userInput, stringToRemove);
	}
}

void print(int index) {
	std::cout << "String found at position " << index << std::endl;
}

void print(char* arr) {
	std::cout << arr << std::endl;
}