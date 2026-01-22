#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

struct TelemetryData {
    float altitude;
    float speed;
    float battery;
};


// Abstract base class for telemetry processors

class TelemetryProcessor {
public:
    virtual ~TelemetryProcessor() = default;
    virtual void process(const TelemetryData& data) = 0;
    virtual void report() = 0;
};

// Processor for various telemetry data types

class AltitudeProcessor : public TelemetryProcessor {
    float total_altitude = 0.0f;
    int count = 0;

public:

    void process(const TelemetryData& data) override {
        total_altitude += data.altitude;
        count++;
        if (data.altitude > 100.0f) {
            std::cout << "High altitude alert: " << data.altitude << "m" << std::endl;
        }
    }

    void report() override {
        float avg_altitude = (count > 0) ? total_altitude / count : 0.0f;
        std::cout << "avg altitude: " << avg_altitude << "m" << std::endl;
    }

};

class SpeedProcessor : public TelemetryProcessor {
    float total_speed = 0.0f;
    int count = 0;

public:
    void process(const TelemetryData& data) override {
        total_speed += data.speed;
        count++;
    }

    void report() override {
        float avg_speed = (count > 0) ? total_speed / count : 0.0f;
        std::cout << "avg speed: " << avg_speed << "m/s" << std::endl;
    }
};

class BatteryProcessor : public TelemetryProcessor {
    float total_battery = 0.0f;
    int count = 0;

public:
    void process(const TelemetryData& data) override {
        total_battery += data.battery;
        count++;
        if (data.battery < 20.0f) {
            std::cout << "Low battery alert: " << data.battery << "%" << std::endl;
        }
    }

    void report() override {
        float avg_battery = (count > 0) ? total_battery / count : 0.0f;
        std::cout << "avg battery: " << avg_battery << "%" << std::endl;
    }
};

// Strategy pattern to manage multiple processors

class TelemetryManager {
    std::vector<TelemetryProcessor*> processors;
public:
    void add_processor(TelemetryProcessor* processor) {
        processors.push_back(processor);
    }
    void process_data(const TelemetryData& data) {
        for (auto processor : processors) {
            processor->process(data);
        }
    }
    void report() {
        for (auto processor : processors) { 
            processor->report();
        }
    }
};

// Class to read telemetry data from file

class TelemetryRead {
public:
    void read(const std::string& filename, TelemetryProcessor& processor) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "error membuka " << filename << std::endl;
            return;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            TelemetryData data;
            if (iss >> data.altitude >> data.speed >> data.battery) {
                processor.process(data);
            }
        }
        file.close();
};

// Main function to demonstrate the telemetry processing

int main() {
    TelemetryManager manager;
    AltitudeProcessor altitude_processor;
    SpeedProcessor speed_processor;
    BatteryProcessor battery_processor;
    
    manager.add_processor(&altitude_processor);
    manager.add_processor(&speed_processor);
    manager.add_processor(&battery_processor);
    
    TelemetryRead reader;
    reader.read("lampiran/telemetry_data.txt", manager);

    manager.report();
    return 0;
}