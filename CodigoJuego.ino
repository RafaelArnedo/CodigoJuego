// Variable Global
int botella=0;  // Si botella=1, no botella=0
int pinInterrupt=1;  // Pin de interrupcion
int vdb=0;  //Para verificar el estado la tapa

void estado_botella(){
       botella=1; //Si el valor de vdb=0 significa que baja la tapa
      }
void estado_botella2(){
      vdb=1;            //Si el valor de vdb=0 significa que no sube la tapa
  }
      
void setup() {
    attachInterrupt(digitalPinToInterrupt(pinInterrupt), estado_botella, RISING); // Si hay un flanco de subida existe una botella por tanto botella=1
    attachInterrupt(digitalPinToInterrupt(pinInterrupt), estado_botella2, FALLING); // Si hay un falnco de bajada la tapa volvio a su posicion inicial por tanto vdb=1

     
}
int medir_botella(){
  //Se espera 2 segundos para verificar el estado de la tapa
      unsigned long t=millis();   
      unsigned long t2=0;
      while((t2-t)<200){
            t2=millis();
        }
   //Si luego de 2 segundos
     if(botella==1 && vdb==1) //Todo correcto baja y sube la tapa
          return 1;
     if(botella==0 && vdb==0) // Todo correcto no hay tapa
           return 0;
     if(botella==1 && vdb==0) //Baja la tapa pero no sube
          return 2;
  
    }

void loop(){
       
  
  
  
  }
