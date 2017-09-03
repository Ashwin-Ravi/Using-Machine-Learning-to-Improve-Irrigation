function [Moist1,Temp1,Humid1,Temp2] = Serial_Read(arduino) 
 
%%Scan the serial object 
Humid1 = fscanf(arduino);%atmospheric Humidity 
Temp2 = fscanf(arduino);%air temp 
Moist1 = fscanf(arduino);%Soil Mositure 
Temp1 = fscanf(arduino);%soil temp 
 
end