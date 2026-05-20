#ifndef REPORT_GENERATOR_H
#define REPORT_GENERATOR_H

#include "TelemetryRecord.h"
#include "TelemetryValidator.h"
#include <string>
#include <vector>

class ReportGenerator {
public:
    void generateReport(
        const std::vector<TelemetryRecord>& records,
        const TelemetryValidator& validator,
        const std::string& outputPath
    );
};

#endif