// TODO: Парсер должен принимать вектор tokens и на его основе
// возвращать структуру, (пока что) содержащую число, оператор и еще одно число

#include "lexer.hpp"
#include <vector>
#include <iostream>

struct BinaryExp {
	Token left{};
	Token op{};
	Token right{};
};

class Parser {
public:
	void init(std::vector<Token> inputTokens) {
		tokens = inputTokens;
	}
	BinaryExp process() {
		find();
		return exp;
	}
private:
	std::vector<Token> tokens{};
	BinaryExp exp{};

	void find() {
		if (tokens[0].type == TokenType::Num &&
			(tokens[1].type == TokenType::Plus || tokens[1].type == TokenType::Minus)
			&& tokens[2].type == TokenType::Num)
		{
			exp.left = tokens[0];
			exp.op = tokens[1];
			exp.right = tokens[2];
		}
	}
};

int main() {
	Lexer lexer{};
	std::cout << "Lexer output:\n\n";
	lexer.test();
	std::vector<Token> tokens{ lexer.tokenize() };

	Parser parser{};
	parser.init(tokens);
	BinaryExp exp{ parser.process() };

	std::cout << "\n\n\nParser output:\n\nLeft num:\t\t" << exp.left.content << '\n';
	std::cout << "Opeator:\t\t" << exp.op.content << '\n';
	std::cout << "Right num:\t\t" << exp.right.content << "\n\n";

	std::cout << "Size of array:\t\t" << tokens.size() << '\n';

	return 0;
}