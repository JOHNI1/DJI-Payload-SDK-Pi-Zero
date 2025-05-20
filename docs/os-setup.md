# 🔧 Raspberry Pi Zero 2 W — OS Setup Guide

> **Goal:** Produce a micro‑SD card that boots a Pi Zero 2 W headless, joins Wi‑Fi, and exposes SSH.

## 1  Install Raspberry Pi Imager

Download and install the [official imager](https://www.raspberrypi.com/software/) for your laptop’s OS.

## 2  Insert the micro‑SD card

Use a USB micro‑SD reader. A minimum of 8 GB is recommended.

## 3  Choose image & board

| Field                   | Selection                       |
| ----------------------- | ------------------------------- |
| **Raspberry Pi Device** | *Raspberry Pi Zero*             |
| **Operating System**    | *Raspberry Pi OS Lite (32‑bit)* |
| **Storage**             | *Your SD card*                  |

## 4  Open advanced settings

Click **Next** ▸ in the imager, then in the pop‑up **Use OS customisation?** choose **Edit settings**.

## 5  General tab

* ✔ **Set hostname** → `raspberrypi`
* ✔ **Set username and password**

  * **Username:** `pi`
  * **Password:** `mypass`
* ✔ **Configure wireless LAN**

  * **SSID / Password:** *fill in your 2.4 GHz network*
  * **Wireless LAN country:** `IL`
  * Leave **Show password** and **Hidden SSID** unchecked

## 6  Services tab

* ✔ **Enable SSH** → *Use password authentication*

## 7  Write image

Click **Save**, answer **Yes** to apply customisations, then **Write**.  When complete, eject the card.