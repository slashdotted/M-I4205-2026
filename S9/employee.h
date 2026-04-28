#pragma once
#include <string>

// Interfaces are just classes
// where each method is a pure virtual one
// (virtual AND = 0)
class IHireable {
public:
  virtual void hire() = 0;
};

class Employee : public IHireable {
public:
  Employee(std::string name, std::string institute, int nr);
  // Employee() = default;
  ~Employee();
  std::string name() const;
  std::string institute() const;
  int employeenr() const;
  void hire() override;

  // polymorphic method (it can be overriden)
  // runtime binding
  virtual std::string classname() const;

  // polymorphic method (it can be overridden)
  // = 0 "pure virtual method" (it has no implementation in this class)
  virtual void fire() = 0;

protected:
  std::string m_name;
  std::string m_institute;
  int m_employeenr;
};
