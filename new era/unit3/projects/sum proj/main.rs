#![no_std]
#![no_main]
// we dont need these things in an arduino
 
// dont worry about this for now :)
use panic_halt as _;
 
fn toggle() -> ! {
    led.toggle()
}
 
#[arduino_hal::entry]
fn main() -> ! {
   // in rust, we do things a bit differently. We are setting up all the digital
   // pins by setting them to a variable dp (digital pins)
   let dp = arduino_hal::Peripherals::take().unwrap();
   let pins = arduino_hal::pins!(dp);
 
   // setting a variable led to the output of pin 13
   let mut led = pins.d13.into_output();
 
   // again, the same thing but with the pin for the button.
   let mut button = pins.d12.into_input()
   let mut buttonison = false;

 
   loop {
       if ( ishigh(&button) != buttonison ) {
           led.toggle;
       }
       arduino_hal::delay_ms(200);
       ishigh(&button) = buttonison;
   }
}
