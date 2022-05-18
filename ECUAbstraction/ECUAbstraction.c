

/******************************************************

*    
              - ECUAbstraction.c                                              
*   
              - Created: 16 / 5 / 2022                
* 
              - Author : Mohamed Khaled              
* 
              - Note : 
*                                                       
******************** code ****************************/
 
 /*include RTE Apllication Header*/ 
 #include "Rte_TempHBridgeSWC.h"
 
 /* code for runnable - Read temp */  
void ReadTemperature_Function (){ 

 unsigned int readVal ; 
 
/* Trigger adc conversion and read the value from sensor*/ 
Adc_StartGroupConversion(1);  
Adc_ReadGroup(1,&readVal); 


/* convrt digital output to corssponding voltage value */ 
/* assume 10-bit adc 2.5 referance voltage*/ 

float voltOutput = (2.5/1024) * readVal; 

/* convert voltage to temp val assume 35deg is output .35V  */   

float temperature = voltOutput * 100 ; 


/* pass the temperature val to rte write  */  
/*this rte layer is generated from tool*/
  Rte_Write_PP_Temperature_I_Temperature(temperature);
    
    
    
}  



/* code for runnable - start motor service */  
void StartMotor(unsigned char FanSpeed){
    if (FanSpeed < 50){
        /* trigger cooling fan with half speed */
        /* Hibridge setting to 0 1  */ 
        Dio_WriteChannel(10,STD_LOW);
        Dio_WriteChannel(11,STD_HIGH);
        
    } 
    else { 
    /* trigger cooling fan with half speed */
    /* Hibridge setting to 1 1  */ 
        Dio_WriteChannel(10,STD_HIGH);
        Dio_WriteChannel(11,STD_HIGH);
        
    }
} 


/* code for runnable - stop motor service */ 

void StopMotor(){
    
    /* stop motor */ 
    /* Hibridge setting to 0 0  */ 
    Dio_WriteChannel(10,STD_LOW);
    Dio_WriteChannel(11,STD_LOW);
}




