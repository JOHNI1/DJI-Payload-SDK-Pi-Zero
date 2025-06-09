# 🔌 Headless SSH Access

You have **two ways** to reach the Raspberry Pi Zero 2 W without a screen.

| Method | When to use | Requires LAN? |
|--------|-------------|---------------|
| **A. Wi-Fi (LAN)** | Normal lab / home | ✅ Yes |
| **B. USB-Ethernet gadget** | Field work, no router available | ❌ No |

---

## A · Wi-Fi (LAN)
1. **Boot**   
   Insert the flashed micro-SD and power the Pi via **PWR IN** (5 V ≥ 2.5 A).
2. **Find the Pi’s IP**  
   ```bash
   ip a  # on your PC – note your subnet, e.g. 192.168.68.0/24
   sudo apt install nmap    # first time only
   nmap -sn 192.168.68.0/24 # change to your subnet
   ```
   *Tip ▸* run `nmap` **before and after powering the Pi** and differentiate between the lists.
3. **SSH in**

   ```bash
   ssh pi@<pi_ip>
   # password: mypass
   ```
4. *(Optional but wise)* change the password: `passwd`.

---

## B · USB-Ethernet gadget  — direct cable, no Wi-Fi needed

> **Do the “one-off setup” while still on Wi-Fi (method A).**

### One-off setup (on the Pi)
1. <br/>

   ```bash
   sudo nano /boot/firmware/config.txt
   ```
   Add inside the [all] section:
   ```txt
   enable_uart=1
   dtoverlay=disable-bt
   ```
   Save by pressing Ctrl+O, Ctrl+M, Ctrl+X <br/>

2. <br/>

   To apply changes, reboot:
   ```bash
   sudo reboot
   ```

### Cable connection & login

1. Power via **PWR IN** as usual.
2. connect USB-to-TTL module like FT232 to the raspberry pi. (GND->GND, RX->TX, TX->RX)
3. connect:
   ```bash
   screen /dev/ttyUSB0 115200
   ```
