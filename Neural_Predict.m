%Prediction function using Neural Network  

function [Predict] = Neural_Predict( VarIn ) 
I=xlsread('TrainingData.xlsx'); 
load('Exp1.mat');%loading pre-calculated weights 
q1=mean(I(1,:)); 
a = 1.7159; 
b = 2/3 ; 
%normalize the variables and store it in a temporary variable 
Temp_Var(1,1) = (VarIn(1,1)-mean(I(1,:)))/20 ; 
Temp_Var(2,1) = (VarIn(2,1)-mean(I(2,:)))/20; 
Temp_Var(3,1) = (VarIn(3,1)-mean(I(3,:)))/20; 
Temp_Var(4,1) = (VarIn(4,1)-mean(I(4,:)))/20; 
y0=[1;Temp_Var(:,1)]; 
 
%Predicting the future values 
 
 v1=W1*y0; 
 y1= a*tanh(b*v1) ; 
 
 y1db=[1;y1]; 
 v2=W2*y1db; 
 y2=1.2*v2; 
 
 Out=(y2*20)+q1; 
 Predict=Out; 
end