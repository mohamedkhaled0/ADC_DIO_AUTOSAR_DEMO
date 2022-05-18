

/******************************************************

*    
              - AplicationSWC.c                                              
*   
              - Created: 18 / 5 / 2022                
* 
              - Author : Mohamed Khaled              
* 
              - Note : 
*                                                       
******************** code ****************************/

/*include RTE Apllication Header*/ 
#include "Rte_TemControlSWC.h"

void TemperatureControl(){
    
  float temperature ; 
  /* read the data from Rte layer */  
  /* Rte FUN + Port Interface + name of the variable to call the Fun from Rte */ 
  Rte_Read_RP_Temperature_Temperature(&temperature);  
  
  /*    Condition     */ 
  if (temperature >= 50 && temperature < 75 ){
      
      /*Run motor at half speed */ 
      Rte_Call_RP_StartMotor_StartMotor(25); 
      
  }else if (temperature >= 75){ 
  
       /*Run motor at full speed */ 
      Rte_Call_RP_StartMotor_StartMotor(100); 
  } 
  else if (temperature < 50){ 
  
     /*stop motor */  
     Rte_Call_RP_StopMotor_StopMotor(); 
      
  }else {
      
      //Do Nothing 
  }
  
    
}

