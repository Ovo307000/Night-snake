#include <random>
#include <iostream>

void redColor() {
	std::cout << "\u001b[38;2;255;0;0m";
}

void greenColor() {
	std::cout << "\u001b[38;2;0;255;0m";
}

void reSetColor() {
	std::cout << "\u001b[0m";
}

bool choose(std::mt19937& gen, std::uniform_int_distribution<int>& dist) {
	int randomNumber = dist(gen);
	return (randomNumber == 1);
}

void run() {
	int minNumber = 0;
	int maxNumber = 1;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(minNumber,maxNumber);

	if (choose(gen, dist)) {
		greenColor();
		std::cout << "Night snack right!!!" << std::endl;
		reSetColor();
	}
	else {
		redColor();
		std::cout << "Night snack false!!!" << std::endl;
		reSetColor();
	}
}

void main() {
	int frequency = 1;

	for (int i = 0; i < frequency; i++)
	{
		run();
	}
}