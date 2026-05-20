#include "ReportGenerator.h"
#include <fstream>
#include <iomanip>
#include <iostream>

void ReportGenerator::generateReport(
    const std::vector<TelemetryRecord>& records,
    const TelemetryValidator& validator,
    const std::string& outputPath
) {
    std::ofstream outputFile(outputPath);

    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not create report file: " << outputPath << std::endl;
        return;
    }

    int totalRecords = records.size();
    int validRecords = 0;
    int invalidRecords = 0;
    int warningRecords = 0;

    double totalAltitude = 0;
    double totalAirspeed = 0;
    double totalEngineTemp = 0;

    for (const TelemetryRecord& record : records) {
        if (validator.isValid(record)) {
            validRecords++;
            totalAltitude += record.getAltitudeFt();
            totalAirspeed += record.getAirspeedKnots();
            totalEngineTemp += record.getEngineTempC();

            if (validator.hasWarning(record)) {
                warningRecords++;
            }
        } else {
            invalidRecords++;
        }
    }

    outputFile << "Flight Telemetry Processing Report\n";
    outputFile << "==================================\n\n";

    outputFile << "Summary\n";
    outputFile << "-------\n";
    outputFile << "Total records: " << totalRecords << "\n";
    outputFile << "Valid records: " << validRecords << "\n";
    outputFile << "Invalid records: " << invalidRecords << "\n";
    outputFile << "Warning records: " << warningRecords << "\n\n";

    if (validRecords > 0) {
        outputFile << std::fixed << std::setprecision(2);
        outputFile << "Averages for Valid Records\n";
        outputFile << "--------------------------\n";
        outputFile << "Average altitude: " << totalAltitude / validRecords << " ft\n";
        outputFile << "Average airspeed: " << totalAirspeed / validRecords << " knots\n";
        outputFile << "Average engine temperature: " << totalEngineTemp / validRecords << " C\n\n";
    }

    outputFile << "Invalid Record Details\n";
    outputFile << "----------------------\n";

    for (const TelemetryRecord& record : records) {
        std::vector<std::string> issues = validator.getIssues(record);

        if (!issues.empty()) {
            outputFile << "Timestamp: " << record.getTimestamp() << "\n";
            outputFile << "Aircraft ID: " << record.getAircraftId() << "\n";

            for (const std::string& issue : issues) {
                outputFile << "- " << issue << "\n";
            }

            outputFile << "\n";
        }
    }

    outputFile.close();

    std::cout << "Report generated successfully: " << outputPath << std::endl;
}