# SDSRH
A project based on file structures concept in C++ language which is  designed to get the input from the user to a text file and CRUD  operations are performed on the same. 


This C++ program is designed to manage COVID-19 patient records and vaccination appointments efficiently. It offers features for adding, searching, and displaying patient records, as well as booking vaccination slots and viewing vaccination statistics.

## Table of Contents

- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [COVID-19 Patient Records](#covid-19-patient-records)
- [Vaccination Management](#vaccination-management)
- [Software Engineering](#Topics-and-Software-Engineering-techniques)
- [License](#license)

## Features

### COVID-19 Patient Records

- Add patient details including BU number, name, age, phone number, and hospital.
- Search for patients by BU number or name (secondary key).
- Remove patient records.
- Display patient records.
- Secondary key index for efficient searching.
- Data files for patient records and index storage.

### Vaccination Management

- Record vaccination appointments with Aadaar number, name, age, gender, phone, and address.
- View and search vaccination records.
- Book vaccination slots with start and end times.
- Sort vaccination slots.
- Display vaccination statistics, including the number of vaccinated people and available slots.

## Usage

### COVID-19 Patient Records

1. **Add Patient Record:** Enter patient details, including BU number, name, age, phone number, and hospital. The system will store the data and update the index files.

2. **Search Patients:** Search for patients by BU number or name (secondary key). The system displays matching records.

3. **Remove Patient Records:** Delete patient records by specifying the BU number.

4. **Display Patients:** View the details of all patients in the system.

### Vaccination Management

1. **Add Vaccination Record:** Record vaccination appointments by entering Aadaar number, name, age, gender, phone number, and address. The system will store the data and update the index files.

2. **View Vaccination Records:** Display vaccination records, including Aadaar number, name, age, gender, phone number, and address.

3. **Search Vaccination Records:** Search for vaccination records by name (secondary key) and display matching records.

4. **Book Vaccination Slots:** Book available vaccination slots with specified start and end times.

5. **Sort Vaccination Slots:** Sort the vaccination slots based on start times.

6. **View Vaccination Statistics:** Check the number of people vaccinated and the available slots.


## Topics and Software Engineering techniques

### 1.Git
usage of GitHub for the whole project
[Git](https://github.com/Venkatchavan/SDSRH/commits/main)

### 2.UML
UML Diagramm  (Class,Activity Diagram and UseCase Diagrams for the project with Edlich's Fund)
[UML](https://github.com/Venkatchavan/SDSRH/tree/develop/UML%20Diagrams)

### 3.Requirement Analysis [Clickhere-Requirements](https://github.com/Venkatchavan/SDSRH/tree/545fee67bb11e94ccfd2d53bbbd2074747dfb997/Requirements)

A. **Patient Information Management:**
   - **Description:** The system must allow users to input and manage patient information, including BU number, name, and age.
     
B. **Search Functionality:**
   - **Description:** Users should be able to search for patient details using their BU number. NOTE: ONE OF THE FUNCTIONALITY
     
C. **IDE Integration:**
   - **Description:** The system needs to seamlessly integrate with DevC++, providing convenient shortcuts for development tasks.
     
D. **Optimized Build Process:**
   - **Description:** The build process should be optimized for minimal code compilation time to ensure efficient development.
     
E. **SonarCloud Integration:**
   - **Description:** Integrate SonarCloud for continuous code quality checks, providing insights into project metrics.

These requirements ensure effective patient data management, convenient development workflows, and a focus on code quality throughout the development process.

### 4.Analysis

Thorough analysis encompasses defining a patient-centric scope, identifying stakeholders, mitigating risks, ensuring compliance, integrating seamlessly, and evaluating technical feasibility, budget, scalability, and market differentiation, setting the stage for a robust Patient Management System.

### 5.DDD

Employing Domain-Driven Design principles, the project aligns business goals and technical implementation, fostering a modular, decoupled architecture to enhance flexibility, scalability, and maintainability in developing an innovative Patient Management System.
-[Domain-Driven-Design](https://github.com/Venkatchavan/SDSRH/tree/022c15586b925a99794a5c0bf3a44dd5d59815db/DDD)

### 6.Metrices
Creation of SonarCloud account and connecting to repository (with advanced settings) for metric badges:

[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=Venkatchavan_SDSRH&metric=alert_status)](https://sonarcloud.io/dashboard?id=Venkatchavan_SDSRH)
[![Bugs](https://sonarcloud.io/api/project_badges/measure?project=Venkatchavan_SDSRH&metric=bugs)](https://sonarcloud.io/dashboard?id=Venkatchavan_SDSRH)
[![Code Smells](https://sonarcloud.io/api/project_badges/measure?project=Venkatchavan_SDSRH&metric=code_smells)](https://sonarcloud.io/dashboard?id=Venkatchavan_SDSRH)
[![Duplicated Lines (%)](https://sonarcloud.io/api/project_badges/measure?project=Venkatchavan_SDSRH&metric=duplicated_lines_density)](https://sonarcloud.io/dashboard?id=Venkatchavan_SDSRH)
[![Maintainability Rating](https://sonarcloud.io/api/project_badges/measure?project=Venkatchavan_SDSRH&metric=sqale_rating)](https://sonarcloud.io/dashboard?id=Venkatchavan_SDSRH)
[![Reliability Rating](https://sonarcloud.io/api/project_badges/measure?project=Venkatchavan_SDSRH&metric=reliability_rating)](https://sonarcloud.io/dashboard?id=Venkatchavan_SDSRH)
[![Security Rating](https://sonarcloud.io/api/project_badges/measure?project=Venkatchavan_SDSRH&metric=security_rating)](https://sonarcloud.io/dashboard?id=Venkatchavan_SDSRH)
[![Vulnerabilities](https://sonarcloud.io/api/project_badges/measure?project=Venkatchavan_SDSRH&metric=vulnerabilities)](https://sonarcloud.io/dashboard?id=Venkatchavan_SDSRH)

[IF ABOVE LINK EXPIRES CLICK HERE](https://github.com/Venkatchavan/SDSRH/blob/9b89a16a83c5dbeff8433d30916fe27172cfecd5/Screenshot%202024-01-22%20233715.png)

### 7.Clean code development

Creation of a Cheat Sheet for upcoming projects - [ccd-sdsrh.md](https://github.com/Venkatchavan/SDSRH/blob/1b9eefd12c6a1c8141f0645d0fcad34efc3137b6/ccd-sdsrh.md)

### 8.Build

Utilizes C++ with a custom build system for managing COVID-19 patient data and vaccination appointments, designed for seamless integration as a reusable package.
-[build-of-project](https://github.com/Venkatchavan/SDSRH/blob/31251148b1c798fda081937a9a0abb818a3e8365/build_of_project.md)

### 9.Unit Tests
The project's unit tests ensure robust functionality and adherence to specifications, promoting code reliability and preventing regression issues in the Patient Management System.
-[see-unit-tests](https://github.com/Venkatchavan/SDSRH/blob/b9ce8026f8903818f0c4c1dedaf1197e5038d062/unittest.md)

### 10.IDE

Adding most favorite shortcuts here and create own to allow faster developemnt without lifting hands from keyboard
-[IDE](https://github.com/Venkatchavan/SDSRH/blob/b2abb86d4edbd729e6f60a8ecf2ab4c7e46ee24b/IDE)

### 11.Functional Programming

Apply functional programming for it's understanding and adding a class
-[Functional Programming](https://github.com/Venkatchavan/SDSRH/blob/5acdd244c7b1416cf94fc53c0b02d4ba1942b46e/functional-programming.md)


## License

This project is licensed under the Venkat Chavan N student at SRH BERLIN UNIVERSITY OF APPLIED SCIENCES.
Subject Specialization: MSc Computer Science | Big Data and Artificial Intelligence 
Contact venkatchavan1999@gmail.com 
