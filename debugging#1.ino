int fade;	


void setup()
{
	pinMode(5, OUTPUT);	
	pinMode(6, OUTPUT);		
	fade = 255;	         
}

void loop()
{



	analogWrite(5, fade);
	analogWrite(5, (255-fade));

	fade--;	
	delay(500);
}