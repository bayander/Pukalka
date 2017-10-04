int unitID = 1;
int baudRate = 9600;

int Gun_pin = 2;
int Gun_on_delay;
int Gun_off_delay;

void setup()
{
  Serial.begin(baudRate);
  pinMode(Gun_pin, OUTPUT);
  Gun_on_delay  = 0; //[ms]
  Gun_off_delay = 500; //[ms]

}

void loop()
{
  digitalWrite(Gun_pin, LOW);
  delay(Gun_on_delay);
  digitalWrite(Gun_pin, HIGH);
  delay(Gun_off_delay);
  
  String message;
  while (Serial.available())
  {
    delay(3);
    if (Serial.available() > 0)
    {
      char c = Serial.read();
      message += c;
    }
  }
  if (message)
  {
    int ID = message.substring(0, 3).toInt();
    if (ID == unitID && messageCheck(message))
    {
      if (message.substring(3, 6) == "GUN")
      {
        int freq = message.substring(6, 9).toInt();
        int dFac = message.substring(9, 12).toInt();
        Gun_on_delay  = int(1000*0.01*dFac/freq);
        Gun_off_delay = int(1000*0.01*(100 - dFac)/freq);
        setted();

        //Serial.println(Gun_on_delay);
        //Serial.println(Gun_off_delay);
        
        return;
      }
    }
  }
}

void run(String message)
{ 
  int ID = message.substring(0, 3).toInt();
  if (ID == unitID && messageCheck(message))
  {
    if (message.substring(3, 6) == "GUN")
    {
      int freq = message.substring(6, 9).toInt();
      int dFac = message.substring(9, 12).toInt();
      Gun_on_delay  = int(1000*0.01*dFac/freq);
      Gun_off_delay = int(1000*0.01*(100 - dFac)/freq);
      setted();
      return;
    }
  }
}

void setted()
{
  String message;
  message = message + formatedString(String(unitID), 3);
  message = message + "SETTED";
  message = message + formatedString(String(checkSum(message)), 3);
  Serial.print(message + "\n");
}

//Check input message formation
bool messageCheck(String  message)
{
  int length = message.length();
  
  int chSum = message.substring(length - 4, length - 1).toInt(); 
    
  bool sumCheck = (chSum == checkSum(message.substring(0, length - 4)));  
  bool endCheck = (message.substring(length - 1) == "\n");  
   
  if (sumCheck && endCheck)
    return true;
  else
    return false; 
}

//Check sum
int checkSum(String str)
{
  int sum = 0;
  for(int i = 0; i < str.length(); i++)
    sum += str.charAt(i);
  return (sum % 256);
}

//Fill String to length by zeroes
String formatedString(String str, int length)
{
  String _str = str;
  for (int i = 0; i < (length - str.length()); i++)
  {
    _str = "0" + _str;
  }
  return _str;
}
