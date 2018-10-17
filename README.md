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
- [Clear Processing] 清除畫面，只保留原始圖片檔(左上角)
- [Close App] 關閉程式
- [Gray] 圖片灰階(顯示於左下角)
- [Eqhist] 直方圖等化(顯示於左下角)
- [Open Image] 打開圖片，且限制只能開圖片檔
- [Open Image] 打開圖片，且限制只能開圖片檔

- [Blur] 均值濾波(顯示於中間上方)
- [Median Blur] 中值濾波(顯示於中間上方)
- [Gaussian Blur] 高斯濾波(顯示於中間上方)
- [Bilateral Blur] 雙邊濾波(顯示於中間上方)
- [Threshold] 圖片二值化，並可輸入固定閾值(0~255)(顯示於中間下方)
PS. 固定閾值：直接給定一個灰階值當閾值，再用這個閾值進行二值化。
- [Threshold (otsu)] 圖片二值化，並使用自適應閾值(顯示於中間下方)
PS. 自適應閾值：會依據輸入影像計算出較合適的閾值，再用這個閾值進行二值化。

形態學：先經過 Threshold (otsu) 再行運算。
- [Dilate] 圖片膨脹(顯示於右上方)
- [Erode] 圖片侵蝕(顯示於右上方)
- [Open] 去除小雜訊(顯示於右上方)
- [Closing] 去除小洞(顯示於右上方)
- [Gradient] 找輪廓(顯示於右上方)
- [TopHat] 形態學Open及輸入影像之間的差異(顯示於右上方)
- [BlackHat] 形態學Close及輸入影像之間的差異(顯示於右上方)
