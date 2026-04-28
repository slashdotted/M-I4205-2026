#include "employee.h"
#include "researcher.h"
#include <iostream>

using std::cout;

/*void showDetails(Employee e) {
  cout << "Name:" << e.name() << " Istitute:" << e.institute()
       << " Nr:" << e.employeenr() << " Classname:" << e.classname() << '\n';
}*/

void showDetails2(const Employee &e) {
  cout << "Name:" << e.name() << " Istitute:" << e.institute()
       << " Nr:" << e.employeenr() << " Classname:" << e.classname() << '\n';
}

void showDetails2(const Employee *e) {
  cout << "Name:" << e->name() << " Istitute:" << e->institute()
       << " Nr:" << e->employeenr() << " Classname:" << e->classname() << '\n';
}

int main() {
  /*Employee e{"Franco", "ISIN", 42};
  showDetails(e);
  showDetails2(e);
  showDetails2(&e);*/

  Researcher r{"Elvis", "IDNẀ", 4324, "Networks"};
  // showDetails(r);
  showDetails2(r);
  showDetails2(&r);
  // cout << r.name() << "," << r.institute() << "," << r.employeenr() << ","
  //     << r.researcharea() << '\n';
}
