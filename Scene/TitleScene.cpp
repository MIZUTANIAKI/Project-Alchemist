#include "TitleScene.h"
#include "ImageMng.h"

TitleScene::TitleScene()
{
	scnID_ = SCN_ID::SCN_TITLE;
}

TitleScene::~TitleScene()
{
}

UNBS TitleScene::Update(UNBS own)
{
	return std::move(own);
}

void TitleScene::Draw(void)
{
}

SCN_ID TitleScene::GetSCNID_(void)
{
	return scnID_;
}
