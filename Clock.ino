#include <DS1302.h>
DS1302 rtc(6, 7, 8);
int a, b, c, d, e, f, g = 0;
int aa, bb, cc, dd, ee, ff, gg = 0;
int regym = 0;
int lineage = 5;
int dots = 9;
Time t;

void setup()
{
	rtc.halt(false);
	rtc.writeProtect(false);
  pinMode(lineage, OUTPUT);
  pinMode(dots, OUTPUT);
	DDRB = DDRB | 0B00111100; // Katod
	DDRC = DDRC | 0B00111111; // Anod
}

char katod[10][1] = { 
{ 0B00000000 },  // 0
{ 0B00100000 },  // 1
{ 0B00010000 },  // 2
{ 0B00110000 },  // 3
{ 0B00001000 },  // 4
{ 0B00101000 },  // 5
{ 0B00011000 },  // 6
{ 0B00111000 },  // 7
{ 0B00000100 },  // 8
{ 0B00100100 }   // 9
};

char anod[6][1] = { 
{ 0B00000001 },  // 1
{ 0B00000010 },  // 2
{ 0B00000100 },  // 3
{ 0B00001000 },  // 4
{ 0B00010000 },  // 5
{ 0B00100000 }   // 6
};

       
void loop()
{
	analogWrite(lineage, 6);
 	   
	PORTC = anod[0][0];
	PORTB = katod[a][0];
  digitalWrite(dots, aa);
	delay(1);

	PORTC = 0B00000000;
	PORTB = 0B00000000;
  digitalWrite(dots, LOW);
	delay(1);

	PORTC = anod[1][0];
	PORTB = katod[b][0];
  digitalWrite(dots, bb);
	delay(1);

	PORTC = 0B00000000;
	PORTB = 0B00000000;
  digitalWrite(dots, LOW);
	delay(1);

	PORTC = anod[2][0];
	PORTB = katod[c][0];
  digitalWrite(dots, cc);
	delay(1);

	PORTC = 0B00000000;
	PORTB = 0B00000000;
  digitalWrite(dots, LOW);
	delay(1);

	PORTC = anod[3][0];
	PORTB = katod[d][0];
  digitalWrite(dots, dd);
	delay(1);

	PORTC = 0B00000000;
	PORTB = 0B00000000;
  digitalWrite(dots, LOW);
	delay(1);

	PORTC = anod[4][0];
	PORTB = katod[e][0];
  digitalWrite(dots, ee);
	delay(1);

	PORTC = 0B00000000;
	PORTB = 0B00000000;
  digitalWrite(dots, LOW);
	delay(1);

	PORTC = anod[5][0];
	PORTB = katod[f][0];
  digitalWrite(dots, ff);
	delay(1);

	PORTC = 0B00000000;
	PORTB = 0B00000000;
  digitalWrite(dots, LOW);
	delay(1);

	if (digitalRead(0) == HIGH)//Esli najata knopka Regyma ... 
	{
		regym++;
		PORTC = 0B00000011;
		perebeg();
		if (regym > 4)
		{
			regym = 0;
		}
		rtc.halt(true);
		rtc.writeProtect(true);
		regyms();
	}

	if (digitalRead(2) == HIGH)
	{
		rtc.setTime(12, 0, 0);
		rtc.setDate(6, 8, 2010);
	}

	t = rtc.getTime();

	if (t.sec <= 9)
	{
		a = t.sec;
		b = 0;
	}
	if (t.sec > 9)
	{
		a = t.sec - 10;
		b = 1;
	}
	if (t.sec > 19)
	{
		a = t.sec - 20;
		b = 2;
	}
	if (t.sec > 29)
	{
		a = t.sec - 30;
		b = 3;
	}
	if (t.sec > 39)
	{
		a = t.sec - 40;
		b = 4;
	}
	if (t.sec > 49)
	{
		a = t.sec - 50;
		b = 5;
	}

	//======================================

	if (t.min <= 9)
	{
		c = t.min;
		d = 0;
	}
	if (t.min > 9)
	{
		c = t.min - 10;
		d = 1;
	}
	if (t.min > 19)
	{
		c = t.min - 20;
		d = 2;
	}
	if (t.min > 29)
	{
		c = t.min - 30;
		d = 3;
	}
	if (t.min > 39)
	{
		c = t.min - 40;
		d = 4;
	}
	if (t.min > 49)
	{
		c = t.min - 50;
		d = 5;
	}

	//======================================

	if (t.hour <= 9)
	{
		e = t.hour;
		f = 0;
	}
	if (t.hour > 9)
	{
		e = t.hour - 10;
		f = 1;
	}
	if (t.hour > 19)
	{
		e = t.hour - 20;
		f = 2;
	}
	if (t.hour >= 24)
	{
		e = 0;
		f = 0;
	}
//===========================================
//===========================================

  ssdot();
  obnovlenie();
}

int ssdot()
{
  if (b == 0)
  {
    ff = LOW;
    aa = HIGH;
  }
  if (b == 1)
  {
    aa = LOW;
    bb = HIGH;
  }
  if (b == 2)
  {
    bb = LOW;
    cc = HIGH;
  }
  if (b == 3)
  {
    cc = LOW;
    dd = HIGH;
  }
  if (b == 4)
  {
    dd = LOW;
    ee = HIGH;
  }
  if (b == 5)
  {
    ee = LOW;
    ff = HIGH;
  }
}

int regyms()
{
  	if (regym == 1) { // Regym 1
		g = 0;

		while (g == 0) {
			PORTC = anod[0][0];
			PORTB = katod[a][0];
			delay(5);

			PORTC = anod[1][0];
			PORTB = katod[b][0];
			delay(5);

			if (digitalRead(2) == HIGH) {
				a--;
				if (a < 0) {
					a = 9;
					b -= 1;
				}
				if (b < 0) {
					b = 5;
				}
				delay(200);
			}

			if (digitalRead(1) == HIGH) {
				a++;
				if (a > 9) {
					a = 0;
					b += 1;
				}
				if (b > 5) {
					b = 0;
				}
				delay(200);
			}


			if (digitalRead(0) == HIGH) {
				g = 1;
				regym = 2;
				PORTC = 0B00001100;
				perebeg();
			}
		}
	}

	if (regym == 2) { // Regym 2
		g = 0;

		while (g == 0) {
			PORTC = anod[2][0];
			PORTB = katod[c][0];
			delay(5);

			PORTC = anod[3][0];
			PORTB = katod[d][0];
			delay(5);

			if (digitalRead(2) == HIGH) {
				c--;
				if (c < 0) {
					c = 9;
					d -= 1;
				}
				if (d < 0) {
					d = 5;
				}
				delay(200);
			}

			if (digitalRead(1) == HIGH) {
				c++;
				if (c > 9) {
					c = 0;
					d += 1;
				}
				if (d > 5) {
					d = 0;
				}
				delay(200);
			}

			if (digitalRead(0) == HIGH) {
				g = 1;
				regym = 3;
				PORTC = 0B00110000;
				perebeg();

			}
		}
	}

	if (regym == 3) { // Regym 3
		g = 0;

		while (g == 0) {
			PORTC = anod[4][0];
			PORTB = katod[e][0];
			delay(5);

			PORTC = anod[5][0];
			PORTB = katod[f][0];
			delay(5);

			if (digitalRead(2) == HIGH) {
				e--;
				if (e < 0) {
					e = 9;
					f -= 1;
				}
				if (f < 0) {
					f = 2;
					e = 3;
				}

				delay(200);
			}

			if (digitalRead(1) == HIGH) {
				e++;
				if (e > 9) {
					e = 0;
					f += 1;
				}
				if (f > 2) {
					f = 0;
				}
				if (e == 4 && f == 2)
				{
					e = 0;
					f = 0;
				}
				delay(200);
			}


			if (digitalRead(0) == HIGH) {
				g = 1;
				regym = 0;
				PORTC = 0B00111111;
				perebeg();
				rtc.halt(false);
				rtc.writeProtect(false);
				rtc.setTime((f*10) + e, (d*10) + c, (b*10) + a);
			}
		}
	}

}

int obnovlenie()
{

	if (a == 0)
	{
		if (b == 0)
		{
			if (c == 0)
			{
				if (d >= 0)
				{
					PORTC = 0B00111111;
					perebeg();
				}
			}
		}
	}

}

void perebeg()
{
	for (int perebeg = 0; perebeg <= 9; perebeg++)
	{
		PORTB = katod[perebeg][0];
		delay(50);
	}
}
