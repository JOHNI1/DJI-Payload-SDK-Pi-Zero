# 🔌 Headless SSH Access

1. **Insert SD & power the Pi**
   Plug the flashed micro‑SD into the Pi Zero 2 W, then power the **PWR IN** micro‑USB with a stable 5 V ≥ 2 A adapter.
2. **Ensure Wi‑Fi is available**
   The Pi will attempt to join the SSID you set; keep that AP powered.
3. **Find the IP address**
   *Option A – Router GUI* ▸ Log in to your router and look for a client named **raspberrypi**.
   *Option B – `nmap`* ▸ On your development PC:

   ```bash
   sudo apt install nmap      # once
   nmap -sn 192.168.68.0/24   # replace with your subnet
   ```

   Compare the device list **before** and **after** powering the Pi (use a diff tool for clarity).
4. **SSH in**

   ```bash
   ssh pi@<pi_ip>
   # password: mafat
   ```
5. **Change the password (optional, recommended)**

   ```bash
   passwd
   ```