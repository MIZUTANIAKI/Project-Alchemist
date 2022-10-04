#pragma once
#include "BaseScene.h"

class TitleScene :
    public BaseScene
{
public:
	TitleScene();
	~TitleScene();
	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name="own">今流れているシーン</param>
	/// <returns></returns>
	UNBS Update(UNBS own) override;

	/// <summary>
	/// 描画処理
	/// </summary>
	/// <param name=""></param>
	void Draw(void) override;
	SCN_ID GetSCNID_(void)override;
private:
};

