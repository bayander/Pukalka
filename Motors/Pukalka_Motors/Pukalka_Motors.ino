const int t = 100;

const int M1_start_stop = 22;
const int M1_chdir      = 23;
const int M1_led_dir1   = 24;
const int M1_led_dir2   = 25;
const int M1_rel1       = 26;
const int M1_rel2       = 27;
const int M1_ter1       = 28;
const int M1_ter2       = 29; 

const int M2_start_stop = 30;
const int M2_chdir      = 31;
const int M2_led_dir1   = 32;
const int M2_led_dir2   = 33;
const int M2_rel1       = 34;
const int M2_rel2       = 35;
const int M2_ter1       = 36;
const int M2_ter2       = 37;

const int M3_start_stop = 38;
const int M3_chdir      = 39;
const int M3_led_dir1   = 40;
const int M3_led_dir2   = 41;
const int M3_rel1       = 42;
const int M3_rel2       = 43;
const int M3_ter1       = 44;
const int M3_ter2       = 45;

void chDOmode(int pin)
{
  if (digitalRead(pin) == HIGH)
    digitalWrite(pin, LOW);
  if (digitalRead(pin) == LOW)
    digitalWrite(pin, HIGH);
  delay(t);  
}

void chDir(int rel1, int rel2, int led_dir1, int led_dir2)
{
  digitalWrite(rel1, HIGH);
  delay(t);
      
  if (digitalRead(rel2) == HIGH)
  {
    digitalWrite(rel2, LOW);
    digitalWrite(led_dir1, HIGH);
    digitalWrite(led_dir2, LOW);
  }  
  if (digitalRead(rel2) == LOW)
  {
    digitalWrite(rel2, HIGH);
    digitalWrite(led_dir1, LOW);
    digitalWrite(led_dir2, HIGH);
  }
  delay(t);    
}

void M1_setup()
{
  pinMode(M1_start_stop, INPUT);
  pinMode(M1_chdir,      INPUT);
  pinMode(M1_led_dir1,   OUTPUT);
  pinMode(M1_led_dir2,   OUTPUT);
  pinMode(M1_rel1,       OUTPUT);
  pinMode(M1_rel2,       OUTPUT);
  pinMode(M1_ter1,       INPUT);
  pinMode(M1_ter2,       INPUT);

  digitalWrite(M1_start_stop, HIGH);
  digitalWrite(M1_chdir,      HIGH);
}

void M1_action()
{
  if (digitalRead(M1_start_stop) == HIGH)
    chDOmode(M1_rel1);
  if ((digitalRead(M1_chdir) == HIGH) || (digitalRead(M1_ter1) == HIGH) || (digitalRead(M1_ter2) == HIGH))
    chDir(M1_rel1, M1_rel2, M1_led_dir1, M1_led_dir2);
}

void M2_setup()
{
  pinMode(M2_start_stop, INPUT);
  pinMode(M2_chdir,      INPUT);
  pinMode(M2_led_dir1,   OUTPUT);
  pinMode(M2_led_dir2,   OUTPUT);
  pinMode(M2_rel1,       OUTPUT);
  pinMode(M2_rel2,       OUTPUT);
  pinMode(M2_ter1,       INPUT);
  pinMode(M2_ter2,       INPUT);

  digitalWrite(M2_start_stop, HIGH);
  digitalWrite(M2_chdir,      HIGH);
}

void M2_action()
{
  if (digitalRead(M2_start_stop) == HIGH)
    chDOmode(M2_rel1);
  if ((digitalRead(M2_chdir) == HIGH) || (digitalRead(M2_ter1) == HIGH) || (digitalRead(M2_ter2) == HIGH))
    chDir(M2_rel1, M2_rel2, M2_led_dir1, M2_led_dir2);
}

void M3_setup()
{
  pinMode(M3_start_stop, INPUT);
  pinMode(M3_chdir,      INPUT);
  pinMode(M3_led_dir1,   OUTPUT);
  pinMode(M3_led_dir2,   OUTPUT);
  pinMode(M3_rel1,       OUTPUT);
  pinMode(M3_rel2,       OUTPUT);
  pinMode(M3_ter1,       INPUT);
  pinMode(M3_ter2,       INPUT);

  digitalWrite(M3_start_stop, HIGH);
  digitalWrite(M3_chdir,      HIGH);
}

void M3_action()
{
  if (digitalRead(M3_start_stop) == HIGH)
    chDOmode(M3_rel1);
  if ((digitalRead(M3_chdir) == HIGH) || (digitalRead(M3_ter1) == HIGH) || (digitalRead(M3_ter2) == HIGH))
    chDir(M3_rel1, M3_rel2, M3_led_dir1, M3_led_dir2);
}

void setup() 
{
  M1_setup();
  M2_setup();
  M3_setup();
}

void loop() 
{
  M1_action();
  M2_action();
  M3_action();
}
