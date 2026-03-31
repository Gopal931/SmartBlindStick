# 🦯 Smart Blind Stick

> A life-saving IoT-based assistive device with real-time hazard detection and emergency communication 🚨

---

## 📌 Overview

The **Smart Blind Stick** is an assistive device designed for visually impaired individuals to help them navigate safely and independently. It uses sensors to detect obstacles and water hazards, and includes an emergency SOS system for critical situations.

---

## 🚀 Features

- 🔍 **Obstacle Detection**
  - Uses ultrasonic sensor to detect objects in real time
  - Alerts the user using buzzer or vibration

- 💧 **Water Detection**
  - Detects wet/slippery surfaces
  - Helps prevent accidental slips

- 🔊 **Real-Time Feedback**
  - Instant alerts for hazards

- 🚨 **Emergency SOS Button**
  - Sends SMS to caretaker
  - Automatically makes an emergency call

- 📡 **GSM Communication (SIM900A)**
  - Works without internet
  - Uses SIM card for calling and messaging

---

## 🛠️ Tech Stack

- **Microcontroller**: Arduino / NodeMCU  
- **Sensors**:
  - Ultrasonic Sensor
  - Water Sensor  
- **Communication**:
  - SIM900A GSM Module  
- **Other Components**:
  - Buzzer / Vibration Motor
  - Push Button (SOS)
  - Battery

---

## ⚙️ Working Principle

1. Ultrasonic sensor continuously scans surroundings  
2. If obstacle is detected → alert is triggered  
3. Water sensor detects wet surfaces → warning alert  
4. SOS button pressed:
   - GSM module sends SMS 📩  
   - GSM module makes a call 📞  

---
