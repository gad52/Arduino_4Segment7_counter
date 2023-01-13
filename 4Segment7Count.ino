unsigned int segA = 3;
unsigned int segB = 4;
unsigned int segC = 5;
unsigned int segD = 6;
unsigned int segE = 7;
unsigned int segF = 8;
unsigned int segG = 9;
unsigned int segDP = 2;

unsigned int ch1 = 13;
unsigned int ch4 = 12;
unsigned int ch2 = 11;
unsigned int ch3 = 10;

void setup() {
  int segments[] = {segA, segB, segC, segD, segE, segF, segG, segDP, ch1, ch2, ch3, ch4};
  for(int i = 0; i < 12; i++)
  {
     pinMode(segments[i],OUTPUT);
  }
  digitalWrite(ch1, HIGH);
  digitalWrite(ch2, HIGH);
  digitalWrite(ch3, HIGH);
  digitalWrite(ch4, HIGH);
}

void WriteVal(int digit)
{
  switch(digit)
  {
    case 0:
      Display0();
      break;
    case 1:
      Display1();
      break;
    case 2:
      Display2();
      break;
    case 3:
      Display3();
      break;
    case 4:
      Display4();
      break;
    case 5:
      Display5();
      break;
    case 6:
      Display6();
      break;
    case 7:
      Display7();
      break;
    case 8:
      Display8();
      break;
    case 9:
      Display9();
      break;
     default:
       AllOff();
       break;
  }
}
void Display0()
{
     int segments[] = {segA, segB, segC, segD, segE, segF, segG};
     int state[] =    {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW}; 
     for(int i = 0; i < 7; i++)
     {
        digitalWrite(segments[i], state[i]);
     }
}

void Display1()
{
     int segments[] = {segA, segB, segC, segD, segE, segF, segG};
     int state[] =    {LOW, HIGH, HIGH, LOW, LOW, LOW, LOW}; 
     for(int i = 0; i < 7; i++)
     {
        digitalWrite(segments[i], state[i]);
     }
}

void Display2()
{
     int segments[] = {segA, segB, segC, segD, segE, segF, segG};
     int state[] =    {HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH}; 
     for(int i = 0; i < 7; i++)
     {
        digitalWrite(segments[i], state[i]);
     }
}

void Display3()
{
     int segments[] = {segA, segB, segC, segD, segE, segF, segG};
     int state[] =    {HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH}; 
     for(int i = 0; i < 7; i++)
     {
        digitalWrite(segments[i], state[i]);
     }
}

void Display4()
{
     int segments[] = {segA, segB, segC, segD, segE, segF, segG};
     int state[] =    {LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH}; 
     for(int i = 0; i < 7; i++)
     {
        digitalWrite(segments[i], state[i]);
     }
}

void Display5()
{
     int segments[] = {segA, segB, segC, segD, segE, segF, segG};
     int state[] =    {HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH}; 
     for(int i = 0; i < 7; i++)
     {
        digitalWrite(segments[i], state[i]);
     }
}

void Display6()
{
     int segments[] = {segA, segB, segC, segD, segE, segF, segG};
     int state[] =    {HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH}; 
     for(int i = 0; i < 7; i++)
     {
        digitalWrite(segments[i], state[i]);
     }
}

void Display7()
{
     int segments[] = {segA, segB, segC, segD, segE, segF, segG};
     int state[] =    {HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW}; 
     for(int i = 0; i < 7; i++)
     {
        digitalWrite(segments[i], state[i]);
     }
}

void Display8()
{
     int segments[] = {segA, segB, segC, segD, segE, segF, segG};
     int state[] =    {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH}; 
     for(int i = 0; i < 7; i++)
     {
        digitalWrite(segments[i], state[i]);
     }
}

void Display9()
{
     int segments[] = {segA, segB, segC, segD, segE, segF, segG};
     int state[] =    {HIGH, HIGH, HIGH, LOW, LOW, HIGH, HIGH}; 
     for(int i = 0; i < 7; i++)
     {
        digitalWrite(segments[i], state[i]);
     }
}

void AllOff()
{
     int segments[] = {segA, segB, segC, segD, segE, segF, segG};
      int state[] =    {LOW, LOW, LOW, LOW, LOW, LOW, LOW};
     for(int i = 0; i < 7; i++)
     {
        digitalWrite(segments[i], state[i]);
     }
}

int getdigit(int num, int n)
{
    int r = num / pow(10, n);
    r = r % 10;
    return r;
}

 //ch1, ch2, ch3, ch4
void DisplayNum(int num)
{
  bool bStart = false;
  bool bConditon = false;
   int sleepTime = 5;
   int digit[4] = {};
   bConditon = false; 
   int state[4][4] = {HIGH, HIGH, HIGH, LOW,
                      HIGH, HIGH, LOW, HIGH,
                      HIGH, LOW, HIGH, HIGH,
                      LOW, HIGH, HIGH, HIGH};

   //this tries to make the update uniform when counting at rate
   for(int i = 3; i >= 0; i--)
   {
        digit[i] = getdigit(num,i);
        if(digit > 0 || sleepTime != 5)
        {
            sleepTime--;
        }
   }
   bConditon = digit[3] > 0;

   for(int i = 3; i >= 0; i--)
   {
    if(i != 3)
    {
      bConditon = bStart || (bStart == false && digit[i] > 0);
    }
    if(bConditon)
    {
      bStart = true;
      AllOff();
      digitalWrite(ch1, state[i][0]);
      digitalWrite(ch2, state[i][1]);
      digitalWrite(ch3, state[i][2]);
      digitalWrite(ch4, state[i][3]);
      WriteVal(digit[i]);
      delay(sleepTime);
    }
   }
}

int counter = 0;
int counter2 = 0;
void loop() {
      DisplayNum(counter);
      if(counter2%100==0)
      {
      counter++;
      }
      if(counter == 10000)
      {
        counter = 0;
      }
      counter2++;
}
