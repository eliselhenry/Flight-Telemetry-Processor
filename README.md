# Flight Telemetry Processor

## Overview

My Flight Telemetry Processor is a C++ command-line application that parses, validates, and reports on simulated aircraft telemetry data. This project was designed to demonstrate object-oriented software development, file processing, validation logic, error handling, and Linux-based command-line execution.

## Features

- Parses aircraft telemetry records from a CSV file
- Validates altitude, airspeed, heading, engine temperature, and status fields
- Detects invalid and warning-level telemetry records
- Calculates summary statistics for valid records
- Generates a text-based telemetry analysis report
- Uses a modular object-oriented design

## Technologies Used

- C++
- Linux/macOS terminal
- Git/GitHub
- Makefile
- Object-Oriented Programming
- File I/O
- CSV Parsing

## Project Structure

```text
flight-telemetry-processor/
├── README.md
├── Makefile
├── data/
│   └── telemetry.csv
├── output/
├── include/
│   ├── TelemetryRecord.h
│   ├── TelemetryParser.h
│   ├── TelemetryValidator.h
│   └── ReportGenerator.h
└── src/
    ├── main.cpp
    ├── TelemetryRecord.cpp
    ├── TelemetryParser.cpp
    ├── TelemetryValidator.cpp
    └── ReportGenerator.cpp
````
## Build Instructions
```text
make
````

## Run Instructions
```text
make run
````

## View the Report
```text
cat output/report.txt
````

## Sample Output
```text
Flight Telemetry Processing Report
==================================

Summary
-------
Total records: 10
Valid records: 7
Invalid records: 3
Warning records: 3
````