#pragma once
#include "BaseScene.h"

class TitleScene :
    public BaseScene
{
public:
	TitleScene();
	~TitleScene();
	/// <summary>
	/// �X�V����
	/// </summary>
	/// <param name="own">������Ă���V�[��</param>
	/// <returns></returns>
	UNBS Update(UNBS own) override;

	/// <summary>
	/// �`�揈��
	/// </summary>
	/// <param name=""></param>
	void Draw(void) override;
	SCN_ID GetSCNID_(void)override;
private:
};

