#ifndef TELEMETRY_VALIDATOR_H
#define TELEMETRY_VALIDATOR_H

#include "TelemetryRecord.h"
#include <string>
#include <vector>

class TelemetryValidator {
public:
    bool isValid(const TelemetryRecord& record) const;
    bool hasWarning(const TelemetryRecord& record) const;
    std::vector<std::string> getIssues(const TelemetryRecord& record) const;
};

#endif