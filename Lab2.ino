char input;
String in = "";
const int ledPin = 13;
const int time_base = 500;
 
void setup() {
  Serial.begin(9600);
  Serial.setTimeout(10);
  pinMode(ledPin,OUTPUT);
}
void loop() {
  while (Serial.available()==0){}
  while (Serial.available() > 0){
    input = Serial.read();
    if(input == '0' || input == '1'){
      Serial.println("The value of n " + String(input));
      in.concat(input);
      if (isPalindrome(in)){
        digitalWrite(ledPin,HIGH);
        delay(time_base); 
        Serial.println("Now Input is " + in);
        Serial.println("Is Palimdrome Led Is ON");
      }
      else{
        digitalWrite(ledPin,LOW);
        delay(time_base); 
        Serial.println("Now Input is " + in);
        Serial.println("Is Not Palimdrome Led Is OFF");
      }
    }
  }
}

boolean isPalindrome(String original){
       String reverse = ""; // Objects of String class  
      int length = original.length();   
      for ( int i = length - 1; i >= 0; i-- )  
         reverse = reverse + original.charAt(i);  
      if (original.equals(reverse))  
         return true; 
      else  
         return false;    
}
