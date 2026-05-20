#include "TelemetryValidator.h"

bool TelemetryValidator::isValid(const TelemetryRecord& record) const {
    return getIssues(record).empty();
}

bool TelemetryValidator::hasWarning(const TelemetryRecord& record) const {
    return record.getAltitudeFt() > 50000 ||
           record.getAirspeedKnots() > 750 ||
           record.getEngineTempC() > 750 ||
           record.getStatus() == "WARNING";
}

std::vector<std::string> TelemetryValidator::getIssues(const TelemetryRecord& record) const {
    std::vector<std::string> issues;

    if (record.getAltitudeFt() < 0) {
        issues.push_back("Invalid altitude: altitude cannot be negative");
    }

    if (record.getAirspeedKnots() < 0) {
        issues.push_back("Invalid airspeed: airspeed cannot be negative");
    }

    if (record.getHeadingDeg() < 0 || record.getHeadingDeg() > 359) {
        issues.push_back("Invalid heading: heading must be between 0 and 359 degrees");
    }

    if (record.getEngineTempC() < 0) {
        issues.push_back("Invalid engine temperature: temperature cannot be negative");
    }

    std::string status = record.getStatus();

    if (status != "NORMAL" && status != "WARNING" && status != "ERROR") {
        issues.push_back("Invalid status: status must be NORMAL, WARNING, or ERROR");
    }

    return issues;
}