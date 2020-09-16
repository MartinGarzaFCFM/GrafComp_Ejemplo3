////////////////////////////////////////////////////////////////////////////////
// Filename: modelclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "modelclass.h"


ModelClass::ModelClass()
{
	m_Texture = 0;
}


ModelClass::ModelClass(const ModelClass& other)
{
}


ModelClass::~ModelClass()
{
}


bool ModelClass::Initialize(OpenGLClass* OpenGL, char* textureFilename, 
	unsigned int textureUnit, bool wrap)
{
	bool result;


	// Initialize the vertex and index buffer that hold the geometry for the triangle.
	result = InitializeBuffers(OpenGL);
	if(!result)
	{
		return false;
	}

	// Load the texture for this model.
	result = LoadTexture(OpenGL, textureFilename, textureUnit, wrap);
	if(!result)
	{
		return false;
	}

	return true;
}


void ModelClass::Shutdown(OpenGLClass* OpenGL)
{
	// Release the texture used for this model.
	ReleaseTexture();

	// Release the vertex and index buffers.
	ShutdownBuffers(OpenGL);

	return;
}


void ModelClass::Render(OpenGLClass* OpenGL)
{
	// Put the vertex and index buffers on the graphics pipeline to prepare them for drawing.
	RenderBuffers(OpenGL);

	return;
}


bool ModelClass::InitializeBuffers(OpenGLClass* OpenGL)
{
	VertexType* vertices;
	unsigned int* indices;


	// Set the number of vertices in the vertex array.
	m_vertexCount = 14;

	// Set the number of indices in the index array.
	m_indexCount = 36;

	// Create the vertex array.
	vertices = new VertexType[m_vertexCount];
	if(!vertices)
	{
		return false;
	}

	// Create the index array.
	indices = new unsigned int[m_indexCount];
	if(!indices)
	{
		return false;
	}

	// Load the vertex array with data.
	// FIRST FACE
	// Bottom left.
	vertices[0].x = -1.0f;  // Position.
	vertices[0].y = -1.0f;
	vertices[0].z = 0.0f;

	vertices[0].tu = 0.0f;  // Texture coordinates.
	vertices[0].tv = 0.33f;

	// Top left.
	vertices[1].x = -1.0f;  // Position.
	vertices[1].y = 1.0f;
	vertices[1].z = 0.0f;

	vertices[1].tu = 0.0f;  // Texture coordinates.
	vertices[1].tv = 0.66f;

	// top right.
	vertices[2].x = 1.0f;  // Position.
	vertices[2].y = 1.0f;
	vertices[2].z = 0.0f;

	vertices[2].tu = 0.25f;  // Texture coordinates.
	vertices[2].tv = 0.66f;

	//bottom right
	vertices[3].x = 1.0f;  // Position.
	vertices[3].y = -1.0f;
	vertices[3].z = 0.0f;

	vertices[3].tu = 0.25f;  // Texture coordinates.
	vertices[3].tv = 0.33f;


	// SECOND FACE !!!!

	// top right
	vertices[4].x = 1.0f;  // Position.
	vertices[4].y = 1.0f;
	vertices[4].z = 2.0f;
			 
	vertices[4].tu = 0.50f;  // Texture coordinates.
	vertices[4].tv = 0.66;

	//bottom right
	vertices[5].x = 1.0f;  // Position.
	vertices[5].y = -1.0f;
	vertices[5].z = 2.0f;
			 
	vertices[5].tu = 0.50f;  // Texture coordinates.
	vertices[5].tv = 0.33f;

	///////////////////////
	//THIRD FACE
	//////////////////////

	// top right
	vertices[6].x = -1.0f;  // Position.
	vertices[6].y = 1.0f;
	vertices[6].z = 2.0f;

	vertices[6].tu = 0.75f;  // Texture coordinates.
	vertices[6].tv = 0.66;

	//bottom right
	vertices[7].x = -1.0f;  // Position.
	vertices[7].y = -1.0f;
	vertices[7].z = 2.0f;

	vertices[7].tu = 0.75f;  // Texture coordinates.
	vertices[7].tv = 0.33f;

	///////////////////////
	//FOURTH FACE
	//////////////////////

		// top right
	vertices[8].x = -1.0f;  // Position.
	vertices[8].y = 1.0f;
	vertices[8].z = 0.0f;

	vertices[8].tu = 1.0f;  // Texture coordinates.
	vertices[8].tv = 0.66;

	//bottom right
	vertices[9].x = -1.0f;  // Position.
	vertices[9].y = -1.0f;
	vertices[9].z = 0.0f; 

	vertices[9].tu = 1.0f;  // Texture coordinates.
	vertices[9].tv = 0.33f;

	///////////////////////
//ROOF FACE
//////////////////////

	// bottom left
	vertices[10].x = -1.0f;  // Position.
	vertices[10].y = 1.0f;
	vertices[10].z = 0.0f;

	vertices[10].tu = 0.25f;  // Texture coordinates.
	vertices[10].tv = 1.0f;

	//top left
	vertices[11].x = -1.0f;  // Position.
	vertices[11].y = 1.0f;
	vertices[11].z = 2.0f;

	vertices[11].tu = 0.50f;  // Texture coordinates.
	vertices[11].tv = 1.0f;

	///////////////////////
//BOTTOM FACE
//////////////////////

	// bottom left
	vertices[12].x = -1.0f;  // Position.
	vertices[12].y = -1.0f;
	vertices[12].z = 0.0f;

	vertices[12].tu = 0.25f;  // Texture coordinates.
	vertices[12].tv = 0.0f;

	//top left
	vertices[13].x = -1.0f;  // Position.
	vertices[13].y = -1.0f;
	vertices[13].z = 2.0f;

	vertices[13].tu = 0.50f;  // Texture coordinates.
	vertices[13].tv = 0.0f;


	// Load the index array with data.
	//PRIMERA CARA
	indices[0] = 0;  // Bottom left.
	indices[1] = 1;  // Top LEFT.
	indices[2] = 2;  // Bottom right.

	indices[3] = 0;
	indices[4] = 2;
	indices[5] = 3;

	//SEGUNDA CARA
	indices[6] = 3;
	indices[7] = 2;
	indices[8] = 4;

	indices[9] = 3;
	indices[10] = 4;
	indices[11] = 5;

	//TERCERA CARA
	indices[12] = 5;
	indices[13] = 4;
	indices[14] = 6;

	indices[15] = 5;
	indices[16] = 6;
	indices[17] = 7;

	//CUARTA CARA
	indices[18] = 7;
	indices[19] = 6;
	indices[20] = 8;

	indices[21] = 7;
	indices[22] = 8;
	indices[23] = 9;

	//ROOF
	indices[24] = 2;
	indices[25] = 10;
	indices[26] = 11;

	indices[27] = 2;
	indices[28] = 11;
	indices[29] = 4;

	//BOT
	indices[30] = 3;
	indices[31] = 5;
	indices[32] = 13;

	indices[33] = 3;
	indices[34] = 13;
	indices[35] = 12;



	
	// Allocate an OpenGL vertex array object.
	OpenGL->glGenVertexArrays(1, &m_vertexArrayId);

	// Bind the vertex array object to store all the buffers and vertex attributes we create here.
	OpenGL->glBindVertexArray(m_vertexArrayId);

	// Generate an ID for the vertex buffer.
	OpenGL->glGenBuffers(1, &m_vertexBufferId);

	// Bind the vertex buffer and load the vertex (position and texture) data into the vertex buffer.
	OpenGL->glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferId);
	OpenGL->glBufferData(GL_ARRAY_BUFFER, m_vertexCount * sizeof(VertexType), vertices, GL_STATIC_DRAW);

	// Enable the two vertex array attributes.
	OpenGL->glEnableVertexAttribArray(0);  // Vertex position.
	OpenGL->glEnableVertexAttribArray(1);  // Texture coordinates.

	// Specify the location and format of the position portion of the vertex buffer.
	OpenGL->glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferId);
	OpenGL->glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(VertexType), 0);

	// Specify the location and format of the texture coordinate portion of the vertex buffer.
	OpenGL->glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferId);
	OpenGL->glVertexAttribPointer(1, 2, GL_FLOAT, false, sizeof(VertexType), (unsigned char*)NULL + (3 * sizeof(float)));

	// Generate an ID for the index buffer.
	OpenGL->glGenBuffers(1, &m_indexBufferId);

	// Bind the index buffer and load the index data into it.
	OpenGL->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBufferId);
	OpenGL->glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indexCount* sizeof(unsigned int), indices, GL_STATIC_DRAW);
	
	// Now that the buffers have been loaded we can release the array data.
	delete [] vertices;
	vertices = 0;

	delete [] indices;
	indices = 0;

	return true;
}


void ModelClass::ShutdownBuffers(OpenGLClass* OpenGL)
{
	// Disable the two vertex array attributes.
	OpenGL->glDisableVertexAttribArray(0);
	OpenGL->glDisableVertexAttribArray(1);
	
	// Release the vertex buffer.
	OpenGL->glBindBuffer(GL_ARRAY_BUFFER, 0);
	OpenGL->glDeleteBuffers(1, &m_vertexBufferId);

	// Release the index buffer.
	OpenGL->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	OpenGL->glDeleteBuffers(1, &m_indexBufferId);

	// Release the vertex array object.
	OpenGL->glBindVertexArray(0);
	OpenGL->glDeleteVertexArrays(1, &m_vertexArrayId);

	return;
}


void ModelClass::RenderBuffers(OpenGLClass* OpenGL)
{
	// Bind the vertex array object that stored all the information about the vertex and index buffers.
	OpenGL->glBindVertexArray(m_vertexArrayId);

	// Render the vertex buffer using the index buffer.
	glDrawElements(GL_TRIANGLES, m_indexCount, GL_UNSIGNED_INT, 0);

	return;
}


bool ModelClass::LoadTexture(OpenGLClass* OpenGL, char* textureFilename, 
	unsigned int textureUnit, bool wrap)
{
	bool result;


	// Create the texture object.
	m_Texture = new TextureClass;
	if(!m_Texture)
	{
		return false;
	}

	// Initialize the texture object.
	result = m_Texture->Initialize(OpenGL, textureFilename, textureUnit, wrap);
	if(!result)
	{
		return false;
	}

	return true;
}


void ModelClass::ReleaseTexture()
{
	// Release the texture object.
	if(m_Texture)
	{
		m_Texture->Shutdown();
		delete m_Texture;
		m_Texture = 0;
	}

	return;
}