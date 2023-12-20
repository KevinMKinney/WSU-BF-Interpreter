#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>

using std::ostringstream;
using std::string;
using std::cin;
using std::cout;

#define MEM_SIZE 128

class BfState {
	string code;
	const char* ip; // a pointer to the current instruction in code

	char data[MEM_SIZE]; // the data
	char* dp; // a pointer to the data cell to modify next

	public: 
		// constructor
		BfState(string inputCode) {
			code = inputCode;
			ip = &code[0];

			memset(data, 0, MEM_SIZE);
			dp = &data[0];
		}

		void run() {
			for (;*ip != '\0'; ip++) {
				switch (*ip) {
					case ('>'):
						inc_dp();
						break;

					case ('<'):
						dec_dp();
						break;

					case ('+'):
						inc_data();
						break;

					case ('-'):
						dec_data();
						break;

					case ('.'):
						output();
						break;

					case (','):
						input();
						break;

					case ('['):
						loop();
						break;

					case (']'):
						repeat();
						break;

					default:
						break;
				}
			}
			return;
		}

	private:
		// the '>' command
		void inc_dp() {
			++dp;
			return;
		}
		// the '<' command
		void dec_dp() {
			--dp;
			return;
		}
		// the '+' command
		void inc_data() {
			++*dp;
			return;
		}
		// the '-' command
		void dec_data() {
			--*dp;
			return;
		}
		// the '.' command
		void output() {
			putchar(*dp);
			return;
		}
		// the ',' command
		void input() {
			*dp = getchar();
			return;
		}
		// the '[' command
		void loop() {
			if (!*dp) {
				int loopCount = 1;
				while (loopCount > 0) {
					ip++;
					if (*ip == ']') {
						loopCount--;
					}
					if (*ip == '[') {
						loopCount++;
					}
				}
			}
			return;
		}
		// the ']' command
		void repeat() {
			int loopCount = 1;
			while (loopCount > 0) {
				ip--;
				if (*ip == ']') {
					loopCount++;
				}
				if (*ip == '[') {
					loopCount--;
				}
			}
			ip--;
			return;
		}
};

int main(int argc, char const *argv[]) {
	
	ostringstream input;
	input << cin.rdbuf();
	 
	BfState* bf = new BfState(input.str());
	bf->run();

	delete bf;

	return 0;
}