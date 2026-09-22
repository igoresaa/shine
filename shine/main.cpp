//#include "lexer.hpp"
//#include "parser.hpp"
//#include <iostream>
//
//int main() {
//	Lexer lexer{};
//	std::vector<Token> tokens = lexer.tokenize();
//	
//	Parser parser{};
//	parser.init(tokens);
//	BinaryExp exp = parser.process();
//	
//	std::cout << "Left num: " << exp.left.content << '\n';
//	std::cout << "Opeator: " << exp.op.content << '\n';
//	std::cout << "Right num: " << exp.right.content << "\n\n";
//
//	std::cout << tokens.size() << '\n';
//
//	return 0;
//}