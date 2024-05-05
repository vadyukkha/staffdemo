#include "../include/Employee.h"

Employee::Employee(const int64_t id, const std::string& name,
                   const int64_t work_time, const Positions position, const int64_t payment)
    : id_(id), name_(name), work_time_(work_time), position_(position),
        payment_(payment) {}

void Employee::setWorkTime(const int64_t hours) {
    work_time_ = hours;
}
