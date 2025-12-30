# Youtube Reference

#### Node-RED - OpenPLC V4 Modbus Communication Tutorial

<p align="center">

<a href="https://www.youtube.com/watch?v=uHFYutyVTIM" target="\_blank">

<img src="https://img.youtube.com/vi/uHFYutyVTIM/0.jpg" alt="YouTube Video Thumbnail" width="480" />

</a>

</p>

# PLC V3 Runtime Installation (Linux Debian)
### Steps


##### 1. Preparation System
```
sudo apt update && sudo apt upgrade -y
sudo apt install -y git build-essential cmake python3 python3-pip python3-venv
```

##### 2. Clone
```
cd ~
git clone https://github.com/thiagoralves/OpenPLC_v3.git
cd OpenPLC_v3
```

##### 3. Install
```
sudo ./install.sh linux
```

##### 4. Run OpenPLC_v3
```
sudo ./start_openplc.sh
```
Check status:
```
sudo ps aux | grep openplc
```
Example output:
```
root         384  0.0  0.0   4352  1380 ?        Ss   05:01   0:00 /bin/bash /home/yaseralie/OpenPLC_v3/start_openplc.sh
yaseral+   20527  0.0  0.0   3884  1808 pts/0    S+   11:17   0:00 grep openplc
```
##### 5. Open browser
Address IP with port: 8080
Example: http://127.0.0.1:8080/login
Login with default username & password
Username: openplc
Password: openplc

##### Reset Password (forget password)
Open file with terminal or winscp, location in the standalone installer
```
/home/yaseralie/OpenPLC_v3/webserver/openplc.db
```
Open SQLite
```
sqlite3 /home/yaseralie/OpenPLC_v3/webserver/openplc.db
```
```
.tables
```
Output must be:
```
Programs   Settings   Slave_dev  Users
```
View Users table
```
SELECT * FROM Users;
```
Reset password
```
UPDATE Users
SET password='openplc'
WHERE username='openplc';
```
# PLC V3 Runtime Installation (Windows 11)
### Steps
##### 1. Install Ubuntu
Install Ubuntu from Microsoft Store

##### 2. Clone
```
git clone https://github.com/thiagoralves/OpenPLC_v3.git
cd OpenPLC_v3
```
##### 3. Install
```
sudo ./install.sh linux
```
##### 4. Run OpenPLC_v3
```
sudo ./start_openplc.sh
```
##### Kill Running OpenPLC
Check running service:
```
sudo ps aux | grep openplc
```
Check Service:
```
systemctl list-units | grep openplc
```
Stop service
```
sudo systemctl stop openplc
sudo systemctl disable openplc
```

# Desktop Editor
Link:
```
https://autonomylogic.com/download
```
Location address mapping:
```
Format: %<AREA><SIZE><ADDRESS>

| Area  | Def.              | Example           |
| ----- | ----------------- | ----------------- |
| `%I`  | Input             | Sensor            |
| `%Q`  | Output            | Aktuator          |
| `%M`  | Memory (internal) | Flag              |
| `%IW` | Input Word        | Analog Input      |
| `%QW` | Output Word       | Analog Output     |
| `%MW` | Memory Word       | Internal register |
Example:
%IX0.0   → Input bit 0
%IX0.1   → Input bit 1
```

Modbus Mapping
```
| OpenPLC | Modbus           |
| ------- | ---------------- |
| `%IX`   | Discrete Input   |
| `%QX`   | Coil             |
| `%MW`   | Holding Register |
| `%IW`   | Input Register   |
Example:
%QX0.0 → Modbus Coil 0

For Holding Register Mapping:
| OpenPLC | Node-RED (FC3) |
| ------- | -------------- |
| %MW0    | **1024**       |
| %MW1    | **1025**       |
| %MW2    | **1026**       |
| %MW10   | **1034**       |

```
