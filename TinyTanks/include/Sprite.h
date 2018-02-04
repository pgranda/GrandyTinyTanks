#include "Node.h"
#include "UGFW.h"
#include "Enumerations.h"

#include "Vector4.h"
#include "Matrix4.h"

class Sprite : public Node
{
public:
	//Constructors -- makes a UG Sprite object for us to use
	Sprite(const char* a_fileName, int a_width, int a_height, Vector2 a_origin, Vector4 a_UVCoords);
	Sprite(const char* a_fileName, int a_width, int a_height, Vector2 a_origin);

	//Destructor
	virtual ~Sprite();
	
	/**
	Sets the Sprite Layer.

	@param a_uiLayer Layer on which our player should be drawn.
	*/
	void SetLayer(unsigned int a_uiLayer);
	

	/**
	Updates the position of objects in the world.

	@param a_fdt DeltaTime of the main program.
	*/
	void Update(float a_fdt);

	/**
	Changes sprite position in the world.

	@param a_movementVec Sprites movement vector.
	*/
	void MoveSprite(Vector3 a_movementVec);

	/**
	Draws the sprite.
	*/
	void MarkForDraw();

	/**
	Stops drawing the sprite.
	*/
	void StopDrawing();

	/**
	Destroys the sprite.
	*/
	void DestroySprite();

	/**
	Sets sprite positions
	*/
	void SetPosition(Vector2 a_pos);

	/**
	Gets isDrawing flag state.

	@return isDrawing Returns the flag which determines if the sprite is being drawn.
	*/
	bool GetIsDrawing();

	/**
	Sets Sprite UV Coordinates

	@param a_animFrames Array of UV coordinates on sprite sheet.
	*/
	void SetSpriteUVCoordinates(float* a_animFrames);

private:
	int m_iSpriteID;
	int m_iWidth;
	int m_iHeight;
	bool isDrawing;
	Vector2 m_v2Origin;

};