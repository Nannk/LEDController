const char index_html[] PROGMEM = R"=====(
<!DOCTYPE HTML><html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1" charset="UTF-8">
  <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.7.2/css/all.css" integrity="sha384-fnmOCqbTlWIlj8LyTjo7mOUStjsKC4pOpQbqyi7RrhN7udi9RwhKkMHpvLbHG9Sr" crossorigin="anonymous">
  <style>
    html 
    {
     font-family: Arial;
     display: inline-block;
     margin-left: 10px;
     text-align: left;
    }

    h2 
    { 
        font-size: 2.0rem; 
    }
  </style>
</head>
<body>
  <h2>ESP8266 DHT Server</h2>
  <a href="sldline" target="myiframe">Solid Line</a><br><br>
  <a href="movline" target="myiframe">Moving Line</a><br><br>
  <a href="epilepsy" target="myiframe">Epilepsy Mode</a><br><br>
  <a href="sunmode" target="myiframe">Sunrise Mode</a><br><br><br>

  <a href="flash" target="myiframe">Flashmode</a><br><br>
  <a href="off" target="myiframe">Lights OFF</a><br><br>

</body>
</html>
)=====";