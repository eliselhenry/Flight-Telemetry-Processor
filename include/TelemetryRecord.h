#ifndef TELEMETRY_RECORD_H
#define TELEMETRY_RECORD_H

#include <string>

class TelemetryRecord {
private:
    std::string timestamp;
    std::string aircraftId;
    int altitudeFt;
    int airspeedKnots;
    int headingDeg;
    int engineTempC;
    std::string status;

public:
    TelemetryRecord();

    TelemetryRecord(
        const std::string& timestamp,
        const std::string& aircraftId,
        int altitudeFt,
        int airspeedKnots,
        int headingDeg,
        int engineTempC,
        const std::string& status
    );

    std::string getTimestamp() const;
    std::string getAircraftId() const;
    int getAltitudeFt() const;
    int getAirspeedKnots() const;
    int getHeadingDeg() const;
    int getEngineTempC() const;
    std::string getStatus() const;
};

#endif