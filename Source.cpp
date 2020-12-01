#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <array>

//wrapper for our array
struct inputArr
{
	int arr[200];
};

//This method takes the text our puzzle input and out puts an array
inputArr getPuzzleInput()
{
	inputArr input;

	std::ifstream file;
	std::string line;
	file.open("puzzle-input.txt");
	int count = 0;
	while (std::getline(file, line))
	{
		input.arr[count] = std::stoi(line);
		count++;
	}

	return input;
}

//AOC Day 1 Part 1
//Find two numbers whose sum equals 2020, multiply them together for the answer

//so the method we need is k - input[i], where k is our target value and input[i] is a value in the list. The we check the list for the result,
//here we are assuming that there are only a single correct pair so we can break as soon as we find a match
void findAnswer(inputArr input)
{
	for (int i = 0; i < 200 - 1; i++)
	{
		int result = 2020 - input.arr[i];


		bool exists = std::find(std::begin(input.arr), std::end(input.arr), result) != std::end(input.arr);

		if (exists)
		{
			std::cout << input.arr[i] << " + " << result << '\n';
			std::cout << "Answer: " << (input.arr[i] * result);
			break;
		}
	}
}

//AOC Day 1 Part 2
//Find 3 numbers whose sum equals 2020, multiply them together for the answer

//take the sorted input, set a fixed point arr[i], and two pointers first arr[i + 1] and last arr[size - 1], then if the sum of the 3 equals 2020 print
//out the 3 values, else if the sum is less increment the first pointer, else decrement the last pointer. The while condition maintains that there is 
//no overlap and only unique permutations are checked
void findAnswer2(inputArr input)
{
	int countFirst;
	int countLast;
	int size = sizeof(input.arr) / sizeof(input.arr[0]);


	for (int i = 0; i < size - 2; i++)
	{
		countFirst = i + 1;
		countLast = size - 1;
		while (countFirst < countLast)
		{
			int point = input.arr[i];
			int first = input.arr[countFirst];
			int last = input.arr[countLast];

			if (point + first + last == 2020)
			{
				std::cout << point << " + " << first << " + " << last << " = " << (point + first + last) << '\n';
				break;
			}
			else if (point + first + last < 2020)
				countFirst++;
			else
				countLast--;
		}
	}
}

int main()
{
	inputArr input = getPuzzleInput();
	std::sort(std::begin(input.arr), std::end(input.arr));
	for (int i = 0; i < 200; i++)
	{
		std::cout << i << ":" << input.arr[i] << '\n';
	}

	//findAnswer(input);
	findAnswer2(input);

	return 0;
};
