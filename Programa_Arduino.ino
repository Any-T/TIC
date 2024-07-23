int outputpin=9; //pin para PWM
int f;
int x;
int N = 128; //Prescalador

void setup()
  {
    Serial.begin(9600);
    pinMode(outputpin, OUTPUT); 
    TCCR1A=_BV(COM1A1)|_BV(COM1A0)|_BV(WGM11); //Fast PWM
    TCCR1B=_BV(WGM13)|_BV(WGM12)|_BV(CS12); //PWM Phase, frequency correction Mode
  }

void loop()
  {
    
    while(1)
    {
      if(Serial.available()>0) // if there is data to read
      {
        f=Serial.read(); // read data
        ICR1 = (16000000/(2*N*f))-1;
        OCR1A = ICR1/2;
      }
      
      // Read analog input from pin A0
      double sensorValue = analogRead(A0);
      // Map the analog value (0-1023) to a voltage range (0-5V)
      double voltage = sensorValue * (5.0 / 1023.0);

      // Print the voltage value to serial (send to MATLAB)
      Serial.println(voltage);
    }
    
  }
