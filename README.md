# Arduino-Yun-cURL-POST
Very basic example showing how to do POST requests from Arduino YUN

To set this up:

1.  Make sure your Arduino Yun is connected to WiFi or Ethernet with access to the internet. 
2.  Change the `BACKEND_URL` at the top to whatever server your PHP lives on
3.  `process.addParameter("val="+String(_value));` change val to be whatever name your PHP file looks for
