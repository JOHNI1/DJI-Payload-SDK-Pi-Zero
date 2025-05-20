# 📚 Install build dependencies (Pi Zero 2 W)

Run after you have an SSH shell on the Pi.

```bash
# 1 – refresh package lists and bring the OS up‑to‑date
sudo apt update && sudo apt upgrade -y

# 2 – toolchain + CMake + libusb for compiling the DJI Payload SDK
sudo apt install -y build-essential cmake libusb-1.0-0-dev

# 3 – GPIO userspace interface (modern character‑device API)
sudo apt install -y gpiod libgpiod-dev
```

> **Next step →** Clone or `scp` the Payload‑SDK source, configure CMake, and build.  Refer to `app/` examples in the repo root for a minimal GPIO‑driven payload program.
