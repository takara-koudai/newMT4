#include <Novice.h>
#include "MatrixTrans.h"
#include "Quaternion.h"

const char kWindowTitle[] = "LC1C_20_タナカコウダイ_タイトル";

const int kWindowWidth = 1280;
const int kWindowHeight = 720;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);


	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Quaternion p1 = { 2.0f,3.0f,4.0f,1.0f };
	Quaternion p2 = { 1.0f,3.0f,5.0f,2.0f };
	Quaternion identity = IdentituQuaternion();
	Quaternion conj = Conjugate(p1);
	Quaternion inv = Inverse(p1);
	Quaternion normal = Normalize(p1);
	Quaternion mul1 = Multiply(p1, p2);
	Quaternion mul2 = Multiply(p2, p1);
	float norm = Norm(p1);


	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		

		
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
