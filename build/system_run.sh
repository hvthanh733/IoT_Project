# đổi file iot_build_run.service hoặc start.sh thì reload
sudo systemctl daemon-reload

# Sửa start.sh thì phải restart
sudo systemctl restart iot_build_run.service
