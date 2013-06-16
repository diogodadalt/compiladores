#include "symbol.h"

Symbol::Symbol(const std::string& text, const Common::TokenType& tokenType): text(text), tokenType(tokenType) {}

Symbol::Symbol(const std::string& text, const Common::TokenType& tokenType, const Common::DataType& dataType): text(text), tokenType(tokenType), dataType(dataType) {}

Symbol::Symbol(const std::string& text, const Common::DataType& dataType): text(text), dataType(dataType) {}

std::string Symbol::getText() {
	return text;
}

void Symbol::setText(const std::string &value) {
	text = value;
}

Common::DataType Symbol::getDataType() const {
	return dataType;
}

void Symbol::setDataType(const Common::DataType &value) {
	dataType = value;
}

Common::TokenType Symbol::getTokenType() const {
	return tokenType;
}

void Symbol::setTokenType(const Common::TokenType &value) {
	tokenType = value;
}

int Symbol::getCount() const {
	return count;
}

void Symbol::setCount(int value) {
	count = value;
}
