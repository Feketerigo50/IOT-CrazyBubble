# IOT-CrazyBubble

 以 App Inventor 結合 Arduino 實作能夠幫助腦麻兒復健的正回饋泡泡機

## Project motivation
 「腦性麻痺」簡稱「腦麻」，形容的是在幼年早期出現的永久性運動障礙統稱，具有這種症狀的孩童，被稱為腦麻兒。目前主要的治療方式可以分為「藥物治療」、「手術治療」以及「輔助醫療」三種，在輔助醫療行為中我們可以透過以 task-oriented 加上 motor learning 的概念，為腦麻兒的復健提供一定程度的幫助。在已知個案非常喜歡泡泡以及音樂的前提下，以 Arduino 結合 App 控制工具、藍芽、馬達、感測器，以及簡單的電路設計，製作出一台「只要手做出目標復健動作，便會主動播放其最喜歡的歌曲，以及產出大量繽紛的泡泡」的輔助機器，這樣一來便可以促進該孩童復健，造福社會。
    
## Implementation
 由於實作過程中發生不可抗力之因素，感測器取得困難，故改成單純由 App 觸發之輔助機器。
 
 修改過後的控制流程為
 
 ![image](https://github.com/Feketerigo50/IOT-CrazyBubble/blob/master/demo_image/flowchart.png)
 
 App Inventor上的控制程式碼
 
 ![image](https://github.com/Feketerigo50/IOT-CrazyBubble/blob/master/demo_image/appcode.png)
 
 藉由 App 按鈕傳送訊號給 Arduino，Arduino 根據信號內容控制泡泡機轉動以及喇叭撥放
	
 Arudino 上主要控制機器的程式碼如下
 
 ```
 case 'S':
  digitalWrite(LED,HIGH); // 透過這行控制音樂播放
  analogWrite(5,210);     // 這行控制吹泡桿轉動速度
  digitalWrite(4,HIGH);   // 泡泡機轉速
  break;
 case 'E':
  digitalWrite(LED,LOW);
  digitalWrite(4,LOW);
  break;
 ```
 
 最後再加上電路設計便成功!
 
 ## Result
 
 與想像中有龐大落差的最終產出
 
 ![image](https://github.com/Feketerigo50/IOT-CrazyBubble/blob/master/demo_image/machine.png)
 
 
 ## Conclusion
 
 透過此專案學到了很多硬體方面知識，實際操作後對整個物聯網的架構更加了解，也熟悉許多課堂上的知識，當初構想時有跟外校的特殊教育學系實習老師一同討論，透過會產生音樂，泡泡，這樣獎勵性教育的方式提供給腦麻兒一個復健的手段，只可惜最後實作時並沒有成功，外觀部分也過於陽春，期待之後有閒能夠改進。
 
 不，才不會，程式沒寫錯，線路沒接錯不就好了嗎? 哈哈哈！(懶惰癌徹底發作)
 
 ## Reference
 
  wiki and some of my friends.
