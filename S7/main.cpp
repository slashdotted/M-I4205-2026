#include <iostream>

struct Meeple {
  Meeple(const std::string &name = "Bob") : m_name{name} {
    std::cout << "Meeple " << m_name << " was born!\n";
    ++meeple_counter;
  }

  // Copy constructor
  // Called whenever we construct a copy of an object
  // (typically with pass-by-value)
  Meeple(const Meeple &o) : m_name{o.m_name} {
    std::cout << "A duplicate meeple " << m_name << " was born!\n";
    ++meeple_counter;
  }

  // Copy assignment operator
  // Called whenever we write x = o
  // where x is the "current" object
  Meeple &operator=(const Meeple &o) {
    std::cout << "Overwriting meeple " << m_name << " with " << o.m_name
              << '\n';
    m_name = o.m_name;
    return *this;
  }

  ~Meeple() {
    // Destructor
    std::cout << "Meeple " << m_name << " dies!\n";
    --meeple_counter;
  }
  static unsigned int getMeepleCount() { return meeple_counter; }

private:
  std::string m_name;
  static unsigned int meeple_counter;
};

struct MeepleCar {
  Meeple driver{"Max"};
};

struct MeepleBike {
  MeepleBike() : biker{new Meeple{"Robert"}} {}

  // Copy constructor
  MeepleBike(const MeepleBike &o) : biker{new Meeple{*o.biker}} {}

  // Copy assignment operator
  MeepleBike &operator=(const MeepleBike &o) {
    *biker = *o.biker;
    return *this;
  }

  // Destructor
  ~MeepleBike() { delete biker; }

  Meeple *biker;
};

struct MeepleHorse {
  // RAII
  MeepleHorse() : jockey{new Meeple{"Slash"}} {}
  ~MeepleHorse() { delete jockey; }
  // Prevent copy (with = delete)
  MeepleHorse(const MeepleHorse &) = delete;
  MeepleHorse &operator=(const MeepleHorse &) = delete;

private:
  Meeple *jockey;
};

struct MeepleElephant {
  // We need this because the copy constructor hides
  // the default constructor
  MeepleElephant() = default;
  // Deleted copy constructor
  MeepleElephant(const MeepleElephant &) = delete;
  // Delete copy operator
  MeepleElephant &operator=(const Meeple &) = delete;

private:
  Meeple mahout;
};

// Here we are "reserving" some space in memory
// for the the static field
unsigned int Meeple::meeple_counter{0};

void hug(Meeple m) {
  std::cout << "Hugging a meeple\n";
  std::cout << Meeple::getMeepleCount() << " Meeples\n";
}

void hit(const Meeple &m) {
  std::cout << "Hitting a meeple\n";
  std::cout << Meeple::getMeepleCount() << " Meeples\n";
}

void wash(MeepleCar c) {}

void wash(MeepleBike b) {}

void wash(MeepleHorse h) {}

void part1() {
  using std::cout;
  cout << Meeple::getMeepleCount() << " Meeples\n";
  Meeple j{"Jay"};
  cout << Meeple::getMeepleCount() << " Meeples\n";
  {
    Meeple k{"Kay"};
    cout << Meeple::getMeepleCount() << " Meeples\n";
    // k dies here
  }
  Meeple c{"Davide"};
  hit(c);
  cout << Meeple::getMeepleCount() << " Meeples\n";
  hug(c);
  cout << Meeple::getMeepleCount() << " Meeples\n";
  cout << "=======================\n";
  c = j;
  cout << Meeple::getMeepleCount() << " Meeples\n";
  cout << "=======================\n";
  auto u{new Meeple{"You"}};
  cout << Meeple::getMeepleCount() << " Meeples\n";
  delete u;
}

void part2() {
  // MeepleCar m;
  // wash(m);
  MeepleBike mb;
  MeepleBike mb2;
  wash(mb);
  mb = mb2;
  MeepleHorse mh;
  // wash(mh);
  MeepleElephant me;
}

int main() {
  // part1();
  part2();
}
