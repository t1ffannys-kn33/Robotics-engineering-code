int operation, num1, num2;
char answer;

void setup (){
  Serial.begin(9600);
}

void loop (){

  Serial.print("Enter a first number: ");
  while(!Serial.available()) {}           
  num1 = Serial.parseInt();
  Serial.println(num1);

  Serial.print("Enter a second number: ");
  while(!Serial.available()) {}
  num2 = Serial.parseInt();
  Serial.println(num2);

  Serial.print("Enter 1 to add 2 to multiply 3 to divide and 4 to subtract");
  while(!Serial.available()) {}
  operation = Serial.parseInt();  

  if (operation == 1){
    Serial.print("Your sum is: ");
    Serial.println(mySumFunction(num1, num2));
  } 
  if (operation == 2){
    Serial.print("Your result is: ");
    Serial.println(myMultiplyFunction(num1, num2));
  } 
  if (operation == 3){
    Serial.print("Your result is: ");
    Serial.println(myDivideFunction(num1, num2));
  } 
  if (operation == 4){
    Serial.print("Your result is: ");
    Serial.println(mySubtractFunction(num1, num2));
  } 

  delay(1000);
}

int mySubtractFunction(int x, int y){    
  int result = x - y;
  return result;         
}

int myDivideFunction(int x, int y){    
  int result = x / y;
  return result;         
}

int myMultiplyFunction(int x, int y){    
  int result = x * y;
  return result;         
}

int mySumFunction(int x, int y){    
  int result = x + y;
  return result;         
}