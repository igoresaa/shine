#pragma once
#include <vector>
#include <iostream>

enum class TokenType {
	Num,
	Plus,
	Minus,
	Unknown,
};

struct Token {
	TokenType type{};
	std::string content{};
};

class Lexer {
public:
	void test();
	std::vector<Token> tokenize();
};