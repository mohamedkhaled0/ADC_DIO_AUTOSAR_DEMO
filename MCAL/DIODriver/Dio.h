/******************************************************

*    
              - Dio.h                                              
*   
              - Created: 9 / 5 / 2022                
* 
              - Author : Mohamed Khaled              
* 
              - Note : 
*                                                       
******************** Gaurd ****************************/ 



#ifndef DIO_H 
#define DIO_H 

typedef unsigned int Dio_ChannelType ;  

typedef unsigned char Dio_LevelType ; 
#define STD_HIGH 1 
#define STD_LOW  0 




/*  
  Returns the value of the specified DIO channel 
  parmeters : ChannelId  
  return : voltage level 
*/ 
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);



/*
Service to set a level of a channel.
parmeters : ChannelId , Level
Return : void 
*/
void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level);
 


#endif