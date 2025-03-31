# Control LEDs with Telegram Bot using ESP32

## 📌 Project Overview
This project allows you to control LEDs using an ESP32 board via a Telegram bot. By sending specific commands through Telegram, you can turn LEDs on and off remotely.

## 🚀 Features
- Control up to 4 LEDs via Telegram commands
- Secure communication using WiFi and Telegram API
- Real-time LED state monitoring

## 🛠 Components Required
- **ESP32 Board**
- **4 LEDs**
- **Jumper Wires**
- **Telegram Account**

## 🔧 Setup Instructions
### 1️⃣ Create a Telegram Bot
1. Open Telegram and search for `BotFather`.
2. Start a chat and type `/newbot`.
3. Follow the instructions to set up the bot and get your **API Token**.
4. Save the bot token for later use.

### 2️⃣ Install Required Libraries
Ensure you have the following libraries installed in the Arduino IDE:
- `WiFi.h`
- `WiFiClientSecure.h`
- `UniversalTelegramBot.h`
- `ArduinoJson.h`

### 3️⃣ Update WiFi & Bot Credentials
Modify these lines in the code with your credentials:
```cpp
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
#define BOTtoken "YOUR_TELEGRAM_BOT_TOKEN"
#define CHAT_ID "YOUR_TELEGRAM_CHAT_ID"
```

### 4️⃣ Upload the Code to ESP32
1. Connect ESP32 to your computer.
2. Open the Arduino IDE and select the correct board and port.
3. Upload the provided `.ino` file.
4. Open the Serial Monitor to check for successful WiFi and Telegram connections.

### 5️⃣ Use Telegram Commands
Once the ESP32 is running, send these commands to your bot:
- `/led1_on` - Turns LED 1 ON
- `/led1_off` - Turns LED 1 OFF
- `/led2_on` - Turns LED 2 ON
- `/led2_off` - Turns LED 2 OFF
- `/led3_on` - Turns LED 3 ON
- `/led3_off` - Turns LED 3 OFF
- `/led4_on` - Turns LED 4 ON
- `/led4_off` - Turns LED 4 OFF
- `/state` - Shows the current LED status

## 📷 Demonstration
(Include images or GIFs of the working project here)

## 🔥 Future Improvements
- Adding support for controlling relays and appliances
- Enhancing security with authentication
- Integrating with a mobile app

## 📜 License
This project is open-source under the MIT License.

---

Happy coding! 🎉 If you found this useful, give a ⭐ and share your feedback!

