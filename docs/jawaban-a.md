# Bagian A

## 1. Analisis Kondisi  
Done at 10:01 WIB, 20th January 2026

## 2. Source Control Management  
### a. Commands dalam Git :  
1. git init : Untuk memulai _Git repository_ baru di direktori yang sama.
2. git clone : Menciptakan sebuah salinan dari sebuah _repository_.
3. git status : Menunjukkan status dari direktori pengerjaan kita dan _staging area_.
4. git add : Menambahkan perubahan dari direktori pengerjaan ke _staging area_.
5. git commit : Mencatat perubahan _staging area_ di repositori dengan pesan tambahan.
6. git log : Melihatkan riwayat _commit_ dari cabang sekarang.
7. git branch : Melihatkan seluruh cabang yang ada di cabang sekarang.
8. git checkout : Pindah ke suatu cabang yang berbeda.
9. git merge : Menggabungkan sebuah cabang ke cabang yang sekarang.
10. git pull : Mengambil perubahan dari repositori dan menggabungkannya dengan cabang sekarang.
11. git push : Mengunggah _commit_ ke repositori.
12. git rm : Menghapus _file_ dan _index_ dari direktori pengerjaan.

**Source** : [geeksforgeeks.org](https://www.geeksforgeeks.org/git/useful-git-commands-and-basic-concepts/)

### b. _GitHub and VSCode setup_ :  
![Tangkapan layar A_2_b.png](images/A_2/A_2_b.png)

### c. _Git Education_ :  
Jumlah file tangkapan layar terlalu banyak, silahkan lihat hasil tangkapan layar [disini](images/A_2/A_2_c/)

### d. _Git SSH Security_ :  
Berikut adalah tangkapan layar untuk pengerjaan subsoal ini :  
![Tangkapan layar A_2_d.png](images/A_2/A_2_d.png)

### e. _Branches for A and B parts_ :
Berikut adalah tangkapan layar untuk pengerjaan subsoal ini (20 Januari 2026) :
![Tangkapan layar A_2_e.png](images/A_2/A_2_e.png)

## 3. Pengenalan Ground Control Station :  
### a. Instalasi Mission Planner :
![Tangkapan layar A_3_a.png](images/A_3/A_3_a.png)

### b. Fitur Utama Mission Planner :  
1. _Flight DATA Screen Overview_ : Menampilkan _Heads-up Display_ (HUD) dari _Mission Planner Ground Station_ serta menampilkan data telemetri yang dikirim oleh ArduPilot.
2. _Flight PLAN Screen_ : Membuat sebuah misi yang akan dilaksanakan oleh UAV. Fitur ini dapat menciptakan secara otomatis beberapa hal seperti misi survei, _circular waypoints_, _simple grid_.
3. _SETUP Screen_ : Fitur untuk mengatur dan mengkonfigurasi autopilot untuk UAV yang akan digunakan.
4. _CONFIGuration and Tuning Screens_ : Fitur untuk mengatur/menyetel parameter kontrol sehingga UAV dapat bergerak sebagaimana mestinya.
5. _SIMULATION Screen_ : Digunakan untuk melakukan simulasi secara virtual di Mission Planner tanpa harus meresikokan UAV untuk diuji coba.

**Source** : [ardupilot.org](https://ardupilot.org/planner/docs/mission-planner-features.html#)

### c. Pemetaan dengan Mission Planner :  
Berikut adalah setelan yang digunakanan untuk misi survei "Lapangan Bola Basket ITB" :  
![Tangkapan layar A_3_c.png](images/A_3/A_3_c.png)  
File ._waypoints_ ada [di sini](lampiran/Basketball_Survey.waypoints)

**Source** : [youtube.com](https://www.youtube.com/watch?v=i0oL5wek-c4)

## 4. Development Environment  
### a. Instalasi _Packages_ :  
Berikut adalah tangkapan layar bukti instalasi packages dalam WSL :
![Tangkapan layar A_2_e.png](images/A_4/1.png)  
![Tangkapan layar A_2_e.png](images/A_4/2.png)  

## b. ROS2 Humble Installation :
Berikut adalah tangkapan layar dari 2 terminal yang menjalankan sistem talkel-listener sederhana :  
![Tangkapan layar A_2_e.png](images/A_4/3.png)  

## 5. Dasar-Dasar UAV  
### a. Perbedaan VTOL, HTOL, dan Hybrid :
- VTOL :  
 1. Terbang dengan menggunakan gaya angkat vertikal dari rotor.
 2. Melakukan gerak horizontal dengan memiringkan orientasi UAV ke arah yang diinginkan.
 3. Dapat diluncurkan dimana saja dan memiliki manuverabilitas yang unggul.
 4. Kapasitas payload relatif lebih kecil dibandingkan tipe UAV lainnya.
 5. Biasa digunakan untuk survei, mapping, pertanian, pengantar barang ringan, dll.  
**Source** : [pilotinstitute.com](https://pilotinstitute.com/everything-about-vtol-drones/)  
- HTOL :  
 1. Terbang dengan menggunakan gaya angkat dari sayap/_airfoil_.
 2. Melakukan gerak horizontal menggunakan _thrust_.
 3. Harus melakukan _take-off_ dan _landing_ di sebuah _runway_.
 4. Biasa digunakan sebagai transportasi komersial.  
**Source** : [wikipedia.com](https://en.wikipedia.org/wiki/CTOL)  
- Hybrid :
 1. Melakukan vertikal _take-off_ dan _landing_ serta terbang horizontal menggunakan mekanisme HTOL/_fixed wing_.
 2. Memiliki jangkauan jarak yang lebih luas daripada VTOL dan manuverabilitas yang lebih baik daripada HTOL.
 3. Biasa digunakan untuk survei, agrikultur, logistik, dll.
**Source** : [unmannedsystemstechnology.com](https://www.unmannedsystemstechnology.com/expo/hybrid-vtol-fixed-wing-uav-manufacturers/)

### b. Istilah dalam mekanisme UAV :
- Gerak _roll_ : Gerak berputar di _longitudinal axis_ UAV.
- Gerak _yaw_ : Gerak berputar di _vertical axis_ UAV.
- Gerak _pitch_ : Gerak berputar di _lateral axis_ UAV. 
- _Air speed_ : Kecepatan pesawat relatif terhadap udara sekitarnya.
- _Ground speed_ : Kecepatan horizontal UAV relatif terhadap permukaan bumi.
- HDOP : Sebuah metrik yang digunakan untuk mengukur akurasi dari sistem GPS dan DGPS.
- RSSI : Indikasi yang mengukur seberapa kuat sinyal radio yang diterima.  
Relasi _air speed_ dan _ground speed_ : _Ground speed_ adalah jumlah vektor dari _true airspeed_ dan _wind speed_.  
**Source** : [Gerak UAV](https://en.wikipedia.org/wiki/Aircraft_principal_axes), [_Air Speed_ dan _Ground Speed_](https://en.wikipedia.org/wiki/Ground_speed), [HDOP](https://en.wikipedia.org/wiki/Dilution_of_precision), [RSSI](https://wiki.teltonika-networks.com/view/RSSI)

### c. Komponen-Komponen UAV :
1. _Airframe_  
Struktur dari sebuah UAV. Desain airframe dipengaruhi oleh _Design Requirements & Objectives_ (DRO) dari UAV itu sendiri.  
2. _Propulsion System_  
Sistem yang akan menghasilkan _thrust_ sehingga UAV dapat terbang. Konfigurasi dari sistem propulsi bergantung pada tipe dari UAV itu sendiri (VTOL, HTOL, atau Hybrid).  
3. _Power System_  
Terdiri dari baterai dan monitor baterai. Baterai yang umum digunakan untuk UAV adalah baterai Lithium polimer.  
4. _Flight Control System_  
Merupakan otak dari UAV. Sistem ini terdiri dari komponen elektronik seperti ESC, IMU, dan mikrokontroler.  
5. _Communication System_  
Sistem yang memungkinkan UAV untuk mentransmisikan dan menerima data dengan _Ground Control Station_.  

Berikut adalah diagram hubungan antarkomponen UAV di atas :  
![Diagram hubungan antarkomponen UAV](images/A_5/A_5_c.png)

**Source** : [Publikasi](https://www.researchgate.net/publication/342823335_Air-Ground_Integrated_Mobile_Edge_Networks_A_Survey)

### d. Publikasi Ilmiah UAV :  
Topik : [_UAV Path Planning Based on Improved A*and DWA Algorithms_](https://onlinelibrary.wiley.com/doi/epdf/10.1155/2021/4511252)  
Artikel ini membahas seberapa efektif penggunaan algoritma A* dan DWA dalam UAV _path planning_. _Path planning_ dibagi menjadi _path planning_ global dan _path planning_ local. _Path planning_ global memanfaatkan peta lingkungan dengan hambatan yang diketahui dan menggunakan algoritma A*. _Path planning_ lokal memanfaatkan peta lingkungan dengan hambatan yang tidak diketahui dan menggunakan algoritma DWA. Kedua algoritma ini akan digunakan untuk melakukan _path planning_ dan membandingkan hasilnya dengan hasil yang diperoleh hanya dengan algoritma DWA.  
Improvisasi pada algoritma A* dilakukan dengan meminimalisasi sudut besar (di titik belok) dan menetapkan jarak aman UAV dengan hambatan yang ada. Detail dari model ini dijelaskan lebih lanjut di dalam artikel. Algoritma DWA juga diimprovisasi dengan menambahkan _adaptive weight_ dan _safety threshold_ ke dalam algoritma tersebut. Kedua algoritma yang telah diimprovisasi kemudian digabungkan dan akan digunakan untuk mensimulasikan _path planning_ UAV.  
Artikel di atas juga menyediakan _test case_ untuk algoritma A* dan DWA. Hasil simulasi menunjukkan bahwa algoritma A* dan DWA mengurangi panjang lintasan sebesar 2,4% dibandingkan lintasan yang dihasilkan oleh algoritma DWA. Selain itu, algoritma A* dan DWA memiliki waktu terbang 35,7% lebih cepat dibandingkan waktu terbang oleh algoritma DWA.