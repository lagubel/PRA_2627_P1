#include "Square.h"
#include <stdexcept>
bool Square::check(Point2D* vertices) {
double d01 = Point2D::distance(vertices[0], vertices[1]);
double d12 = Point2D::distance(vertices[1], vertices[2]);
double d23 = Point2D::distance(vertices[2], vertices[3]);
double d30 = Point2D::distance(vertices[3], vertices[0]);
return (d01 == d12) && (d12 == d23) && (d23 == d30);
}
Square::Square() : Rectangle() {
vs[0] = Point2D(-1, 1);
vs[1] = Point2D(1, 1);
vs[2] = Point2D(1, -1);
}

Square::Square(std::string color, Point2D* vertices) : Rectangle(color, vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Los vértices no forman un cuadrado válido");
    }
}

void Square::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Los vértices no forman un cuadrado válido");
    }
    Rectangle::set_vertices(vertices);
}

std::ostream& operator<<(std::ostream &out, const Square &s) {
    out << "[Square: color = " << s.color << "; v0 = " << s.vs[0]
        << "; v1 = " << s.vs[1] << "; v2 = " << s.vs[2]
        << "; v3 = " << s.vs[3] << "]";
    return out;
}
