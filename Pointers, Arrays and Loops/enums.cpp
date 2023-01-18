#include <iostream>

enum class Color { red, blue, green };
enum class TrafficLight { red, blue, green };

void color_func(Color& c)
{
  if (c < Color::blue)
  {
    printf("c is Color::red\n");
  }
}

int main()
{
  Color c1 = Color::red;
  Color c2 = Color::blue;
  Color c3 = Color::red;

  color_func(c1);
  color_func(c2);

  if (c1 == c3)
  {
    printf("c1 == c3\n");
  }

  if (c1 == c2)
  {
    printf("c1 == c2\n");
  }

  if (c1 == Color::red)
  {
    printf("c1 == Color::red\n");
  }

  TrafficLight tl = TrafficLight::blue;
  TrafficLight *t = &tl;
  *t = TrafficLight::red;

  if (*t == TrafficLight::red)
  {
    printf("*t == TrafficLight::red\n");
  }

  return 0;
}
