from database import insert_sensor_data, get_latest_sensor_data

# Thêm dữ liệu vào database
insert_sensor_data(10, 10, 0)

# Lấy dữ liệu mới nhất để kiểm tra
latest_data = get_latest_sensor_data()
print(latest_data)  # In dữ liệu mới nhất ra màn hình
