int pulsador;
int piso;

int indicelinea;
int indiceLED;
//Conexiones entre el display y Arduino
int pinCLK = 3;
int pinCS = 1;
int pinDIN = 2;
char archivo_fotogramas[6][8]={
  {0x00,0x00,0x04,0x02,0x7F,0x02,0x04,0x00},//Flecha arriba
  {0x00,0x00,0x20,0x40,0xFE,0x40,0x20,0x00},//Flecha abajo
  {0x00,0x08,0x84,0x82,0xFE,0x80,0x80,0x00},//1
  {0x00,0x00,0xE4,0x92,0x92,0x8E,0x00,0x00}, //2
  {0x00,0x00,0x54,0x92,0x92,0x6C,0x00,0x00},//3
  {0x00,0x30,0x28,0x24,0xFE,0x20,0x00,0x00},//4
};


void convertir_byte_a_bits(char DATA)
{
digitalWrite(pinCS,LOW);
for(indiceLED=8;indiceLED>=1;indiceLED--)
{
digitalWrite(pinCLK,LOW);
digitalWrite(pinDIN,DATA&0x80); //Extrae cada bit del byte "DATA"
DATA = DATA<<1;
digitalWrite(pinCLK,HIGH);
}
}
void Impresion_Linea(int indicelinea, char contenidolinea)
{
digitalWrite(pinCS,LOW);
convertir_byte_a_bits(indicelinea); //Envia el valor de la linea del display
convertir_byte_a_bits(contenidolinea); //Envia el valor de los LEDs de la
// linea del display
digitalWrite(pinCS,HIGH);
}
void puesta_en_marcha()
{
Impresion_Linea(0x09, 0x00); //Tipo de decodificado ：BCD
Impresion_Linea(0x0a, 0x03); //Brillo de los LEDs
Impresion_Linea(0x0b, 0x07); //Cantidad de LEDs por linea :8 LEDs
Impresion_Linea(0x0c, 0x01); //Desconexion del display ：0 Modo normal ：1
Impresion_Linea(0x0f, 0x00); //Modo de prueba del display :1 Modo EOT
//del display :0
}


void setup(){
  pinMode(OUTPUT,4);
  pinMode(OUTPUT,5);
  pinMode(INPUT,6);
  pinMode(INPUT,7);
  pinMode(INPUT,8);
  pinMode(INPUT,9);
  pinMode(INPUT,10);
  pinMode(INPUT,11);
  
  pinMode(pinCLK,OUTPUT);
pinMode(pinCS,OUTPUT);
pinMode(pinDIN,OUTPUT);
delay(50);
puesta_en_marcha();
  
}
void loop(){
  
  

  
  
if(digitalRead(7)==HIGH){
  pulsador=1;
}
if(digitalRead(9)==HIGH){
  pulsador=2;
}
if(digitalRead(11)==HIGH){
  pulsador=3;
}
if(digitalRead(13)==HIGH){
  pulsador=4;
}
if(digitalRead(6)==HIGH){
  piso=1;
}
if(digitalRead(8)==HIGH){
  piso=2;
}
if(digitalRead(10)==HIGH){
  piso=3;
}
if(digitalRead(12)==HIGH){
  piso=4;
}
if(piso==1){
  if((pulsador==2)||(pulsador==3)||(pulsador==4)){
    
    
         
    
     digitalWrite(4,HIGH);
     
puesta_en_marcha();
  for(indicelinea=1;indicelinea<9;indicelinea++)
{
Impresion_Linea(indicelinea, archivo_fotogramas[0][indicelinea-1]);
}
delay(100); //Tiempo de espera entre fotograma y fotograma

   }
}
  
if(piso==2){
  if((pulsador==3)||(pulsador==4)){
    digitalWrite(4,HIGH);
    puesta_en_marcha();
  for(indicelinea=1;indicelinea<9;indicelinea++)
{
Impresion_Linea(indicelinea, archivo_fotogramas[0][indicelinea-1]);
}
delay(100); //Tiempo de espera entre fotograma y fotograma
    }
  
    if(pulsador==1){
    digitalWrite(5,HIGH);
    puesta_en_marcha();
  for(indicelinea=1;indicelinea<9;indicelinea++)
{
Impresion_Linea(indicelinea, archivo_fotogramas[1][indicelinea-1]);
}
delay(100); //Tiempo de espera entre fotograma y fotograma
    }
}
if(piso==3){
  if((pulsador==1)||(pulsador==2)){
    digitalWrite(5,HIGH);
    puesta_en_marcha();
  for(indicelinea=1;indicelinea<9;indicelinea++)
{
Impresion_Linea(indicelinea, archivo_fotogramas[1][indicelinea-1]);
}
delay(100); //Tiempo de espera entre fotograma y fotograma
    }
  
    if(pulsador==4){
    digitalWrite(4,HIGH);
    puesta_en_marcha();
  for(indicelinea=1;indicelinea<9;indicelinea++)
{
Impresion_Linea(indicelinea, archivo_fotogramas[0][indicelinea-1]);
}
delay(100); //Tiempo de espera entre fotograma y fotograma
    }
}
if(piso==4){
  if((pulsador==1)||(pulsador==2)||(pulsador==3)){
     digitalWrite(5,HIGH);
     puesta_en_marcha();
  for(indicelinea=1;indicelinea<9;indicelinea++)
{
Impresion_Linea(indicelinea, archivo_fotogramas[1][indicelinea-1]);
}
delay(100); //Tiempo de espera entre fotograma y fotograma
   }
}
if(pulsador==1 && piso==1){
  
puesta_en_marcha();
  for(indicelinea=1;indicelinea<9;indicelinea++)
{
Impresion_Linea(indicelinea, archivo_fotogramas[2][indicelinea-1]);
}
delay(100); //Tiempo de espera entre fotograma y fotograma
  
  
  digitalWrite(4,LOW);
digitalWrite(5,LOW);

}
if(pulsador==2 && piso==2){
  puesta_en_marcha();
  for(indicelinea=1;indicelinea<9;indicelinea++)
{
Impresion_Linea(indicelinea, archivo_fotogramas[3][indicelinea-1]);
}
delay(100); //Tiempo de espera entre fotograma y fotograma
  
digitalWrite(4,LOW);
digitalWrite(5,LOW);
}
if(pulsador==3 && piso==3){
  
  puesta_en_marcha();
  for(indicelinea=1;indicelinea<9;indicelinea++)
{
Impresion_Linea(indicelinea, archivo_fotogramas[4][indicelinea-1]);
}
delay(100); //Tiempo de espera entre fotograma y fotograma
  
digitalWrite(4,LOW);
digitalWrite(5,LOW);
}


if(pulsador==4 && piso==4){
  

  
digitalWrite(4,LOW);
digitalWrite(5,LOW);

  puesta_en_marcha();
  for(indicelinea=1;indicelinea<9;indicelinea++)
{
Impresion_Linea(indicelinea, archivo_fotogramas[5][indicelinea-1]);
}
delay(100); //Tiempo de espera entre fotograma y fotograma

}
}

