#include "BaseScene.h"

BaseScene::BaseScene()
{
	scnID_ = SCN_ID::SCN_BASE;
}

BaseScene::~BaseScene()
{
}

SCN_ID BaseScene::GetSCNID_(void)
{
	return SCN_ID::SCN_BASE;
}
