#pragma once
#include "lecturer.h"
#include "researcher.h"
#include <string>

class LecturerResearcher : public Lecturer, public Researcher {
public:
  LecturerResearcher(std::string name, std::string institute, int nr,
                     std::string studies, std::string course,
                     std::string researcharea, double researchpercentage);
  double researchpercentage() const;

  std::string classname() const override;

  void fire() override;

protected:
  double m_researchpercentage;
};
