fn main() -> ! {
    let dp = arduino_hal::Peripherals::take().unwrap();
    let pins = arduino_hal::pins!(dp);

    let mut led = pins.d13.into_output();
    led.set_high();

    loop {
        led.toggle();
        arduino_hal::delay_ms(100);
    }
}