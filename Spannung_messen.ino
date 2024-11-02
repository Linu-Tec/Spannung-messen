int Sensor = A1; // Der Spannungssensor wird am Pin A1 (Analog "1") angeschlossen.

float Messwert;
float Spannung;

void setup(){
  Serial.begin(9600); //serielle Verbindung starten. Dies ist notwendig um die Ergebnisse später mit dem Begehl "Serial.Println" an den Seriellen Monitor senden zu können.
}

void loop(){
  Messwert=analogRead(Sensor); //Spannungswert am analogen Eingang auslesen
  Spannung= map(Messwert, 0, 1023, 0, 250); //Umwandeln des Sensorwertes mit Hilfe des "map" Befehls. Da der Map-Befehl keine Kommastellen ausgibt, wird hier vorerst mit größeren Zahlen gearbeitet.
  Spannung=Spannung/10; // Das Ergebnis wird nun durch 10 geteilt, um die Anzeige als korrekten Wert mit einer Nachkommastelle ausgeben zu können.
  Serial.println(Spannung, 2); //Endgültigen Spannungswert im seriellen Monitor anzeigen. Die Zahl "2" in der Klammer sorgt dafür, dass das Ergebnis mit zwei Nachkommastellen angezeigt wird. Eine "1" würde hier für eine Nachkommastellen sorgen etc.
  delay(1000); //Eine Sekunde warten, damit im Seriellen Monitor nicht zu viele Daten ankommen.
}
