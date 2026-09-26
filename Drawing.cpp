#include "Drawing.h"
#include "ListLinked.h"
#include "Circle.h"
#include "Square.h"
#include <iostream>
Drawing::Drawing() {
shapes = new ListLinked<Shape*>();
}
Drawing::~Drawing() {
delete shapes;
}
void Drawing::add_front(Shape* shape) {
shapes->insert(0, shape);
}
void Drawing::add_back(Shape* shape) {
shapes->append(shape);
}
void Drawing::print_all() {
for (int i = 0; i < shapes->size(); ++i) {
Shape* s = shapes->get(i);
std::cout << s << std::endl;
}
}
double Drawing::get_area_all_circles() {
double total_area = 0.0;
for (int i = 0; i < shapes->size(); ++i) {
Shape* s = shapes->get(i);
Circle* c = dynamic_cast<Circle*>(s);
if (c != nullptr) {
total_area += c->area();
}
}
return total_area;
}
void Drawing::move_squares(double incX, double incY) {
for (int i = 0; i < shapes->size(); ++i) {
Shape* s = shapes->get(i);
Square* sq = dynamic_cast<Square*>(s);
if (sq != nullptr) {
sq->translate(incX, incY);
}
}
}
