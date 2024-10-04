#include <WiFi.h>
#include <WebServer.h>

#define RED_LED_PIN 12      // LED for ambulance/firetruck
#define YELLOW_LED_PIN 13   // LED for firetruck
#define BLUE_LED_PIN 14     // LED for traffic

#define LEFT_LED_PIN 25     // LED for left direction
#define RIGHT_LED_PIN 26    // LED for right direction
#define CENTER_LED_PIN 27   // LED for center direction

const char* ssid = "";  // Replace with your Wi-Fi SSID
const char* password = "";  // Replace with your Wi-Fi password

WebServer server(80);  // Create a web server object

void handleClassification() {
  if (server.hasArg("classification") && server.hasArg("direction")) {
    String classification = server.arg("classification");
    String direction = server.arg("direction");
    
    Serial.println("Classification received: " + classification);
    Serial.println("Direction received: " + direction);
    
    server.send(200, "text/plain", "Classification and direction received");

    // Handle classification: control color LEDs
    if (classification == "ambulance") {
      digitalWrite(RED_LED_PIN, HIGH);  // Turn on red LED
      digitalWrite(YELLOW_LED_PIN, LOW);
      digitalWrite(BLUE_LED_PIN, LOW);
    } 
    else if (classification == "firetruck") {
      digitalWrite(RED_LED_PIN, LOW);
      digitalWrite(YELLOW_LED_PIN, HIGH);  // Turn on yellow LED
      digitalWrite(BLUE_LED_PIN, LOW);
    } 
    else if (classification == "traffic") {
      digitalWrite(RED_LED_PIN, LOW);
      digitalWrite(YELLOW_LED_PIN, LOW);
      digitalWrite(BLUE_LED_PIN, HIGH);  // Turn on blue LED
    }

    // Handle direction: control direction LEDs
    if (direction == "left") {
      digitalWrite(LEFT_LED_PIN, HIGH);  // Turn on left LED
      digitalWrite(RIGHT_LED_PIN, LOW);
      digitalWrite(CENTER_LED_PIN, LOW);
    } 
    else if (direction == "right") {
      digitalWrite(LEFT_LED_PIN, LOW);
      digitalWrite(RIGHT_LED_PIN, HIGH);  // Turn on right LED
      digitalWrite(CENTER_LED_PIN, LOW);
    } 
    else if (direction == "center") {
      digitalWrite(LEFT_LED_PIN, LOW);
      digitalWrite(RIGHT_LED_PIN, LOW);
      digitalWrite(CENTER_LED_PIN, HIGH);  // Turn on center LED
    }
  } else {
    Serial.println("Missing classification or direction");
    server.send(400, "text/plain", "Bad request: missing classification or direction");
  }
}

void setup() {
  Serial.begin(115200);  // Start serial communication

  // Set classification LED pins as OUTPUT
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);

  // Set direction LED pins as OUTPUT
  pinMode(LEFT_LED_PIN, OUTPUT);
  pinMode(RIGHT_LED_PIN, OUTPUT);
  pinMode(CENTER_LED_PIN, OUTPUT);

  // Ensure all LEDs are off initially
  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(YELLOW_LED_PIN, LOW);
  digitalWrite(BLUE_LED_PIN, LOW);
  digitalWrite(LEFT_LED_PIN, LOW);
  digitalWrite(RIGHT_LED_PIN, LOW);
  digitalWrite(CENTER_LED_PIN, LOW);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi!");
  Serial.println(WiFi.localIP());  // Print the IP address of the ESP32

  // Set up HTTP route
  server.on("/classify", handleClassification);  // Route to handle classification and direction
  server.begin();  // Start the server
}

void loop() {
  server.handleClient();  // Handle incoming client requests
}
