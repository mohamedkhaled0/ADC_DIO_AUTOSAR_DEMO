/******************************************************

*    
              - Dio.c                                              
*   
              - Created: 9 / 5 / 2022                
* 
              - Author : Mohamed Khaled              
* 
              - Note : 
*                                                       
******************** Code ****************************/  

#include "Dio.h" 


/*  
  Returns the value of the specified DIO channel 
  parmeters : ChannelId  
  return : voltage level 
*/ 
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId){ 
    
    unsigned int ReadVal ; 
 
   // asume channel 10 maped to PORTP pin 0  
   switch (ChannelId) { 
   case 10 : 
     ReadVal = PORTP & (1<<0);  
     break; 
   } 

   if (ReadVal == 0x00) return STD_LOW ; 
   else return STD_HIGH;  
   
}  



/*
Service to set a level of a channel.
parmeters : ChannelId , Level
Return : void 
*/
void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level){
    
    // asume channel 10 maped to PORTP pin 0 
   switch (ChannelId) { 
   case 10 : 
      switch(level){
          case STD_HIGH :
           PORTP |= (1<< 0);          
           break; 
          case STD_LOW :  
           PORTP &= ~(1<<0);          
      }
     break;  
   }  
    
    
}




