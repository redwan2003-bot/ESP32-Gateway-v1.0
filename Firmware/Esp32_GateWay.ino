/*
 * Project: Redwan-Gateway v1.0 (Day 1)
 * Purpose: Industrial IoT Gateway (W5500 Ethernet + RS485)
 * Author: Redwan Ahmmed (EasyEDA Campus Ambassador)
 */

#include <SPI.h>
#include <Ethernet.h>

// --- PIN DEFINITIONS (Derived from your Schematic) ---
#define W5500_CS     10   // Ethernet Chip Select
#define RS485_TX     17   // UART TX
#define RS485_RX     18   // UART RX
#define RS485_DE_RE  4    // Data Enable / Receive Enable Pin
#define STATUS_LED   48   // Built-in LED for ESP32-S3

// --- NETWORKING CONFIG ---
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

// --- RTOS TASK HANDLES ---
TaskHandle_t EthernetTask;
TaskHandle_t RS485Task;

void setup() {
    Serial.begin(115200);
    pinMode(STATUS_LED, OUTPUT);
    pinMode(RS485_DE_RE, OUTPUT);
    digitalWrite(RS485_DE_RE, LOW); // Set to Receive mode initially

    // Initialize W5500 Ethernet
    Ethernet.init(W5500_CS);
    
    // START RTOS TASKS
    xTaskCreatePinnedToCore(HandleEthernet, "EthTask", 4096, NULL, 1, &EthernetTask, 1);
    xTaskCreatePinnedToCore(HandleRS485, "SerialTask", 4096, NULL, 2, &RS485Task, 0);
}

void loop() {
    // Empty: Task management is handled by FreeRTOS
}

// --- TASK 1: ETHERNET MANAGEMENT ---
void HandleEthernet(void * pvParameters) {
    Serial.println("[System] Starting Ethernet Service...");
    if (Ethernet.begin(mac) == 0) {
        Serial.println("[Error] Failed to configure Ethernet via DHCP");
    }
    
    for (;;) {
        auto link = Ethernet.linkStatus();
        if (link == LinkOFF) {
            digitalWrite(STATUS_LED, LOW); // Signal Error
        } else {
            // Placeholder for Day 3: Secure MQTT Client logic
            digitalWrite(STATUS_LED, HIGH); 
        }
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

// --- TASK 2: RS485 / MODBUS ENGINE ---
void HandleRS485(void * pvParameters) {
    Serial1.begin(9600, SERIAL_8N1, RS485_RX, RS485_TX);
    Serial.println("[System] RS485 Industrial Bus Online...");

    for (;;) {
        // Example: Sending a Modbus Query or Data Packet
        digitalWrite(RS485_DE_RE, HIGH); // Switch to Transmit
        Serial1.print("GET_DATA_CMD"); 
        Serial1.flush();
        digitalWrite(RS485_DE_RE, LOW);  // Switch back to Receive
        
        // Listen for Response
        unsigned long start = millis();
        while (millis() - start < 100) { // 100ms Timeout
            if (Serial1.available()) {
                String response = Serial1.readString();
                Serial.printf("[RS485] Data Received: %s\n", response.c_str());
                break;
            }
        }
        vTaskDelay(pdMS_TO_TICKS(5000)); // Query every 5 seconds
    }
}