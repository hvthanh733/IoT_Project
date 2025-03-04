// #include "Saver.h"

// std::string Saver::getLogFilePath(const std::string& sensorName) {
//     auto now = std::chrono::system_clock::now();
//     auto now_time = std::chrono::system_clock::to_time_t(now);
    
//     std::stringstream ss;
//     ss << "logs_all/logs_sensors/" << sensorName << "/";
//     ss << std::put_time(std::localtime(&now_time), "%d%m%y-%H%M%S") << ".bin";
    
//     return ss.str();
// }

// void Saver::saveData(const std::string& sensorName, bool check) {
//     if (!check) return;

//     std::string logFile = getLogFilePath(sensorName);

//     // Tạo thư mục nếu chưa có
//     std::filesystem::create_directories("logs_all/logs_sensors/" + sensorName);

//     std::ofstream file(logFile, std::ios::app);
//     if (file.is_open()) {
//         // file << "🔥 Fire detected at " << logFile << std::endl;
//         file.close();
//         std::cout << "Đã ghi log: " << logFile << std::endl;
//     } else {
//         std::cerr << "Lỗi: Không thể mở file log" << std::endl;
//     }
// }
