#include <iostream>
#include <vector>

struct DataObject {
  virtual void display() const = 0;
  virtual ~DataObject() { std::cout << "~DataObject()\n"; }
};

struct IntObject : public DataObject {
  IntObject() : m_value{new int} {}
  ~IntObject() {
    std::cout << "~IntObject()\n";
    delete m_value;
  }
  IntObject(const IntObject &) = delete;
  IntObject &operator=(const IntObject &) = delete;
  void display() const override { std::cout << *m_value << '\n'; }

private:
  int *m_value;
};

void doSomething() {
  std::vector<DataObject *> objs;
  objs.push_back(new IntObject);
  objs.push_back(new IntObject);
  objs.push_back(new IntObject);
  objs.push_back(new IntObject);

  for (auto p : objs) {
    delete p;
  }
}

int main() { doSomething(); }
