# LED Control Panel (web edition)
> A web interface to communicate with a microcontroller over I2C


[![BSD 3-Clause](https://img.shields.io/apm/l/atomic-design-ui.svg?)](https://github.com/Cap1LED/interface/blob/master/LICENSE)
[![Version](https://img.shields.io/badge/rustc-1.46+-ab6000.svg)](https://blog.rust-lang.org/2020/08/27/Rust-1.46.0.html)

This is a web interface written in HTML/JS that interacts with an API written in Rust with Actix Web, which interacts with a microcontroller over I2C to gather temperature data as well as set duty cycle of PWM outputs.


## Installation

```sh
git clone https://github.com/Cap1LED/interface.git led_interface
cd led_interface
cargo build --release
cargo run --release
```

## Development setup

Requirements:
* Rust Stable 1.51+
* Cargo 1.51+
* A platform with I2C output on /dev/i2c-1

All good? Cool. Clone the repo `git clone https://github.com/Cap1LED/interface.git led_interface` and you're off to the races. Yes, it's really that simple.

## Release History

* 0.0.1
    * Initial Commit!
    * UI served on localhost:8000/static/index.html
    * Dummy data served, still needs connection to I2C


## Contributing

1. Fork it (<https://github.com/Cap1LED/interface/fork>)
2. Create your feature branch (`git checkout -b feature/fooBar`)
3. Commit your changes (`git commit -am 'Add some fooBar'`)
4. Push to the branch (`git push origin feature/fooBar`)
5. Create a new Pull Request
