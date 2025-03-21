import sqlite3

DB_PATH = "../database/data.db"

def get_db_connection():
    """Kết nối đến database SQLite."""
    conn = sqlite3.connect(DB_PATH)
    conn.row_factory = sqlite3.Row  # Trả về kết quả dạng dictionary
    return conn

def insert_sensor_data(temperature, humidity, fire_detected):
    """Thêm dữ liệu cảm biến vào database."""
    conn = get_db_connection()
    cursor = conn.cursor()
    cursor.execute(
        "INSERT INTO sensor_data (temperature, humidity, fire_detected) VALUES (?, ?, ?)",
        (temperature, humidity, fire_detected),
    )
    conn.commit()
    conn.close()

def get_latest_sensor_data():
    """Lấy dữ liệu cảm biến mới nhất."""
    conn = get_db_connection()
    cursor = conn.cursor()
    cursor.execute("SELECT * FROM sensor_data ORDER BY timestamp DESC LIMIT 1")
    data = cursor.fetchone()
    conn.close()
    return dict(data) if data else None
