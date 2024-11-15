#include"GameData.h"

//Mapの呼び出し
int GameData::s_score = 1;
//残機のリセット
const int GameData::Zanki_set = 3;
//残機の初期値
int GameData::zanki = 3;
//クリア関連
bool GameData::Gameclear = false;
//ゲームオーバー関連
bool GameData::Gameover = false;
//リトライ関連
bool GameData::Gametry = false;
//ゲームクリアしているかの判定（ステージ３をクリアするとリトライ画像を出さないため等）
bool GameData::clear = false;
