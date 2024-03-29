# SoalShift_modul2_F06
## Soal 1
Elen mempunyai pekerjaan pada studio sebagai fotografer. Suatu hari ada seorang klien yang bernama Kusuma yang meminta untuk mengubah nama file yang memiliki ekstensi .png menjadi “[namafile]_grey.png”. Karena jumlah file yang diberikan Kusuma tidak manusiawi, maka Elen meminta bantuan kalian untuk membuat suatu program C yang dapat mengubah nama secara otomatis dan diletakkan pada direktori /home/[user]/modul2/gambar.
Catatan : Tidak boleh menggunakan crontab.

Jawab :

Dengan memanfaatkan daemon, diawali dengan fork, lalu pada child dilakukan exec untuk mkdir, yaitu membuat folder Gambar untuk menyimpan file, lalu pada parent menggunakan fungsi wait sampai child selesai, lalu dirent untuk mencari file.

[SC for Soal1](ans_soal1/soal1.c)

## Soal 2

Pada suatu hari Kusuma dicampakkan oleh Elen karena Elen dimenangkan oleh orang lain. Semua kenangan tentang Elen berada pada file bernama “elen.ku” pada direktori “hatiku”. Karena sedih berkepanjangan, tugas kalian sebagai teman Kusuma adalah membantunya untuk menghapus semua kenangan tentang Elen dengan membuat program C yang bisa mendeteksi owner dan group dan menghapus file “elen.ku” setiap 3 detik dengan syarat ketika owner dan grupnya menjadi “www-data”. Ternyata kamu memiliki kendala karena permission pada file “elen.ku”. Jadi, ubahlah permissionnya menjadi 777. Setelah kenangan tentang Elen terhapus, maka Kusuma bisa move on.

Catatan: Tidak boleh menggunakan crontab

Jawab :

Dengan menggunakan stat, dilakukan pengecekan apabila terdapat file elen.ku , lalu menggunakan pwd.h dan grp.h untuk memanggil owner dan group dari file elen.ku, lalu dicek apabila owner dan group nya adalah "www-data", jika iya, diubah permissionnya menjadi 777 (membolehkan akses ke semua, owner, group, dan other).

[SC for Soal2](ans_soal2/soal2.c)

## Soal 3

Diberikan file campur2.zip. Di dalam file tersebut terdapat folder “campur2”. 

Buatlah program C yang dapat :

1. mengekstrak file zip tersebut.
2. menyimpan daftar file dari folder “campur2” yang memiliki ekstensi .txt ke dalam file daftar.txt. 

Catatan:  

- Gunakan fork dan exec.
- Gunakan minimal 3 proses yang diakhiri dengan exec.
- Gunakan pipe
- Pastikan file daftar.txt dapat diakses dari text editor

Jawab : 

Dengan memanfaatkan fungsi pipe(), membuat  perintah ls, dan grep menjadi pipe seperti halnya pada shell script.

[SC for Soal3](ans_soal3/soal3.c)

## Soal 4

Dalam direktori /home/[user]/Documents/makanan terdapat file makan_enak.txt yang berisikan daftar makanan terkenal di Surabaya. Elen sedang melakukan diet dan seringkali tergiur untuk membaca isi makan_enak.txt karena ngidam makanan enak. Sebagai teman yang baik, Anda membantu Elen dengan membuat program C yang berjalan setiap 5 detik untuk memeriksa apakah file makan_enak.txt pernah dibuka setidaknya 30 detik yang lalu (rentang 0 - 30 detik).
Jika file itu pernah dibuka, program Anda akan membuat 1 file makan_sehat#.txt di direktori /home/[user]/Documents/makanan dengan '#' berisi bilangan bulat dari 1 sampai tak hingga untuk mengingatkan Elen agar berdiet.

Contoh:

File makan_enak.txt terakhir dibuka pada detik ke-1
Pada detik ke-10 terdapat file makan_sehat1.txt dan makan_sehat2.txt

Catatan: 

- dilarang menggunakan crontab
- Contoh nama file : makan_sehat1.txt, makan_sehat2.txt, dst

Jawab :

Gunakan daemon, lalu di dalamnya manfaatkan stat, dan tipe data time, diakhiri dengan membuat file baru dengan memanfaatkan fopen().

[SC for Soal4](ans_soal4/soal4.c)

## Soal 5

Kerjakan poin a dan b di bawah:

1. Buatlah program c untuk mencatat log setiap menit dari file log pada syslog ke /home/[user]/log/[dd:MM:yyyy-hh:mm]/log#.log

Ket:

- Per 30 menit membuat folder /[dd:MM:yyyy-hh:mm]
- Per menit memasukkan log#.log ke dalam folder tersebut
- ‘#’ : increment per menit. Mulai dari 1
2. Buatlah program c untuk menghentikan program di atas.

NB: Dilarang menggunakan crontab dan tidak memakai argumen ketika menjalankan program.

Jawab :

Manfaatkan read file menggunakan fopen(), pada 1 bagian untuk read, dan 1 bagian lainnya untuk write. Gunakan tipe data time untuk membuat nama folder berdasarkan waktu saat itu.

[SC for Soal5](ans_soal5/soal5.c)
