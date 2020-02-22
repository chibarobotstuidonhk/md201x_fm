# md201x_fm
md201xのファームウェアです  
yskharaのファームウェアからの変更点としては  
ロジック側電源を先に刺さなくてもCANの初期化が行われるように  
目標値と現在値をCANで流すように(ID0x7ff)  
しました  
MDのconfgurePINの2をショートさせるとCANに目標値と現在値を流すようになります  
int型のデータ2つの配列をuint64_tとして送信しているので、ros側でunpackするときは気をつけてください。

```
uint64_t tmp = 0;
can_unpack(msg->data, tmp);
_stream_msg.data[0] = (int)(tmp>>32);
_stream_msg.data[1] = (int)tmp;
```
