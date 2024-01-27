#ifndef COVID_H
#define COVID_H

#include <vector>
#include <string>

class Patient {
public:
    Patient(const std::string& buNumber, const std::string& name, int age);

    const std::string& getBuNumber() const;
    const std::string& getName() const;
    int getAge() const;

private:
    std::string buNumber_;
    std::string name_;
    int age_;
};

class covid {
public:
    void add_patient(const Patient& patient);
    int search_patient(const std::string& buNumber) const;

private:
    std::vector<Patient> patients_;
};

#endif // COVID_H
