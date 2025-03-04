// #include "BusinessHandler.h"
// #include "Saver.h"

// BusinessHandler::BusinessHandler() {
//     wiringPiSetup();
//     pinMode(IR_SENSOR_PIN, INPUT);
// }

// void BusinessHandler::run() {
//     Saver logSaver;

//     while (true) {
//         int sensorValue = digitalRead(IR_SENSOR_PIN);
//         if (sensorValue == LOW) {  // Có lửa
//             std::cout << "🔥 Có lửa!" << std::endl;
//             logSaver.saveData("fire", true);
//         }
//         delay(500);
//     }
// }
