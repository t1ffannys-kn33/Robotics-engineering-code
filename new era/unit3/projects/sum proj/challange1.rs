#![no_std]
#![no_main]
// we dont need these things in an arduino
// dont worry about this for now :)
use arduino_hal::prelude::*;
use panic_halt as _;
use embedded_hal::serial::Read;
 

#[arduino_hal::entry]
fn main() -> ! {
  // in rust, we do things a bit differently. We are setting up all the digital
  // pins by setting them to a variable dp (digital pins)
  let dp = arduino_hal::Peripherals::take().unwrap();
  let pins = arduino_hal::pins!(dp);
 
  // ok so there's alot going on here
  let mut serial = arduino_hal::default_serial!(dp, pins, 57600);
  // serial object being instantiated, baudrate 57600
  ufmt::uwriteln!(&mut serial, "hello world!\r").void_unwrap();
  // we are writing a line, and letting the function "borrow" the serial object.
  //we are also giving the function the message we want, ending with \r (new line)
  //the reason we need to do this in ufmt and uwriteln is that rust uses a different way
  // to store strings the arduino is expecting.
 
  // setting a variable led to the output of pin 13
  let mut led = pins.d13.into_output();
  // again, the same thing but with the pin for the button.
  let mut button = pins.d12.into_input();
  let mut buttonison = false;
  // unsigned 8 bit number
  let mut count : u8 = 0;

  fn toggle() -> ! {
    led.toggle()
 }
 
  loop {
      // set the button variable to the state of the button
      ishigh(&button) = buttonison;
      arduino_hal::delay_ms(200);
      // check if the button has changed
      if ( ishigh(&button) != buttonison ) {
        
        led.toggle;
        //this is a bit of a monstor line, but we are printing the result of concatinating the
        // string toggled! and the count variable. 
        ufmt::uwriteln!(&mut serial, concat!("Toggled!, count is {}\r", count.to_string())).void_unwrap();
        count += 1;
      }
  }
}
