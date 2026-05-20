CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

TARGET = telemetry_processor

SRC = src/main.cpp \
      src/TelemetryRecord.cpp \
      src/TelemetryParser.cpp \
      src/TelemetryValidator.cpp \
      src/ReportGenerator.cpp

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)
	rm -f output/*.txt