#include <Arduino.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>
#include <ArduinoJson.h>
#include <IRremote.h>
#include "security.h"
#include "IRCodes.h"


// Web-server
String request;
DynamicJsonDocument doc(200);
AsyncWebServer server(80);

// IR Remote 
IRsend IrSender;
bool IRpending = false;
unsigned long IRcmd = 0x0;
unsigned char IRlen = 0x0;

void debugInit()
{
  // Just to know which program is running on my Arduino
  Serial.begin(115200);
  Serial.println("-------------------------------------------------------");
  Serial.println(F("START " __FILE__ " from " __DATE__));
  Serial.print(F("Ready to send IR signals at pin "));
  Serial.println(IR_SEND_PIN);
  Serial.println("-------------------------------------------------------");
}

void connectToWiFi()
{
  Serial.printf("Connecting to WiFi %s\n", ssid);

  // Configure WiFi and wait for connection
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  // Print our IP and MAC address on serial port
  Serial.println(WiFi.localIP());
  Serial.println(WiFi.macAddress());
}

void onRequest(AsyncWebServerRequest *request) {
    // dummy callback function for handling params, etc.
}

void onFileUpload(AsyncWebServerRequest *request, const String& filename, size_t index, uint8_t *data, size_t len, bool final)
{
    // dummy callback function signature, not in used in our code
}

// This is the main function that will receive request from the webpage when button is pressed
// and then based on the data that is sent, decide what should be done
void onBody(AsyncWebServerRequest *request, uint8_t *data, size_t len, size_t index, size_t total)
{
  DeserializationError error = deserializeJson(doc, (char*)data);

  if (!error) {
    const char* command = doc["cmd"];
    Serial.printf("command=%s, parsed=", command);

    // Check which button was pressed
    if( strncmp(command,"pwr",3) == 0 )
    {
      //IrSender.sendSAMSUNG(RemoteCodes.btnOnOff, RemoteCodes.codeLen);
      IRcmd = RemoteCodes.btnOnOff;
      IRlen = 32;
      IRpending = true;
      Serial.println("OnOff");
    }
    else if(  strncmp(command,"up",2) == 0  )
    {
      //IrSender.sendSAMSUNG(RemoteCodes.btnUp, RemoteCodes.codeLen);
      IRcmd = RemoteCodes.btnUp;
      IRlen = 32;
      IRpending = true;
      Serial.println("up");
    }

    else if(  strncmp(command,"left",4) == 0  )
    {
      //IrSender.sendSAMSUNG(RemoteCodes.btnLeft, RemoteCodes.codeLen);
      IRcmd = RemoteCodes.btnLeft;
      IRlen = 32;
      IRpending = true;
      Serial.println("left");
    }

    else if(  strncmp(command,"ok",2) == 0  )
    {
      //IrSender.sendSAMSUNG(RemoteCodes.btnOK, RemoteCodes.codeLen);
      IRcmd = RemoteCodes.btnOK;
      IRlen = 32;
      IRpending = true;
      Serial.println("ok");
    }

    else if(  strncmp(command,"right",5) == 0  )
    {
      //IrSender.sendSAMSUNG(RemoteCodes.btnRight, RemoteCodes.codeLen);
      IRcmd = RemoteCodes.btnRight;
      IRlen = 32;
      IRpending = true;
      Serial.println("right");
    }

    else if(  strncmp(command,"down",4) == 0  )
    {
      //IrSender.sendSAMSUNG(RemoteCodes.btnDown, RemoteCodes.codeLen);
      IRcmd = RemoteCodes.btnDown;
      IRlen = 32;
      IRpending = true;
      Serial.println("down");
    }

    else if(  strncmp(command,"back",4) == 0  )
    {
      //IrSender.sendSAMSUNG(RemoteCodes.btnReturn, RemoteCodes.codeLen);
      IRcmd = RemoteCodes.btnReturn;
      IRlen = 32;
      IRpending = true;
      Serial.println("back");
    }

    else if(  strncmp(command,"home",4) == 0  )
    {
      //IrSender.sendSAMSUNG(RemoteCodes.btnHome, RemoteCodes.codeLen);
      IRcmd = RemoteCodes.btnHome;
      IRlen = 32;
      IRpending = true;
      Serial.println("home");
    }

    else if(  strncmp(command,"play",4) == 0  )
    {
      //IrSender.sendSAMSUNG(RemoteCodes.btnPlayPause, RemoteCodes.codeLen);
      IRcmd = RemoteCodes.btnPlayPause;
      IRlen = 32;
      IRpending = true;
      Serial.println("play");
    }

    else if(  strncmp(command,"volup",5) == 0  )
    {
      //IrSender.sendSAMSUNG(RemoteCodes.btnVolUp, RemoteCodes.codeLen);
      IRcmd = RemoteCodes.btnVolUp;
      IRlen = 32;
      IRpending = true;
      Serial.println("volume-up");
    }

    else if(  strncmp(command,"chup",4) == 0  )
    {
      //IrSender.sendSAMSUNG(RemoteCodes.btnChUp, RemoteCodes.codeLen);
      IRcmd = RemoteCodes.btnChUp;
      IRlen = 32;
      IRpending = true;
      Serial.println("channel-up");
    }

    else if(  strncmp(command,"volmute",7) == 0  )
    {
      //IrSender.sendSAMSUNG(RemoteCodes.btnVolEnter, RemoteCodes.codeLen);
      IRcmd = RemoteCodes.btnVolEnter;
      IRlen = 32;
      IRpending = true;
      Serial.println("volume-mute");
    }

    else if(  strncmp(command,"chmiddle",8) == 0  )
    {
      //IrSender.sendSAMSUNG(RemoteCodes.btnChEnter, RemoteCodes.codeLen);
      IRcmd = RemoteCodes.btnChEnter;
      IRlen = 32;
      IRpending = true;
      Serial.println("channel-return");
    }

    else if(  strncmp(command,"volminus",8) == 0  )
    {
      //IrSender.sendSAMSUNG(RemoteCodes.btnVolDown, RemoteCodes.codeLen);
      IRcmd = RemoteCodes.btnVolDown;
      IRlen = 32;
      IRpending = true;
      Serial.println("volume-minus");
    }

    else if(  strncmp(command,"chminus",7) == 0  )
    {
      //IrSender.sendSAMSUNG(RemoteCodes.btnChDown, RemoteCodes.codeLen);
      IRcmd = RemoteCodes.btnChDown;
      IRlen = 32;
      IRpending = true;
      Serial.println("channel-minus");
    }
    else
    {
      Serial.println("Don't recognize cmd");
    }

    // Return HTTP 200 code (success) to the client
    request->send(200, "text/plain", "Ok");
  }
}

void setup() 
{
  debugInit();      // Init serial and other debug features
  connectToWiFi();  // Connect to WiFi

  
  // Initialize SPIFFS (SPI Flash File System)
  SPIFFS.begin(true);

  // serving static content for GET requests on '/' from SPIFFS directory '/'
  server.serveStatic("/", SPIFFS, "/")
        .setDefaultFile("index.html")
        .setCacheControl("max-age=86400");

  // Which functions to use for processing the /api requests
  server.on("/api", HTTP_POST, onRequest, onFileUpload, onBody);

  // What to do when page does not exist
  server.onNotFound([](AsyncWebServerRequest *request){
      request->send(404, "text/plain", "Page Not Found");
  });

  // Start the server
  server.begin();

  
}

void loop()
{
  // If we are waiting to send IR code
  // send it and clear the flag.
  // Sending from the main loop is recommended instead from an interrupt (onBody function),
  // although I tested both of them and they both worked fine.
  if(IRpending)
  {
    IrSender.sendSAMSUNG(IRcmd, IRlen);
    Serial.print("0x");
    Serial.println(IRcmd, HEX);
    IRcmd = 0;
    IRlen = 0;
    IRpending = false;
    delay(300);
  }
}
