﻿#include <Novice.h>
#include "MatrixTrans.h"

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

	Vector3 from0 = Normalize(Vector3{ 1.0f,0.7f,0.5f });
	//Vector3 to0 = Multiply(from0, -1);
	Vector3 to0 = -from0;

	Vector3 from1 = Normalize(Vector3{ -0.6f,0.9f,0.2f });
	Vector3 to1 = Normalize(Vector3{ 0.4f,0.7f,-0.5f });

	Matrix4 rotateMatrix0 = DirectionToDirection(Normalize(Vector3{ 1.0f,0.0f, 0.0f }), Normalize(Vector3{ -1.0f,0.0f, 0.0f }));
	Matrix4 rotateMatrix1 = DirectionToDirection(from0, to0);
	Matrix4 rotateMatrix2 = DirectionToDirection(from1, to1);


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

		MatrixScreenPrintf(0, 20, rotateMatrix0, "rotateMatrix0");
		MatrixScreenPrintf(0, 20 + 20 * 5, rotateMatrix1, "rotateMatrix1");
		MatrixScreenPrintf(0, 20 + 20 * 10, rotateMatrix2, "rotateMatrix2");
	
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
