# Arduino ve NeoPixel LED ile Duvar Saati Projesi

Bu projede, Arduino ve NeoPixel LED şerit kullanarak bir dijital duvar saati yaptım. Saati göstermek için her saat, dakika ve saniyeyi temsil eden LED'ler, duvar saatinin bir parçası olarak düzenlendi. Projede 3D modeller de kullanıldı; gerekli modelleri Thingiverse'den indirebilirsiniz.

## Proje Özeti

Arduino'nun gücünü ve NeoPixel LED'lerin renk seçeneklerini kullanarak, hem işlevsel hem de görsel olarak şık bir duvar saati tasarladım. Her LED, saati renkli bir biçimde gösteriyor ve bu sayede zamanın geçişini gözle görülür şekilde deneyimleyebiliyorsunuz. Kodlar, Arduino C dilinde yazıldı.

### Kullanılan Malzemeler

- **Arduino**: Saatin beyni olarak tüm LED'lerin kontrolünü sağlar.
- **NeoPixel LED Şerit**: Saati göstermek için kullanılan renkli LED'ler.
- **3D Modeller**: Saat kasası ve düzeni için Thingiverse'den temin edilebilir modeller.
- **Güç Kaynağı**: NeoPixel LED'leri çalıştırmak için yeterli güç sağlanmalıdır (örn. 5V 2A).

### Özellikler

- **Renkli Saat Gösterimi**: Her saat, dakika ve saniye için farklı renklerde LED'ler yanar.
- **Yumuşak Geçişler**: Dakika ve saniyelerde LED'ler yumuşak geçişlerle değişir.
- **Kişiselleştirilebilir Tasarım**: Saat kasasını ve LED düzenini kendi ihtiyaçlarınıza göre Thingiverse'den bulacağınız 3D modellerle uyarlayabilirsiniz.

### Kurulum ve Yapılandırma

1. **Arduino'ya Kod Yükleme**: 
   - [Buraya kod dosyanızı yükleyin veya bağlantıyı ekleyin]
   
2. **3D Modellerin Baskısı**: 
   - Saatin montajını yapmak için gerekli 3D modelleri Thingiverse.com üzerinden indirebilirsiniz. (Bağlantıyı ekleyin veya belirli bir model adı verin.)

3. **Montaj**:
   - NeoPixel LED şeridi, 3D baskı ile oluşturulan saat kasasına yerleştirin.
   - Arduino'yu ve LED şeridi doğru bir şekilde bağlayın (Dijital pinler ve güç bağlantıları).

4. **Güç Sağlama**: Güç kaynağını Arduino ve LED şeride bağlayarak sistemi çalıştırın.

### Kod Açıklaması

- **Arduino C ile Yazılmış Kod**: LED'lerin saat, dakika ve saniyeyi gösterecek şekilde yanmasını sağlamak için kodlar Arduino C ile yazıldı. 
- **NeoPixel Kütüphanesi**: NeoPixel LED'lerin renklerini ve parlaklıklarını kontrol etmek için Adafruit'in NeoPixel kütüphanesi kullanıldı.

### Görseller

Aşağıda proje sırasında çekilen görseller bulunmaktadır:

#### Montaj Görüntüsü
[![Montaj Görüntüsü](path/to/assembly_image.jpg)](https://github.com/bilalorhanlr/Wall_Clock/blob/main/clock1.jpeg)

#### Çalışır Durumda LED Gösterimi
[![LED Gösterimi](path/to/led_display_image.jpg)](https://github.com/bilalorhanlr/Wall_Clock/blob/main/clock4.jpeg)

### Gelecekteki Geliştirmeler

- **WiFi veya Bluetooth ile Senkronizasyon**: Saatin otomatik olarak güncellenmesi için bir WiFi modülü ile senkronizasyon eklenebilir.
- **Daha Fazla Renk Seçeneği**: Kullanıcıya farklı renk temaları seçme imkanı sunulabilir.
- **Sesli Bildirim**: Saat başında sesli bildirim eklenebilir.

---

Bu duvar saati projesi, Arduino ve NeoPixel LED ile hem görsel açıdan çekici hem de işlevsel bir çalışma olarak tasarlanmıştır. Thingiverse'den alacağınız 3D modeller ve bu rehberle saatinizi kolayca oluşturabilirsiniz!
