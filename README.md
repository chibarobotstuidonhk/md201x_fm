# md201x_fw
md201xのファームウェアです．  
メモリに保存するパラメータが増えたりしているので，書き込んだ後は***必ず***もう一度パラメータ，IDを書き込み直してください．  
yskharaのファームウェアからの変更点としては，  
ロジック側電源を先に刺さなくてもCANの初期化が行われるように  
目標値と現在値をCANで流すように(ID0x7ff)  
しました．  
MDのconfgurePINの2をショートさせるとCANに目標値と現在値を流すようになります．  
int型のデータ2つの配列をuint64_tとして送信しているので、ros側でunpackするときは気をつけてください．

```
uint64_t tmp = 0;
can_unpack(msg->data, tmp);
_stream_msg.data[0] = (int)(tmp>>32);
_stream_msg.data[1] = (int)tmp;
```
# swingモード実装
baseid+2にfloatで指令値[rad/s]を送ると回転を始め，予め決めた角度[rad]だけ回り(指令を送った時点での場所からの相対角)，shutdownします．  
uartからSASRで回転角を決めることができます．  
SSVLに角速度を渡すと動作確認ができます．  

# 位置制御モードのD制御追加
uartでSKDPと打つとDゲインを決めることができます．  
