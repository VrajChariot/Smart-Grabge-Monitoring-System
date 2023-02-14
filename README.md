# Smart-Grabge-Monitoring-System
A smart garbage monitoring/management system for smart cities in India to make cities more clean and efficient
currently the waste management system in India is working randomly and it need's many revolutionary changes. By this project multiple issues of waste management can be solved.
# Features/Benifits of it :
1) Constant monitoring of waste around the city
2) Reminders when dustbin is filled 
3) Optimized route for waste management 
4) No need of wifi network in rural areas
5) Long ranage rf communication used for rural areas.
6) Web dashboard for live waste monitoring.
# Full details are given below :
[e-Kachra Daan.pdf](https://github.com/VrajChariot/Smart-Grabge-Monitoring-System/files/10734572/e-Kachra.Daan.pdf)
#Basic concept :
- A dustbin which is in a area where wifi is available will send its data directly to Blynk IoT cloud 
- Dustbin which is in rural area will send its data to a gateway using rf signals
- Gateway will send data of dustbins in rural area to Blynk IoT cloud
# Steps :
-Firstly you will need to upload Iot dustbin to a nodemcu board which act as an normal IoT dustbin which sends data to Blynk Dashboard through wifi
- Then upload and configure transmitter code to arduino nano which in our case will be our transmitter
- After that upload Receiver code to arduino nano on receiver side 
- Upload Gateway code to ESP32 for enabling Blynk Communication Through Wifi
- Configure Blynk Dashboard

