#include "TelemetryParser.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<TelemetryRecord> TelemetryParser::parseCsvFile(const std::string& filePath) {
    std::vector<TelemetryRecord> records;
    std::ifstream inputFile(filePath);

    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open input file: " << filePath << std::endl;
        return records;
    }

    std::string line;

    // Skip CSV header.
    std::getline(inputFile, line);

    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string timestamp;
        std::string aircraftId;
        std::string altitude;
        std::string airspeed;
        std::string heading;
        std::string engineTemp;
        std::string status;

        std::getline(ss, timestamp, ',');
        std::getline(ss, aircraftId, ',');
        std::getline(ss, altitude, ',');
        std::getline(ss, airspeed, ',');
        std::getline(ss, heading, ',');
        std::getline(ss, engineTemp, ',');
        std::getline(ss, status, ',');

        try {
            TelemetryRecord record(
                timestamp,
                aircraftId,
                std::stoi(altitude),
                std::stoi(airspeed),
                std::stoi(heading),
                std::stoi(engineTemp),
                status
            );

            records.push_back(record);
        } catch (...) {
            std::cerr << "Warning: Skipping malformed row: " << line << std::endl;
        }
    }

    inputFile.close();
    return records;
}