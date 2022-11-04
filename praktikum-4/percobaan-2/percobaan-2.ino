#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;
float ax_offset, ay_offset, az_offset;
float gx_offset, gy_offset, gz_offset;
void calibrate_mpu();

void setup(void) {
  Serial.begin(115200);
  // Inisialisasi sensor
  while (!mpu.begin()) {
    Serial.println("Tidak dapat menemukan MPU-6050!");
  }
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  Serial.print("Rentang accelerometer diset ke ");
  switch (mpu.getAccelerometerRange()) {
  case MPU6050_RANGE_2_G:
  Serial.println("+-2G");
  break;
  case MPU6050_RANGE_4_G:
  Serial.println("+-4G");
  break;
  case MPU6050_RANGE_8_G:
  Serial.println("+-8G");
  break;
  case MPU6050_RANGE_16_G:
  Serial.println("+-16G");
  break;
  }
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  Serial.print("Rentang gyroscope diset ke ");
  switch (mpu.getGyroRange()) {
  case MPU6050_RANGE_250_DEG:
  Serial.println("+- 250 deg/s");
  break;
  case MPU6050_RANGE_500_DEG:
  Serial.println("+- 500 deg/s");
  break;
  case MPU6050_RANGE_1000_DEG:
  Serial.println("+- 1000 deg/s");
  break;
  case MPU6050_RANGE_2000_DEG:
  Serial.println("+- 2000 deg/s");
  break;
  }
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  Serial.print("Filter bandwidth diset ke ");
  switch (mpu.getFilterBandwidth()) {
  case MPU6050_BAND_260_HZ:
  Serial.println("260 Hz");
  break;
  case MPU6050_BAND_184_HZ:
  Serial.println("184 Hz");
  break;
  case MPU6050_BAND_94_HZ:
  Serial.println("94 Hz");
  break;
  case MPU6050_BAND_44_HZ:
  Serial.println("44 Hz");
  break;
  case MPU6050_BAND_21_HZ:
  Serial.println("21 Hz");
  break;
  case MPU6050_BAND_10_HZ:
  Serial.println("10 Hz");
  break;
  case MPU6050_BAND_5_HZ:
  Serial.println("5 Hz");
  break;
  }
  // Kalibrasi sensor (harap diamkan sensor)
  calibrate_mpu();
  Serial.println("");
  delay(5000);
}

void loop() {
  // Ambil hasil bacaan dari sensor
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  // Tampilkan hasil bacaan
  Serial.print("Percepatan aX: ");
  Serial.print(a.acceleration.x);
  Serial.print(", aY: ");
  Serial.print(a.acceleration.y);
  Serial.print(", aZ: ");
  Serial.print(a.acceleration.z);
  Serial.println(" m/s^2");
  Serial.print("Rotasi gX: ");
  Serial.print(g.gyro.x - gx_offset);
  Serial.print(", gY: ");
  Serial.print(g.gyro.y - gy_offset);
  Serial.print(", gZ: ");
  Serial.print(g.gyro.z - gz_offset);
  Serial.println(" rad/s"); 
  Serial.print("Temperatur: ");
  Serial.print(temp.temperature);
  Serial.println(" degC");  
  Serial.println("");
  delay(500);
  } 
  
  void calibrate_mpu() {
    Serial.println("\nLetakkan MPU-6050 di bidang datar yang stabil!");
    for (int i = 7; i > 0; i--) {
    Serial.println((String) "Kalibrasi dalam " + i + " detik...");
    delay(1000);
  } 
  Serial.println("Menjalankan proses kalibrasi (harap tunggu)!");
  int total_loop = 3000;
  float total_ax = 0, total_ay = 0, total_az = 0;
  float total_gx = 0, total_gy = 0, total_gz = 0; 
  for (int i = 0; i < total_loop; i++) {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);  
  total_ax += a.acceleration.x;
  total_ay += a.acceleration.y;
  total_az += a.acceleration.z; 
  total_gx += g.gyro.x;
  total_gy += g.gyro.y;
  total_gz += g.gyro.z;
  } 
  // Rata-rata hasil keseluruhan untuk menghasilkan offset
  ax_offset = total_ax / total_loop;
  ay_offset = total_ay / total_loop;
  // az_offset = total_az / total_loop - 9.8;  
  az_offset = total_az / total_loop - 9.8;  
  gx_offset = total_gx / total_loop;
  gy_offset = total_gy / total_loop;
  gz_offset = total_gz / total_loop;  
  // Tampilkan hasil offset
  Serial.print("\nOffset aX: ");
  Serial.print(ax_offset);
  Serial.print(", aY: ");
  Serial.print(ay_offset);
  Serial.print(", aZ: ");
  Serial.print(az_offset);
  Serial.println(" m/s^2"); 
  Serial.print("Offset gX: ");
  Serial.print(gx_offset);
  Serial.print(", gY: ");
  Serial.print(gy_offset);
  Serial.print(", gZ: ");
  Serial.print(gz_offset);
  Serial.println(" rad/s");
 }