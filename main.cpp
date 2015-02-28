#include "CompilerLA.h"
#include <string>
#include <iomanip>

int main(){
	
	char x[80], y[80], Delim[] = " ";
	char *token, *next;
	std::ifstream f;
	std::fstream g;  // write into file
	std::string input;
	int m = 0, n = 0, d = 0;

	std::cout << "Enter file name with whole address for execution.\n";
	std::cout << "For example, the file is loacted at C:\\filae\\demo.txt\n";
	std::cout << "Please enter your file address for word analysis: ";
	std::cin >> input;

	f.open(input.c_str(),std::ios::in);
	g.open("ndata.txt", std::ios::out);
	while (!f.eof()){
		f.getline(x, 80, '\n');
		re_commend(x, m);
		token = strtok_s(x, Delim, &next);
		while (token != nullptr){
			n = strlen(token);
			write_file(g, n, token);
			token = strtok_s(nullptr, Delim, &next);
		}
	}
	g.close();
	f.close();

	int a = 0, counter = 1, d_counter = 0;
	std::string line, result;
	g.open("ndata.txt", std::ios::in);
	while (!g.eof()){
		g.getline(y, 80, '\n');
		token = strtok_s(y, Delim, &next);
		std::cout << std::right << std::setw(5) << "Output:" << std::endl << std::endl;
		std::cout << std::right << std::setw(5) << "token" << std::left << std::setw(20) << "\t\t\t\tlexeme" << std::endl << std::endl;
		while (token != nullptr){
			line = std::to_string(counter);
			line += "->";
			
			result = classify_token(token, n, d_counter);
			
			std::cout << std::right << std::setw(5) << result << "\t\t\t\t" << std::left << std::setw(30) << token << std::endl;
			token = strtok_s(nullptr, Delim, &next);
			d_counter = 0;
			counter++;

		}
	}
	g.close();

	std::cout << "Check your newdata.txt file in the same folder with this file. \n" << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;

	
}
