#ifndef TELEMETRY_PARSER_H
#define TELEMETRY_PARSER_H

#include "TelemetryRecord.h"
#include <string>
#include <vector>

class TelemetryParser {
public:
    std::vector<TelemetryRecord> parseCsvFile(const std::string& filePath);
};

#endif