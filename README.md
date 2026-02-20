# Day 01: ESP32-Gateway v1.0 — Industrial IoT Baseboard

## 📌 Project Overview
The **ESP32-Gateway** is a high-performance, industrial-grade IoT gateway designed to bridge the gap between low-level hardware sensors and high-level backend systems. Developed as the "Hardware Root of Trust" for the **#30DaysOfEngineering** challenge, this PCB demonstrates professional-grade standards in circuit integrity and manufacturing readiness.

As an **EasyEDA Campus Promotion Ambassador**, I have utilized **EasyEDA Pro** to ensure this design meets industry standards for graduation projects and hardware innovation.



## 🛠 Technical Specifications
* **Core MCU:** ESP32-S3 (Dual-core, supports AI acceleration).
* **Ethernet:** W5500 via SPI for deterministic, low-latency networking.
* **Industrial Bus:** RS485/Modbus interface for long-range communication with industrial sensors.
* **Power Stage:** Integrated Buck Converter supporting **9V-24V DC input**, ensuring compatibility with industrial PLC power rails.
* **Design Methodology:** Developed using **EasyEDA Pro** with a specific focus on differential pair routing, component positioning, and thermal management.



## 🏗 System Architecture
The firmware utilizes a **non-blocking FreeRTOS design**. This ensures that high-priority industrial bus tasks (RS485) and the network stack (Ethernet) operate concurrently on separate cores without data loss or latency issues.



## 🚀 Engineering Foresight (Roadmap)
Hardware engineering is an iterative process. This **v1.0 release** is a stable **MVP (Minimum Viable Product)**, with the following tunings planned for future versions:

* **Isolation:** Implementation of opto-isolated RS485 for high-noise industrial environments.
* **Power Redundancy:** Addition of a Li-ion UPS circuit for zero-downtime operation.
* **Security:** Integration of an ATECC608A Hardware Security Module (HSM) for encrypted cloud authentication.

---

## 🤝 Let's Connect
I am a **Hardware Specialist and Backend Developer** focused on the intersection of robust software backbones and high-performance hardware.

| Platform | Link |
| :--- | :--- |
| **LinkedIn** | [linkedin.com/in/redwanahmmed](https://linkedin.com/in/redwanahmmed) |
| **GitHub** | [github.com/redwan2003-bot](https://github.com/redwan2003-bot) |
| **Portfolio/Blog** | [medium.com/@reahs302444](https://medium.com/@reahs302444) |
| **Email** | [reah30244@gmail.com](mailto:reah30244@gmail.com) |

---

## 📂 Repository Structure
```text
├── /Hardware
│   ├── Schematic_V1.0.pdf      # EasyEDA Pro exported schematic
│   ├── Gerber_Files/           # Production-ready manufacturing files
│   └── BOM_Redwan_Gateway.csv  # Detailed Bill of Materials
├── /Firmware
    └── Esp32_GateWay.ino       # C++ source code using FreeRTOS tasks
