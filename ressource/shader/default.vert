#version 330 core
layout (location = 0) in vec2 aPos;   // the position variable has attribute position 0
layout (location = 1) in vec4 aColor; // the color variable has attribute position 1

out vec4 ourColor; // output a color to the fragment shader
out vec2 TexCoord;

void main()
{
  gl_Position = vec4(aPos, 0.0f, 1.0f);
  ourColor = aColor; // set ourColor to the input color we got from the vertex data
}