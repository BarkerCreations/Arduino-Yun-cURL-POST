#include <Bridge.h>

String BACKEND_URL = "http://yoururl.com/yourphp.php";
Process p;

void setup() {
  // put your setup code here, to run once:

  Bridge.begin();
  Serial.begin(9600);

  while (!Serial);
}

void loop() {
  // put your main code here, to run repeatedly:

  /* your sensors or buttons trigger the request */
  if (somethingHappens) {
    doCurl(sensorValue);
  }

  /* Response from the request, if needed */
  while (p.available()>0) {
    char c = p.read();
    Serial.print(c);
  }
}

void doCurl(int _value) {
  Serial.println(_value);

  process.begin("curl");
  process.addParameter("-k"); // allow insecure (not https)
  process.addParameter("-X"); // use POST instead of default GET
  process.addParameter("POST");
  process.addParameter("-H"); // Any headers go after -H
  process.addParameter("Content-Type:application/x-www-form-encoded");

  /* Add data */
  process.addParameter("-d");
  process.addParameter("val="+String(_value));
  process.addParameter(BACKEND_URL);
  
  process.runAsynchronously();
}
