int num1, num2, sum;
char answer;

void setup (){
  Serial.begin(9600);
}

void loop (){

  Serial.print("Enter a first number: ");
  while(!Serial.available()) {}           
        // “!Serial.available” is equivalent to “Serial.available == 0”
  num1 = Serial.parseInt();
  Serial.println(num1);

  Serial.print("Enter a second number: ");
  while(!Serial.available()) {}
  num2 = Serial.parseInt();
  Serial.println(num2);
  
  answer = ShouldIAdd(); //call function ShouldIAdd to assign value to “answer”

  if (answer == 'Y'){
    sum = mySumFunction(num1, num2); //call mySumFunction if user wants it!
    Serial.print("Your sum is: ");
    Serial.println(sum);
  } else {
    Serial.println("Thanks for nothing!");
  }

  delay(1000);
}

char ShouldIAdd(){       //a return type function with no parameters
  char yesorno;
  Serial.println("Press Y to add your numbers.");
  while(!Serial.available()) {}
  yesorno = Serial.read();

  return yesorno;        //returns a character
}

int mySumFunction(int x, int y){     //a return type function with two parameters
  int result = x + y;
  return result;         //returns an integer
}