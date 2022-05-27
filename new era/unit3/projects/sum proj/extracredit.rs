#![no_std]
#![no_main]
// we dont need these things in an arduino
// dont worry about this for now :)
use arduino_hal::prelude::*;
use panic_halt as _;
use embedded_hal::serial::Read;
 
fn toggle() -> ! {
   led.toggle()
}
#[arduino_hal::entry]
fn main() -> ! {
  let dp = arduino_hal::Peripherals::take().unwrap();
  let pins = arduino_hal::pins!(dp);

  let mut serial = arduino_hal::default_serial!(dp, pins, 57600);

  let mut adc = arduino_hal::Adc::new(dp.ADC, Default::default());

	// a0 is not mutable because we are only reading from it
  let a0 = pins.a0.into_analog_input(&mut adc);
	let mut button = pins.d12.into_input()


  ufmt::uwriteln!(&mut serial, "hello world!\r").void_unwrap();
 
  loop {
		if (ishigh(&button)) {
			ufmt::uwrite!(&mut serial, "{}", a0.analog_read(&mut adc)).void_unwrap();
    	arduino_hal::delay_ms(200);
		}
  }
}
