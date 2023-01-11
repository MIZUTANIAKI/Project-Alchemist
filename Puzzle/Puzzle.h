#pragma once
#include <vector>
#include <memory>
#include "Vector2.h"
#include "EnumTypeList.h"
#include "PosDate.h"
#include "MinoDate.h"
#include "MinoTemplate.h"
#include "../WorldDate/DateSystem.h"
#include "../WorldDate/Constellation.h"
#include "../WorldDate/SeasonSystem.h"


/// <summary>
/// TODO
/// パズルモード時の処理を作成
/// 注意点としてアイテム選択の時に選択したやつで
/// ミノが変わるからそれを反映させるようにするために
/// からでミノを設定する選択モードをつくったりする？
/// </summary>

class Puzzle
{
public:
	Puzzle();
	~Puzzle();

	void Init(int x = 6,int y = 10);

	/// <summary>
	/// 選択の時とパズルの時にぶんき
	/// </summary>
	/// <param name=""></param>
	void Update(void);
	
private:
	int GetAstrogicalBonus(Color color);

	bool SetPoint(int x, int y, std::vector<Vector2>& vec);
	std::vector<Vector2> PointFix(int x, int y, std::vector<Vector2>& vec);
	void DellPuzzleFieldDate(int id);

	int GetColor(Color color);



	std::vector<std::vector<PosDate>> puzzlefield;

	PosDate posDate_;
	PuzzleMode puzzleMode_;
	Color nextColor_;
	std::vector<std::vector<bool>> pasteMino_;
	MinoTemplate nowMino_;
	std::vector<std::vector<bool>> grabMino_;
	std::unique_ptr<MinoDate> monoDate_;


	int MAPSIZEX;
	int MAPSIZEY;
};

