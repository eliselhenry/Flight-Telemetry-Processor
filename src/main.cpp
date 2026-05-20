#include "TelemetryParser.h"
#include "TelemetryValidator.h"
#include "ReportGenerator.h"
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
    std::string inputPath = "data/telemetry.csv";
    std::string outputPath = "output/report.txt";

    if (argc == 3) {
        inputPath = argv[1];
        outputPath = argv[2];
    } else if (argc != 1) {
        std::cerr << "Usage: ./telemetry_processor [input_csv output_report]" << std::endl;
        return 1;
    }

    TelemetryParser parser;
    TelemetryValidator validator;
    ReportGenerator reportGenerator;

    std::vector<TelemetryRecord> records = parser.parseCsvFile(inputPath);

    if (records.empty()) {
        std::cerr << "No telemetry records were processed." << std::endl;
        return 1;
    }

    reportGenerator.generateReport(records, validator, outputPath);

    return 0;
}