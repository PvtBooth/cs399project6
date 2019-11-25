/******************************************************************************/
/*!
\file   IntroStackState.c
\author Ryan Booth
\date   3/9/2017
\par    Project: BlastDroids
\par    Copyright � 2017 DigiPen (USA) Corporation.
\brief
*/
/******************************************************************************/

#include "IntroStackState.h"
#include "GameStateStack.h"
#include "MainMenuStackState.h"
#include "Graphics.h"
#include "Sprite.h"
#include "EntityManager.h"
#include "RenderComponent.h"
#include "Camera.h"

/*------------------------------------------------------------------------------
// Private Consts:
//----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
// Private Structures:
//----------------------------------------------------------------------------*/
typedef struct IntroStackState IntroStackState;
struct IntroStackState
{
    StackState stackState;

    TextureAsset *textureTest;
    Sprite *spriteTest;
    Entity *entityTest;

};
/*------------------------------------------------------------------------------
// Public Variables:
//----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
// Private Variables:
//----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
// Private Function Declarations:
//----------------------------------------------------------------------------*/
static void Init(StackState *self);
static void Update(StackState *self, float dt);
static bool InputHandle(StackState *self, InputEvent *inputEvent);
static void Render(StackState *self);
static void Exit(StackState *self);
/*------------------------------------------------------------------------------
// Public Functions:
//----------------------------------------------------------------------------*/
StackState *IntroStackState_Create()
{
    IntroStackState *state = calloc(1, sizeof(IntroStackState));
    state->stackState.init = Init;
    state->stackState.update = Update;
    state->stackState.inputHandle = InputHandle;
    state->stackState.exit = Exit;
    state->stackState.render = Render;
    state->stackState.renderBelow = false;
    state->stackState.updateBelow = false;
    state->stackState.name = "Intro";

    return &state->stackState;
}
/*------------------------------------------------------------------------------
// Private Functions:
//----------------------------------------------------------------------------*/
static void Init(StackState *self)
{
    IntroStackState *state = (IntroStackState*)self;
    self->entityManager = EntityManager_Create(self);
    self->graphicsManager = GraphicsManager_Create(self);

    RECT windowSize = Graphics_GetWindowResolution();
    Vector2 size;
    size.x = (float)(windowSize.right - windowSize.left);
    size.y = (float)(windowSize.bottom - windowSize.top);
    Camera_Init();
    //state->textureTest = Texture_Load("Assets/finalstates/intro.png");
    state->textureTest = AssetTable_TryLoadTextureAsset("Intro", "Assets/finalstates/intro.png");
    assert(state->textureTest);
    state->spriteTest = Sprite_Create(state->textureTest);
    state->entityTest = EntityManager_CreateEntity(self->entityManager, "Background");
    Entity_AttachComponent(state->entityTest, TransformComponent_Create());
    TransformComponent_AddScale(state->entityTest->transformComponent, size);
    Entity_AttachComponent(state->entityTest, RenderComponent_CreateSprite(state->spriteTest, RENDER_BEHAVIOR_SPRITE, RENDER_LAYER_BACKGROUND));
}

static void Update(StackState *self, float dt)
{
    UNREFERENCED_PARAMETER(self);

    Camera_Update(dt);

    if (AEInputCheckTriggered(VK_RETURN))
    {
        GameStateStack_PushState(MainMenuStackState_Create());
        GameStateStack_PopState();
    }
}

static bool InputHandle(StackState *self, InputEvent *inputEvent)
{
  UNREFERENCED_PARAMETER(self);

  if (inputEvent->inputEventType != INPUT_EVENT_TYPE_TRIGGERED)
  {
    return false;
  }
  if (inputEvent->inputType == INPUT_TYPE_BUTTON_A || inputEvent->inputType == INPUT_TYPE_BUTTON_START)
  {
    GameStateStack_PushState(MainMenuStackState_Create());
    GameStateStack_PopState();
    return true;
  }

  return false;

}

static void Render(StackState *self)
{
  GraphicsManager_Render(self->graphicsManager);
}

static void Exit(StackState *self)
{
    EntityManager_DestroyAllImmediate(self->entityManager);
    EntityManager_Destroy(self->entityManager);
    GraphicsManager_Destroy(self->graphicsManager);
}