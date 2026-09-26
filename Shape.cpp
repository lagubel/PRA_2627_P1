#include "Shape.h"
#include <stdexcept>
#include <string>

Shape::Shape() : color("red") {}

Shape::Shape(std::string color) {
	if (color != "red" && color != "green" && color != "blue") {
		throw std::invalid_argument("Color no válido");
	}
	this->color = color;
}

std::string Shape::get_color() const {
	return color;
}

void Shape::set_color(std::string c) {
	if (c != "red" && c != "green" && c != "blue") {
		throw std::invalid_argument("color no válido");
	}
	this->color = c;
}
