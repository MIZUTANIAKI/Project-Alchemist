#include <DxLib.h>
#include "ModelLoad.h"

ModelLoad::ModelLoad()
{
}

ModelLoad::~ModelLoad()
{
}

void ModelLoad::Load(int* handl, std::string filep)
{
	auto loadModel = [&](std::string filename, int* modelHandle) {
		LoadNow(modelHandle, filename);
	};

	std::thread thr(loadModel, filep, handl);
	thr.detach();
}

bool ModelLoad::IsLoadFIn(void)
{
	return loadF;
}

void ModelLoad::LoadNow(int* modelHandle, std::string filename)
{
	loadF = false;
	{
		mtx.lock();
		*modelHandle = MV1LoadModel(filename.c_str());
		mtx.unlock();
	}
	loadF = true;
}
