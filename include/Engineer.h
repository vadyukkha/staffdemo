#pragma once
#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include <iostream>
#include "Personal.h"
#include "Interfaces.h"

class Project;

class Engineer : public Personal, public ProjectBudget {
 public:
    Engineer(const int64_t id, const std::string& name,
             const int64_t workTime, const int64_t payment, Positions position);
    virtual ~Engineer() = default;

    void calcSalary() override;
    int64_t calcBudgetPart() override;
    void printInfo() override;
 protected:
    Project* project_;
};

class Tester : public Engineer {
 public:
    Tester(const int64_t id, const std::string& name,
           const int64_t workTime, const int64_t payment, Positions position, const Project* project);
    ~Tester() override = default;

    int64_t calcProAdditions(int64_t bags) override;
    void calcSalary() override;
};

class Programmer : public Engineer {
 public:
    Programmer(const int64_t id, const std::string& name,
               const int64_t workTime, const int64_t payment, Positions position, const Project* project);
    ~Programmer() override = default;

    int64_t calcProAdditions(int64_t bonus) override;
    void calcSalary() override;
};

class TeamLeader : public Programmer, public Heading {
 public:
    TeamLeader(const int64_t id, const std::string& name,
               const int64_t workTime, const int64_t payment, Positions position, const Project* project);
    ~TeamLeader() override = default;

    int64_t calcHeads() override;
    void calcSalary() override;
};

#endif  // INCLUDE_ENGINEER_H_
