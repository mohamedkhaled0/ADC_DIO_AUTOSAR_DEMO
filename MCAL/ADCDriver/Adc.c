/******************************************************

*    
              - Adc.c                                              
*   
              - Created: 10 / 5 / 2022                
* 
              - Author : Mohamed Khaled              
* 
              - Note : 
*                                                       
******************** Code ****************************/   



void Adc_StartGroupConversion(Adc_GroupType Group) {
    
    if (Group == 1 ){
        
        
        /* 
        
         do steps to start conversion on the target 
        
        */ 
        
        
        
    }
    
    
} 



Std_ReturnType Adc_ReadGroup(Adc_GroupType Group,const Adc_ValueGroupType* DataBufferPtr) {
     
      int AdcVal ; 
     
     if (Group == 1 ){
      
      AdcVal = /*  register or private fun with return tpe */ 
      *DataBufferPtr = AdcVal ;    
        
    }
    
    
    
}











