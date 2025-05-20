# 📦 DJI‑Payload‑SDK‑Pi‑Zero

**One‑sentence summary —** End‑to‑end guide for wiring a Raspberry Pi Zero 2 W to a DJI FlyCart 30 via the DJI Payload SDK (PSDK) and exposing custom GPIO‑controlled payload behaviour.

## What this project is about

This repository documents **how to turn a Raspberry Pi Zero 2 W into an intelligent payload computer** that talks to a DJI aircraft through the **E‑Port** using the DJI **Payload SDK**.  You will find:

* *OS preparation* — flash Raspberry Pi OS Lite (32‑bit, non‑legacy) completely headless.
* *Networking* — bring the Pi online over Wi‑Fi and reach it with SSH.
* *Dependency installation* — install minimal build tools and libraries required to compile the PSDK and drive GPIO lines.
* *Application templates* — minimal C++ examples that listen to PSDK widget callbacks and toggle GPIO pins.

## What the DJI Payload SDK does

DJI’s **Payload SDK** is a protocol implementation plus helper libraries that let you develop **Linux‑based payloads** which connect to compatible DJI drones (M300 RTK, FlyCart 30, etc.) via USB, UART or CAN:

* **Transport layer** over the drone’s Expansion Port (E‑Port).
* **Widget framework**: create UI elements in DJI Pilot so the operator can send commands to the payload.
* **Telemetry/data channels** for passing files, images, or custom packets.

Think of it as the drone‑side equivalent of a USB class driver: it exposes your payload to the aircraft and Pilot app without you having to reverse‑engineer proprietary protocols.

## Hardware & OS we cover

| Item                         | Spec / Selection                                         |
| ---------------------------- | -------------------------------------------------------- |
| Drone                        | **DJI FlyCart 30**                                       |
| Payload computer             | **Raspberry Pi Zero 2 W**                                |
| Expansion Port               | **E‑Port** (UART/USB‑C)                                  |
| Operating system for payload | **Raspberry Pi OS Lite 32‑bit** (non‑legacy, kernel 6.x) |

## Documentation map

| Phase                                 | File                                               |
| ------------------------------------- | -------------------------------------------------- |
| 1 – Flash & configure Raspberry Pi OS | [`docs/os-setup.md`](docs/os-setup.md)             |
| 2 – Locate the Pi & SSH in            | [`docs/ssh-connection.md`](docs/ssh-connection.md) |
| 3 – Install build prerequisites       | [`docs/dependencies.md`](docs/dependencies.md)     |
