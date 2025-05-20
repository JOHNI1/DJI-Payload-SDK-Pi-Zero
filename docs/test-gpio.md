# 🧪 Step 1: Simple C++ Test Program


<details>
  <summary>Make sure you have libgpiod installed on the Raspberry Pi</summary>
  
```bash
sudo apt update
sudo apt install libgpiod-dev gpiod
```
  
</details>


Below is a minimal C++ example that **sets a GPIO pin HIGH for 2 seconds, then LOW**.

## 🔧 Example: `gpiotest.cpp`

```cpp
#include <gpiod.h>
#include <iostream>
#include <unistd.h> // for sleep

int main() {
    const char* chipname = "gpiochip0";  // GPIO chip
    const unsigned int line_num = 17;    // BCM GPIO 17 (physical pin 11)
    const char* consumer = "gpio_test";

    // Open the GPIO chip
    gpiod_chip* chip = gpiod_chip_open_by_name(chipname);
    if (!chip) {
        std::cerr << "Failed to open chip\n";
        return 1;
    }

    // Get the line
    gpiod_line* line = gpiod_chip_get_line(chip, line_num);
    if (!line) {
        std::cerr << "Failed to get line\n";
        gpiod_chip_close(chip);
        return 1;
    }

    // Request line as output and set initial value to 0 (LOW)
    if (gpiod_line_request_output(line, consumer, 0) < 0) {
        std::cerr << "Failed to request line as output\n";
        gpiod_chip_close(chip);
        return 1;
    }

    std::cout << "Setting GPIO HIGH...\n";
    gpiod_line_set_value(line, 1);
    sleep(2);  // Hold for 2 seconds

    std::cout << "Setting GPIO LOW...\n";
    gpiod_line_set_value(line, 0);

    gpiod_line_release(line);
    gpiod_chip_close(chip);
    return 0;
}
```

---

## 🧱 Step 2: Compile

```bash
g++ -o gpiotest gpiotest.cpp -lgpiod
```

---

## ⚡ Step 3: Run with sudo

```bash
sudo ./gpiotest
```

> 🧪 You can now measure **GPIO 17 (pin 11)** with a multimeter — it should go **3.3V → 0V**.

---

## 📌 Notes

* Use [pinout.xyz](https://pinout.xyz) to check which **BCM number** maps to which physical pin.
* You can change `line_num = 17` to any other GPIO pin supported by the Pi.
* For integration with the DJI SDK, you’d just toggle this based on SDK callback logic.


![](../images/Pi-Zero-pinout.png)
