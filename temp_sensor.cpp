#include <Arduino.h>           // Обов'язково для PlatformIO!
#include <SPI.h>               // Виправлення для бібліотеки Adafruit BusIO
#include <Wire.h>
#include <Adafruit_MLX90614.h>

// Створюємо об'єкт датчика
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup() {
  // Запускаємо зв'язок з ПК
  Serial.begin(115200);
  
  // Даємо трохи часу на запуск Монітора порту
  delay(1000);
  Serial.println("Тестування датчика MLX90614...");

  // Ініціалізація датчика
  // За замовчуванням бібліотека використовує стандартні піни I2C (21 SDA, 22 SCL)
  if (!mlx.begin()) {
    Serial.println("Помилка! Датчик MLX90614 не знайдено. Перевірте з'єднання.");
    while (1); // Зупиняємо програму, якщо датчик не підключено
  }
  Serial.println("Датчик успішно підключено!");
}

void loop() {
  // Читаємо температуру навколишнього середовища (температура самого чипа)
  Serial.print("Навколишня температура: ");
  Serial.print(mlx.readAmbientTempC());
  Serial.println(" °C");

  // Читаємо температуру об'єкта перед датчиком
  Serial.print("Температура об'єкта: ");
  Serial.print(mlx.readObjectTempC());
  Serial.println(" °C");

  Serial.println("-------------------------");
  delay(1000); // Оновлюємо дані кожну секунду
}