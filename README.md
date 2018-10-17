# Qt-Project2-影像分析與強化

## 開發環境

- Ubuntu 14.04
- Qt Creator
- 執行於 NVIDIA Jetson TK1
- PS. 此專案未加入cv套件之檔案

## 專案介紹

- 為了在工廠進行瑕疵檢測，因此需要針對檢測物件進行影像分析與強化，使其前後景分離找出清晰的料件影像。
- 撰寫一個能夠使用影像灰階及影像灰階直方等化，任一種臨界值決定法之二值化，及能夠疊代使用(平滑、中值、高斯、雙邊)雜訊去除法，以及任一種影像強化法，最後Show出結果的程式，並讓其在Jetson TK1上執行。

## 專案成果

![image](https://cdn1-t17-techbang.pixfs.net/system/attached_images/2018/10/246189/original/5b6619e75331af25244613df50f591ac.png)

- [Open Image] 打開圖片，且限制只能開圖片檔



