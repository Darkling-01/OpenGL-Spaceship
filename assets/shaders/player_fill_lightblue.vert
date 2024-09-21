#version 300 core

//global variables

layout (location = 0) in vec3 aPos  // the position variable has attribute position 0

// in qualified variables are typically changed per vertex
out  vec4 vertexColor;  // specify a color output to the fragment shader

void main(){
   gl_Position = vec4(aPos, 1.0);
   vertexColor = vec4(0.678f, 0.847f, 0.902f, 1.0f);  // set the output variable to baby-blue color

}


