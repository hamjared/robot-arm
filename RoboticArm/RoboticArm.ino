/*
 Name:		RoboticArm.ino
 Created:	3/6/2022 11:07:14 AM
 Author:	Jared
*/



#include "RobotArmApi.h"
#include "esp32-hal-ledc.h"
#include "ServoWrapper.h"
#include "Stepper.h"
#include <Wifi.h>
#include <WebServer.h>
#include "Config.h"

ServoWrapper servo(15);
Stepper stepper(22, 23, 1.8);

int servoAngle = 0;

//Webserver items
WebServer server(80);



void setup() {
	Serial.begin(115200);
	Serial.println("Init the servo");
	servo.init();

	stepper.init();

	stepper.rotate(12000, Stepper::Direction::CCW);

	xTaskCreate(webServer, "Task2", 30000, NULL, 1, NULL);

}

// the loop function runs over and over again until power down or reset
void loop() {
	
	stepper.update();

}


void webServerSetup() {
	WiFi.mode(WIFI_STA); // set ESP32 to connect to a network
	WiFi.setHostname("RobotArm");
	WiFi.begin(ssid, password);
	Serial.print("Connecting to WiFi ..");
	while (WiFi.status() != WL_CONNECTED) {
		Serial.print('.');
		delay(1000);
	}
	Serial.println(WiFi.localIP());
}

void webServer(void* stuff) {
	webServerSetup();
   
    String header;
    

    unsigned long currentTime = millis();
    unsigned long previousTime = 0;
    const long timeoutTime = 2000;


    server.on("/status", getStatus);
	server.on("/setServoAngle", HTTP_POST, setServo1Angle);
    server.begin();
    Serial.println("Web server setup");

	while (true) {
		server.handleClient();
	}

}

