#include <iostream>
#include <string>
#include <vector>
#include <cctype>

enum class TokenType {
	Num,
	Plus,
	Minus,
	Unknown,
};

struct Token
{
	TokenType type{};
	std::string content{};
};

class Lexer {
public:
	void test() {
		search();
		std::cout << "type 0: Num\ntype 1: Plus\ntype 2: Minus\ntype 3: Unknown\n\n";
		for (const auto& n : tokens) {
			std::cout << n.content << "\t\ttype: " << static_cast<int>(n.type) << '\n';
		}
	}

private:
	std::string input{ "123 - test +" };
	std::vector<Token> tokens{};

	int position{};
	std::string segment{};

	void define() {
		while (position < input.size() && input[position] != ' ') {
			segment += input[position];
			position++;
		}
		pushToken();
	}

	void search() {
		while (position < input.size()) {
			define();
			segment = "";
			position++; // пропускаем пробел
		}
	}

	void pushToken() {
		if (segment == "+") {
			tokens.push_back(
				{ TokenType::Plus, segment }
			);
		}
		else if (segment == "-") {
			tokens.push_back(
				{ TokenType::Minus, segment }
			);
		}
		else if (isNumber()) {
			tokens.push_back(
				{ TokenType::Num, segment }
			);
		}
		else {
			tokens.push_back(
				{ TokenType::Unknown, segment }
			);
		}
	}

	bool isNumber() {
		for (size_t i = 0; i < segment.size(); i++) {
			if (!std::isdigit(segment[i])) {
				return false;
			}
		}
		return true;
	}
};



int main() {
	Lexer lexer{};
	lexer.test();
	return 0;
}