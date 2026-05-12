#include "lecturerresearcher.h"
#include <iostream>

int main() {
  LecturerResearcher lr{"Penn", "ThumbsUp",   32424, "Cross Cultural",
                        "C++",  "Innovation", 0.42};
  std::cout << "Classname: " << lr.Lecturer::classname() << '\n';
  std::cout << "Classname: " << lr.Researcher::classname() << '\n';
  std::cout << "Classname: " << lr.classname() << '\n';

  std::cout << "Name:" << lr.name() << '\n';
}
