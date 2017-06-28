// Fading LED, Arduino by MohamadKh75
// 2017-06-28
// ********************


int LED = 9;    //connected to digital PWM pin 9
int brightness = 0;   //brightness of LED
int fade_amount = 15;    //fade amount to apply
bool flag = 1;    //set flag to show current brightness is less than 256

void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  analogWrite(LED, brightness);

  if (flag)
    {
    brightness = brightness + fade_amount;

    if (brightness >= 255)
      flag = false;
    }
    
  else
    {
    brightness = brightness - fade_amount;

    if (brightness <= 0)
      flag = true;
    }


  Serial.print(brightness);
  Serial.println();
  
  delay(50);
}
