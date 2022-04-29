#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <array>


#include<game/game.h>
#include <opengl/debug.h>
#include "block.h"

namespace Crazycraft
{
	void BlockDefs::addBlock(Block b)
	{
		bdata.push_back(b);
	}

	Block BlockDefs::getBlockData(int b)
	{
		if (b >= bdata.size())
			return bdata[0];

		return bdata[b];
	}
} 
