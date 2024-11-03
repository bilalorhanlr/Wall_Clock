#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#endif

#include <DS3231_Simple.h>
DS3231_Simple Saat;

DateTime TarihVeSaat;

#define LEDSAAT_PIN    6
#define LEDAYDINLATMA_PIN    5

#define LEDSAAT_SAYISI 69
#define LEDAYDINLATMA_SAYISI 12

uint32_t dakikaRengi = 0x800000; // saf kırmızı
uint32_t saatRengi = 0x008000;   // saf yeşil

int saatYüzeyParlakligi = 0;

Adafruit_NeoPixel stripSaat(LEDSAAT_SAYISI, LEDSAAT_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel stripAydinlatma(LEDAYDINLATMA_SAYISI, LEDAYDINLATMA_PIN, NEO_GRB + NEO_KHZ800);

const int numuneSayisi = 12;

int numuneler[numuneSayisi];
int okumaIndeksi = 0;
long toplam = 0;
long ortalama = 0;

void setup() {
  Serial.begin(9600);
  Saat.begin();

  stripSaat.begin();           
  stripSaat.show();            
  stripSaat.setBrightness(100);

  stripAydinlatma.begin();           
  stripAydinlatma.show();            
  stripAydinlatma.setBrightness(50); 

  for (int buOkuma = 0; buOkuma < numuneSayisi; buOkuma++) {
    numuneler[buOkuma] = 0;
  }
}

void loop() {
  zamanOku();
  zamaniGoster();

  numuneler[okumaIndeksi] = analogRead(A0); 
  Serial.print("Işık sensörü değeri dizilere eklendi = ");
  Serial.println(numuneler[okumaIndeksi]);
  okumaIndeksi = okumaIndeksi + 1;

  if (okumaIndeksi >= numuneSayisi) {
    okumaIndeksi = 0;
  }

  int parlaklikToplami = 0;
  for (int i = 0; i < numuneSayisi; i++) {
    parlaklikToplami += numuneler[i];
  }
  Serial.print("Parlaklık dizisinin toplamı = ");
  Serial.println(parlaklikToplami);

  int isikSensorDegeri = parlaklikToplami / numuneSayisi;
  Serial.print("Ortalama ışık sensörü değeri = ");
  Serial.println(isikSensorDegeri);

  saatYüzeyParlakligi = map(isikSensorDegeri, 50, 1000, 200, 1);
  stripSaat.setBrightness(saatYüzeyParlakligi);
  Serial.print("Eşlenmiş parlaklık değeri = ");
  Serial.println(saatYüzeyParlakligi);
  
  stripSaat.show();

  stripAydinlatma.fill(16777215, 0, LEDAYDINLATMA_SAYISI);
  stripAydinlatma.show();

  delay(5000);   
}

void zamanOku(){
  TarihVeSaat = Saat.read();
  
  Serial.println("");
  Serial.print("Zaman: ");   Serial.print(TarihVeSaat.Hour);
  Serial.print(":"); Serial.print(TarihVeSaat.Minute);
  Serial.print(":"); Serial.println(TarihVeSaat.Second);
  Serial.print("Tarih: 20");   Serial.print(TarihVeSaat.Year);
  Serial.print(":");  Serial.print(TarihVeSaat.Month);
  Serial.print(":");    Serial.println(TarihVeSaat.Day);
}

void zamaniGoster(){

  stripSaat.clear();

  int ilkDakikaRakami = TarihVeSaat.Minute % 10; 
  rakamGoster(ilkDakikaRakami, 0, dakikaRengi);

  int ikinciDakikaRakami = floor(TarihVeSaat.Minute / 10); 
  rakamGoster(ikinciDakikaRakami, 21, dakikaRengi);

  int ilkSaatRakami = TarihVeSaat.Hour;
  if (ilkSaatRakami > 12) {
    ilkSaatRakami -= 12;
  }
  ilkSaatRakami %= 10;
  rakamGoster(ilkSaatRakami, 42, saatRengi);

  int ikinciSaatRakami = TarihVeSaat.Hour;
  if (ikinciSaatRakami > 12) {
    ikinciSaatRakami -= 12;
  }
  if (ikinciSaatRakami > 9) {
    stripSaat.fill(saatRengi, 48, 6);
  }
}

void rakamGoster(int rakam, int offset, uint32_t renk){
    switch (rakam) {
    case 0:
      rakamSifir(offset, renk);
      break;
    case 1:
      rakamBir(offset, renk);
      break;
    case 2:
      rakamIki(offset, renk);
      break;
    case 3:
      rakamUc(offset, renk);
      break;
    case 4:
      rakamDort(offset, renk);
      break;
    case 5:
      rakamBes(offset, renk);
      break;
    case 6:
      rakamAlti(offset, renk);
      break;
    case 7:
      rakamYedi(offset, renk);
      break;
    case 8:
      rakamSekiz(offset, renk);
      break;
    case 9:
      rakamDokuz(offset, renk);
      break;
    default:
      break;
  }
}
