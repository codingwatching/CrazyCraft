#include <opengl/debug.h>
namespace Crazycraft
{


	struct Texture
	{
	public:
		unsigned char front;
		unsigned char back;
		unsigned char left;
		unsigned char right;
		unsigned char up;
		unsigned char down;

		Texture()
		{
			front = 0;
			back = 0;
			left = 0;
			right = 0;
			up = 0;
			down = 0;
		}

		Texture(unsigned char _front, unsigned char _back, unsigned char _left, unsigned char _right, unsigned char _up, unsigned char _down)
		{
			front = _front;
			back = _back;
			left = _left;
			right = _right;
			up = _up;
			down = _down;
		}

		int Gett(int FaceId)
		{
			switch (FaceId)
			{
				case 0:
					return front;
				case 1:
					return back;
				case 2:
					return left;
				case 3:
					return right;
				case 4:
					return up;
				case 5:
					return down;

				default:
					break;
			}
			return 0;
		}

	};


	struct Block
	{
	public:
		std::string name;
		char maxstack;
		bool isTransparent;

		Texture textures;

		Block(std::string newname, char newmaxstack, Texture t = Texture(), bool _isTransparent = false)
		{
			textures = t;
			name = newname;
			maxstack = newmaxstack;
			isTransparent = _isTransparent;
		}

	};

	class BlockDefs
	{
		std::vector<Block> bdata;
	public:
		void addBlock(Block b);

		Block getBlockData(int b);
	};

struct Face{
Vertex tl;
Vertex tr;
Vertex bl;
Vertex br;
bool isSolid;
Face(Vertex _tl,Vertex _tr,Vertex _bl,Vertex _br,bool _isSolid){
tl = _tl;
tr = _tr;
bl = _bl;
br = _br;
isSolid = _isSolid;
}
Face(){
}
};
struct BlockModel
{
	std::vector<Face> up;
	std::vector<Face> down;
	std::vector<Face> left;
	std::vector<Face> right;
	std::vector<Face> front;
	std::vector<Face> back;
	std::vector<Face> mid;

	std::vector<Face> getfaces(int f){
		switch (f)
		{
			case 0:
				return front;
			case 1:
				return back;
			case 2:
				return left;
			case 3:
				return right;
			case 4:
				return up;
			case 5:
				return down;
			case 6:
				return mid;
			default:
				ASSERT(false);

		
		}
	}
	glm::vec3 getfacedir(int f){
		
	switch (f)
	{
		case 0:
	return glm::vec3(0,0,0);
		case 1:
	return glm::vec3(0,0,0);
		case 2:
	return glm::vec3(0,0,0);
		case 3:
	return glm::vec3(0,0,0);
		case 4:
	return glm::vec3(0,0,0);
		case 5:
	return glm::vec3(0,0,0);
		default:
	ASSERT(false);
	}

	}
};

}