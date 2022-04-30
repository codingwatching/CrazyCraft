#include "Chunk.h"
#include <opengl/debug.h>
#include "game/world/Voxeldata.h"
#include <FastNoise/FastNoise.h>

static int TextureAtlasSizeInBlocks = 16;
float NormalizedBlockTextureSize = 0;

unsigned char Chunk::getBlock(int x, int y, int z)
{
	if (x < 0 || x > 16 || y < 0 || y > 16 || z < 0 || z > 16) return 0;
	int l = 4 + (noiseOutput[(((x + pos.x * dimensions.x) * dimensions.y) + (z + pos.z * dimensions.z))]) * 2;

	if (y <= l - 1)
		return 2;
	if (y == l)
		return 1;
	return 0;

}

bool Chunk::isBlockTransparent(int x, int y, int z)
{

	return bd.getBlockData(getBlock(x, y, z)).isTransparent;

}

glm::vec2 getuv(Crazycraft::Texture texture, int VertexID, int Faceid)
{
	float y = texture.Gett(Faceid) / TextureAtlasSizeInBlocks;
	float x = texture.Gett(Faceid) - (y * TextureAtlasSizeInBlocks);

	x *= NormalizedBlockTextureSize;
	y *= NormalizedBlockTextureSize;

	y = 1. - y - NormalizedBlockTextureSize;

	if (VertexID == 0)
		return glm::vec2(x - NormalizedBlockTextureSize, y);
	if (VertexID == 1)
		return glm::vec2(x, y);
	if (VertexID == 2)
		return glm::vec2(x, y + NormalizedBlockTextureSize);
	if (VertexID == 3)
		return glm::vec2(x - NormalizedBlockTextureSize, y + NormalizedBlockTextureSize);


	return glm::vec2(0, 0);

}

void Chunk::generate()
{

}

void Chunk::UpdateRenderData()
{
	unsigned int tricount = 0;
	unsigned int transparent_tricount = 0;


	for (int x = 0; x <= 16; x++)
	{
		for (int y = 0; y <= 16; y++)
		{
			for (int z = 0; z <= 16; z++)
			{
				Crazycraft::Block b = bd.getBlockData(getBlock(x, y, z));
				if (getBlock(x, y, z))
				{

					if (isBlockTransparent(x, y, z))
					{//generating transparent block data

						if (!getBlock(x, y, z - 1))
						{

							transparent_verticies.push_back(
								Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x - 1, y - 1, z - 1) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 0, 0)));
							transparent_verticies.push_back(
								Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x, y - 1, z - 1) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 1, 0)));
							transparent_verticies.push_back(
								Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x, y, z - 1) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 2, 0)));
							transparent_verticies.push_back(
								Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x - 1, y, z - 1) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 3, 0)));
							transparent_tris.push_back(transparent_tricount);
							transparent_tris.push_back(transparent_tricount + 1);
							transparent_tris.push_back(transparent_tricount + 2);
							transparent_tris.push_back(transparent_tricount + 2);
							transparent_tris.push_back(transparent_tricount + 3);
							transparent_tris.push_back(transparent_tricount);
							transparent_tricount += 4;

						}
						if (!getBlock(x, y, z + 1))
						{


							transparent_verticies.push_back(
								Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x - 1, y - 1, z) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 0, 1)));
							transparent_verticies.push_back(
								Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x, y - 1, z) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 1, 1)));
							transparent_verticies.push_back(
								Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x, y, z) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 2, 1)));
							transparent_verticies.push_back(
								Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x - 1, y, z) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 3, 1)));
							transparent_tris.push_back(transparent_tricount);
							transparent_tris.push_back(transparent_tricount + 1);
							transparent_tris.push_back(transparent_tricount + 2);
							transparent_tris.push_back(transparent_tricount + 2);
							transparent_tris.push_back(transparent_tricount + 3);
							transparent_tris.push_back(transparent_tricount);
							transparent_tricount += 4;

						}
						if (!getBlock(x + 1, y, z))
						{


							transparent_verticies.push_back(
								Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x, y - 1, z) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 0, 2)));
							transparent_verticies.push_back(
								Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x, y - 1, z - 1) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 1, 2)));
							transparent_verticies.push_back(
								Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x, y, z - 1) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 2, 2)));
							transparent_verticies.push_back(
								Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x, y, z) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 3, 2)));
							transparent_tris.push_back(transparent_tricount);
							transparent_tris.push_back(transparent_tricount + 1);
							transparent_tris.push_back(transparent_tricount + 2);
							transparent_tris.push_back(transparent_tricount + 2);
							transparent_tris.push_back(transparent_tricount + 3);
							transparent_tris.push_back(transparent_tricount);
							transparent_tricount += 4;

						}
						if (!getBlock(x - 1, y, z))
						{


							transparent_verticies.push_back(
								Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x - 1, y - 1, z - 1) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 0, 3)));
							transparent_verticies.push_back(
								Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x - 1, y - 1, z) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 1, 3)));
							transparent_verticies.push_back(
								Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x - 1, y, z) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 2, 3)));
							transparent_verticies.push_back(
								Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x - 1, y, z - 1) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 3, 3)));
							transparent_tris.push_back(transparent_tricount);
							transparent_tris.push_back(transparent_tricount + 1);
							transparent_tris.push_back(transparent_tricount + 2);
							transparent_tris.push_back(transparent_tricount + 2);
							transparent_tris.push_back(transparent_tricount + 3);
							transparent_tris.push_back(transparent_tricount);
							transparent_tricount += 4;

						}
						if (!getBlock(x, y + 1, z))
						{


							transparent_verticies.push_back(
								Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x - 1, y, z) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 0, 4)));
							transparent_verticies.push_back(
								Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x - 1, y, z - 1) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 1, 4)));
							transparent_verticies.push_back(
								Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x, y, z - 1) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 2, 4)));
							transparent_verticies.push_back(
								Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x, y, z) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 3, 4)));
							transparent_tris.push_back(transparent_tricount);
							transparent_tris.push_back(transparent_tricount + 1);
							transparent_tris.push_back(transparent_tricount + 2);
							transparent_tris.push_back(transparent_tricount + 2);
							transparent_tris.push_back(transparent_tricount + 3);
							transparent_tris.push_back(transparent_tricount);
							transparent_tricount += 4;

						}
						if (!getBlock(x, y - 1, z))
						{


							transparent_verticies.push_back(
								Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x - 1, y - 1, z) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 0, 5)));
							transparent_verticies.push_back(
								Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x - 1, y - 1, z - 1) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 1, 5)));
							transparent_verticies.push_back(
								Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x, y - 1, z - 1) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 2, 5)));
							transparent_verticies.push_back(
								Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x, y - 1, z) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 3, 5)));
							transparent_tris.push_back(transparent_tricount);
							transparent_tris.push_back(transparent_tricount + 1);
							transparent_tris.push_back(transparent_tricount + 2);
							transparent_tris.push_back(transparent_tricount + 2);
							transparent_tris.push_back(transparent_tricount + 3);
							transparent_tris.push_back(transparent_tricount);
							transparent_tricount += 4;

						}
					}
					else //generating non-transparent block data
					{


						if (isBlockTransparent(x, y, z - 1))
						{


							verticies.push_back(
								Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x - 1, y - 1, z - 1) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 0, 0)));
							verticies.push_back(Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x, y - 1, z - 1) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 1, 0)));
							verticies.push_back(Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x, y, z - 1) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 2, 0)));
							verticies.push_back(Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x - 1, y, z - 1) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 3, 0)));
							tris.push_back(tricount);
							tris.push_back(tricount + 1);
							tris.push_back(tricount + 2);
							tris.push_back(tricount + 2);
							tris.push_back(tricount + 3);
							tris.push_back(tricount);
							tricount += 4;

						}
						if (isBlockTransparent(x, y, z + 1))
						{


							verticies.push_back(Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x - 1, y - 1, z) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 0, 1)));
							verticies.push_back(Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x, y - 1, z) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 1, 1)));
							verticies.push_back(Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x, y, z) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 2, 1)));
							verticies.push_back(Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x - 1, y, z) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 3, 1)));
							tris.push_back(tricount);
							tris.push_back(tricount + 1);
							tris.push_back(tricount + 2);
							tris.push_back(tricount + 2);
							tris.push_back(tricount + 3);
							tris.push_back(tricount);
							tricount += 4;

						}
						if (isBlockTransparent(x + 1, y, z))
						{


							verticies.push_back(Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x, y - 1, z) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 0, 2)));
							verticies.push_back(Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x, y - 1, z - 1) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 1, 2)));
							verticies.push_back(Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x, y, z - 1) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 2, 2)));
							verticies.push_back(Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x, y, z) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 3, 2)));
							tris.push_back(tricount);
							tris.push_back(tricount + 1);
							tris.push_back(tricount + 2);
							tris.push_back(tricount + 2);
							tris.push_back(tricount + 3);
							tris.push_back(tricount);
							tricount += 4;

						}
						if (isBlockTransparent(x - 1, y, z))
						{


							verticies.push_back(
								Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x - 1, y - 1, z - 1) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 0, 3)));
							verticies.push_back(Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x - 1, y - 1, z) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 1, 3)));
							verticies.push_back(Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x - 1, y, z) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 2, 3)));
							verticies.push_back(Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x - 1, y, z - 1) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 3, 3)));
							tris.push_back(tricount);
							tris.push_back(tricount + 1);
							tris.push_back(tricount + 2);
							tris.push_back(tricount + 2);
							tris.push_back(tricount + 3);
							tris.push_back(tricount);
							tricount += 4;

						}
						if (isBlockTransparent(x, y + 1, z))
						{


							verticies.push_back(Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x - 1, y, z) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 0, 4)));
							verticies.push_back(Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x - 1, y, z - 1) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 1, 4)));
							verticies.push_back(Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x, y, z - 1) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 2, 4)));
							verticies.push_back(Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x, y, z) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 3, 4)));
							tris.push_back(tricount);
							tris.push_back(tricount + 1);
							tris.push_back(tricount + 2);
							tris.push_back(tricount + 2);
							tris.push_back(tricount + 3);
							tris.push_back(tricount);
							tricount += 4;

						}
						if (isBlockTransparent(x, y - 1, z))
						{


							verticies.push_back(Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x - 1, y - 1, z) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 0, 5)));
							verticies.push_back(
								Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x - 1, y - 1, z - 1) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 1, 5)));
							verticies.push_back(Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x, y - 1, z - 1) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 2, 5)));
							verticies.push_back(Vertex(glm::vec3(50.0f, 50.0f, 50) * glm::vec3(x, y - 1, z) + (glm::vec3) (pos * (dimensions * glm::ivec3(50, 50, 50))), getuv(b.textures, 3, 5)));
							tris.push_back(tricount);
							tris.push_back(tricount + 1);
							tris.push_back(tricount + 2);
							tris.push_back(tricount + 2);
							tris.push_back(tricount + 3);
							tris.push_back(tricount);
							tricount += 4;

						}
					}

				}

			}
		}
	}

//generating transparent render data
	unsigned int transparent_vb;

	GLCall(glGenVertexArrays(1, &transparent_rd.vao));//VAO
	GLCall(glBindVertexArray(transparent_rd.vao));

	GLCall(glGenBuffers(1, &transparent_vb));//VBO
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, transparent_vb));
	GLCall(glBufferData(GL_ARRAY_BUFFER, transparent_verticies.size() * sizeof(Vertex), transparent_verticies.data(), GL_STATIC_DRAW));

	GLCall(glGenBuffers(1, &transparent_rd.ibo));//IBO
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, transparent_rd.ibo));
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, transparent_tris.size() * sizeof(unsigned int), transparent_tris.data(), GL_STATIC_DRAW));

	GLCall(glEnableVertexAttribArray(0));//first argument
	GLCall(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (int*) 0));

	GLCall(glEnableVertexAttribArray(1));//second argument
	GLCall(glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (int*) (sizeof(float) * 3)));

//generating non-transparent render data
	unsigned int vb;

	GLCall(glGenVertexArrays(1, &rd.vao));//VAO
	GLCall(glBindVertexArray(rd.vao));

	GLCall(glGenBuffers(1, &vb));//VBO
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, vb));
	GLCall(glBufferData(GL_ARRAY_BUFFER, verticies.size() * sizeof(Vertex), verticies.data(), GL_STATIC_DRAW));

	GLCall(glGenBuffers(1, &rd.ibo));//IBO
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rd.ibo));
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, tris.size() * sizeof(unsigned int), tris.data(), GL_STATIC_DRAW));

	GLCall(glEnableVertexAttribArray(0));//first argument
	GLCall(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (int*) 0));

	GLCall(glEnableVertexAttribArray(1));//second argument
	GLCall(glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (int*) (sizeof(float) * 3)));

}

void Chunk::render()
{
	//rendering non-transparent blocks
	GLCall(glBindVertexArray(rd.vao));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rd.ibo));
	GLCall(glDrawElements(GL_TRIANGLES, tris.size(), GL_UNSIGNED_INT, nullptr));
	//rendering transparent blocks
	GLCall(glBindVertexArray(transparent_rd.vao));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, transparent_rd.ibo));
	GLCall(glDrawElements(GL_TRIANGLES, transparent_tris.size(), GL_UNSIGNED_INT, nullptr));
}


Chunk::Chunk(glm::ivec3 _pos){
bd.addBlock(Crazycraft::Block("E",1,Crazycraft::Texture(0,0,0,0,0,0),true));
bd.addBlock(Crazycraft::Block("E",1,Crazycraft::Texture(1,1,1,1,3,2)));
bd.addBlock(Crazycraft::Block("E",1,Crazycraft::Texture(2,2,2,2,2,2)));
bd.addBlock(Crazycraft::Block("E",1,Crazycraft::Texture(33,33,33,33,33,33),true));
 NormalizedBlockTextureSize = 1. / (float)TextureAtlasSizeInBlocks;
 pos = _pos;
noiseOutput = std::vector<float>(16*16);
auto fnGenerator = FastNoise::New<FastNoise::Simplex>();
// Generate a 16 x 16 x 16 area of noise
fnGenerator->GenUniformGrid2D(noiseOutput.data(), 0, 0, 16, 16, 0.2f,122);
}
