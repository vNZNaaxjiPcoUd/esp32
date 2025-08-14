#include <WiFi.h>

// https://sites.google.com/site/arduinochutiyan/esp32_%E5%9F%BA%E7%A4%8E/a12-web%E6%8E%A7%E5%88%B6led?authuser=0

// 設定 Wi-Fi 網路 SSID 與密碼

const char* ssid = "book";

const char* password = "12345678";


// 建立 Web 伺服器，監聽 80 端口

WiFiServer server(80);


// 記錄 LED 狀態

bool redState = false;

bool greenState = false;


void setup() {

    Serial.begin(115200); // 初始化序列埠，設定波特率為 115200

   

    // 設定 ESP32 以 Station 模式連線至 Wi-Fi

    WiFi.mode(WIFI_STA);

    WiFi.begin(ssid, password);

   

    Serial.print("Connecting to WiFi");

    while (WiFi.status() != WL_CONNECTED) {

        delay(500);

        Serial.print(".");

    }

    Serial.println("\nWiFi connected");

    Serial.print("Station IP Address: ");

    Serial.println(WiFi.localIP());

   

    server.begin(); // 啟動 Web 伺服器


    // 設定 GPIO 16 和 GPIO 17 為輸出模式

    pinMode(16, OUTPUT);

    pinMode(17, OUTPUT);

}


void loop() {

    WiFiClient client = server.available(); // 檢查是否有用戶端連線

    if (client) {

        String request = client.readStringUntil('\r'); // 讀取客戶端請求

        client.flush(); // 清空接收緩衝區


        // 根據請求字串控制 LED

        if (request.indexOf("/red/on") != -1) {

            digitalWrite(16, HIGH); // 開啟紅色 LED

            redState = true;

        } else if (request.indexOf("/red/off") != -1) {

            digitalWrite(16, LOW);  // 關閉紅色 LED

            redState = false;

        } else if (request.indexOf("/green/on") != -1) {

            digitalWrite(17, HIGH); // 開啟綠色 LED

            greenState = true;

        } else if (request.indexOf("/green/off") != -1) {

            digitalWrite(17, LOW);  // 關閉綠色 LED

            greenState = false;

        }


        // 回應 HTTP 請求，顯示 HTML5 按鈕介面

        client.print("HTTP/1.1 200 OK\nContent-Type: text/html\n\n");

        client.print("<html><head><style>");

        client.print(".btn { width: 300px; height: 300px; border-radius: 50%; font-size: 20px; border: none; cursor: pointer; text-align: center; line-height: 100px; display: inline-block; margin: 10px; }");

        client.print(".red-on { background-color: red; color: white; }");

        client.print(".red-off { background-color: darkred; color: white; }");

        client.print(".green-on { background-color: green; color: white; }");

        client.print(".green-off { background-color: darkgreen; color: white; }");

        client.print("</style></head><body>");

        client.print("<h1>ESP32 Web Server</h1>");

        client.print("<button class='" + String(redState ? "red-on" : "red-off") + " btn' onclick=\"location.href='/red/" + String(redState ? "off" : "on") + "'\">Red</button>");

        client.print("<button class='" + String(greenState ? "green-on" : "green-off") + " btn' onclick=\"location.href='/green/" + String(greenState ? "off" : "on") + "'\">Green</button>");

        client.print("</body></html>");

       

        client.stop(); // 關閉連線

    }

}


