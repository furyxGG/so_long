#include "so_long.h"

void    create_win()
{
    void    *mlx_ptr; // Grafik sunucusuyla bağlantı için işaretçi
    void    *win_ptr; // Oluşturulacak pencere için işaretçi

    // 1. Grafik sunucusuyla bağlantı kur
    mlx_ptr = mlx_init();
    if (mlx_ptr == NULL)
        return ; // Bağlantı başarısız olursa programdan çık

    // 2. Yeni bir pencere oluştur
    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "İlk Pencerem");
    if (win_ptr == NULL)
        return ; // Pencere oluşturma başarısız olursa programdan çık

    // 3. Olay döngüsünü başlat
    // Bu fonksiyon pencerenin açık kalmasını ve olayları dinlemesini sağlar.
    mlx_loop(mlx_ptr);

    // mlx_loop sonsuz bir döngü olduğu için bu satıra normalde ulaşılmaz.
    // Çıkış işlemleri olay yönetimi ile (sonraki derslerde) yapılır.
}