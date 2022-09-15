#include "project.h"

void _help() {
	std::cout << "How to use: "; 
	std::cout << "./a.out [--flag] [number]" << std::endl;
	std::cout << "Flags availables: " << std::endl;
	std::cout << "--decimalToBinary | -b : Convert from decimal to binary." << std::endl;
	std::cout << "--binaryToDecimal | -d : Convert from binary to decimal." << std::endl;
}

void decimal_to_binary(int number) {
	std::cout << "Converting from decimal to binary..." << std::endl;
	int binary_array[32], i{0};

	while (number > 0) {
		binary_array[i] = number % 2;
		i++;
		number = number / 2;
	}

	for (int k = i - 1; k >= 0; k-- ) {
		std::cout << binary_array[k];
	}

	std::cout << std::endl;
}

void binary_to_decimal(int number) {
	std::cout << "Converting from binary to decimal..." << std::endl;
	int last_digit {0}, number_decimal {0}, base {1};

	while(number) {
		last_digit = number % 10;
		number = number / 10; 
		number_decimal += last_digit * base;
		base = base * 2; 
	}

	std::cout << number_decimal << std::endl;
}


void _start(int argc, char** argv){
	if (argc > 2) {

		std::string param = argv[1]; 
		int number = std::stoi(argv[2]);

		if (param == "--decimalToBinary" || param == "-b") {
			decimal_to_binary(number);

		} else if(param == "--binaryToDecimal" || param == "-d") {
			binary_to_decimal(number);

		} else {
			_help();
		}
		
	} else {
		_help();
	}
}