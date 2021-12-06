/*
Datos de desarrollador:
Nombre:Carlos Vergara Andraes 
Correo:carlos.vergara.andraes@gmail.com 
Fecha creaci�n:Julio-2016

Descripci�n de librer�a:

Libreria para C.I 74HC595 entrada serial 8 bit y salida paralela
(8-bit serial-in, serial or parallel-out shift register with outputlatches; 3-state)

1.-Acerca de esta librer�a y c�mo usarla: 

Fue creada para mostrar n�meros del 0 al 9 en display de 7 segmentos c�todo com�n.
Para utilizarla se debe declarar 3 pines del microcontrolador, como ejemplo ver punto 2. 
Para llamar este procedimiento solo basta con pasar un valor de 0 a 9 seg�n deseamos 
visualizar en display de 7 segmentos, a modo de prueba mostraremos el valor "0" 
en display de 7 segmentos, para esto debemos escribir en nuestro programa: LIB74HC595(0);,
y asi sucesivamente para pasar otros valores (LIB74HC595(3);LIB74HC595(7,);, ect).

2.-Declaraci�n de pines de E/S PIC16F628A:

Descripci�n de pines definidos en microcontrolador y su simil de 74HC595.

PIC16F628A        |     C.I 74HC595 
SPI74HC595_DATA         DS          
SPI74HC595_LATCH        ST_CP
SPI74HC595_CLOCK        SH_CP

Definici�n de nombres en c�digo CCS

#define SPI74HC595_LATCH  PIN_A2
#define SPI74HC595_CLOCK  PIN_A3
#define SPI74HC595_DATA   PIN_A1

3.-Para llamar a procedimiento y enviar numero de 0 a 9 a C.I 74HC595
LIB74HC595(0);
LIB74HC595(1);
LIB74HC595(2);
LIB74HC595(3);
LIB74HC595(4);
LIB74HC595(5);
LIB74HC595(6);
LIB74HC595(7);
LIB74HC595(8);
LIB74HC595(9);

4.-Array de representaci�n de n�meros 0-9
byte const segDisplay[2][8]={{ 1,0,1,1,1,1,1,1},{0,0,0,0,0,1,1,0}};
*/
void LIB74HC595(int8 num){
   int8 i;
   int8 j;
   output_low(SPI74HC595_CLOCK);
   output_low(SPI74HC595_LATCH);
      for (i=num;i<=num ; i++){
         for (j=0;j<8; j++){
            if(segDisplay[i][j]==1){
               output_high(SPI74HC595_DATA); 
            }
            else{
               output_low(SPI74HC595_DATA);
            }
            //output_bit(SPI74HC595_DATA,segDisplay[i][j]);
            //valor=segDisplay[i][j];
            output_high(SPI74HC595_CLOCK);
            output_low(SPI74HC595_CLOCK);
         }
         output_high(SPI74HC595_LATCH);
         output_low(SPI74HC595_LATCH);
      }
 return;
}

//test1
