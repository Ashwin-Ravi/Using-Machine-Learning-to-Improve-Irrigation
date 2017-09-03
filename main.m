clc; 
clearall; 
closeall; 
 
% initialize all variables Soil_moisture-Moist,Soil_temp-Temp,Air 
Humidity-Humid, Air Temperature-TempAir. 
 
Moist = zeros(1,10); 
Temp = zeros(1,10); 
Humid = zeros(1,10); 
TempAir = zeros(1,10); 
VarIn=zeros(4,1); % input variable to the neural network 
 
arduino=serial('COM3','BaudRate',9600); % create serial communication 
object on port COM4 
 
fopen(arduino); % initiate arduino communication 
pause(2); 
 
 
 
% Running multiple times for demonstration sake 
 
fori = 1:2 
 
[Moist1,Temp1,Humid1,Temp2] = Serial_Read(arduino);% acquiring relevant 
data 
 
%%%Converting from string to double 
 
Moist(i)=str2double(Moist1); 
Temp(i)=str2double(Temp1); 
TempAir(i)=str2double(Temp2); 
Humid(i)=str2double(Humid1); 
Moist1=str2double(Moist1) 
Temp1=str2double(Temp1) 
Temp2=str2double(Temp2) 
Humid1=str2double(Humid1) 
 
%%Assigning Variable 
 
VarIn(1,1)=Moist(i); 
VarIn(2,1)=Temp(i); 
VarIn(3,1)=TempAir(i); 
VarIn(4,1)=Humid(i); 

%%%Decision taking 
 
 Prediction = Neural_Predict(VarIn ) 
 
if(Prediction > 800) 
motor=2; 
else 
motor=1; 
end 
 
Serial_Write(motor,arduino); 
 
end 
% end communication with arduino 
fclose(arduino); 
delete(arduino); 
clear arduino; 