#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

// put function declarations here:
void checkConnection();
bool getRequest();
void putRequest(bool, float, float);
int sensorRead(int, int);

//The ID and Password from our WiFi network
const char* ssid = "Redmi Note 8";
const char* password = "Limon_Cruiser";

//I/O elements from the board
int LED = 2;
int pump = 3;
int Sensor = 4;
int Sensor2 = 0;

//Variables to use with the program
int fixHumidity = 35;
bool ev1 = false;
bool ev2 = false;
bool ev3 = false;
bool mode = false;
int temperature = 0;
int humidity1 = 0;

int samples = 32;
int value = 0;
float variable = 0;
float variable2 = 0;

//To be used with the PUT request
char jsonOutput[128];

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT); //LED configured as output
  pinMode(pump, OUTPUT); //pump configured as output
  WiFi.begin(ssid, password); //Initialize WiFi connection
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) { //While trying to connect ... will be added
    Serial.print(".");
    delay(500);
  }

  Serial.println("\nConnected to the WiFi network!!"); //If connected the IP will be displayed
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  checkConnection();
  mode = getRequest(); //Retrieve data from Database
  delay(5000);
  //Raw sensors readings of temperature and moisture
  variable = sensorRead(Sensor, samples);
  variable2 = sensorRead(Sensor2, samples);
  //Data conditioning (raw reading to current reading)
  temperature = variable * 50 / 750;
  humidity1 = map(variable2, 4095, 1768, 0, 100);
  //Set a limit of 0 to 100 % of moisture
  if(humidity1 > 100) {
    humidity1 = 100;
  }
  if(humidity1 < 0) {
    humidity1 = 0;
  }
  //Send data to the Database
  putRequest(ev1, humidity1, temperature);
  delay(5000);

//Main program logic
  if(mode){
    //Automatic Mode
    if(humidity1 < fixHumidity) {
      digitalWrite(pump, HIGH);
      ev1 = true;
    }
    else {
    digitalWrite(pump, LOW);
    ev1 = false;
  }
  }
  else { //Manual Mode 
    if(ev1) {
      digitalWrite(pump, HIGH);
    }
    else {
    digitalWrite(pump, LOW);
  }
  }
}

// Wifi Connection function
void checkConnection() {
  if ((WiFi.status() == WL_CONNECTED)) {
    digitalWrite(LED, HIGH); //Once connected the LED will turn on
  }
else {
    digitalWrite(LED, LOW); //If the WiFi connection is not established the LED is off
  }
}
//GET request function
bool getRequest() {
    HTTPClient client; //HTTP Client is used with a get request

    //The url is used to establish a connection with a REST API (Database)
    client.begin("https://garden-21dd2-default-rtdb.firebaseio.com/location/house/actuators.json");
    int httpCode = client.GET();

    if (httpCode == 200){ //If the GET request is successfull all the response is loaded in payload
      String payload = client.getString();
      //Serial.println(payload);

      //The response received a little modifications, space removing and info trimmed and converted into an Array
      char json[100]; 
      payload.replace(" ", "");
      payload.replace("\n", "");
      payload.trim();
      payload.toCharArray(json, 100);

      //Info is deserialized in a document
      StaticJsonDocument<100> doc;
      deserializeJson(doc, json);

      //Search for the desired key and parse it to a variable
      bool EV1 = doc["EV1"];
      bool EV2 = doc["EV2"];
      bool EV3 = doc["EV3"];
      bool Mode = doc["Mode"];

      //Data parsing from local variables to global variables
      ev1 = EV1;
      ev2 = EV2;
      ev3 = EV3;
      mode = Mode;
      client.end();
    }
    else {
      //If the connection with the REST API isn´t established, a message is printed with the error code
      Serial.println("Error on HTTP request"); 
      Serial.println("\nStatus Code: " + String(httpCode));
    }
    return mode;
  }

//PUT request function
void putRequest(bool _ev1, float _moisture1, float _temperature) {
    HTTPClient client;
    //UR//The url is used to establish a connection with a REST API (Database)
    client.begin("https://garden-21dd2-default-rtdb.firebaseio.com/location/house/sensors.json");
    client.addHeader("Content-Type", "application/json");

    const size_t CAPACITY = JSON_OBJECT_SIZE(7); //We will add three fields in the request
    StaticJsonDocument<CAPACITY> doc;

    JsonObject obj = doc.to<JsonObject>();

    obj["EV1"] = _ev1;    //Fields to be added
    obj["EV2"] = false;
    obj["EV3"] = true;
    obj["moisture1"] = _moisture1;
    obj["moisture2"] = 48;
    obj["moisture3"] = 72;
    obj["temperature"] = _temperature;

    serializeJson(doc, jsonOutput);
    //Serial.println(jsonOutput);

    int httpCode = client.PUT(String(jsonOutput)); //PUT request

    if (httpCode == 200){ //If successfull we get a response back with the info we just sent
      String payload = client.getString();
     // Serial.println(payload);

      client.end();
    }
    else {
      //If the connection with the REST API isn´t established, a message is printed with the error code
      Serial.println("Error on HTTP request");
      Serial.println("\nStatus Code: " + String(httpCode));
    }
}

//Function for the Analog Reading of a sensor
int sensorRead(int sensor, int Samples) {
  for (int i=0; i<Samples; i++){
    value += analogRead(sensor);
  }
  value /= 32;
  return value;
}