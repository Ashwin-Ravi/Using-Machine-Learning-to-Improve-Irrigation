# Using-Machine-Learning-to-Improve-Irrigation
Contains the files for integrating several on-field sensors to an arduino. And further integrated to MATLAB to perform predictions using Machine Learning Algorithms, ANNs. The intention is to save as much water as possible in age old irrigation systems.
The system is considered to have several on-field sensors such as soil moisture sensor, temperature and humidity sensor ect. These sensors are integrated to an on-field arduino (called the transmitter arduino).
This sensor information is transmitted to a central unit incharge of processing. Here the sensor information is received and sent to MATLAB for making predections using Artificial Neural Networks.
The Network is trained using irrigation data in order to predict the future Moisture content in soil. This will estimate the quantity of water required by the plant beforehand. Allowing the system to maintain optimal water levels. Also avoiding water wastage.
This decision is used to either switch on or switch off a motor which would supply water to plants using sprinkler based irrigation techniques.
Note: I have not included the code for training the Neural Network.
