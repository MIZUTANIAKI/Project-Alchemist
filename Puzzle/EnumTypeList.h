#pragma once

/// <summary>
/// 色
/// </summary>
enum class Color
{
	None,
	Red,	//火
	Green,	//風（気）
	Blue,	//水
	Yellow,	//土（地）
	Purple,	//空
	White	//時
};

/// <summary>
/// パズルモード
/// </summary>
enum class PuzzleMode
{
	none,
	write
};

/// <summary>
/// ミノの名前リスト
/// </summary>
enum class MinoTemplate
{
	Fmino,
	Imino,
	Lmino,
	Nmino,
	Pmino,
	Tmino,
	Umino,
	Vmino,
	Wmino,
	Xmino,
	Ymino,
	Zmino,
	Max
};
