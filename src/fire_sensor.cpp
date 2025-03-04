#include <wiringPi.h>
#include <mosquitto.h>
#include <hiredis/hiredis.h>
#include <iostream>
#include <unistd.h>
#include <ctime>
#include "fire_sensor.h"
#include <sys/stat.h>  // Thư viện để tạo thư mục

#define FIRE_SENSOR_PIN 14
#define MQTT_BROKER "localhost"
#define MQTT_PORT 1883
#define MQTT_TOPIC "iot/fire"
#define REDIS_HOST "localhost"
#define REDIS_PORT 6379

// void detectFire() {
//     pinMode(FIRE_SENSOR_PIN, INPUT);

//     // Khởi tạo MQTT
//     mosquitto_lib_init();
//     mosquitto *mqttClient = mosquitto_new(NULL, true, NULL);
//     if (mosquitto_connect(mqttClient, MQTT_BROKER, MQTT_PORT, 60) != MOSQ_ERR_SUCCESS) {
//         std::cerr << "⚠️ Lỗi kết nối MQTT!" << std::endl;
//         return;
//     }

//     // Kết nối Redis
//     redisContext *redis = redisConnect(REDIS_HOST, REDIS_PORT);
//     if (redis == NULL || redis->err) {
//         std::cerr << "⚠️ Không thể kết nối Redis!" << std::endl;
//         return;
//     }

//     // Tạo thư mục logs nếu chưa có
//     std::string logDir = "build/logs_sensors/fire";

//     while (true) {
//         std::string message;
//         if (digitalRead(FIRE_SENSOR_PIN) == LOW) {
//             message = "🔥 Phát hiện lửa!";
//         } else {
//             message = "✅ Không có lửa";
//         }

//         // Gửi dữ liệu qua MQTT
//         mosquitto_publish(mqttClient, NULL, MQTT_TOPIC, message.size(), message.c_str(), 0, false);
//         std::cout << "📡 Gửi MQTT: " << message << std::endl;

//         if (digitalRead(FIRE_SENSOR_PIN) == LOW) {  // Chỉ lưu nếu có cháy
//             // Lưu vào Redis
//             time_t now = time(0);
//             char timestamp[30];
//             strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&now));

//             redisReply *reply = (redisReply *)redisCommand(redis, "LPUSH fire_logs \"%s - %s\"", timestamp, message.c_str());
//             freeReplyObject(reply);

//             std::cout << "💾 Lưu Redis: " << message << " (" << timestamp << ")" << std::endl;

//             // Lưu log vào file trong thư mục `/build/logs_sensors/fire/`
//             std::string logFile = logDir + "/fire_log.txt";
//             std::ofstream log(logFile, std::ios::app);
//             if (log.is_open()) {
//                 log << timestamp << " - " << message << std::endl;
//                 log.close();
//             } else {
//                 std::cerr << "❌ Không thể ghi file log!" << std::endl;
//             }
//         }

//         sleep(1);
//     }

//     // Dọn dẹp
//     mosquitto_destroy(mqttClient);
//     mosquitto_lib_cleanup();
//     redisFree(redis);
// }
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <iostream>
#include <cstring>
#include <fstream>

void createDirectory(const std::string &path) {
    struct stat st;
    if (stat(path.c_str(), &st) == 0) {  
        if (S_ISDIR(st.st_mode)) {
            return;  // Thư mục đã tồn tại
        } else {
            std::cerr << "⚠️ " << path << " tồn tại nhưng không phải thư mục!" << std::endl;
            return;
        }
    }

    // Chỉ tạo thư mục nếu nó chưa có
    if (mkdir(path.c_str(), 0777) != 0) {
        std::cerr << "❌ Lỗi khi tạo thư mục: " << path << " (Lỗi: " << strerror(errno) << ")" << std::endl;
    } else {
        std::cout << "📁 Đã tạo thư mục: " << path << std::endl;
    }
}

void detectFire() {
    std::string dirPath = "logs_sensors/fire";  // Chạy trong build, không cần "build/"
    std::string filePath = dirPath + "/fire.log";  

    // Chỉ tạo thư mục "fire" trong "logs_sensors"
    createDirectory(dirPath);

    // Tạo file fire.log
    std::ofstream outFile(filePath);
    if (outFile) {
        outFile << "🔥 Fire detected log\n";
        outFile.close();
        std::cout << "📄 Đã tạo file: " << filePath << std::endl;
    } else {
        std::cerr << "❌ Lỗi khi tạo file: " << filePath << std::endl;
    }
}
