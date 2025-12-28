
Dynamixel Dxl(3);
#define boy 400 // 20 Saniye Öğrenme
long v1[boy], v2[boy], v3[boy], v4[boy], v5[boy], v6[boy], sayac, i, j, k, l, m, n;

void setup() 
{
  pinMode(16, INPUT_PULLDOWN);
  pinMode(BOARD_LED_PIN, OUTPUT);
  Dxl.begin(3);

  Dxl.jointMode(1);
  Dxl.jointMode(2);
  Dxl.jointMode(3);
  Dxl.jointMode(4);
  Dxl.jointMode(5);
  Dxl.jointMode(6);

  Dxl.jointMode(7);
  Dxl.jointMode(14);
  Dxl.jointMode(17);
  Dxl.jointMode(16);
  Dxl.jointMode(15);
  Dxl.jointMode(13);

  Dxl.maxTorque(7, 0);
  Dxl.maxTorque(14, 0);
  Dxl.maxTorque(17, 0);
  Dxl.maxTorque(16, 0);
  Dxl.maxTorque(15, 0);
}

void loop() 
{
  if (digitalRead(16) == HIGH) // Button for Learning 
  {
    digitalWrite(BOARD_LED_PIN, LOW); // LED on
    delay(500);
    
    while (digitalRead(16) == LOW && i < boy)  // 20 Saniye Öğrenme
    {
      v1[i++] = Dxl.getPosition(7);
      v2[j++] = Dxl.getPosition(14);
      v3[k++] = Dxl.getPosition(17);
      v4[l++] = Dxl.getPosition(16);
      v5[m++] = Dxl.getPosition(15);
      v6[n++] = Dxl.getPosition(13);
      delay(50);
    }
    digitalWrite(BOARD_LED_PIN, HIGH); // LED Off
    sayac = i;
    delay(500);
  }

  else if (digitalRead(17) == HIGH) // Button for Repeating 
  {
    i = 0, j = 0, k = 0, l = 0, m = 0, n = 0;
    digitalWrite(BOARD_LED_PIN, LOW); // LED on
    delay(500);

    while (digitalRead(17) == LOW && i < sayac)
    {
      Dxl.goalPosition(1, v1[i++]);
      Dxl.goalPosition(2, v2[j++]);
      Dxl.goalPosition(5, v3[k++]);
      Dxl.goalPosition(3, v4[l++]);
      Dxl.goalPosition(4, v5[m++]);
      Dxl.goalPosition(6, v6[n++]);
      delay(50);
    }

    digitalWrite(BOARD_LED_PIN, HIGH); // LED Off
    i = 0, j = 0, k = 0, l = 0, m = 0, n = 0;
    delay(500);
  }
}
