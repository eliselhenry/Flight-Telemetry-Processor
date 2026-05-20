#include "TelemetryRecord.h"

TelemetryRecord::TelemetryRecord()
    : timestamp(""),
      aircraftId(""),
      altitudeFt(0),
      airspeedKnots(0),
      headingDeg(0),
      engineTempC(0),
      status("") {}

TelemetryRecord::TelemetryRecord(
    const std::string& timestamp,
    const std::string& aircraftId,
    int altitudeFt,
    int airspeedKnots,
    int headingDeg,
    int engineTempC,
    const std::string& status
)
    : timestamp(timestamp),
      aircraftId(aircraftId),
      altitudeFt(altitudeFt),
      airspeedKnots(airspeedKnots),
      headingDeg(headingDeg),
      engineTempC(engineTempC),
      status(status) {}

std::string TelemetryRecord::getTimestamp() const {
    return timestamp;
}

std::string TelemetryRecord::getAircraftId() const {
    return aircraftId;
}

int TelemetryRecord::getAltitudeFt() const {
    return altitudeFt;
}

int TelemetryRecord::getAirspeedKnots() const {
    return airspeedKnots;
}

int TelemetryRecord::getHeadingDeg() const {
    return headingDeg;
}

int TelemetryRecord::getEngineTempC() const {
    return engineTempC;
}

std::string TelemetryRecord::getStatus() const {
    return status;
}