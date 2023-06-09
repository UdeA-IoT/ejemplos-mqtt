/*
URL codigo: https://github.com/luisllamasbinaburo/ESP32-Examples/blob/main/35_Mqtt/ESP32_Utils.hpp
*/

void ConnectWiFi_STA(bool useStaticIP = false) {
   Serial.println("");
   WiFi.mode(WIFI_STA);
   WiFi.begin(ssid, password);
   if(useStaticIP) WiFi.config(ip, gateway, subnet);
   while (WiFi.status() != WL_CONNECTED) { 
     delay(100);  
     Serial.print('.'); 
   }
 
   Serial.println("");
   Serial.print("Starting STA:\t");
   Serial.println(ssid);
   Serial.print("IP address:\t");
   Serial.println(WiFi.localIP());
}

void ConnectWiFi_AP(bool useStaticIP = false) { 
   Serial.println("");
   WiFi.mode(WIFI_AP);

   while(!WiFi.softAP(ssid, password)) {
     Serial.println(".");
     delay(100);
   }
   
   if(useStaticIP) {
    WiFi.softAPConfig(ip, gateway, subnet);
   }

   Serial.println("");
   Serial.print("Starting AP:\t");
   Serial.println(ssid);
   Serial.print("IP address:\t");
   Serial.println(WiFi.softAPIP());
}
