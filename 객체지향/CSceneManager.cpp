#include "CSceneManager.h"
#include "CSceneGame.h"
CSceneManager::CSceneManager()
{
    sceneGame = nullptr;// new CSceneGame();

    sceneOver = nullptr;
    sceneTitle = new SceneTitle();
}

CSceneManager* CSceneManager::GetInstance()
{
    return this;
}

void CSceneManager::run(short input)
{
    if (sceneGame != nullptr)
    {
        sceneGame->Update(input);
    }
    if (sceneOver != nullptr)
    {
        sceneOver->Update(input);
    }
    if (sceneTitle != nullptr)
    {
        if (sceneTitle->Update(input))
        {
            delete sceneTitle;
            sceneTitle = nullptr;
            sceneGame = new CSceneGame();
        }
    }
}
