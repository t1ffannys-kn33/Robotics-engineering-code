mod mymodule {
    mod toggleled {
        unsafe{
            // this code has to be unsafe, because the rust compiler doesnt know where we will be
            // using this function. We know it will work because we will only use
            // it in a place that has led instantiated
            pub fn toggle() -> ! {
                led.toggle()
            }
        }
    }
}