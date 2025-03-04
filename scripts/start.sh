#!/bin/bash
mkdir -p /home/thanh/IoT_Project/build/logs_run
touch "$LOG_FILE"

LOG_FILE="/home/thanh/IoT_Project/build/logs_run/runtime_logs.log"

cd /home/thanh/IoT_Project/build

# Build project
cmake .. >> "$LOG_FILE" 2>&1
make -j$(nproc) >> "$LOG_FILE" 2>&1

# Kiểm tra nếu build thành công
if [ $? -eq 0 ]; then
    echo "$(date) - Đã chạy dự án" >> "$LOG_FILE"
else
    echo "$(date) - Build thất bại" >> "$LOG_FILE"
    exit 1
fi

# Chạy chương trình sau khi build
./src/raspberry >> "$LOG_FILE" 2>&1 &  # Chạy Raspberry Pi app
./backend/backend >> "$LOG_FILE" 2>&1 &  # Chạy Backend server

exit 0
