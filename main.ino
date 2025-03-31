#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

#define BOTtoken "xxxxx:xxxxxxx"
#define CHAT_ID "xxxxxxxxxx"

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

int botRequestDelay = 1000;
unsigned long lastTimeBotRan;

const int ledPins[] = {25, 26, 27, 14};  // GPIOs for LEDs
bool ledStates[] = {LOW, LOW, LOW, LOW};

void handleNewMessages(int numNewMessages) {
  Serial.println("handleNewMessages");
  Serial.println(String(numNewMessages));

  for (int i = 0; i < numNewMessages; i++) {
    String chat_id = String(bot.messages[i].chat_id);
    if (chat_id != CHAT_ID) {
      bot.sendMessage(chat_id, "Unauthorized user", "");
      continue;
    }

    String text = bot.messages[i].text;
    Serial.println(text);
    String from_name = bot.messages[i].from_name;

    if (text == "/start") {
      String welcome = "Welcome, " + from_name + ".\n";
      welcome += "Use these commands to control LEDs:\n";
      welcome += "/led1_on - Turn LED 1 ON\n";
      welcome += "/led1_off - Turn LED 1 OFF\n";
      welcome += "/led2_on - Turn LED 2 ON\n";
      welcome += "/led2_off - Turn LED 2 OFF\n";
      welcome += "/led3_on - Turn LED 3 ON\n";
      welcome += "/led3_off - Turn LED 3 OFF\n";
      welcome += "/led4_on - Turn LED 4 ON\n";
      welcome += "/led4_off - Turn LED 4 OFF\n";
      welcome += "/state - Get LED states";
      bot.sendMessage(chat_id, welcome, "");
    }

    for (int j = 0; j < 4; j++) {
      if (text == "/led" + String(j + 1) + "_on") {
        ledStates[j] = HIGH;
        digitalWrite(ledPins[j], ledStates[j]);
        bot.sendMessage(chat_id, "LED " + String(j + 1) + " is ON", "");
      }
      if (text == "/led" + String(j + 1) + "_off") {
        ledStates[j] = LOW;
        digitalWrite(ledPins[j], ledStates[j]);
        bot.sendMessage(chat_id, "LED " + String(j + 1) + " is OFF", "");
      }
    }

    if (text == "/state") {
      String stateMsg = "LED states:\n";
      for (int j = 0; j < 4; j++) {
        stateMsg += "LED " + String(j + 1) + ": " + (ledStates[j] ? "ON" : "OFF") + "\n";
      }
      bot.sendMessage(chat_id, stateMsg, "");
    }
  }
}

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], ledStates[i]);
  }

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println(WiFi.localIP());
  client.setCACert(TELEGRAM_CERTIFICATE_ROOT);
}

void loop() {
  if (millis() > lastTimeBotRan + botRequestDelay) {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    while (numNewMessages) {
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }
    lastTimeBotRan = millis();
  }
}
