int fade;	


void setup()
{
	pinMode(5, OUTPUT);	
	pinMode(6, OUTPUT);		
	fade = 255;	         
}

void loop()
{


	analogWrite(9, fade);
	analogWrite(10, (255-fade));

	fade--;	
	delay(500);
}