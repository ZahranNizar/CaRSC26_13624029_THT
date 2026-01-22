#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include <mutex>
#include <filesystem>

using namespace std;

mutex mtx;

std::filesystem::path getSourceDir()
{
    return std::filesystem::path(__FILE__).parent_path();
}

void StreamVideo() {
    while(true) {
        cout << "Receiving video frame..." << endl;
        this_thread::sleep_for(chrono::seconds(2));
    }
}

void TelemetryData() {
    streampos lastpos = 0;

    while(true) {
        {
            lock_guard<mutex> lock(mtx);

            auto base = getSourceDir();
            auto telemetryPath = base / "../../../lampiran/telemetry.txt";
            ifstream telemetryFile(telemetryPath);

            telemetryFile.seekg(lastpos);

            string line;
            
            while (getline(telemetryFile, line)) {
                cout << line << endl;
                this_thread::sleep_for(chrono::seconds(3));
            }
            lastpos = telemetryFile.tellg();            
        }
    }
}

int main() {
    thread t1(StreamVideo);
    thread t2(TelemetryData);
    
    t1.join();
    t2.join();

    return 0;
}