#include "gtest/gtest.h"
#include "covid.h"

// Test fixture for covid class
class CovidTest : public ::testing::Test {
protected:
    covid patientTracker;
};

// Test fixture for patient class
class PatientTest : public ::testing::Test {
protected:
    PatientTest() : patient("12345", "John Doe", 30) {}

    Patient patient;
};

// Patient class tests
TEST_F(PatientTest, Getters) {
    EXPECT_EQ(patient.getBuNumber(), "12345");
    EXPECT_EQ(patient.getName(), "Sam");
    EXPECT_EQ(patient.getAge(), 30);
}

// covid class tests
TEST_F(CovidTest, AddPatient) {
    Patient newPatient("67890", "Shubman", 25);
    patientTracker.add_patient(newPatient);

    EXPECT_EQ(patientTracker.search_patient("67890"), 0);
}

TEST_F(CovidTest, SearchPatientNotFound) {
    EXPECT_EQ(patientTracker.search_patient("nonexistent"), -1);
}

TEST_F(CovidTest, SearchPatientFound) {
    Patient existingPatient("54321", "Mithali", 40);
    patientTracker.add_patient(existingPatient);

    EXPECT_EQ(patientTracker.search_patient("54321"), 0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
